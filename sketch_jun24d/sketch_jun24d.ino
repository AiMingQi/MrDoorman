/* RGB module project code
 */
int redpin = 11; //select the pin for the red LED

int greenpin =12;// select the pin for the green LED
int bluepin =13; // select the pin for the  blue LED

int ledval;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{

 for(ledval=255; ledval>0; ledval--)
  {
   // analogWrite(bluepin, ledval);
   // analogWrite(greenpin, 255-ledval);
   analogWrite(redpin, 128-ledval);
   delay(5); 
  }
  
for(ledval=0; ledval<255; ledval++)
  {
   // analogWrite(bluepin, ledval);
   // analogWrite(greenpin, 255-ledval);
   analogWrite(redpin, 128-ledval);
   delay(5); 
  }
  delay(1000);
 Serial.println(ledval, DEC);
}
