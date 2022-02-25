
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function


void init()
{
    TRISESET = 0x0ff;   // set bits 0-7 to output (0)
    return;
}