// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include <avr/pgmspace.h>
#if __CLION_IDE__
#include "MPU6050/MPU6050.h" // not necessary if using MotionApps include file
#include "MPU6050/MPU6050_6Axis_MotionApps20.h"
#else
#include "MPU6050_6Axis_MotionApps20.h"
#endif

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      21

#include <Servo.h>

#define MAX_DELTATIME 20000
#define analogPin 1
#define DIR_PIN 4
#define SERVO_PIN 10

#define ENCODER_PIN 3
#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
//#define TEST_COMMUNICATION_LATENCY

#include <ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;

std_msgs::Float32 yaw_msg;
std_msgs::Float32 pitch_msg;
std_msgs::Float32 roll_msg;
//std_msgs::Float32 revolution_msg;
geometry_msgs::Twist twist_msg;

ros::Publisher pub_yaw("yaw", &yaw_msg);
ros::Publisher pubTwist("twist", &twist_msg);
//ros::Publisher pubRevolutions("revolutions", &revolution_msg);
ros::Publisher pubRoll("roll", &roll_msg);
ros::Publisher pubPitch("pitch", &pitch_msg);

void onLedCommand(const std_msgs::String &cmd_msg);
void onSteeringCommand(const std_msgs::UInt8 &cmd_msg);
void onSpeedCommand(const std_msgs::Int16 &cmd_msg);
ros::Subscriber<std_msgs::String> ledCommand("led", onLedCommand);
ros::Subscriber<std_msgs::UInt8> steeringCommand("steering", onSteeringCommand);
ros::Subscriber<std_msgs::Int16> speedCommand("speed", onSpeedCommand);

#ifdef TEST_COMMUNICATION_LATENCY
#include <std_msgs/Bool.h>
std_msgs::Bool resp_msg;

ros::Publisher pubResponse("resp", &resp_msg);
void onLatency(const std_msgs::Bool &cmd_msg) {
    resp_msg.data = true;
    pubResponse.publish(&resp_msg);
}
ros::Subscriber<std_msgs::Bool> requestCommand("req", onLatency);
#endif

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high


// uncomment "OUTPUT_READABLE_QUATERNION" if you want to see the actual
// quaternion components in a [w, x, y, z] format (not best for parsing
// on a remote host such as Processing or something though)
//#define OUTPUT_READABLE_QUATERNION

// uncomment "OUTPUT_READABLE_EULER" if you want to see Euler angles
// (in degrees) calculated from the quaternions coming from the FIFO.
// Note that Euler angles suffer from gimbal lock (for more info, see
// http://en.wikipedia.org/wiki/Gimbal_lock)
//#define OUTPUT_READABLE_EULER

// uncomment "OUTPUT_READABLE_REALACCEL" if you want to see acceleration
// components with gravity removed. This acceleration reference frame is
// not compensated for orientation, so +X is always +X according to the
// sensor, just without the effects of gravity. If you want acceleration
// compensated for orientation, us OUTPUT_READABLE_WORLDACCEL instead.
//#define OUTPUT_READABLE_REALACCEL

// uncomment "OUTPUT_READABLE_WORLDACCEL" if you want to see acceleration
// components with gravity removed and adjusted for the world frame of
// reference (yaw is relative to initial orientation, since no magnetometer
// is present in this case). Could be quite handy in some cases.
//#define OUTPUT_READABLE_WORLDACCEL

// uncomment "OUTPUT_TEAPOT" if you want output that matches the
// format used for the InvenSense teapot demo
//#define OUTPUT_TEAPOT

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo myservo; // create servo object to control a servo
int servo_pw = 1500;    // variable to set the angle of servo motor
int last_pw = 0;
volatile unsigned long T1Ovs2;
volatile int16_t encoder_counter;              //CAPTURE FLAG
volatile int16_t last_encoder_counter;
volatile unsigned long deltatime = 0;
volatile boolean first_rising = true;

int8_t direction_motor = 1;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
//float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector


// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void StartTimer2(void) {
    pinMode(11, OUTPUT); //976.5625Hz
    TCNT2 = 0;
    TIFR2 = 0x00;
    TIMSK2 = TIMSK2 | 0x01;
    TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS22);
    TCCR2B = (TCCR2B & 0b11111000) | 0x02;//62500HZ= 16MHz/1024/2=7812
    sei();
}

ISR(TIMER2_OVF_vect) {
    TIFR2 = 0x00;
    T1Ovs2++;//INCREMENTING OVERFLOW COUNTER
}

void encoder() {
    if (!first_rising) {
        deltatime = T1Ovs2 * 25 + T1Ovs2 * 5 / 10 + TCNT2 / 10;// prevent overflow of integer number!
    }

    T1Ovs2 = 0;         //SAVING FIRST OVERFLOW COUNTER
    TCNT2 = 0;
    first_rising = false;
    encoder_counter++;
}


// ================================================================
// ===               SUBSCRIBERS                                ===
// ================================================================
void onSteeringCommand(const std_msgs::UInt8 &cmd_msg) {
    if ((cmd_msg.data <= 180) && (cmd_msg.data >= 0)) {
        // scale it to use it with the servo (value between 0 and 180)
        servo_pw = map(cmd_msg.data, 0, 180, 900, 1900);

        if (last_pw!=servo_pw) {
            myservo.writeMicroseconds(servo_pw);
        }
        last_pw = servo_pw;
    }
}

void onSpeedCommand(const std_msgs::Int16 &cmd_msg) {
    int16_t motor_val = cmd_msg.data / 4;

    if (motor_val < 0) {
        digitalWrite(DIR_PIN, LOW);
        motor_val = motor_val * -1;
        direction_motor = 1;

    } else {
        digitalWrite(DIR_PIN, HIGH);
        direction_motor = -1;
    }

    if (abs(motor_val) < 15) {
        motor_val = 15;
    }

    OCR2A = motor_val;
}


/* Control lights */
/*L20C32+16+8+4+2+1, 32+16/16=2+1 -> R , 8+4/4=2+1 -> G, 2+1 -> B : WHITE=63, RED=48, YELLOW=56,OR 60*/
void onLedCommand(const std_msgs::String &cmd_msg){
    if (strcmp_P(cmd_msg.data, PSTR("Lle")) == 0)
    {
        pixels.setPixelColor(0, pixels.Color(255,80,0)); //yellow
        pixels.setPixelColor(7, pixels.Color(255,80,0)); //yellow
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lri")) == 0)
    {
        pixels.setPixelColor(3, pixels.Color(255,80,0)); //yellow
        pixels.setPixelColor(4, pixels.Color(255,80,0)); //yellow
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lstop")) == 0)
    {
        for (uint8_t i=4;i<8;i++)
            pixels.setPixelColor(i, pixels.Color(255,0,0)); //red
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lpa")) == 0 || strcmp_P(cmd_msg.data, PSTR("Lta")) == 0)
    {
        for (uint8_t i=0;i<4;i++)
            pixels.setPixelColor(i, pixels.Color(50,50,50)); //white (darker)

        for (uint8_t i=4;i<8;i++)
            pixels.setPixelColor(i, pixels.Color(50,0,0)); //red (darker)

    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lre")) == 0)
    {
        pixels.setPixelColor(5, pixels.Color(50,50,50)); //white (darker)
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lfr")) == 0)
    {
        for (uint8_t i=0;i<4;i++)
            pixels.setPixelColor(i, pixels.Color(255,255,255)); //white
    }
    else if (strcmp_P(cmd_msg.data, PSTR("LdiL")) == 0)
    {
        for (uint8_t i=0;i<8;i++)
            pixels.setPixelColor(i, pixels.Color(0,0,0)); //disable
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
}

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================
void setup() {
    nh.getHardware()->setBaud(1000000);
    nh.initNode();
    nh.advertise(pubTwist);
    nh.advertise(pub_yaw);
    //nh.advertise(pubRevolutions);
    nh.advertise(pubRoll);
    nh.advertise(pubPitch);

    nh.subscribe(ledCommand);
    nh.subscribe(steeringCommand);
    nh.subscribe(speedCommand);
    #ifdef TEST_COMMUNICATION_LATENCY
    nh.subscribe(requestCommand);
    nh.advertise(pubResponse);
    #endif

    // join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif

    // initialize device
    nh.logerror(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    nh.loginfo(F("Testing device connections..."));
    nh.loginfo(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // load and configure the DMP
    //Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXAccelOffset(-573);
    mpu.setYAccelOffset(-2139);
    mpu.setZAccelOffset(1723); // 1688 factory default for my test chip
    mpu.setXGyroOffset(71);
    mpu.setYGyroOffset(-12);
    mpu.setZGyroOffset(28);

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        //Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        nh.loginfo(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        nh.loginfo(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        nh.logerror(F("DMP Initialization failed (code"));
        nh.logerror("" + devStatus);
        nh.logerror(F(")"));
    }

    pinMode(ENCODER_PIN, INPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENCODER_PIN, INPUT_PULLUP);
    digitalWrite(ENCODER_PIN, HIGH);             //pull up
    StartTimer2();
    // attaches the servo on pin 9 to the servo object
    myservo.attach(SERVO_PIN);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), encoder, RISING);
    pixels.begin(); // This initializes the NeoPixel library.
}


// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {

        // Serial.println("here");
        // other program behavior stuff here
        // val = analogRead(analogPin);    // read the input pin
//        Serial.println(va/l);  
//          Serial.print((float)deltatime); ///*0.0000000625 second
//         Serial.print("Millisecond Encode"); 
//          Serial.print((int)encoder_counter);
//          Serial.print("\n");
//          serialEvent(); //read serial port commands from odroid
//          if (stringComplete) 
//          {
//            lightControl(); // control lights of the car, this function should call befor control motor
//            servoControl(); // control servo motor
//            speedControl();
//            stringComplete = false;
//             Serial.print("string");
//          }
        // if you are really paranoid you can frequently test in between other
        // stuff to see if mpuInterrupt is true, and if so, "break;" from the
        // while() loop to immediately process the MPU data
        // .
        // .
        // .
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        //nh.logerror("FIFO overflow!");

        // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);

        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

#ifdef OUTPUT_READABLE_QUATERNION
        // display quaternion values in easy matrix form: w x y z
            mpu.dmpGetQuaternion(&q, fifoBuffer);
//            Serial.print("quat\t");
            //Serial.print(q.w);
            //Serial.print("\t");
            //Serial.print(q.x);
            //Serial.print("\t");
            //Serial.print(q.y);
            //Serial.print("\t");
            //Serial.println(q.z);
#endif

#ifdef OUTPUT_READABLE_EULER
        // display Euler angles in degrees
//            mpu.dmpGetQuaternion(&q, fifoBuffer);
//            mpu.dmpGetEuler(euler, &q);
            //Serial.print("euler\t");
            //Serial.print(euler[0] * 180/M_PI);
            //Serial.print("\t");
            //Serial.print(euler[1] * 180/M_PI);
            //Serial.print("\t");
            //Serial.println(euler[2] * 180/M_PI);
#endif

#ifdef OUTPUT_READABLE_YAWPITCHROLL
        // display Euler angles in degrees
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
//            //Serial.print("ypr\t");
//            //Serial.println(ypr[0] * 180/M_PI);
//            //Serial.print("\t");
//            //Serial.print(ypr[1] * 180/M_PI);
//            //Serial.print("\t");
//            //Serial.println(ypr[2] * 180/M_PI);
#endif



//        //Serial.print("y");
//        //Serial.print(ypr[0] * 180/M_PI);
//        //Serial.print("s");
//        //Serial.print(deltatime); ///*0.0000000625 second
//        //Serial.print("e"); 
//        Serial.print((int)encoder_counter);
//        Serial.print("\n");

        yaw_msg.data = ypr[0] * 180.0 / M_PI;
        pub_yaw.publish(&yaw_msg);

        pitch_msg.data = ypr[1] * 180.0 / M_PI;
        pubPitch.publish(&pitch_msg);

        roll_msg.data = ypr[2] * 180.0 / M_PI;
        pubRoll.publish(&roll_msg);

        //revolution_msg.data = encoder_counter / 6.0;
        //pubRevolutions.publish(&revolution_msg);

        // we did receive data from the motor
        if (last_encoder_counter != encoder_counter) {
            if (deltatime != 0) {
                //twist_msg.linear.y = deltatime;
                //rad/second -> each tick is 0.005 ms: Arduino timer is 2Mhz , but counter divided by 10 in arduino! 6 lines per revolution!
                if (deltatime > 0) {
                    twist_msg.linear.x = (M_PI / 3.0) / (deltatime * 0.005 * 0.001);
                } else {
                    twist_msg.linear.y = 0;
                }
            }

            twist_msg.linear.x = twist_msg.linear.x * direction_motor;
            twist_msg.linear.y = 0.0;
            twist_msg.linear.z = 0.0;
            pubTwist.publish(&twist_msg);
        } else {
            // we did receive nothing so check if the motor has stopped
            if (T1Ovs2 * 25 + T1Ovs2 * 5 / 10 + TCNT2 / 10 > MAX_DELTATIME) {
                twist_msg.linear.x = 0.0;
                twist_msg.linear.y = 0.0;
                twist_msg.linear.z = 0.0;

                first_rising = true;

                pubTwist.publish(&twist_msg);

                deltatime = 0;
            }
        }
        last_encoder_counter = encoder_counter;
    }

    nh.spinOnce();
}


