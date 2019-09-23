# PS2 controller for the robot

Download the PS2X_lib.zip file. Then go to "Sketch > Include Library > Add .ZIP Library..." and include the library.

After successfull import you will be able to open "File > Examples > PS2X_lib > Examples > PS2X_Example". Upload to your arduino, connect the wires and you should recieve the values from your remote.

The example uses the pins 10 to 13.

It does work with Arduino Uno R3, but not with Arduino Leonardo since the USB host is not transferring the serial data back.

![Connection](ps2_arduino_test.jpg)

We change the pins because 10 to 13 is used for the motor shield. New assignment:

| PS2         | PS2 Pin |  old |  new |
|-------------|:-------:|:----:|:----:|
| Data        |    1    |  12  |   9  |
| Command     |    2    |  11  |   8  |
|             |    3    |      |      |
| Ground      |    4    |  GND |  GND |
| Power       |    5    | 3.3V | 3.3V |
| Attention   |    6    |  10  |   7  |
| Clock       |    7    |  13  |   6  |
|             |    8    |      |      |
| Acknowledge |    9    |      |      |

Testfile to check if it works: PS2X_6-7-8-9.ino worked with Arduino Uno and CH340 clone from China.
