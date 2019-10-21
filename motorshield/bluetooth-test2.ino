#include <SoftwareSerial.h> // WORKS! Connect power and TXD from the board to pin 2
// BT software: On send '1' and off send '0'
 
SoftwareSerial BTSerial(2, 3);   // RX | TX
char BTinput = '0';

void setup() {
  Serial.begin(57600);
  BTSerial.begin(9600);  // HC-05 default speed in AT 38400
  delay(2000); // Arduino needs a second to switch interactive mode
  Serial.println("Ready to recieve messages");
  pinMode(13, OUTPUT);
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
}
