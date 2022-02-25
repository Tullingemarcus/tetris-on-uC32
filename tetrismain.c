
#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function

// main function
// this is where the program will start
int main(){
    
    OledHostInit();
    while(1){
        tetris();
    }
    return 0;
}
