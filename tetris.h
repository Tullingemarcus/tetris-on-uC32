
// declaration of function related to oled initialization
void OledHostInit(void);
unsigned char Spi2PutByte(unsigned char bVal);
void OledDspInit(void);
void OledUpdate(void);
void OledPutBuffer(int cb, unsigned char *rgbTx);
void display_start(void);

// declaration of global constant and array
#define cbOledDispMax   512 //max number of bytes in display buffer
unsigned char rgbOledBmp[cbOledDispMax];
int block[512];                 // tetrisblock
int letter[512];  
int digit[512];
extern int square;
extern int stick;
extern int pillar;
extern int delayVar;
extern int count;

// declaration of other functions
void user_isr(void);
void init(void);
void tetris(void);
void delay(int);
void enable_interrupt(void);
void squareUpdate(void);
void stickUpdate(int);
void pillarUpdate(int);
int blockPos(int, int);
void blockPage(int);
void removeRow(int);
int getbtns(void);
void deletePrev(int, int);
void moveSquare(int, int, int);
void moveStick(int, int, int);
void movePillar(int, int, int);
void gameover(void);

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

