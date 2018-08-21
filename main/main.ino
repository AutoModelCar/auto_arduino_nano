// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include <avr/pgmspace.h>
#if __CLION_IDE__
#include "MPU6050/MPU6050_6Axis_MotionApps20.h"
#include "MPU6050/MPU6050.h" // not necessary if using MotionApps include file
#else
#include "MPU6050_6Axis_MotionApps20.h"
#endif
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN 6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 21

#include <Servo.h>
#define MAX_DELTATIME 20000
#define DIR_PIN 4
#define SERVO_PIN 10

#define ENCODER_PIN 3
#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
//#define TEST_COMMUNICATION_LATENCY
#define SERVO_FEEDBACK_MOTOR_PIN 0

//Voltmeter
#define NEWLED_PIN 13
#define BATTERY_PIN A6
#define ENABLE_PIN 7
int ledState = HIGH;                // ledState used to set the LED
unsigned long previousMillis = 0;   // will store last time LED was updated
const float referenceVolts = 4.7; //Default reference on Teensy is 3.3V
const float R1 = 3700.0;
const float R2 = 1490.0;
unsigned int interval = 500;           // interval at which to blink (milliseconds)
float measuredVoltage;
unsigned long enableCounter;

#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

const char LED_TOPIC[]  PROGMEM  = { "led" };
const char STEERING_TOPIC[]  PROGMEM  = { "steering" };
const char SPEED_TOPIC[]  PROGMEM  = { "speed" };
const char YAW_TOPIC[]  PROGMEM  = { "yaw" };
const char ROLL_TOPIC[]  PROGMEM  = { "roll" };
const char PITCH_TOPIC[]  PROGMEM  = { "pitch" };
const char TWIST_TOPIC[]  PROGMEM  = { "twist" };
const char STEERING_ANGLE_TOPIC[]  PROGMEM  = { "steering_angle" };
const char VOLTAGE_TOPIC[]  PROGMEM  = { "voltage" };

ros::NodeHandle nh;

std_msgs::Float32 yaw_msg;
std_msgs::Float32 pitch_msg;
std_msgs::Float32 roll_msg;
std_msgs::UInt16 steering_msg;
geometry_msgs::Twist twist_msg;
std_msgs::Float32 voltage_msg;

ros::Publisher pub_yaw(FCAST(YAW_TOPIC), &yaw_msg);
ros::Publisher pubTwist(FCAST(TWIST_TOPIC), &twist_msg);
ros::Publisher pubRoll(FCAST(ROLL_TOPIC), &roll_msg);
ros::Publisher pubPitch(FCAST(PITCH_TOPIC), &pitch_msg);
ros::Publisher pubSteeringAngle(FCAST(STEERING_ANGLE_TOPIC), &steering_msg);
ros::Publisher pubVoltage(FCAST(VOLTAGE_TOPIC), &voltage_msg);

void onLedCommand(const std_msgs::String &cmd_msg);
void onSteeringCommand(const std_msgs::UInt16 &cmd_msg);
void onSpeedCommand(const std_msgs::Int16 &cmd_msg);

ros::Subscriber<std_msgs::String> ledCommand(FCAST(LED_TOPIC), onLedCommand);
ros::Subscriber<std_msgs::UInt16> steeringCommand(FCAST(STEERING_TOPIC), onSteeringCommand);
ros::Subscriber<std_msgs::Int16> speedCommand(FCAST(SPEED_TOPIC), onSpeedCommand);

MPU6050 mpu;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
Servo myservo; // create servo object to control a servo
int servo_pw = 1500;    // variable to set the angle of servo motor
int last_pw = 0;
bool servo_initialized = false;
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
uint8_t packetSize;    // expected DMP packet size (default is 42 bytes)
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
    cli();
    if (!first_rising) {
        deltatime = T1Ovs2 * 25 + T1Ovs2 * 5 / 10 + TCNT2 / 10;// prevent overflow of integer number!
    }

    T1Ovs2 = 0;         //SAVING FIRST OVERFLOW COUNTER
    TCNT2 = 0;
    first_rising = false;
    encoder_counter++;
    sei();
}


// ================================================================
// ===               SUBSCRIBERS                                ===
// ================================================================
void onSteeringCommand(const std_msgs::UInt16 &cmd_msg) {
    // scale it to use it with the servo (value between 0 and 180)
    if ((cmd_msg.data <= 180) && (cmd_msg.data >= 0))
    {
        // scale it to use it with the servo (value between 0 and 180)
        servo_pw = map(cmd_msg.data, 0, 180, 950, 2050);

        if (last_pw != servo_pw) {
            myservo.writeMicroseconds(servo_pw);
        }

        if (!servo_initialized) {
            // attaches the servo on pin 9 to the servo object
            myservo.attach(SERVO_PIN);
            servo_initialized = true;
        }

        last_pw = servo_pw;
    }
}

void onSpeedCommand(const std_msgs::Int16 &cmd_msg) {
    int16_t motor_val = cmd_msg.data / 4;

    if (abs(motor_val) > 255) {
        return;
    }

    uint8_t servo_val = (uint8_t) abs(motor_val);

    // if speed is set to 0 we keep the old direction
    // and just do nothing but set the val
    // else the speed direction might get inversed
    if (motor_val < 0) {
        digitalWrite(DIR_PIN, HIGH);
        direction_motor = -1;
    } else if (motor_val > 0) {
        digitalWrite(DIR_PIN, LOW);
        direction_motor = 1;
    }

    if (servo_val < 15) {
        servo_val = 15;
    }

    OCR2A = servo_val;
}

#if NUMPIXELS == 8
/* Control lights */
/*L20C32+16+8+4+2+1, 32+16/16=2+1 -> R , 8+4/4=2+1 -> G, 2+1 -> B : WHITE=63, RED=48, YELLOW=56,OR 60*/
void onLedCommand(const std_msgs::String &cmd_msg) {
    if (strcmp_P(cmd_msg.data, PSTR("Lle")) == 0) {
        pixels.setPixelColor(0, pixels.Color(255, 80, 0)); //yellow
        pixels.setPixelColor(7, pixels.Color(255, 80, 0)); //yellow
    } else if (strcmp_P(cmd_msg.data, PSTR("Lri")) == 0) {
        pixels.setPixelColor(3, pixels.Color(255, 80, 0)); //yellow
        pixels.setPixelColor(4, pixels.Color(255, 80, 0)); //yellow
    } else if (strcmp_P(cmd_msg.data, PSTR("Lstop")) == 0) {
        for (uint8_t i = 4; i < 8; i++)
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //red
    } else if (strcmp_P(cmd_msg.data, PSTR("Lpa")) == 0 || strcmp_P(cmd_msg.data, PSTR("Lta")) == 0) {
        for (uint8_t i = 0; i < 4; i++)
            pixels.setPixelColor(i, pixels.Color(50, 50, 50)); //white (darker)

        for (uint8_t i = 4; i < 8; i++)
            pixels.setPixelColor(i, pixels.Color(50, 0, 0)); //red (darker)

    } else if (strcmp_P(cmd_msg.data, PSTR("Lre")) == 0) {
        pixels.setPixelColor(5, pixels.Color(50, 50, 50)); //white (darker)
    } else if (strcmp_P(cmd_msg.data, PSTR("Lfr")) == 0) {
        for (uint8_t i = 0; i < 4; i++)
            pixels.setPixelColor(i, pixels.Color(255, 255, 255)); //white
    } else if (strcmp_P(cmd_msg.data, PSTR("LdiL")) == 0) {
        for (uint8_t i = 0; i < 8; i++)
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //disable
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
}
#endif

#if NUMPIXELS == 21
void onLedCommand(const std_msgs::String &cmd_msg) {
    pixels.setBrightness(16);
    if (strcmp_P(cmd_msg.data, PSTR("left")) == 0) {
        for (uint8_t i = 18; i < 20; i++)
            pixels.setPixelColor(i, pixels.Color(255, 80, 0)); //yellow
    } else if (strcmp_P(cmd_msg.data, PSTR("right")) == 0) {
        for (uint8_t i = 11; i < 13; i++)
            pixels.setPixelColor(i, pixels.Color(255, 80, 0)); //yellow
    } else if (strcmp_P(cmd_msg.data, PSTR("brake")) == 0) {
        for (uint8_t i = 0; i < 3; i++)
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //red

        for (uint8_t i = 8; i < 10; i++)
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //red
    } else if (strcmp_P(cmd_msg.data, PSTR("reverse")) == 0 || strcmp_P(cmd_msg.data, PSTR("Lta")) == 0) {
        for (uint8_t i = 0; i < 3; i++)
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //red

        for (uint8_t i = 8; i < 10; i++)
            pixels.setPixelColor(i, pixels.Color(255, 0, 0)); //red
    } else if (strcmp_P(cmd_msg.data, PSTR("disable")) == 0) {
        for (uint8_t i = 0; i < 21; i++)
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); //disable
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
}
#endif

void displayVoltageGoodLed() {
    pixels.setBrightness(16);
    pixels.setPixelColor(5, 0, 255, 0);
    pixels.setPixelColor(15, 0, 255, 0);
    pixels.setPixelColor(16, 0, 255, 0);
    pixels.show();
}

void displayVoltageWarningLed() {
    pixels.setBrightness(16);
    pixels.setPixelColor(5, 255, 255, 0);
    pixels.setPixelColor(15, 255, 255, 0);
    pixels.setPixelColor(16, 255, 255, 0);
    pixels.show();
}

void displayVoltageBadLed() {
    pixels.setBrightness(16);
    pixels.setPixelColor(5, 255, 0, 0);
    pixels.setPixelColor(15, 255, 0, 0);
    pixels.setPixelColor(16, 255, 0, 0);
    pixels.show();
}

void disableLed() {
    pixels.setPixelColor(5, 0, 0, 0);
    pixels.setPixelColor(15, 0, 0, 0);
    pixels.setPixelColor(16, 0, 0, 0);
    pixels.show();
}

int readEEPROMInt(int addr) {
    byte low, high;
    low=EEPROM.read(addr);
    high=EEPROM.read(addr+1);
    return low + ((high << 8)&0xFF00);
}

void setup() {
    nh.getHardware()->setBaud(500000);
    nh.initNode();
    nh.advertise(pubTwist);
    nh.advertise(pub_yaw);
    nh.advertise(pubRoll);
    nh.advertise(pubPitch);
    nh.advertise(pubSteeringAngle);
    nh.advertise(pubVoltage);

    nh.subscribe(ledCommand);
    nh.subscribe(steeringCommand);
    nh.subscribe(speedCommand);

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
    mpu.setXAccelOffset(readEEPROMInt(0));
    mpu.setYAccelOffset(readEEPROMInt(2));
    mpu.setZAccelOffset(readEEPROMInt(4)); // 1688 factory default for my test chip
    mpu.setXGyroOffset(readEEPROMInt(6));
    mpu.setYGyroOffset(readEEPROMInt(8));
    mpu.setZGyroOffset(readEEPROMInt(10));

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
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), encoder, RISING);
    pixels.begin(); // This initializes the NeoPixel library.
    //Voltmeter
    pinMode(NEWLED_PIN, OUTPUT);
    digitalWrite(ENABLE_PIN, LOW);
}


// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    //while (!mpuInterrupt && fifoCount < packetSize) {}

    if (mpuInterrupt || fifoCount >= packetSize) {

        // reset interrupt flag and get INT_STATUS byte
        mpuInterrupt = false;
        mpuIntStatus = mpu.getIntStatus();

        // get current FIFO count
        fifoCount = mpu.getFIFOCount();

        // check for overflow (this should never happen unless our code is too inefficient)
        if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
            // reset so we can continue cleanly
            mpu.resetFIFO();
            nh.logerror(F("FIFO overflow!"));

            // otherwise, check for DMP data ready interrupt (this should happen frequently)
        } else if (mpuIntStatus & 0x02) {
            // wait for correct available data length, should be a VERY short wait
            uint16_t fifoCount = mpu.getFIFOCount();
            if (fifoCount >= packetSize) {

                // read a packet from FIFO
                mpu.getFIFOBytes(fifoBuffer, packetSize);

                // track FIFO count here in case there is > 1 packet available
                // (this lets us immediately read more without waiting for an interrupt)
                fifoCount -= packetSize;

                // display Euler angles in degrees
                mpu.dmpGetQuaternion(&q, fifoBuffer);
                mpu.dmpGetGravity(&gravity, &q);
                mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

                yaw_msg.data = ypr[0];
                pub_yaw.publish(&yaw_msg);

                pitch_msg.data = ypr[1];
                pubPitch.publish(&pitch_msg);

                roll_msg.data = ypr[2];
                pubRoll.publish(&roll_msg);

                // if the motor has stopped we publish the speed when IMU data is rdy because this runs at 100hz
                if (last_encoder_counter == encoder_counter) {
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
                    // we did receive data from the motor
                else {
                    if (deltatime != 0) {
                        //rad/second -> each tick is 0.005 ms: Arduino timer is 2Mhz , but counter divided by 10 in arduino! 6 lines per revolution!
                        twist_msg.linear.x = (M_PI / 3.0) / (deltatime * 0.005 * 0.001);
                    } else {
                        twist_msg.linear.x = 0.0;
                    }

                    twist_msg.linear.x = twist_msg.linear.x * direction_motor;
                    twist_msg.linear.y = 0.0;
                    twist_msg.linear.z = 0.0;
                    pubTwist.publish(&twist_msg);
                }
                last_encoder_counter = encoder_counter;

                steering_msg.data = analogRead(SERVO_FEEDBACK_MOTOR_PIN);
                pubSteeringAngle.publish(&steering_msg);

                /***Voltmeter**/
                int value = analogRead(BATTERY_PIN);
                int enable_pin_status = LOW;
                float vout = (value * referenceVolts) / 1024.0;
                measuredVoltage = vout / (R2/(R1+R2));
                unsigned long currentMillis = millis();

                //Check voltage, if it is below 13V then the indicator start blinking before turning off
                if (measuredVoltage > 14.0){
                    unsigned long enableCounter_now = millis();
                    unsigned long dt = enableCounter_now - enableCounter;

                    if (dt > 3000){
                        enable_pin_status = HIGH;
                        ledState = HIGH;
                    }
                    else
                        enable_pin_status = LOW;
                }
                else{
                    enableCounter = millis();
                    enable_pin_status = LOW;
                }

                if (measuredVoltage > 14.5) {
                    displayVoltageGoodLed();
                } else if (measuredVoltage <= 14.5 && measuredVoltage >= 13.8)
                {
                    if(currentMillis - previousMillis > interval)
                    {
                        // save the last time you blinked the LED
                        previousMillis = currentMillis;

                        // if the LED is off turn it on and vice-versa:
                        if (ledState == LOW) {
                            ledState = HIGH;
                            displayVoltageWarningLed();
                        }
                        else {
                            ledState = LOW;
                            disableLed();
                        }
                    }
                } else if (measuredVoltage < 13.7) {
                    // save the last time you blinked the LED
                    if(currentMillis - previousMillis > interval) {
                        previousMillis = currentMillis;

                        // if the LED is off turn it on and vice-versa:
                        if (ledState == LOW) {
                            ledState = HIGH;
                            displayVoltageBadLed();
                        } else {
                            ledState = LOW;
                            disableLed();
                        }
                    }
                }

                digitalWrite(ENABLE_PIN, enable_pin_status);
                voltage_msg.data = measuredVoltage;
                pubVoltage.publish(&voltage_msg);
            }
        }
    }

    nh.spinOnce();
}

