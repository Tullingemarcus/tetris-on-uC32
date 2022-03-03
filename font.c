#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

/*
1 1 1 0  0 1 1 0  1 0 0 1  1 1 1 1  0 1 1 0  1 0 0 1  1 1 1 1  1 1 1 1
1 0 0 1  1 0 0 1  1 1 1 1  1 0 0 0  1 0 0 1  1 0 0 1  1 0 0 0  1 0 0 1 
1 0 0 0  1 1 1 1  1 0 0 1  1 1 1 0  1 0 0 1  1 0 0 1  1 1 1 0  1 1 1 1 
1 0 1 1  1 0 0 1  1 0 0 1  1 0 0 0  1 0 0 1  1 0 0 1  1 0 0 0  1 0 1 1 
1 0 0 1  1 0 0 1  1 0 0 1  1 0 0 0  1 0 0 1  1 0 0 1  1 0 0 0  1 0 0 1 
1 1 1 0  1 0 0 1  1 0 0 1  1 1 1 1  0 1 1 0  0 1 1 0  1 1 1 1  1 0 0 1 
*/

// When called, write GAMEOVER to the top of the screen.
void gameover(){
    letter[122] = 0x67;
    letter[121] = 0x99;
    letter[120] = 0xf1;
    letter[119] = 0x9d;
    letter[118] = 0x99;
    letter[117] = 0x97;

    rgbOledBmp[122] |= letter[122];
    rgbOledBmp[121] |= letter[121];
    rgbOledBmp[120] |= letter[120];
    rgbOledBmp[119] |= letter[119];
    rgbOledBmp[118] |= letter[118];
    rgbOledBmp[117] |= letter[117];

    letter[122 + 128] = 0xf9;
    letter[121 + 128] = 0x1f;
    letter[120 + 128] = 0x79;
    letter[119 + 128] = 0x19;
    letter[118 + 128] = 0x19;
    letter[117 + 128] = 0xf9;

    rgbOledBmp[122 + 128] |= letter[122 + 128];
    rgbOledBmp[121 + 128] |= letter[121 + 128];
    rgbOledBmp[120 + 128] |= letter[120 + 128];
    rgbOledBmp[119 + 128] |= letter[119 + 128];
    rgbOledBmp[118 + 128] |= letter[118 + 128];
    rgbOledBmp[117 + 128] |= letter[117 + 128];   

    letter[122 + 256] = 0x96;
    letter[121 + 256] = 0x99;
    letter[120 + 256] = 0x99;
    letter[119 + 256] = 0x99;
    letter[118 + 256] = 0x99;
    letter[117 + 256] = 0x66;

    rgbOledBmp[122 + 256] |= letter[122 + 256];
    rgbOledBmp[121 + 256] |= letter[121 + 256];
    rgbOledBmp[120 + 256] |= letter[120 + 256];
    rgbOledBmp[119 + 256] |= letter[119 + 256];
    rgbOledBmp[118 + 256] |= letter[118 + 256];
    rgbOledBmp[117 + 256] |= letter[117 + 256];

    letter[122 + 384] = 0xff;
    letter[121 + 384] = 0x91;
    letter[120 + 384] = 0xf7;
    letter[119 + 384] = 0xd1;
    letter[118 + 384] = 0x91;
    letter[117 + 384] = 0x9f;

    rgbOledBmp[122 + 384] |= letter[122 + 384];
    rgbOledBmp[121 + 384] |= letter[121 + 384];
    rgbOledBmp[120 + 384] |= letter[120 + 384];
    rgbOledBmp[119 + 384] |= letter[119 + 384];
    rgbOledBmp[118 + 384] |= letter[118 + 384];
    rgbOledBmp[117 + 384] |= letter[117 + 384];
}

void digit0(int page){
    digit[122 + page * 128] = 0x6 << 2;
    digit[121 + page * 128] = 0x9 << 2;
    digit[120 + page * 128] = 0x9 << 2;
    digit[119 + page * 128] = 0x9 << 2;
    digit[118 + page * 128] = 0x9 << 2;
    digit[117 + page * 128] = 0x6 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}


void digit1(int page){
    digit[122 + page * 128] = 0x4 << 2;
    digit[121 + page * 128] = 0x6 << 2;
    digit[120 + page * 128] = 0x4 << 2;
    digit[119 + page * 128] = 0x4 << 2;
    digit[118 + page * 128] = 0x4 << 2;
    digit[117 + page * 128] = 0xe << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit2(int page){
    digit[122 + page * 128] = 0x6 << 2;
    digit[121 + page * 128] = 0x9 << 2;
    digit[120 + page * 128] = 0x8 << 2;
    digit[119 + page * 128] = 0x6 << 2;
    digit[118 + page * 128] = 0x1 << 2;
    digit[117 + page * 128] = 0xf << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit3(int page){
    digit[122 + page * 128] = 0x7 << 2;
    digit[121 + page * 128] = 0x8 << 2;
    digit[120 + page * 128] = 0x6 << 2;
    digit[119 + page * 128] = 0x8 << 2;
    digit[118 + page * 128] = 0x8 << 2;
    digit[117 + page * 128] = 0x7 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit4(int page){
    digit[122 + page * 128] = 0x8 << 2;
    digit[121 + page * 128] = 0xc << 2;
    digit[120 + page * 128] = 0xa << 2;
    digit[119 + page * 128] = 0xf << 2;
    digit[118 + page * 128] = 0x8 << 2;
    digit[117 + page * 128] = 0x8 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit5(int page){
    digit[122 + page * 128] = 0xf << 2;
    digit[121 + page * 128] = 0x1 << 2;
    digit[120 + page * 128] = 0x7 << 2;
    digit[119 + page * 128] = 0x8 << 2;
    digit[118 + page * 128] = 0x9 << 2;
    digit[117 + page * 128] = 0x6 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit6(int page){
    digit[122 + page * 128] = 0xe << 2;
    digit[121 + page * 128] = 0x1 << 2;
    digit[120 + page * 128] = 0x7 << 2;
    digit[119 + page * 128] = 0x9 << 2;
    digit[118 + page * 128] = 0x9 << 2;
    digit[117 + page * 128] = 0x6 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit7(int page){
    digit[122 + page * 128] = 0xe << 2;
    digit[121 + page * 128] = 0x9 << 2;
    digit[120 + page * 128] = 0x4 << 2;
    digit[119 + page * 128] = 0x2 << 2;
    digit[118 + page * 128] = 0x2 << 2;
    digit[117 + page * 128] = 0x8 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit8(int page){
    digit[122 + page * 128] = 0x6 << 2;
    digit[121 + page * 128] = 0x9 << 2;
    digit[120 + page * 128] = 0x6 << 2;
    digit[119 + page * 128] = 0x9 << 2;
    digit[118 + page * 128] = 0x9 << 2;
    digit[117 + page * 128] = 0x6 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}


void digit9(int page){
    digit[122 + page * 128] = 0x6 << 2;
    digit[121 + page * 128] = 0x9 << 2;
    digit[120 + page * 128] = 0x6 << 2;
    digit[119 + page * 128] = 0xe << 2;
    digit[118 + page * 128] = 0x8 << 2;
    digit[117 + page * 128] = 0x7 << 2;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digitclr(int page){
    if(page == 0){
        rgbOledBmp[122 + page * 128] &= 0x01;
        rgbOledBmp[121 + page * 128] &= 0x01;
        rgbOledBmp[120 + page * 128] &= 0x01;
        rgbOledBmp[119 + page * 128] &= 0x01;
        rgbOledBmp[118 + page * 128] &= 0x01;
        rgbOledBmp[117 + page * 128] &= 0x01;
    }
    if(page == 3){
        rgbOledBmp[122 + page * 128] &= 0x08;
        rgbOledBmp[121 + page * 128] &= 0x80;
        rgbOledBmp[120 + page * 128] &= 0x80;
        rgbOledBmp[119 + page * 128] &= 0x80;
        rgbOledBmp[118 + page * 128] &= 0x80;
        rgbOledBmp[117 + page * 128] &= 0x80;
    }
    if(page != 0 && page != 3){
        rgbOledBmp[122 + page * 128] = 0x0;
        rgbOledBmp[121 + page * 128] = 0x0;
        rgbOledBmp[120 + page * 128] = 0x0;
        rgbOledBmp[119 + page * 128] = 0x0;
        rgbOledBmp[118 + page * 128] = 0x0;
        rgbOledBmp[117 + page * 128] = 0x0;
    }
}