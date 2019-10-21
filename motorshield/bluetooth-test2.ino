#include <SoftwareSerial.h> // WORKS! Connect power and TXD from the board to pin 8
// BT software: On send '1' and off send '0' 
// issue is with interrupt on Leonardo not working on pin 2, but 8 - see documentation with SoftwareSerial
 
SoftwareSerial BTSerial(8, 3);   // RX | TX
char BTinput = '0';
boolean pin2 = LOW;

void setup() {
  Serial.begin(57600);
  BTSerial.begin(9600);  // HC-05 default speed in AT 38400
  delay(2000); // Arduino needs a second to switch interactive mode
  Serial.println("Ready to recieve messages");
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}
 
void loop() {
  if (BTSerial.available()) 
  {
    BTinput = BTSerial.read();
    if(BTinput == '1') digitalWrite(13, HIGH);
    if(BTinput == '0') digitalWrite(13, LOW);
    Serial.print("I got: ");
    Serial.println(BTinput);
  }
  //pin2 =  digitalRead(2);
  //if( pin2 == LOW ) Serial.println("***************");
  //Serial.print(pin2);
}
