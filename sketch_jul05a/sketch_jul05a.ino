//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


#define joyRX A0
#define joyRY A1

#define joyLX A2
#define joyLY A3

char strX[16];
char strY[16];



void setup() {
  Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("StartUp:");
  delay(1000);
  Serial.println("8 channel Servo test!");
   pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);

pwm.setPWM(0, 0, 225);
pwm.setPWM(1, 0, 450);
pwm.setPWM(2, 0, 450);
pwm.setPWM(3, 0, 300);

pwm.setPWM(4, 0, 225);
pwm.setPWM(5, 0, 450);
pwm.setPWM(6, 0, 450);
pwm.setPWM(7, 0, 300);
  
  lcd.setCursor(2,1);
  lcd.print("Initialized");
  delay(3000);
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}
 
void loop() {
  // put your main code here, to run repeatedly:
int RxValue = analogRead(joyRX);
int RyValue = analogRead(joyRY);
int LxValue = analogRead(joyLX);
int LyValue = analogRead(joyLY);

//Smooth Arm

int servo0_val=map(RxValue, 0, 1023, 100, 500);
pwm.setPWM(0, 0, servo0_val);

int servo1_val=map(RyValue, 0, 1023, 100, 500);
pwm.setPWM(1, 0, servo1_val);

int servo2_val=map(LyValue, 0, 1023, 100, 450);
pwm.setPWM(2, 0, servo2_val);

int servo3_val=map(LxValue, 0, 1023, 150, 500);
pwm.setPWM(3, 0, servo3_val);

//Bumpy Arm

int servo4_val=map(RxValue, 0, 1023, 100, 500);
pwm.setPWM(4, 0, servo4_val);

int servo5_val=map(RyValue, 0, 1023, 100, 500);
pwm.setPWM(5, 0, servo5_val);

int servo6_val=map(LyValue, 0, 1023, 100, 450);
pwm.setPWM(6, 0, servo6_val);

int servo7_val=map(LxValue, 0, 1023, 150, 500);
pwm.setPWM(7, 0, servo7_val);


sprintf(strX,"0:%04d 1:%04d", servo0_val, servo1_val); // use sprintf() to compose the string str
lcd.setCursor(0,0);
lcd.print(strX);

sprintf(strY,"2:%04d 3:%04d", servo2_val, servo3_val); // use sprintf() to compose the string str
lcd.setCursor(0,1);
lcd.print(strY);



}
