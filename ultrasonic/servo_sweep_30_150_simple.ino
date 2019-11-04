#include <Servo.h>

Servo myservo;  

int pos = 0;    

void setup() {
  myservo.attach(9);  
}

void loop() {
  myservo.write(90);
  delay(10000);
  for (pos = 30; pos <= 150; pos += 1) { 
    myservo.write(pos);   
    delay(15);      
  }
  for (pos = 150; pos >= 30; pos -= 1) { 
    myservo.write(pos);              
    delay(15);    
  }
}
