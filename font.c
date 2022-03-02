#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

void letterA(){
    letter[122] = 0x06 << 2;
    letter[121] = 0x09 << 2;
    letter[120] = 0x09 << 2;
    letter[119] = 0x0f << 2;
    letter[118] = 0x09 << 2;
    letter[117] = 0x09 << 2;

    rgbOledBmp[122] |= letter[122];
    rgbOledBmp[121] |= letter[121];
    rgbOledBmp[120] |= letter[120];
    rgbOledBmp[119] |= letter[119];
    rgbOledBmp[118] |= letter[118];
    rgbOledBmp[117] |= letter[117];
}

void digit0(int page){
    digit[122 + page * 128] = 0x6 << 4;
    digit[121 + page * 128] = 0x9 << 4;
    digit[120 + page * 128] = 0x9 << 4;
    digit[119 + page * 128] = 0x9 << 4;
    digit[118 + page * 128] = 0x9 << 4;
    digit[117 + page * 128] = 0x6 << 4;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}

void digit1(int page){
    digit[122 + page * 128] = 0x1 << 4;
    digit[121 + page * 128] = 0x1 << 4;
    digit[120 + page * 128] = 0x1 << 4;
    digit[119 + page * 128] = 0x1 << 4;
    digit[118 + page * 128] = 0x1 << 4;
    digit[117 + page * 128] = 0x1 << 4;

    rgbOledBmp[122 + page * 128] |= digit[122 + page * 128];
    rgbOledBmp[121 + page * 128] |= digit[121 + page * 128];
    rgbOledBmp[120 + page * 128] |= digit[120 + page * 128];
    rgbOledBmp[119 + page * 128] |= digit[119 + page * 128];
    rgbOledBmp[118 + page * 128] |= digit[118 + page * 128];
    rgbOledBmp[117 + page * 128] |= digit[117 + page * 128];
}