#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

int points = 0;
int points10 = 0;
int points100 = 0;
int points1000 = 0;
void score(){
    
    points += 1;
    if(points % 10 == 0){
        points10 += 1;
        points -= 10;
        if(points10 % 10 == 0){
            points100 += 1;
            points10 -= 10;
            if(points100 % 10 == 0){
                points1000 += 1;
                points100 -= 10;
            }
        }
    }
    int temp = (points) | (points10 << 4) | (points100 << 8) | (points1000 << 12);
    int i;
    for(i = 3; i > -1; i--){
        digitclr(i);
        if((temp & 0x000f) == 0){
            digit0(i);
        }
        if((temp & 0x000f) == 1){
            digit1(i);
        }
        if((temp & 0x000f) == 2){
            digit2(i);
        }
        if((temp & 0x000f) == 3){
            digit3(i);
        }
        if((temp & 0x000f) == 4){
            digit4(i);
        }
        if((temp & 0x000f) == 5){
            digit5(i);
        }
        if((temp & 0x000f) == 6){
            digit6(i);
        }
        if((temp & 0x000f) == 7){
            digit7(i);
        }
        if((temp & 0x000f) == 8){
            digit8(i);
        }
        if((temp & 0x000f) == 9){
            digit9(i);
        }
        temp = temp >> 4;
    }  
}