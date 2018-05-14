/*
 Controlling a servo position using a serial port command
 by zahra boroujeni
 modified on 30 Nov 2015
*/

#include <Servo.h>
#include <MsTimer2.h>
#include <ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>

Servo myservo;  // create servo object to control a servo
int state =0;

int val=90;
int servo_pw=1500;    // variable to read the value from the analog pin
int last_pw=0;
const char* lastLight;
boolean interrupt_flag=false;
boolean ledState=false;
boolean flashingLedState=false;
boolean startFlashing=false;
boolean servo_initialized = false;

int battery_voltage = 0;

#define servo_pin 10
#define POWER_STATE_D0 8
#define POWER_STATE_D1 9
#define BUTTON_GREEN 4
#define BUTTON_RED 5

#define LED_STATUS_EN 3   //LED_STATUS_EN
#define LED_BRACK 11  //LED_LIGHTS_B0
#define LED_PARK_TAIL 13  //LED_LIGHTS_B1
#define LED_TURN_LEFT A0  //LED_LIGHTS_C0
#define LED_TURN_RIGHT A1  //LED_LIGHTS_C1
#define LED_BACKUP A2  //LED_LIGHTS_C2
#define LED_HEAD A3  //LED_LIGHTS_C3

#define ADC6_BAT_VOLT_LEVEL A6
#define ADC7_BAT_VOLT A7
#define AIN0_BAT_VOLT_LEVEL 9
#define AIN1_BAT_VOLT 10


volatile uint8_t *port_to_pcmask[] = {
    &PCMSK0,
    &PCMSK1,
    &PCMSK2
};

static int PCintMode[24];

typedef void (*voidFuncPtr)(void);

volatile static voidFuncPtr PCintFunc[24] = {
    NULL };

volatile static uint8_t PCintLast[3];

const char LED_TOPIC[]  PROGMEM  = { "led" };
const char STEERING_TOPIC[]  PROGMEM  = { "steering" };
const char SPEED_TOPIC[]  PROGMEM  = { "speed" };
const char YAW_TOPIC[]  PROGMEM  = { "yaw" };
const char ROLL_TOPIC[]  PROGMEM  = { "roll" };
const char PITCH_TOPIC[]  PROGMEM  = { "pitch" };

ros::NodeHandle nh;

std_msgs::Float32 yaw_msg;
std_msgs::Float32 pitch_msg;
std_msgs::Float32 roll_msg;
std_msgs::UInt16 steering_msg;

ros::Publisher pubYaw(FCAST(YAW_TOPIC), &yaw_msg);
ros::Publisher pubRoll(FCAST(ROLL_TOPIC), &roll_msg);
ros::Publisher pubPitch(FCAST(PITCH_TOPIC), &pitch_msg);

void onLedCommand(const std_msgs::String &cmd_msg);
void onSteeringCommand(const std_msgs::UInt8 &cmd_msg);

ros::Subscriber<std_msgs::String> ledCommand(FCAST(LED_TOPIC), onLedCommand);
ros::Subscriber<std_msgs::UInt8> steeringCommand(FCAST(STEERING_TOPIC), onSteeringCommand);


/* ============================================
===============================================
*/

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"

#if __CLION_IDE__
#include "MPU6050/MPU6050_6Axis_MotionApps20.h"
#include "MPU6050/MPU6050.h" // not necessary if using MotionApps include file
#else
#include "MPU6050_6Axis_MotionApps20.h"
#endif

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 mpu;
#define OUTPUT_READABLE_YAWPITCHROLL

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
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector


// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

/////////////////////////////////////////////////////////////////////////////////
/*
 * attach an interrupt to a specific pin using pin change interrupts.
 */
void PCattachInterrupt(uint8_t pin, void (*userFunc)(void), int mode) {
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    uint8_t slot;
    volatile uint8_t *pcmask;

    // map pin to PCIR register
    if (port == NOT_A_PORT) {
        return;
    }
    else {
        port -= 2;
        pcmask = port_to_pcmask[port];
    }

// -- Fix by Baziki. In the original sources it was a little bug, which cause analog ports to work incorrectly.
    if (port == 1) {
        slot = port * 8 + (pin - 14);
    }
    else {
        slot = port * 8 + (pin % 8);
    }
// --Fix end
    PCintMode[slot] = mode;
    PCintFunc[slot] = userFunc;
    // set the mask
    *pcmask |= bit;
    // enable the interrupt
    PCICR |= 0x01 << port;
}

void PCdetachInterrupt(uint8_t pin) {
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *pcmask;

    // map pin to PCIR register
    if (port == NOT_A_PORT) {
        return;
    }
    else {
        port -= 2;
        pcmask = port_to_pcmask[port];
    }

    // disable the mask.
    *pcmask &= ~bit;
    // if that's the last one, disable the interrupt.
    if (*pcmask == 0) {
        PCICR &= ~(0x01 << port);
    }
}

// common code for isr handler. "port" is the PCINT number.
// there isn't really a good way to back-map ports and masks to pins.
static void PCint(uint8_t port) {
    uint8_t bit;
    uint8_t curr;
    uint8_t mask;
    uint8_t pin;

    // get the pin states for the indicated port.
    curr = *portInputRegister(port+2);
    mask = curr ^ PCintLast[port];
    PCintLast[port] = curr;
    // mask is pins that have changed. screen out non pcint pins.
    if ((mask &= *port_to_pcmask[port]) == 0) {
        return;
    }
    // mask is pcint pins that have changed.
    for (uint8_t i=0; i < 8; i++) {
        bit = 0x01 << i;
        if (bit & mask) {
            pin = port * 8 + i;
            // Trigger interrupt if mode is CHANGE, or if mode is RISING and
            // the bit is currently high, or if mode is FALLING and bit is low.
            if ((PCintMode[pin] == CHANGE
                || ((PCintMode[pin] == RISING) && (curr & bit))
                || ((PCintMode[pin] == FALLING) && !(curr & bit)))
                && (PCintFunc[pin] != NULL)) {
                PCintFunc[pin]();
            }
        }
    }
}


SIGNAL(PCINT0_vect) {
    PCint(0);
}
SIGNAL(PCINT1_vect) {
    PCint(1);
}
SIGNAL(PCINT2_vect) {
    PCint(2);
}

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

void lowBattery()
{
    flashingLedState=!flashingLedState;
    digitalWrite(LED_STATUS_EN, flashingLedState);
}

/* Check voltage of the battery */
void checkBattery()
{
    // read the input on A7 at default resolution (10 bits)
    battery_voltage = analogRead(A7);

    if ((battery_voltage<770) && (battery_voltage>100)) //check also if there is a battery availabe! //14.8 volt
    {
        if (startFlashing==false)
        {
            MsTimer2::set(500, lowBattery); // 0.5 s period
            MsTimer2::start();
            startFlashing=true;
        }
        if (battery_voltage<740) //14.5 volt
        {
            nh.logerror("Please charge the Battery!");
            startFlashing==false;
            digitalWrite(LED_STATUS_EN, LOW);
            digitalWrite(POWER_STATE_D0, LOW);
            digitalWrite(POWER_STATE_D1, HIGH);
        }
    }
}
/* Control power board*/
void powerBoard(){
    interrupt_flag=false;
    if (state%2==0)//Yellow
    {
        digitalWrite(POWER_STATE_D0, LOW);
        digitalWrite(POWER_STATE_D1, LOW);

    } else if (state%2==1) //green
    {
        digitalWrite(POWER_STATE_D0, HIGH);
        digitalWrite(POWER_STATE_D1, LOW);
    }
}

void count()
{
    state++;
    interrupt_flag=true;
}

void turnOffCar()
{
    int carShutdown=digitalRead(BUTTON_RED);
    if (carShutdown==0)
    {
        digitalWrite(POWER_STATE_D0, HIGH);
        digitalWrite(POWER_STATE_D1, HIGH);
    }
    //MsTimer2::stop();
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

        if (!servo_initialized) {
            // attaches the servo on pin 9 to the servo object
            myservo.attach(servo_pin);
            servo_initialized = true;
        }

        last_pw = servo_pw;
    }
}

void resetLights()
{
    startFlashing==false;
    MsTimer2::stop(); //stop flashing lights
    digitalWrite(LED_TURN_LEFT, LOW);
    digitalWrite(LED_TURN_RIGHT, LOW);
    digitalWrite(LED_BRACK, LOW);
    digitalWrite(LED_PARK_TAIL, LOW);
    digitalWrite(LED_BACKUP, LOW);
    digitalWrite(LED_HEAD, LOW);
}
void flashLeftLight()
{
    ledState=!ledState;
    digitalWrite(LED_TURN_LEFT, ledState);
}
void flashRightLight()
{
    ledState=!ledState;
    digitalWrite(LED_TURN_RIGHT, ledState);
}

/* Control lights*/
void onLedCommand(const std_msgs::String &cmd_msg){
    //resetLights();
    if (strcmp_P(cmd_msg.data, PSTR("Lle")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lle")) != 0)
        {
            digitalWrite(LED_TURN_RIGHT, LOW);
            MsTimer2::set(500, flashLeftLight); // 0.5 s period
            MsTimer2::start();
        }
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lri")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lri")) != 0)
        {
            digitalWrite(LED_TURN_LEFT, LOW);
            MsTimer2::set(500, flashRightLight); // 0.5 s period
            MsTimer2::start();
        }
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lstop")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lstop")) != 0)
            digitalWrite(LED_BRACK, HIGH);
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lpa")) == 0 || strcmp_P(cmd_msg.data, PSTR("Lta")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lpa")) != 0)
        {
            if (strcmp_P(lastLight, PSTR("Lta")) != 0)
                digitalWrite(LED_PARK_TAIL, HIGH);
        }
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lre")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lre")) != 0)
            digitalWrite(LED_BACKUP, HIGH);
    }
    else if (strcmp_P(cmd_msg.data, PSTR("Lfr")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("Lfr")) != 0)
            digitalWrite(LED_HEAD, HIGH);
    }
    else if (strcmp_P(cmd_msg.data, PSTR("LdiL")) == 0)
    {
        if (strcmp_P(lastLight, PSTR("LdiL")) != 0)
            resetLights();
    }

    lastLight=cmd_msg.data;

}


void setup() {
    nh.getHardware()->setBaud(500000);
    nh.initNode();
    nh.advertise(pubYaw);
    nh.advertise(pubRoll);
    nh.advertise(pubPitch);

    nh.subscribe(ledCommand);
    nh.subscribe(steeringCommand);

    //servo motor angle : stright forward
    val=90;
    // attaches the servo on pin 9 to the servo object
    myservo.attach(servo_pin);

    // power board control
    pinMode(POWER_STATE_D0, OUTPUT);
    pinMode(POWER_STATE_D1, OUTPUT);
    pinMode(BUTTON_GREEN, INPUT);
    pinMode(BUTTON_RED, INPUT);

    // LED signals
    pinMode(LED_STATUS_EN, OUTPUT);
    pinMode(LED_BRACK, OUTPUT);
    pinMode(LED_PARK_TAIL, OUTPUT);
    pinMode(LED_TURN_LEFT, OUTPUT);
    pinMode(LED_TURN_RIGHT, OUTPUT);
    pinMode(LED_BACKUP, OUTPUT);
    pinMode(LED_HEAD, OUTPUT);
    // Enable Power light
    digitalWrite(LED_STATUS_EN, LOW);
    // power 5 volt
    digitalWrite(POWER_STATE_D0, LOW);
    digitalWrite(POWER_STATE_D1, LOW);

    resetLights();
    lastLight="";
    MsTimer2::stop();

    //check battery
    //analogReadResolution(8);
    delay(1000);
    checkBattery();

    // green button interrupt
    PCattachInterrupt(4, count, FALLING );

    ///////////////////////////////////////////////////////////////////////////

    // join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz). Comment this line if having compilation difficulties with TWBR.
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif


    // initialize device
    nh.loginfo(F("Initializing I2C devices..."));
    mpu.initialize();

    // verify connection
    nh.loginfo(F("Testing device connections..."));
    nh.loginfo(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // load and configure the DMP
    nh.loginfo(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();
    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(105);
    mpu.setYGyroOffset(-24);
    mpu.setZGyroOffset(2);
    mpu.setXAccelOffset(-2187);
    mpu.setYAccelOffset(-1455);
    mpu.setZAccelOffset(1209); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        nh.loginfo(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        nh.loginfo(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
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
        nh.loginfo(F("DMP Initialization failed (code "));
        nh.logerror("" + devStatus);
        nh.loginfo(F(")"));
    }

}

void loop() {
    //control Power board switch between 5 volt and 12 volt for the brushless motor
    if (interrupt_flag==true)
        powerBoard();
    // wait for MPU interrupt or extra packet(s) available
    if (!mpuInterrupt && fifoCount < packetSize) {
        // reset interrupt flag and get INT_STATUS byte
        mpuInterrupt = false;
        mpuIntStatus = mpu.getIntStatus();

        // get current FIFO count
        fifoCount = mpu.getFIFOCount();

        // check for overflow (this should never happen unless our code is too inefficient)
        if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
            // reset so we can continue cleanly
            mpu.resetFIFO();
            nh.loginfo(F("FIFO overflow!"));

            // otherwise, check for DMP data ready interrupt (this should happen frequently)
        } else if (mpuIntStatus & 0x02) {
            // wait for correct available data length, should be a VERY short wait
            if (fifoCount >= packetSize) {
                fifoCount = mpu.getFIFOCount();

                // read a packet from FIFO
                mpu.getFIFOBytes(fifoBuffer, packetSize);

                // track FIFO count here in case there is > 1 packet available
                // (this lets us immediately read more without waiting for an interrupt)
                fifoCount -= packetSize;

#ifdef OUTPUT_READABLE_YAWPITCHROLL
                // display Euler angles in degrees
                mpu.dmpGetQuaternion(&q, fifoBuffer);
                mpu.dmpGetGravity(&gravity, &q);
                mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

                yaw_msg.data = ypr[0];
                pubYaw.publish(&yaw_msg);

                pitch_msg.data = ypr[1];
                pubPitch.publish(&pitch_msg);

                roll_msg.data = ypr[2];
                pubRoll.publish(&roll_msg);
#endif
            }
        }
    }
    checkBattery();
    turnOffCar();
    nh.spinOnce();
}
