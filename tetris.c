#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int square = 0x0000001e;
int stick = 0x000001fe;
int pillar = 0x00000006;
int delayVar = 20;
int count = 0;

void user_isr(void)
{
    // PORTE += 1;
    if(IFS(0) & 0x8000){
        while(!(PORTD & 0x0800)){

        }
    }
    IFS(0) &= 0xfeff;
    
    return;
}

int getbtns(void){
    int BTN2 =(PORTD & 0x020) >> 5;
    int BTN3 =(PORTD & 0x040) >> 5;
    int BTN4 =(PORTD & 0x080) >> 5;
    int btnstate = BTN2 | BTN3 | BTN4;
    return btnstate;
}

// main function where the code will be run
void tetris()
{
    delay(1000);
    if(count == 1){
        blockPage(pillar);
        pillarUpdate();
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
