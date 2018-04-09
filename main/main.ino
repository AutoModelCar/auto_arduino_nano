// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
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
#define dirPin 4
//#define EncoderPin 8
#define servo_pin 10

#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards


#include <ros.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;

std_msgs::Float32 yaw_msg;
std_msgs::Float32 pitch_msg;
std_msgs::Float32 roll_msg;
std_msgs::Float32 revolution_msg;
geometry_msgs::Twist twist_msg;

ros::Publisher pub_yaw("yaw", &yaw_msg);
ros::Publisher pubTwist("twist", &twist_msg);
ros::Publisher pubRevolutions("revolutions", &revolution_msg);
ros::Publisher pubRoll("roll", &roll_msg);
ros::Publisher pubPitch("pitch", &pitch_msg);

/*void onFrontLeftLedCommand(const std_msgs::UInt32 &cmd_msg);
void onFrontRightLedCommand(const std_msgs::UInt32 &cmd_msg);
void onBackLeftLedCommand(const std_msgs::UInt32 &cmd_msg);
void onBackRightLedCommand(const std_msgs::UInt32 &cmd_msg);*/
void onSteeringCommand(const std_msgs::UInt8 &cmd_msg);
void onSpeedCommand(const std_msgs::Int16 &cmd_msg);
/*ros::Subscriber<std_msgs::UInt32> frontLeftLedCommand("front_left_led", onFrontLeftLedCommand);
ros::Subscriber<std_msgs::UInt32> frontRightLedCommand("front_right_led", onFrontRightLedCommand);
ros::Subscriber<std_msgs::UInt32> backLeftLedCommand("back_left_led", onBackLeftLedCommand);
ros::Subscriber<std_msgs::UInt32> backRightLedCommand("back_right_led", onBackRightLedCommand);*/
ros::Subscriber<std_msgs::UInt8> steeringCommand("steering", onSteeringCommand);
ros::Subscriber<std_msgs::Int16> speedCommand("speed", onSpeedCommand);


// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 mpu;
//MPU6050 mpu(0x69); // <-- use for AD0 high

/* =========================================================================
   NOTE: In addition to connection 3.3v, GND, SDA, and SCL, this sketch
   depends on the MPU-6050's INT pin being connected to the Arduino's
   external interrupt #0 pin. On the Arduino Uno and Mega 2560, this is
   digital I/O pin 2.
 * ========================================================================= */

/* =========================================================================
   NOTE: Arduino v1.0.1 with the Leonardo board generates a compile error
   when using Serial.write(buf, len). The Teapot output uses this method.
   The solution requires a modification to the Arduino USBAPI.h file, which
   is fortunately simple, but annoying. This will be fixed in the next IDE
   release. For more info, see these links:
   http://arduino.cc/forum/index.php/topic,109987.0.html
   http://code.google.com/p/arduino/issues/detail?id=958
 * ========================================================================= */



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

const byte EncoderPin = 3;
int direction_motor = 1;


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

/*--------------------------------------------------------------------------------------------------
INTIALIZING TIMER
---------------------------------------------------------------------------------------------------*/
//void InitTimer1(void)
//{
//   TCNT1=0;                         //SETTING INTIAL TIMER VALUE
//   TCCR1B|=(1<<ICES1);              //SETTING FIRST CAPTURE ON RISING EDGE ,(TCCR1B = TCCR1B | (1<<ICES1)
//   TIMSK1|=(1<<ICIE1)|(1<<TOIE1);   //ENABLING INPUT CAPTURE AND OVERFLOW INTERRUPTS
//}
/*--------------------------------------------------------------------------------------------------
STARTING TIMER
---------------------------------------------------------------------------------------------------*/
//void StartTimer1(void)
//{
////   ///setiing timer 1 as fast pwm : 0x01    1     31372.55hz STARTING TIMER WITH PRESCALER 1
//   TCCR1B = (TCCR1B & 0b11111000) | 0x01;// 16MHz/256/2=31250Hz
//   sei();                          //ENABLING GLOBAL INTERRUPTS 65536
//}
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
    deltatime = T1Ovs2 * 25 + T1Ovs2 * 5 / 10 + TCNT2 / 10;// prevent overflow of integer number!
    T1Ovs2 = 0;         //SAVING FIRST OVERFLOW COUNTER
    TCNT2 = 0;

    encoder_counter++;
}
// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void onFrontLeftLedCommand(const std_msgs::UInt32 &cmd_msg) {
    pixels.setPixelColor(0, cmd_msg.data);
    pixels.setPixelColor(1, cmd_msg.data);
    pixels.show();
}

void onFrontRightLedCommand(const std_msgs::UInt32 &cmd_msg) {
    pixels.setPixelColor(2, cmd_msg.data);
    pixels.setPixelColor(3, cmd_msg.data);
    pixels.show();
}

void onBackLeftLedCommand(const std_msgs::UInt32 &cmd_msg) {
    pixels.setPixelColor(6, cmd_msg.data);
    pixels.setPixelColor(7, cmd_msg.data);
    pixels.show();
}

void onBackRightLedCommand(const std_msgs::UInt32 &cmd_msg) {
    pixels.setPixelColor(4, cmd_msg.data);
    pixels.setPixelColor(5, cmd_msg.data);
    pixels.show();
}



void onSteeringCommand(const std_msgs::UInt8 &cmd_msg) {
    if ((cmd_msg.data <= 180) && (cmd_msg.data >= 0)) {
        servo_pw =
            map(cmd_msg.data, 0, 180, 900, 1900);     // scale it to use it with the servo (value between 0 and 180)
        //if (last_pw!=servo_pw)
        myservo.writeMicroseconds(servo_pw);
        last_pw = servo_pw;
    }
}

void onSpeedCommand(const std_msgs::Int16 &cmd_msg) {
    int motor_val = cmd_msg.data / 4;
    if (motor_val < 0) {
        digitalWrite(dirPin, LOW);
        motor_val = motor_val * -1;
        direction_motor = 1;

    } else {
        digitalWrite(dirPin, HIGH);
        direction_motor = -1;
    }
    OCR2A = motor_val;
}

void setup() {
    nh.getHardware()->setBaud(1000000);
    nh.initNode();
    nh.advertise(pubTwist);
    nh.advertise(pub_yaw);
    nh.advertise(pubRevolutions);
    nh.advertise(pubRoll);
    nh.advertise(pubPitch);

    /*nh.subscribe(frontLeftLedCommand);
    nh.subscribe(frontRightLedCommand);
    nh.subscribe(backLeftLedCommand);
    nh.subscribe(backRightLedCommand);*/

    nh.subscribe(steeringCommand);
    nh.subscribe(speedCommand);

    // join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3v or Ardunio
    // Pro Mini running at 3.3v, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

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

    pinMode(EncoderPin, INPUT);
    pinMode(dirPin, OUTPUT);
    digitalWrite(EncoderPin, HIGH);             //pull up
    // pinMode(13, OUTPUT);
//     InitTimer1();                        //CALLING FUNCTION INITTIMER1 TO INITIALIZE TIMER 1
//     StartTimer1();                       //CALLING FUNCTION STARTTIMER1 TO START TIMER 1
    StartTimer2();
    // attaches the servo on pin 9 to the servo object
    myservo.attach(servo_pin);
    pinMode(EncoderPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(EncoderPin), encoder, RISING);
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

        revolution_msg.data = encoder_counter / 6.0;
        pubRevolutions.publish(&revolution_msg);

        // we did receive data from the motor
        if (last_encoder_counter != encoder_counter) {
            if (deltatime != 0) {
                twist_msg.linear.y = (float) deltatime;
                //rad/second -> each tick is 0.005 ms: Arduino timer is 2Mhz , but counter divided by 10 in arduino! 6 lines per revolution!
                twist_msg.linear.x = (3.14 / 3.0) / (deltatime * 0.005 * 0.001);
            }

            twist_msg.linear.x = twist_msg.linear.x * direction_motor;
            //twist_msg.linear.y = 0.0;
            twist_msg.linear.z = 0.0;
            pubTwist.publish(&twist_msg);
        } else {
            // we did receive nothing so check if the motor has stopped
            if (T1Ovs2 * 25 + T1Ovs2 * 5 / 10 + TCNT2 / 10 > MAX_DELTATIME) {
                twist_msg.linear.x = 0.0;
                twist_msg.linear.y = 0.0;
                twist_msg.linear.z = 0.0;
                pubTwist.publish(&twist_msg);

                deltatime = 0;
            }
        }
    }

    nh.spinOnce();
}


/* Control lights */
/*L20C32+16+8+4+2+1, 32+16/16=2+1 -> R , 8+4/4=2+1 -> G, 2+1 -> B : WHITE=63, RED=48, YELLOW=56,OR 60*/
/*void lightControl(){ 
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //command = strtok_r(inputLight,"L",&command);
//    command = inputLight.charAt(1);
//    val= command - '0';
//    command = inputLight.charAt(2);
//    val=val*10+ (command - '0');
//    int i=val;
//    command = inputLight.charAt(4);
//    val=command - '0';
//    command = inputLight.charAt(5); 
//    val=val*10+ (command - '0');
//    pixels.setPixelColor(i, pixels.Color((val/16)*64,((val%16)/4)*64,(val%4)*64)); // Moderately bright green color.

  if (inputLight=="Lle")
  {
      pixels.setPixelColor(0, pixels.Color(255,80,0)); //yellow
      pixels.setPixelColor(7, pixels.Color(255,80,0)); //yellow
  }  
  else if (inputLight=="Lri")
  {
      pixels.setPixelColor(3, pixels.Color(255,80,0)); //yellow
      pixels.setPixelColor(4, pixels.Color(255,80,0)); //yellow
  }
  else if (inputLight=="Lstop")
  {
    for (int i=4;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(255,0,0)); //red
  }
  else if ((inputLight=="Lpa") || (inputLight=="Lta\r"))
  {
    for (int i=0;i<4;i++)
      pixels.setPixelColor(i, pixels.Color(50,50,50)); //white (darker)

    for (int i=4;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(50,0,0)); //red (darker)

  }
  else if (inputLight=="Lre")
  {
      pixels.setPixelColor(5, pixels.Color(50,50,50)); //white (darker)
  }
  else if (inputLight=="Lfr")
  {
    for (int i=0;i<4;i++)
      pixels.setPixelColor(i, pixels.Color(255,255,255)); //white
  }
  else if (inputLight=="LdiL")
  {
    for (int i=0;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(0,0,0)); //disable
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
/*void serialEvent() {
  while (Serial.available()) 
  {
    //Serial.println("here");
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
     if (inChar == 'S') 
     {
      inputServo="";
      inputLight="";
      inputSpeed="";
      servoComplete = false;
      lightComplete = false;
       //Serial.println("true");
    }
    if (inChar == 'L') 
    {
      servoComplete = true;
       //Serial.println("true");
    }
    else if (inChar == 'M') 
    {
      lightComplete = true;
       //Serial.println("true");
    }
    if (inChar != 'S')
      if (servoComplete==false)
        inputServo += inChar;
      else  if (lightComplete==false)
        inputLight += inChar;
      else if ((inChar != 'M')&&(inChar != '\r'))
        inputSpeed += inChar;

    
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if ((inChar == '\r')&&(servoComplete == true)&&(lightComplete == true))
    {
      stringComplete = true;
    }
  }
}*/


