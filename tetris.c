
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int blockVal = 0xe00e;
void user_isr()
{
    return;
}


// main function where the code will be run
void tetris()
{
    blockPage(blockVal);
    pixelmove();
    delay(1000);
    return;
}