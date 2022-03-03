#include <stdio.h>      // Declarations of standard library
#include <pic32mx.h>    // Declarations of system-specific addresses etc
#include "tetris.h"     // Declarations for sepcific tetris function


// page "num" corresponds to the value for each page
char page1;
char page2;
char page3;
char page4;

// block is the current array with the block
int block[512];
int preblockVal;

// masks blockVal to different pages
void blockPage(int blockVal){
    page1 = (blockVal & 0x000000ff);
    page2 = (blockVal & 0x0000ff00) >> 8;
    page3 = (blockVal & 0x00ff0000) >> 16;
    page4 = (blockVal & 0xff000000) >> 24;
}

// everything related to the square block
void squareUpdate(){
    int i;

    int end = 0;
    int pos = 0;
    // for loop for everthing related to the squares movement and collision
    for(i = 106; i > 0; i--){
        
        // moveSquare moves the square down 1 pixel at a time
        moveSquare(0, i, page1);
        moveSquare(1, i, page2);
        moveSquare(2, i, page3);
        moveSquare(3, i, page4);

        // checks for button presses 02 moves rigth 04 moves left
        if(getbtns() & 0x02){
            preblockVal = square;
            if(square != 0x78000000){
               square = square << 2;
            }
            if(square <= 0x78000000){
                deletePrev(0, i);
                deletePrev(1, i);
                deletePrev(2, i);
                deletePrev(3, i);
                delay(100);
                blockPage(square);
                OledUpdate();
            }
            else{
               square = preblockVal;
            }
        }
        if(getbtns() & 0x04){
            preblockVal = square;
            square = square >> 2;
            if(square >= 0x1e){
                deletePrev(0, i);
                deletePrev(1, i);
                deletePrev(2, i);
                deletePrev(3, i);
                delay(100);
                blockPage(square);
                OledUpdate();
            }
            else{
                square = preblockVal;
            }
        }
        // delete previous pixel above square
        deletePrev(4, i);

        // calculate next row
        end =   (rgbOledBmp[i - 1] & 0xfe) + 
                (rgbOledBmp[i - 1 + 128] << 8) +
                (rgbOledBmp[i - 1 + 128 * 2] << 16) +
                ((rgbOledBmp[i - 1 + 128 * 3] << 24) & 0x7f000000);
        // calculate current row
        pos =   (block[i] + 
                (block[i + 128] << 8) +
                (block[i + 256] << 16) + 
                (block[i + 384] << 24));

        // checks if current row and next row share any bits
        if((end & pos) != 0){     //if true, stack
            OledUpdate();
            // checks remove row
            int k;
            for(k = 1; k <= 97; k += 2){ 
                removeRow(i);
            }
            // checks if player have gone to far and triggers GAMEOVER
            if(i > 106){
                digitclr(0);
                digitclr(1);
                digitclr(2);
                digitclr(3);
                gameover();
                OledUpdate();
                while(1){
                    delay(1000);
                    if(getbtns() & 0x08){
                        main();
                    }
                }  
            }
            count += i;
            return;
        }

        OledUpdate();
        // delay for the loop
        delay(delayVar);
    }
}

// everything related to the stick block
void stickUpdate(int startPos){
    int i;
    int end = 0;
    int pos = 0;

    for(i = startPos; i > 0; i--){
        // rotates block if btn1 is pressed
        if(getbtns() & 0x1){
            deletePrev(0, i);
            deletePrev(1, i);
            deletePrev(2, i);
            blockPage(pillar);
            delay(5);
            pillarUpdate(i);
            break;
        }
        delay(delayVar / 2);

        // moveStick moves the stick down 1 pixel at a time
        moveStick(0, i, page1);
        moveStick(1, i, page2);
        moveStick(2, i, page3);
        moveStick(3, i, page4);

        // checks for button presses 02 moves rigth 04 moves left
        if(getbtns() & 0x02){
            preblockVal = stick;
            if(stick != 0x7f800000){
               stick = stick << 2;
            }
            if(stick <= 0x7f800000){
                deletePrev(0, i);
                deletePrev(1, i);
                delay(100);
                blockPage(stick);
                OledUpdate();
            }
            else{
               stick = preblockVal;
            }
        }
        if(getbtns() & 0x04){
            preblockVal = stick;
            stick = stick >> 2;
            if(stick >= 0x1fe){
                deletePrev(0, i);
                deletePrev(1, i);
                delay(100);
                blockPage(stick);
                OledUpdate();
            }
            else{
                stick = preblockVal;
            }
        }
        // delete previous pixel above stick
        deletePrev(2, i);
        // calculate next row
        end =   (rgbOledBmp[i - 1] & 0xfe) + 
                (rgbOledBmp[i - 1 + 128] << 8) +
                (rgbOledBmp[i - 1 + 128 * 2] << 16) +
                ((rgbOledBmp[i - 1 + 128 * 3] << 24) & 0x7f000000);
        // calculate current row
        pos =   (block[i] + 
                (block[i + 128] << 8) +
                (block[i + 256] << 16) + 
                (block[i + 384] << 24));
        // checks if current row and next row share any bits
        if((end & pos) != 0){     //if true, stack
            OledUpdate();
            int k;
            for(k = 1; k <= 97; k += 2){ 
                removeRow(i);
            }

            // checks if player have gone to far and triggers GAMEOVER
            if(i > 106){
                digitclr(0);
                digitclr(1);
                digitclr(2);
                digitclr(3);
                gameover();
                OledUpdate();
                while(1){
                    delay(1000);
                    if(getbtns() & 0x08){
                        main();
                    }
                }  
            }
            count += i;
            return;
        }

        OledUpdate();
        // delay for the loop
        delay(delayVar / 2); 
    }
}
// everything related to the pillar block
void pillarUpdate(int startPos){
    int i;
    int end = 0;
    int pos = 0;
    for(i = startPos; i > 0; i--){
        // rotates block if btn1 is pressed
        if(getbtns() & 0x1){
            deletePrev(0, i);
            deletePrev(1, i);
            deletePrev(2, i);
            deletePrev(3, i);
            deletePrev(4, i);
            deletePrev(5, i);
            deletePrev(6, i);
            deletePrev(7, i);
            deletePrev(8, i);
            delay(5);
            blockPage(stick);
            stickUpdate(i);
            break;
            
        }
        delay(delayVar / 2);

        // moveStick moves the stick down 1 pixel at a time
        movePillar(0, i, page1);
        movePillar(1, i, page2);
        movePillar(2, i, page3);
        movePillar(3, i, page4);

        // checks for button presses 02 moves rigth 04 moves left
        if(getbtns() & 0x02){
            preblockVal = pillar;
            if(pillar != 0x60000000){
               pillar = pillar << 2;
            }
            if(pillar <= 0x60000000){
                deletePrev(0, i);
                deletePrev(1, i);
                deletePrev(2, i);
                deletePrev(3, i);
                deletePrev(4, i);
                deletePrev(5, i);
                deletePrev(6, i);
                deletePrev(7, i);
                delay(100);
                blockPage(pillar);
                OledUpdate();
            }
            else{
               pillar = preblockVal;
            }
        }
        if(getbtns() & 0x04){
            preblockVal = pillar;
            pillar = pillar >> 2;
            if(pillar >= 0x6){
                deletePrev(0, i);
                deletePrev(1, i);
                deletePrev(2, i);
                deletePrev(3, i);
                deletePrev(4, i);
                deletePrev(5, i);
                deletePrev(6, i);
                deletePrev(7, i);
                delay(100);
                blockPage(pillar);
                OledUpdate();
            }
            else{
                pillar = preblockVal;
            }
        }
        
        // delete previous pixel above pillar
        deletePrev(8, i);
        // calculate next row
        end =   (rgbOledBmp[i - 1] & 0xfe) + 
                (rgbOledBmp[i - 1 + 128] << 8) +
                (rgbOledBmp[i - 1 + 128 * 2] << 16) +
                ((rgbOledBmp[i - 1 + 128 * 3] << 24) & 0x7f000000);
        // calculate current row
        pos =   (block[i] + 
                (block[i + 128] << 8) +
                (block[i + 256] << 16) + 
                (block[i + 384] << 24));
        // checks if current row and next row share any bits
        if((end & pos) != 0){     //if true, stack
            OledUpdate();
            int k;
            for(k = 1; k <= 97; k += 2){ 
                removeRow(i);
            }
            // checks if player have gone to far and triggers GAMEOVER
            if(i > 101){
                digitclr(0);
                digitclr(1);
                digitclr(2);
                digitclr(3);
                gameover();
                OledUpdate();
                while(1){
                    delay(1000);
                    if(getbtns() & 0x08){
                        main();
                    }
                }  
            }
            count += i;
            return;
        }

        OledUpdate();
        // delay for the loop
        delay(delayVar / 2);
    }
}