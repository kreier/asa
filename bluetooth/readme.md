# Bluetooth module AT-09 CC2541 BLE

This cheap bluetooth module supports regular Bluetooth 4.0 as well as BLE (Bluetooth Low Energy) which has a lot of advantages. We try to use just the BLE part. The problem now is the software on the smartphone and the Laptop.

## Renaming the module

All modules are named "JDY-09-V4.3" and to distinguish them its better to rename them. Easy done:

### Download CoolTermWin

https://freeware.the-meiers.org/ 

Connect the serial bridge Silicon Labs CP210x USB to UART Bridge to the module (3.3V, TXD and RXD, GND) and start the program.

Select "Connect", then "Connection > Send String..." and sent "AT+NAME" with a Newline/Enter. The new name like "makerspace" can easy be set by the command "AT+NAMEmakerspace".
