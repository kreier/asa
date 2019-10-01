## Description 

These simple programs just activates the two motors and lets them drive forward (increasingly faster, then slower) and backwards.

motorshield_1.ino takes a slow start forward and backward.

motortest-simple-4 has a 1 second cycle of forward/backward/left/right.

Pins for the Motorshield:

int E1 = 10; // enable pin (PWM) for motor 1
int M1 = 12;
int E2 =11;
int M2 = 13;

### Control the motor

Example motor 1. If Pin 10 (E1) is at analog zero, the motor is deactivated. If the value is increased to 255 (maximum with analogWrite(E1, 255);) the motor is going into the direction, determined by pin 12 (M1). Here HIGH means forward, LOW means backward.
