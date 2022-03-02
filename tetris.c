#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int square = 0x001e0000;
int stick = 0x000001fe;
int pillar = 0x0006000;
int delayVar = 50;
int count = 0;

void user_isr(void)
{    
    // PORTE += 1;
    IFS(0) &= 0xfeff;
    return;
}

int getbtns(void){
    int BTN1 =(PORTF & 0x002) >> 1;
    int BTN2 =(PORTD & 0x020) >> 4;
    int BTN3 =(PORTD & 0x040) >> 4;
    int BTN4 =(PORTD & 0x080) >> 4;
    int btnstate = BTN1 | BTN2 | BTN3 | BTN4;
    return btnstate;
}

// main function where the code will be run
void tetris()
{

    /*
    while(1){
        score();
        delay(1000);
    }
    */
    delay(1000);
    if(count == 1){
        blockPage(pillar);
        pillarUpdate(106);
        count = 0;
    }
    else{
        blockPage(square);
        squareUpdate();
        count = 1;
    }
    if(delayVar >= 10){
        delayVar--;
    }


    return;
}
