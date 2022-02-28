#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

void removeRow(){
    int i;
    if((rgbOledBmp[1] == 0xff) && (rgbOledBmp[1 + 128] == 0xff) 
        && (rgbOledBmp[1 + 256] == 0xff) && (rgbOledBmp[1 + 384] == 0xff)){ 

        for(i = 1; i < 106; i++){
            rgbOledBmp[i]       = rgbOledBmp[i + 3];  // remove row if full and shift down
            rgbOledBmp[i + 128] = rgbOledBmp[i + 3 + 128];
            rgbOledBmp[i + 256] = rgbOledBmp[i + 3 + 256];
            rgbOledBmp[i + 384] = rgbOledBmp[i + 3 + 384];
            /*
            rgbOledBmp[2]       = rgbOledBmp[5]; 
            rgbOledBmp[2 + 128] = rgbOledBmp[5 + 128]; 
            rgbOledBmp[2 + 256] = rgbOledBmp[5 + 256]; 
            rgbOledBmp[2 + 384] = rgbOledBmp[5 + 384];  

            rgbOledBmp[3]       = rgbOledBmp[6]; 
            rgbOledBmp[3 + 128] = rgbOledBmp[6 + 128]; 
            rgbOledBmp[3 + 256] = rgbOledBmp[6 + 256]; 
            rgbOledBmp[3 + 384] = rgbOledBmp[6 + 384]; 

            rgbOledBmp[4]       = rgbOledBmp[7]; 
            rgbOledBmp[4 + 128] = rgbOledBmp[7 + 128]; 
            rgbOledBmp[4 + 256] = rgbOledBmp[7 + 256]; 
            rgbOledBmp[4 + 384] = rgbOledBmp[7 + 384];  
            */
            
        }
        PORTE += 1;                     // increment LEDs by 1
    }
    return;
}