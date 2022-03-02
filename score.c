#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int points = 0;
void score(){
    points += 0x0001;
    int temp;
    int i;
    for(i = 3; i > -1; i--){
        temp = points - (10 * i);
        digitclr(i);
        if(temp == 0){
            digit0(i);
        }
        if(temp == 1){
            digit1(i);
        }
        if(temp == 2){
            digit2(i);
        }
        if(temp == 3){
            digit3(i);
        }
        if(temp == 4){
            digit4(i);
        }
        if(temp == 5){
            digit5(i);
        }
        if(temp == 6){
            digit6(i);
        }
        if(temp == 7){
            digit7(i);
        }
        if(temp == 8){
            digit8(i);
        }
        if(temp == 9){
            digit9(i);
        }
    }  
}