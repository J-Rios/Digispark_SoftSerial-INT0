#include <SoftSerial_INT0.h>

#define P_RX 2                        // Reception PIN (SoftSerial)
#define P_TX 1                        // Transmition PIN (SoftSerial)

SoftSerial Bluetooth(P_RX, P_TX);           // Software serial port for control the Bluetooth module

void setup()
{
    Bluetooth.begin(9600); // Initialize the serial port
}

void loop()
{
    // Basic Echo Test
    if(Bluetooth.available())
        Bluetooth.write(Bluetooth.read());

    delay(100);
}
