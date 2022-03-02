
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function


void init(){
    PORTECLR = 0xff;
    TRISECLR = 0x0ff;     // set bits 0-7 to output (0)
    TRISFSET = 0x02;      // set bit 1 to intput (1) for BTN1
    //TRISDSET = (1 << 8);
    TRISD |= 0xf7e0;      // set to input (1)
    TMR2 = 0x0;           // set timer 2 to start at 0
    T2CON |= 0x8070;      // 8 start timer, 7 set prescale to 256
    PR2 = 31250;          // prescale * PR2 = clock frequency = 100ms
    IFS(0) &= 0xfeff;     // set timeoutflag to 0
    IEC(0) |= 0x0100;     // enable interrupts
    IPC(2) |= 0x01c;      // set priority
    IPC(3) |= 0x01c;
    IECSET(0) = 0x08800;
    enable_interrupt();   // call function enable_interrupts from func.s
    return;
}