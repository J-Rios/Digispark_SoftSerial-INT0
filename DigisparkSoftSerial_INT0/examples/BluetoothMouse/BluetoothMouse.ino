/****************************************************************************************************************/
/* BluetoothMouse - Control the mouse cursor across a bluetooth connection                                      */
/****************************************************************************************************************/

#include <SoftSerial_INT0.h>
#include <DigiMouse.h>

#define P_RX 2                        // Reception PIN (SoftSerial)
#define P_TX 1                        // Transmition PIN (SoftSerial)
#define UMOVE 'A'                     // Up move command
#define DMOVE 'B'                     // Down move command
#define LMOVE 'C'                     // Left move command
#define RMOVE 'D'                     // Right move command
#define CLICK 'E'                     // Click command
#define MOUSE_VELOCITY 1              // Step (pixels) for increase the velocity of the mouse
#define MAX_MOUSE_VELOCITY 10         // Maximum mouse velocity

SoftSerial BLE(P_RX, P_TX);           // Software serial port for control the BLE module

int mx, my;                           // Mouse move x, y
int c_mx, c_my;                       // How much to move
bool mc;                              // Mouse click

/****************************************************************************************************************/

void setup()
{
    mx = 0;    my = 0; // Set to zero the mouse actions
    c_mx = 0;  c_my = 0; // Set to zero the mouse move
    mc = false;
    BLE.begin(9600); // Initialize the serial port
    DigiMouse.begin(); // Initialize the mouse
}

void loop()
{
    static char x, y, c; // Comands variables

    if(BLE.available() >= 3) // If there is 3 data incoming from the serial port
    {
        x = BLE.read(); // Read x command
        y = BLE.read(); // Read y command
        c = BLE.read(); // Read z command

        mouse_action(x, y, c); // Determine the actions to do from the mouse (mx, my & mc)
    }

    // Mouse actions
    if(mc == true)
    {
        left_click(); // Click the mouse
        mc = false;
    }
    DigiMouse.move(mx, my, mc); // Move the mouse
    
    DigiMouse.update(); // Update the USB connection (maintain alive the connection)
}

void mouse_action(char mMoveX, char mMoveY, char mClick)
{
    // X
    if(mMoveX == RMOVE) // X move right command
    {
        if(c_mx < MAX_MOUSE_VELOCITY)
            c_mx = c_mx + MOUSE_VELOCITY; // Increase the x right move velocity
    }
    else if(mMoveX == LMOVE) // X move x left command
    {
        if(c_mx > -MAX_MOUSE_VELOCITY)
            c_mx = c_mx - MOUSE_VELOCITY; // Increase the x left move velocity
    }
    else
        c_mx = 0; // Stop the x move

    // Y
    if(mMoveY == DMOVE) // Y move right command
    {
        if(c_my < MAX_MOUSE_VELOCITY)
            c_my = c_my + MOUSE_VELOCITY; // Increase the y down move velocity
    }
    else if(mMoveY == UMOVE)
    {
        if(c_my > -MAX_MOUSE_VELOCITY)
            c_my = c_my - MOUSE_VELOCITY; // Increase the y up move velocity
    }
    else
        c_my = 0; // Stop the y move

    // Click
    if(mClick == CLICK) // Click command
        mc = true;
    else
        mc = false;
}

void left_click()
{
    DigiMouse.setButtons(1<<0); // Click
    DigiMouse.delay(10);
    DigiMouse.setButtons(0); // Unclick
}
