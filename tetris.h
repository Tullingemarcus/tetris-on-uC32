
// declaration of function related to oled initialization
void OledHostInit(void);
unsigned char Spi2PutByte(unsigned char bVal);
void OledDspInit(void);
void OledUpdate(void);
void OledPutBuffer(int cb, unsigned char *rgbTx);
void display_start(void);   // draws out border

// declaration of global constant and array
#define cbOledDispMax   512 //max number of bytes in display buffer
unsigned char rgbOledBmp[cbOledDispMax];

int block[512];             // Array for tetrisblocks
int letter[512];            // Array for letters
int digit[512];             // Array for digits

extern int square;          // Global variable for shape "square"
extern int stick;           // Global variable for shape "stick"
extern int pillar;          // Global variable for shape "pillar"
extern int delayVar;        // Global variable for gamespeed
extern int count;           // Global variable that randomizes which block spawns

// declaration of other functions
void user_isr(void);        // user_isr is currently not used
void init(void);
void tetris(void);

// declaration of specific funtion delay and getbtns 
void delay(int);
void enable_interrupt(void); // enable_interupts is currently not used
int getbtns(void);

// int blockPos(int, int);

void blockPage(int);        
void removeRow(int);
void deletePrev(int, int);  // removes the previous position of the block

// Handles collisions, shifts, moves, rotations of blocks
void squareUpdate(void);
void stickUpdate(int);
void pillarUpdate(int);

// Functions to move down 1 pixel at the time
void moveSquare(int, int, int);
void moveStick(int, int, int);
void movePillar(int, int, int);

// function to get gameover to appear on screen
void gameover(void);
// function to get digits to appear on screen
void digit0(int);
void digit1(int);
void digit2(int);
void digit3(int);
void digit4(int);
void digit5(int);
void digit6(int);
void digit7(int);
void digit8(int);
void digit9(int);
void digitclr(int);
void score(void);