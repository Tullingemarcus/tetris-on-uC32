#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function



void removeRow(int k){
    if((rgbOledBmp[k] == 0xff) && (rgbOledBmp[k + 128] == 0xff) 
        && (rgbOledBmp[k + 256] == 0xff) && (rgbOledBmp[k + 384] == 0xff)){ 
        int j; 
        for(j = k; j < 101; j++){
            rgbOledBmp[j]       = rgbOledBmp[j + 2];  // remove row if full and shift down
            rgbOledBmp[j + 128] = rgbOledBmp[j + 2 + 128];
            rgbOledBmp[j + 256] = rgbOledBmp[j + 2 + 256];
            rgbOledBmp[j + 384] = rgbOledBmp[j + 2 + 384];
                       
        }
        OledUpdate(); 
        PORTE += 1;                     // increment LEDs by 1
    }
    return;
}