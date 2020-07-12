#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int potpin1 = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer

int redpin = 13; //select the pin for the red LED
int greenpin = 11;// select the pin for the green LED
int bluepin = 3; // select the pin for the  blue LED

int ledval;

int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin

int inp; 

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
   myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
   val1 = 100;
   val2 = 95;
}

void loop() {
 
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print(" in, ");
   // Serial.print(cm);
   // Serial.print("cm");
   // Serial.println();
   // delay(100);




  if (inches < 50){
     analogWrite(bluepin, 0);
  analogWrite(redpin, 255);  
  myservo1.write(100);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(2000);                           // waits for the servo to get there


  
  myservo1.write(75);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(110);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(2000);                           // waits for the servo to get there

  myservo1.write(115);                  // sets the servo position according to the scaled value
  myservo2.write(95);                  // sets the servo position according to the scaled value
  delay(500);                           // waits for the servo to get there
  
  analogWrite(greenpin, 255);
  analogWrite(redpin, 0);
  
  myservo1.write(100);                  // sets the servo position according to the scaled value
  myservo2.write(75);                  // sets the servo position according to the scaled value
  delay(300);   
  
  myservo1.write(95);                  // sets the servo position according to the scaled value
  myservo2.write(75);                  // sets the servo position according to the scaled value
  delay(1800);                         // waits for the servo to get there
  
  analogWrite(bluepin, 255);
  analogWrite(greenpin, 0);
  
  myservo1.write(val1);                  // sets the servo position according to the scaled value
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  delay(4000);                           // waits for the servo to get there
  
  analogWrite(redpin, 0); 
  }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
