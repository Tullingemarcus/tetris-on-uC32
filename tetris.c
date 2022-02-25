
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function


void user_isr()
{
    return;
}


// main function where the code will be run
void tetris()
{
    OledUpdate();
    return;
}