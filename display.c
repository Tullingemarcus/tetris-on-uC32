#include <pic32mx.h>
#include <stdio.h>

/* ------------------------------------------------------------ */
/* Pin definitions for access to OLED control signals on chipKIT Uno32
*/
#define DispVddCtrlOn   (PORTFCLR = 0b01000000)
#define DispVddCtrlOff  (PORTFSET = 0b01000000)

#define DispVbatCtrlOn  (PORTFCLR = 0b0100000)
#define DispVbatCtrlOff (PORTFSET = 0b0100000)

#define DispDataCmdMode (PORTFCLR = 0b010000)
#define DispDataMode    (PORTFSET = 0b010000)

#define DispReset       (PORTGCLR = 0b01000000000)
#define DispNotReset    (PORTGSET = 0b01000000000)

/* ------------------------------------------------------------ */
/* Symbols describing the geometry of the display.
*/
#define cbOledDispMax   512 //max number of bytes in display buffer
#define ccolOledMax     128 //number of display columns
#define crowOledMax     32  //number of display rows
#define cpagOledMax     4   //number of display memory pages

/* ------------------------------------------------------------ */
/* This array is the off-screen frame buffer used for rendering.
** It isn't possible to read back from the OLED display device,
** so display data is rendered into this off-screen buffer and then
** copied to the display.
*/
unsigned char rgbOledBmp[cbOledDispMax];

/* ------------------------------------------------------------ */
/* Description:
** Perform PIC32 device initialization to prepare for use
** of the OLED display.
** This example is hard coded for the chipKIT Uno32 and
** SPI2.
*/
void OledHostInit()
{
    /* Initialize SPI port 2.
    */
    SPI2CON = 0;
    SPI2BRG = 15; //8Mhz, with 80Mhz PB clock
    SPI2STATCLR = 0x40;     // CLR spirov, bit 6
    SPI2CONSET = 0x40;      // SET CKP, bit 6
    SPI2CONSET = 0x20;      // SET MSTEN, bit 5
    SPI2CONSET = 0x8000;    // SET ON, bit 15

    /* Make pins RF4, RF5, and RF6 be outputs.
    */
    TRISFCLR = 0x10; //RF4
    TRISFCLR = 0x20; //RF5
    TRISFCLR = 0x40; //RF6

    /* Make the RG9 pin be an output. On the Basic I/O Shield, this pin
    ** is tied to reset.
    */
    TRISGCLR = 0x200;
}
