
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

// main function
// this is where the program will start
int main()
{
    PORTE &= 0xf00;
    OledHostInit();
    OledDspInit();
    display_start();
    while(1){
        tetris();
    }
    return 0;
}
