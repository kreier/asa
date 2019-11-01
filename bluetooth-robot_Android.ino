// This is for the BLEJoystick app for Android
// Standard settings: A B X Y F B R L S-start C-Select
#include <SoftwareSerial.h> 

int E1 = 10; // enable - with PWM
int M1 = 12;
int E2 = 11;
int M2 = 13;
int spd = 0;
char BTinput = '0';

SoftwareSerial BTSerial(8, 3);   // RX | TX

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  analogWrite(E1, spd);
  analogWrite(E2, spd);
  
  BTSerial.begin(9600);  // HC-05 default speed in AT 38400
}
 
void loop() {
  if (BTSerial.available()) 
  {
    BTinput = BTSerial.read();
    if(BTinput == 'A') { // up - forward
        digitalWrite(M1, HIGH);
        digitalWrite(M2, HIGH);
        if(spd == 0) spd = 200;
    }
    if(BTinput == 'C') { // down - backward
        digitalWrite(M1, LOW);
        digitalWrite(M2, LOW);
        if(spd == 0) spd = 200;
    }
    if(BTinput == 'D') { // left turn
        digitalWrite(M1, HIGH);
        digitalWrite(M2, LOW);
        if(spd == 0) spd = 128;
    }
    if(BTinput == 'B') { // right turn
        digitalWrite(M1, LOW);
        digitalWrite(M2, HIGH);
        if(spd == 0) spd = 128;
    }
    if(BTinput == 'H') spd = 75;  // slow
    if(BTinput == 'E') spd = 100; // medium
    if(BTinput == 'F') spd = 255; // turbo
    if(BTinput == 'G') spd = 0;   // stop
    analogWrite(E1, spd);
    analogWrite(E2, spd);
  }
}
