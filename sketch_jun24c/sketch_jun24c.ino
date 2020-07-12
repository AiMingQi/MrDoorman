int redpin = 12; // select the pin for the red LED
int bluepin =13; // select the pin for the blueLED
int val;
void setup() {
pinMode(redpin, OUTPUT);
pinMode(bluepin, OUTPUT);
Serial.begin(9600);
}
void loop()
{
for(val=255; val>0; val--)
{
analogWrite(13, val);
analogWrite(12, 255-val);
delay(15);
}
for(val=0; val<255; val++)
{
analogWrite(13, val);
analogWrite(12, 255-val);
delay(15);
}
Serial.println(val, DEC);
}
