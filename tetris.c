
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int blockVal = 0xfffe;

void user_isr(void)
{
    // PORTE += 1;
    if(IFS(0) & 0x8000){
        blockVal = blockVal << 15;
        PORTE += 1;
        IFSCLR(0) = 0x08000;
    }
    if(IFS(0) & 0x0800){
        blockVal = blockVal >> 15;
        PORTE -= 1;
        IFSCLR(0) = 0x00800;
    }
    IFS(0) &= 0xfeff;
    
    return;
}


// main function where the code will be run
void tetris()
{
    delay(1000);
    blockPage(blockVal);
    pixelmove();
    return;
}
