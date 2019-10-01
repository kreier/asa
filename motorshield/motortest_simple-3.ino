int E1 = 10; // enable - with PWM
int M1 = 12;
int E2 = 11;
int M2 = 13;

void setup() {
  pinMode(M1, OUTPUT); // no need for analog output
  pinMode(M2, OUTPUT);
  // enable
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  delay(1000);
}

void loop() {
  // forward
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  delay(1000);
  // backward
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  delay(1000);
}
