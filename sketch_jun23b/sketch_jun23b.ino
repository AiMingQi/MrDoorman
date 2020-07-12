/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int potpin1 = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;  // analog pin used to connect the potentiometer
int val1;    // variable to read the value from the analog pin
int val2;    // variable to read the value from the analog pin
int inp; 

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  val1 = 100;
  val2 = 95;
}

void loop() {
  // val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  // val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  // val1 = map(val1, 0, 1023, 75, 125);     // scale it to use it with the servo (value between 0 and 180)
  // val2 = map(val2, 0, 1023, 60, 115);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(75);                  // sets the servo position according to the scaled value
  myservo2.write(100);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(75);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(2000);                           // waits for the servo to get there

  myservo1.write(110);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(75);                  // sets the servo position according to the scaled value
  myservo2.write(110);                  // sets the servo position according to the scaled value
  delay(500);                           // waits for the servo to get there

  myservo1.write(100);                  // sets the servo position according to the scaled value
  myservo2.write(95);                  // sets the servo position according to the scaled value
  delay(900);                           // waits for the servo to get there

  myservo1.write(110);                  // sets the servo position according to the scaled value
  myservo2.write(100);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(80);                  // sets the servo position according to the scaled value
  myservo2.write(90);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(75);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(700);                           // waits for the servo to get there

  myservo1.write(110);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(500);                           // waits for the servo to get there

  myservo1.write(100);                  // sets the servo position according to the scaled value
  myservo2.write(95);                  // sets the servo position according to the scaled value
  delay(3300);                           // waits for the servo to get there

  myservo1.write(95);                  // sets the servo position according to the scaled value
  myservo2.write(70);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(95);                  // sets the servo position according to the scaled value
  myservo2.write(75);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(95);                  // sets the servo position according to the scaled value
  myservo2.write(80);                  // sets the servo position according to the scaled value
  delay(800);                           // waits for the servo to get there

  myservo1.write(110);                  // sets the servo position according to the scaled value
  myservo2.write(65);                  // sets the servo position according to the scaled value
  delay(1000);                           // waits for the servo to get there

  myservo1.write(val1);                  // sets the servo position according to the scaled value
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  delay(4000);                           // waits for the servo to get there
  
  
}
