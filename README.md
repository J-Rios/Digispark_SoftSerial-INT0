# Digispark_SoftSerial-INT0

SoftSerial library modified to use INT0 instead PCINT0 interrupt. It allow digispark uses DigiMouse/DigiKeyboard/DigiJoystick at same time SoftSerial. It provides, for example, to use a Bluetooth module to control the mouse or keyboard.

This is another better option than use Digispark_DigiUSB-SoftSerial. With this one, you don't have to modify the digistump library, just include this new library.

-------------------------------------------------------------------------------------------------------------------------

How to install:
  - Copy the DigisparkSoftSerial_INT0 folder inside Arduino library folders. Depends of the Arduino versions it can be found in any of the following paths:
    C:/.../Arduino-X.X.X/hardware/digistump/libraries
    C:/.../AppData/Local/Arduino15/packages/digistump/hardware/avr/1.6.5/libraries
    C:/.../AppData/Roaming/Arduino15/packages/digistump/hardware/avr/1.6.5/libraries
    ...

How to use (Wich pins are available for the library):
  - Must use P2 (INT0) pin for Rx UART.
  - Should use P1 pin for Tx UART (better results than P0).
  - Cant use P4 if it is used for USB (USB-).
  - Cant use P3 or P5 pins (not PWM pins).

-------------------------------------------------------------------------------------------------------------------------

You can find some examples inside the library.

Enjoy It.
