
// I2C device class (I2Cdev) demonstration Arduino sketch for MPU6050 class using DMP (MotionApps v2.0)
// 6/21/2012 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//      2013-05-08 - added seamless Fastwire support
//                 - added note about gyro calibration
//      2012-06-21 - added note about Arduino 1.0.1 + Leonardo compatibility error
//      2012-06-20 - improved FIFO overflow handling and simplified read process
//      2012-06-19 - completely rearranged DMP initialization code and simplification
//      2012-06-13 - pull gyro and accel data from FIFO packet instead of reading directly
//      2012-06-09 - fix broken FIFO read sequence and change interrupt detection to RISING
//      2012-06-05 - add gravity-compensated initial reference frame acceleration output
//                 - add 3D math helper file to DMP6 example sketch
//                 - add Euler output and Yaw/Pitch/Roll output formats
//      2012-06-04 - remove accel offset clearing for better results (thanks Sungon Lee)
//      2012-06-01 - fixed gyro sensitivity to be 2000 deg/sec instead of 250
//      2012-05-30 - basic DMP initialization working

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"
//#include "MPU6050.h" // not necessary if using MotionApps include file

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

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

// uncomment "OUTPUT_READABLE_YAWPITCHROLL" if you want to see the yaw/
// pitch/roll angles (in degrees) calculated from the quaternions coming
// from the FIFO. Note this also requires gravity vector calculations.
// Also note that yaw/pitch/roll angles suffer from gimbal lock (for
// more info, see: http://en.wikipedia.org/wiki/Gimbal_lock)
#define OUTPUT_READABLE_YAWPITCHROLL

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

#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      21
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
char command;
char NumberColor;
#include <Servo.h>
Servo myservo; // create servo object to control a servo
#define analogPin 1
#define dirPin 4
//#define EncoderPin 8
#define servo_pin 10
int servo_pw=1500;    // variable to set the angle of servo motor
int last_pw=0;
int val;
volatile uint16_t T1Ovs1,T1Ovs2;
volatile uint16_t T2OverFlow;
volatile uint16_t Capt1, Capt2;  //VARIABLES TO HOLD TIMESTAMPS
int16_t Encoder;              //CAPTURE FLAG
int16_t last_Encoder;
volatile uint16_t deltatime=(volatile uint16_t)0;
String inputLight = "";         // a string to hold incoming data
String inputServo = "";         // a string to hold incoming data
String inputSpeed = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
boolean servoComplete=false;
boolean lightComplete=false;
boolean reset_T1Ovs2=false;
const byte EncoderPin = 3;
int direction_motor=1;


#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };



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
void StartTimer2(void)
{
  pinMode(11, OUTPUT); //976.5625Hz 
  TCNT2 =0;
  TIFR2 = 0x00;
  TIMSK2 = TIMSK2 | 0x01;
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  TCCR2B = (TCCR2B & 0b11111000) | 0x02;//62500HZ= 16MHz/1024/2=7812
  sei();  
}

ISR(TIMER2_OVF_vect)
{
     TIFR2 = 0x00;
     T1Ovs2++;//INCREMENTING OVERFLOW COUNTER
}
// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    Serial.begin(115200);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3v or Ardunio
    // Pro Mini running at 3.3v, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
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
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }


     pinMode(EncoderPin,INPUT);
     pinMode(dirPin,OUTPUT);
     digitalWrite(EncoderPin,HIGH);             //pull up
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

void encoder() {  
  deltatime=(T1Ovs2)*25+(T1Ovs2)*5/10+TCNT2/10;// prevent overflow of integer number!
  T1Ovs2=0;         //SAVING FIRST OVERFLOW COUNTER
  TCNT2=0;
  Encoder=Encoder+direction_motor; 
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
//          Serial.print((int)Encoder);
//          Serial.print("\n");
          serialEvent(); //read serial port commands from odroid
          if (stringComplete) 
          {
            lightControl(); // control lights of the car, this function should call befor control motor
            servoControl(); // control servo motor
            speedControl();
            stringComplete = false;
//             Serial.print("string");
          }
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
        Serial.println(F("FIFO overflow!"));

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
            Serial.print("quat\t");
            Serial.print(q.w);
            Serial.print("\t");
            Serial.print(q.x);
            Serial.print("\t");
            Serial.print(q.y);
            Serial.print("\t");
            Serial.println(q.z);
        #endif

        #ifdef OUTPUT_READABLE_EULER
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetEuler(euler, &q);
            Serial.print("euler\t");
            Serial.print(euler[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(euler[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(euler[2] * 180/M_PI);
        #endif

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
//            Serial.print("ypr\t");
//            Serial.println(ypr[0] * 180/M_PI);
//            Serial.print("\t");
//            Serial.print(ypr[1] * 180/M_PI);
//            Serial.print("\t");
//            Serial.println(ypr[2] * 180/M_PI);
        #endif
        
        Serial.print("y");
        Serial.print(ypr[0] * 180/M_PI);
        Serial.print("s");
        Serial.print(deltatime); ///*0.0000000625 second
        Serial.print("e"); 
        Serial.print((int)Encoder);
        Serial.print("\n");

        if (last_Encoder==Encoder)
          deltatime=(volatile uint16_t)0;
        last_Encoder=Encoder;
        

    }
}

/* Control lights*/
void servoControl(){
    if (inputServo=="en")
    {
      myservo.attach(servo_pin);
      //Serial.println("enable");
      //Serial.println(inputString);
    }
    else if (inputServo=="di")
    {
      myservo.detach();
      //Serial.println("detach");
      //Serial.println(inputString);
    }
    else if (inputServo!="")
    {
      //Serial.println(inputServo);
      val=inputServo.toInt();
      if ((val<=180) && (val>=0))
      {
        
        servo_pw = map(val, 0, 180, 900, 1900);     // scale it to use it with the servo (value between 0 and 180)
        //if (last_pw!=servo_pw)
          myservo.writeMicroseconds(servo_pw); 
        last_pw=servo_pw; 
      }
    }
} 
/* Control lights*/
/*L20C32+16+8+4+2+1, 32+16/16=2+1 -> R , 8+4/4=2+1 -> G, 2+1 -> B : WHITE=63, RED=48, YELLOW=56,OR 60*/
void lightControl(){ 
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
    for (int i=0;i<2;i++)
      pixels.setPixelColor(i, pixels.Color(255,80,0)); //yellow
  }  
  else if (inputLight=="Lri")
  {
    for (int i=2;i<4;i++)
      pixels.setPixelColor(i, pixels.Color(255,80,0)); //yellow
  }
  else if (inputLight=="Lstop")
  {
    for (int i=4;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(255,0,0)); //red
  }
  else if ((inputLight=="Lpa") || (inputLight=="Lta\r"))
  {
    for (int i=4;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(255,255,255)); //white
  }
  else if (inputLight=="Lre")
  {
    for (int i=4;i<8;i++)
      pixels.setPixelColor(i, pixels.Color(255,0,0)); //red
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
void speedControl(){ 
  int motor_val=0;
   if (inputSpeed!="")
   {
      motor_val=inputSpeed.toInt();
      motor_val=motor_val/4;
      if (motor_val<0)
      {
        digitalWrite(dirPin, LOW); 
        motor_val=motor_val*-1;
        direction_motor=1;
         
      }
      else
      {
        digitalWrite(dirPin, HIGH);
        direction_motor=-1; 
      }
      OCR2A = motor_val;
   }
}
/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
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
}


