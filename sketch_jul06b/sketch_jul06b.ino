
const int buttonPin = 2; 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
   // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    //
    Serial.print(buttonState);
    Serial.println(); 
  } else {
    // 
    Serial.print(buttonState);
    Serial.println(); 
  }

  delay(2000);
Serial.println(); 



}
