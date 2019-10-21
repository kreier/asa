#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(2, 3);   // RX | TX
char BTinput = '0';

void setup() {
  Serial.begin(57600);
  BTSerial.begin(9600);  // HC-05 default speed in AT 38400
  delay(2000); // Arduino needs a second to switch interactive mode
  Serial.println("Ready to recieve messages");
}
 
void loop() {
  if (BTSerial.available()) 
  {
    BTinput = BTSerial.read();
    Serial.print("I go: ");
    Serial.println(BTinput);
    BTSerial.write("Thanks");
  }
}
