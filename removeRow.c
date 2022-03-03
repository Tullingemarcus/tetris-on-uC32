#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

/* When function is called, checks if there are any filled rows on the display.
*  If filled, remove that row and shift all pixels above it down to fill the gap.
*/
void removeRow(int k){
    // Check if row is full
    if((rgbOledBmp[k] == 0xff) && (rgbOledBmp[k + 128] == 0xff) 
        && (rgbOledBmp[k + 256] == 0xff) && (rgbOledBmp[k + 384] == 0xff)){ 
        // Shift everything down
        int j; 
        for(j = k; j < 101; j++){
            rgbOledBmp[j]       = rgbOledBmp[j + 2];  
            rgbOledBmp[j + 128] = rgbOledBmp[j + 2 + 128];
            rgbOledBmp[j + 256] = rgbOledBmp[j + 2 + 256];
            rgbOledBmp[j + 384] = rgbOledBmp[j + 2 + 384];     
        }
        // Increase score
        score();
        OledUpdate(); 
        // Increase speed of game
        if(delayVar >= 10){
            delayVar -= 1;
        }
    }
    return;
}