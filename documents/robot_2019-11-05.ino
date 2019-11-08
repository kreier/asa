// Most simple setup with just 8 bluetooth keys
// Standard settings: A-up B-right C-down D-left E-fast F-select G-stop H-start autonomous - no extra keys

#include <SoftwareSerial.h> 
#include <NewPing.h>
#include <Servo.h>

#define  TRIGGER_PIN    2
#define  ECHO_PIN       3
#define  BUZZER_PIN     4
#define  BLUETOOTH_RX   8
#define  BLUETOOTH_TX   1
#define  SERVO_PIN      9
#define  E1            10 // enable - with PWM
#define  M1            12
#define  E2            11
#define  M2            13
#define  MAX_DISTANCE 350

int spd = 0;
char BTinput = '0';
int DistanceCm;
int pos = 0;   

SoftwareSerial BTSerial(BLUETOOTH_RX, BLUETOOTH_TX);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;  

void distance() {
   DistanceCm = sonar.ping_cm(); // 10 pings per second  
}

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  analogWrite(E1, spd);
  analogWrite(E2, spd);
  myservo.attach(SERVO_PIN);
  myservo.write(90);

  digitalWrite(BUZZER_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZER_PIN, LOW);
  delay(50);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZER_PIN, LOW);
  delay(50);

  

  
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
    if(BTinput == 'H') {          // square  - A - autonomus with the servo
      for (pos = 30; pos <= 150; pos += 1) { 
        myservo.write(pos);   
        delay(15);      
      }
      for (pos = 150; pos >= 30; pos -= 1) { 
         myservo.write(pos);              
         delay(15);    
      }
      myservo.write(90);
    }
    if(BTinput == 'E') spd = 255; // triange - B - FAST
    if(BTinput == 'F') {          // circle  - Y - SELECT
      // what is my mode? Beep 1 for remote 2 for autonomus and 3 for autonomus with ultrasonic beep
      digitalWrite(BUZZER_PIN, HIGH);  
      delay(50);
      digitalWrite(BUZZER_PIN, LOW);
      delay(50);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(50); 
    }
    if(BTinput == 'G') spd = 0;   // cross   - X - STOP
    analogWrite(E1, spd);
    analogWrite(E2, spd);
    digitalWrite(BUZZER_PIN, HIGH);    
    delay(5);
    digitalWrite(BUZZER_PIN, LOW);
  }
    distance();
}
