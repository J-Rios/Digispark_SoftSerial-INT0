/****************************************************************************************************************/
/* BluetoothKeyboard - Control the keyboard across a bluetooth connection                                       */
/****************************************************************************************************************/

#include <SoftSerial_INT0.h>
#include "DigiKeyboard.h"

#define P_RX 2                        // Reception PIN (SoftSerial)
#define P_TX 1                        // Transmition PIN (SoftSerial)
#define BLE_TIMEOUT 10000             // Time for connect with the BLE module
#define KEY_ENTER 40                  // Keyboard usage values (ENTER Key)
#define KEY_ESC 41                    // Keyboard usage values (ESCAPE Key)

SoftSerial BLE(P_RX, P_TX);           // Software serial port for control the BLE module

/****************************************************************************************************************/

void setup()
{
    BLE.begin(9600); // Initialize the serial port
    BLE.print("at+conn00,15,83,00,12,51\r\n"); // Send the AT command to connect with the Slave module
    DigiKeyboard.delay(BLE_TIMEOUT); // Wait the module for connect
}

void loop()
{
    static char cmd; // Get Command variable
    
    if(BLE.available()) // If there is any data incoming from the serial port
    {
        cmd = BLE.read(); // Get command

        // Manage the command received
        if(cmd == 'A')
            DigiKeyboard.println(" Testing text input ");
        else if(cmd == 'B')
            DigiKeyboard.sendKeyStroke(KEY_ENTER);
        else if(cmd == 'C')
            DigiKeyboard.sendKeyStroke(KEY_ESC);
        // ...
    }
    DigiKeyboard.update(); // Update the USB connection (maintain alive the connection)
}

