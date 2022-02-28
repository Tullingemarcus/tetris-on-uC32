
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function


void init(){
    TRISESET &= 0xf00;  // set bits 0-7 to output (0)
    PORTE += 1;         // LED++ 
    return;
}