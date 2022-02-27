#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

char page1;
char page2;
char page3;
char page4;


void blockPage(int blockVal){
    page1 = (blockVal & 0x000000ff);
    page2 = (blockVal & 0x0000ff00) >> 8;
    page3 = (blockVal & 0x00ff0000) >> 16;
    page4 = (blockVal & 0xff000000) >> 24;
}

void pixelmove(){
    int i;
    int end;
    int block[512];                 // tetrisblock
    //i = page; i > (page - 122); 
    for(i = 122; i > 0; i--){
        block[(i + 2)] = page1;
        block[i + 1] = page1;
        block[i] = page1;
        rgbOledBmp[i] |= block[i];
        rgbOledBmp[i + 1] |= block[i + 1];
        rgbOledBmp[i + 2] |= block[i + 2];

        block[(i + 2) + 128] = page2;
        block[i + 1  + 128] = page2;
        block[i  + 128] = page2;
        rgbOledBmp[i  + 128] |= block[i  + 128];
        rgbOledBmp[i + 1  + 128] |= block[i + 1  + 128];
        rgbOledBmp[i + 2  + 128] |= block[i + 2  + 128];

        rgbOledBmp[i + 3] = 1;
        rgbOledBmp[i + 3 + 128] = 0;
        rgbOledBmp[i + 3 + 128 * 2] = 0;
        rgbOledBmp[i + 3 + 128 * 3] = 128;

        end =   (rgbOledBmp[i - 1] & 0xfe) + 
                (rgbOledBmp[i - 1 + 128] << 8) +
                (rgbOledBmp[i - 1 + 128 * 2] << 16) +
                ((rgbOledBmp[i - 1 + 128 * 3] << 24) & 0x7f);                            ;
        if(end != 0){     //if true, stack
            return;
        }

        OledUpdate();
        delay(100);
    }
}


