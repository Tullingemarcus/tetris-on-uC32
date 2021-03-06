#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

// These values spawns the blocks in the middle of the screen
int square = 0x001e0000;
int stick = 0x000001fe;
int pillar = 0x0006000;

int delayVar = 90;          // Sets speed of the game. 
int count = 0;              // Global variable that randomizes which block spawns

// Interrupt-service routine
void user_isr(void)
{    
    IFS(0) &= 0xfeff;
    return;
}

// Function to see the state of the buttons
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
    delay(1000);
    if(count % 3 == 1){
        blockPage(pillar);
        pillarUpdate(106);
    }
    else{
        blockPage(square);
        squareUpdate();
    }
    return;
}
