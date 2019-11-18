#define PIN_BUZZER 4

void setup() 
{ 
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
 for (int i=40; i<255; i++)
 {
  digitalWrite(PIN_BUZZER,HIGH); // apply 5V to pin 4
  delay(100);
  digitalWrite(PIN_BUZZER,LOW); // apply 0V to pin 4
  delay(200);
 }
 delay(3000);
}
