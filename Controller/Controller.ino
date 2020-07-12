//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#define joyRX A0
#define joyRY A1

#define joyLX A2
#define joyLY A3

char strX[16];
char strY[16];

const int buttonPin = 2; 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("StartUp:");
  delay(1000);
  Serial.println("Controller Initialized");
 
   // initialize the pushbutton pin as an input:
   pinMode(buttonPin, INPUT_PULLUP); 
  
  lcd.setCursor(2,1);
  lcd.print("Initialized");
  delay(3000);
}

void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

     // put your main code here, to run repeatedly:
    int RxValue = analogRead(joyRX);
    int RyValue = analogRead(joyRY);
    int LxValue = analogRead(joyLX);
    int LyValue = analogRead(joyLY);

    Serial.write(RxValue);
    delay(15);
    
    Serial.write(RyValue);
     delay(15);
   
    Serial.write(LxValue);
     delay(15);
     
    Serial.write(LyValue);  
    
    delay(1000);
}
