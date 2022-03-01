#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

void deletePrev(int offset, int i){
    rgbOledBmp[i + offset] &= ~block[i + offset];
    rgbOledBmp[i + offset + 128] &= ~block[i + offset + 128];
    rgbOledBmp[i + offset + 128 * 2] &= ~block[i + offset + 128 * 2];
    rgbOledBmp[i + offset + 128 * 3] &= ~block[i + offset + 128 * 3];
}

void moveSquare(int offset, int i, int page){
    block[(i + 3) + offset * 128] = page;
    block[(i + 2) + offset * 128] = page;
    block[i + 1 + offset * 128] = page;
    block[i + offset * 128] = page;
    rgbOledBmp[i + 3 + offset * 128] |= block[i + 3 + offset * 128];
    rgbOledBmp[i + 2 + offset * 128] |= block[i + 2 + offset * 128];
    rgbOledBmp[i + 1 + offset * 128] |= block[i + 1 + offset * 128];
    rgbOledBmp[i + offset * 128] |= block[i + offset * 128];
    return;
}

void moveStick(int offset, int i, int page){
    block[i + 1 + offset * 128] = page;
    block[i + offset * 128] = page;
    rgbOledBmp[i + 1 + offset * 128] |= block[i + 1 + offset * 128];
    rgbOledBmp[i + offset * 128] |= block[i + offset * 128];
    return;
}

void movePillar(int offset, int i, int page){
    block[i + 7 + offset * 128] = page;
    block[i + 6 + offset * 128] = page;
    block[i + 5 + offset * 128] = page;
    block[i + 4 + offset * 128] = page;
    block[i + 3 + offset * 128] = page;
    block[i + 2 + offset * 128] = page;
    block[i + 1 + offset * 128] = page;
    block[i + offset * 128] = page;
    rgbOledBmp[i + 7 + offset * 128] |= block[i + 7 + offset * 128];
    rgbOledBmp[i + 6 + offset * 128] |= block[i + 6 + offset * 128];
    rgbOledBmp[i + 5 + offset * 128] |= block[i + 5 + offset * 128];
    rgbOledBmp[i + 4 + offset * 128] |= block[i + 4 + offset * 128];
    rgbOledBmp[i + 3 + offset * 128] |= block[i + 3 + offset * 128];
    rgbOledBmp[i + 2 + offset * 128] |= block[i + 2 + offset * 128];
    rgbOledBmp[i + 1 + offset * 128] |= block[i + 1 + offset * 128];
    rgbOledBmp[i + offset * 128] |= block[i + offset * 128];
    return;
}
