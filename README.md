# Digispark_SoftSerial-INT0

SoftSerial library modified to use INT0 instead PCINT0 interrupt.

It allows digispark to use DigiMouse/DigiKeyboard/DigiJoystick and SoftSerial at same time. For example, you can setup this library to use a Bluetooth/WiFi module to control a mouse or keyboard.

This is a better option than the previous [Digispark_DigiUSB-SoftSerial](https://github.com/J-Rios/Digispark_DigiUSB-SoftSerial) approach. With this one, you don't have to modify the digistump library, just include it as a new library.

## How to install

Copy the DigisparkSoftSerial_INT0 folder inside Arduino library folders.  
Depending the Arduino versions, it can be found in any of the following paths:

```text
C:/.../Arduino-X.X.X/hardware/digistump/libraries
C:/.../AppData/Local/Arduino15/packages/digistump/hardware/avr/"X.X.X/libraries
C:/.../AppData/Roaming/Arduino15/packages/digistump/hardware/avr/X.X.X/libraries
```

## How to use (Wich pins are available)

- **Must** use P2 (INT0) pin for Rx UART.
- Should use P1 pin for Tx UART (better results than P0).
- Can't use P3 neither P4 for Tx UART, because them are used for USB (USB+ and USB-).
- Can't use P5 pin, due it could be reset enabled.

---

You can find some examples inside the library.

Enjoy It.
