#include <pic32mx.h>
#include <stdio.h>
#include "tetris.h"

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
    SPI2BRG = 15;           //8Mhz, with 80Mhz PB clock
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

/* ------------------------------------------------------------ */
/* Description:
** Write/Read a byte on SPI port 2
*/
unsigned char Spi2PutByte(unsigned char bVal)
{
    unsigned char bRx;
    /* Wait for transmitter to be ready
    */
    while (!(SPI2STAT & 0x08)); // Check if bit 3 is 0.
    /* Write the next transmit byte.
    */
    SPI2BUF = bVal;
    /* Wait for receive byte.
    */
    while (!(SPI2STAT & 0x1));
    /* Put the received byte in the buffer.
    */
    bRx = SPI2BUF;
    return bRx;
}

/* ------------------------------------------------------------ */
/* Description:
** Initialize the OLED display controller and turn the display on.
*/
void OledDspInit()
{
    /* We're going to be sending commands, so clear the Data/Cmd bit
    */
    DispDataCmdMode;
    /* Start by turning VDD on and wait a while for the power to come up.
    */
    DispVddCtrlOn;
    delay(1);                                                             // change this argument
    
    /* Display off command
    */
    Spi2PutByte(0xAE);

    /* Bring Reset low and then high
    */
    DispReset;
    delay(1);
    DispNotReset;

    /* Send the Set Charge Pump and Set Pre-Charge Period commands
    */
    Spi2PutByte(0x8D);
    Spi2PutByte(0x14);
    Spi2PutByte(0xD9);
    Spi2PutByte(0xF1);
    /* Turn on VCC and wait 100ms
    */
    DispVbatCtrlOn;
    delay(100);

    /* Send the commands to invert the display. This puts the display origin
    ** in the upper left corner.
    */
    Spi2PutByte(0xA1);      //remap columns
    Spi2PutByte(0xC8);      //remap the rows

    /* Send the commands to select sequential COM configuration. This makes the
    ** display memory non-interleaved.
    */
    Spi2PutByte(0xDA);      //set COM configuration command
    Spi2PutByte(0x20);      //sequential COM, left/right remap enabled
    
    /* Send Display On command
    */
    Spi2PutByte(0xAF);
}

/* ------------------------------------------------------------ */
/* Description:
** Update the OLED display with the contents of the memory buffer
*/
void OledUpdate()
{
    int ipag;
    int icol;
    unsigned char *pb;
    pb = rgbOledBmp;
    for (ipag = 0; ipag < cpagOledMax; ipag++) {
        DispDataCmdMode;
        /* Set the page address
        */
        Spi2PutByte(0x22); //Set page command
        Spi2PutByte(ipag); //page number
        /* Start at the left column
        */
        Spi2PutByte(0x00); //set low nibble of column
        Spi2PutByte(0x10); //set high nibble of column
        DispDataMode;
        /* Copy this memory page of display data.
        */
        OledPutBuffer(ccolOledMax, pb);
        pb += ccolOledMax;
    }
}

/* ------------------------------------------------------------ */
/* Description:
** Send the bytes specified in rgbTx to the slave.
*/
void OledPutBuffer(int cb, unsigned char *rgbTx)
{
    int ib;
    unsigned char bTmp;
    /* Write/Read the data
    */
    for (ib = 0; ib < cb; ib++) {
        /* Wait for transmitter to be ready
        */
        while (!(SPI2STAT & 0x08)); // Check if bit 3 is 0.
        /* Write the next transmit byte.
        */
        SPI2BUF = *rgbTx++;
        /* Wait for receive byte.
        */
        while (!(SPI2STAT & 0x1));
        bTmp = SPI2BUF;
    }
}

// function to fill array with desired value
void display_start()
{
    rgbOledBmp[0] = 0xff;
    
    int i = 1;
	while(i <= 126)
	{
		rgbOledBmp[i] = 1; 
        i++;
	}
    rgbOledBmp[116] = 0xff;
    int k;
    for(k = 127; k <= 384; k += 128){
        rgbOledBmp[k] = 0xff;
        rgbOledBmp[k + 1] = 0xff;
    }
    for(k = 129; k <= 254; k++){
        rgbOledBmp[k] = 0x0;
        rgbOledBmp[k + 128] = 0x0;
    }
    rgbOledBmp[116 + 128] = 0xff;
    rgbOledBmp[116 + 256] = 0xff;
    int j = 385;
    while(j <= 510)
	{
		rgbOledBmp[j] = 128; 
        j++;
	}
    rgbOledBmp[116 + 384] = 0xff;
    rgbOledBmp[511] = 0xff;
    return;
}