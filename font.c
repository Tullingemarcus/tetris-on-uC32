#include <stdio.h>      // Declarations of standard library
#include "tetris.h"     // Declarations for sepcific tetris function

//Letter A
/*
00   1111 
00  11  11
00  11  11
00  111111
00  11  11
00  11  11

     11
    1  1
    1  1
    1111
    1  1
    1  1
*/

void letterA(){
    int letter[512];
    letter[114] = 0x01e;
    letter[113] = 0x033;
    letter[112] = 0x033;
    letter[111] = 0x03f;
    letter[110] = 0x033;
    letter[109] = 0x033;

    rgbOledBmp[114] |= letter[114];
    rgbOledBmp[113] |= letter[113];
    rgbOledBmp[112] |= letter[112];
    rgbOledBmp[111] |= letter[111];
    rgbOledBmp[110] |= letter[110];
    rgbOledBmp[109] |= letter[109];
}