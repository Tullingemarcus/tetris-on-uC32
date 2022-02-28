#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

char page1;
char page2;
char page3;
char page4;
int block[512];                 // tetrisblock

void blockPage(int blockVal){
    page1 = (blockVal & 0x000000ff);
    page2 = (blockVal & 0x0000ff00) >> 8;
    page3 = (blockVal & 0x00ff0000) >> 16;
    page4 = (blockVal & 0xff000000) >> 24;
}

void movepix(int offset, int i, int page){
    block[(i + 3) + offset * 128] = page;
    block[(i + 2) + offset * 128] = page;
    block[i + 1 + offset * 128] = page;
    block[i + offset * 128] = page;
    rgbOledBmp[i + offset * 128] |= block[i + offset * 128];
    rgbOledBmp[i + 1 + offset * 128] |= block[i + 1 + offset * 128];
    rgbOledBmp[i + 2 + offset * 128] |= block[i + 2 + offset * 128];
    rgbOledBmp[i + 3 + offset * 128] |= block[i + 3 + offset * 128];
    return;
}

void pixelmove(){
    int i;
    int end = 0;
    int pos = 0;
    //i = page; i > (page - 122); 
    for(i = 110; i > 0; i--){


        movepix(0, i, page1);
        movepix(1, i, page2);
        movepix(2, i, page3);
        movepix(3, i, page4);

        if((end & pos) != 0){     //if true, stack
        /*
            rgbOledBmp[i] &= ~block[i + 4];
            rgbOledBmp[i + 128] &= ~block[i + 128];
            rgbOledBmp[i + 128 * 2] &= ~block[i + 128 * 2];
            rgbOledBmp[i + 128 * 3] &= ~block[i + 128 * 3];
        */
            return;
        }

        rgbOledBmp[i + 4] &= ~block[i + 4];
        rgbOledBmp[i + 4 + 128] &= ~block[i + 4 + 128];
        rgbOledBmp[i + 4 + 128 * 2] &= ~block[i + 4 + 128 * 2];
        rgbOledBmp[i + 4 + 128 * 3] &= ~block[i + 4 + 128 * 3];

        end =   (rgbOledBmp[i - 1] & 0xfe) + 
                (rgbOledBmp[i - 1 + 128] << 8) +
                (rgbOledBmp[i - 1 + 128 * 2] << 16) +
                ((rgbOledBmp[i - 1 + 128 * 3] << 24) & 0x7f000000);

        pos =   (block[i] + 
                (block[i + 128] << 8) +
                (block[i + 256] << 16) + 
                (block[i + 384] << 24));
        removeRow();
        OledUpdate();
        delay(50);
    }
}


