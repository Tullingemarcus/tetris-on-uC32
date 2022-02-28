#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

void removeRow(){
    if(rgbOledBmp[1] == 0xff){  
        rgbOledBmp[1] = rgbOledBmp[4];  // remove row if full and shift down
        rgbOledBmp[2] = rgbOledBmp[5];
        rgbOledBmp[3] = rgbOledBmp[6];
        init();                         // increment LEDs by 1
    }
    return;
}