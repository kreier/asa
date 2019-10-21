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

### Assigned pins from the motorshield

| pin | general UNO | general Leonardo | used for | pin | general UNO | general Leonardo | used for |
|:---:|:-----------:|:----------------:|:--------:|:---:|:-----------:|------------------|:--------:|
| 0   |      RX     |        RX        |          |  A0 |             |                  |          |
| 1   |      TX     |        TX        |          |  A1 |             |                  |          |
| 2   |             |        SDA       |          |  A2 |             |                  |          |
| 3~  |             |        SCL       |          |  A3 |             |                  |          |
| 4   |             |        A6        |          |  A4 |     SDA     |                  |          |
| 5~  |             |                  |          |  A5 |     SCL     |                  |          |
| 6~  |             |        A7        |          |     |             |                  |          |
| 7   |             |                  |          |     |             |                  |          |
| 8   |             |        A8        |          |     |             |                  |          |
| 9~  |             |        A9        |          |     |             |                  |          |
| 10~ |             |        A10       |    E1    |     |             |                  |          |
| 11~ |             |                  |    E2    |     |             |                  |          |
| 12  |             |        A11       |    M1    |     |             |                  |          |
| 13  |     LED     |       ~ too      |    M2    |     |             |                  |          |

Here ~ refers to a PWM [Pulse Wide Modulation](https://en.wikipedia.org/wiki/Pulse-width_modulation) Pin with 480 Hz and 8bit resolution.

### SoftwareSerial and Arduino Leonardo

On my Arduino Uno I could use pin 2 for SoftwareSerial, but since it is interrupt-based I have to use pin 8 for the Leonardo. Finally got it working. 2019-10-21
