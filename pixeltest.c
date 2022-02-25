#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

void pixelmove(){
    for(int i = 1; i < 126; i++){
        rgbOledBmp[i] = 8;
        delay(100);
    }
}