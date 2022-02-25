
// declaration of function related to oled initialization
void OledHostInit(void);
unsigned char Spi2PutByte(unsigned char bVal);
void OledDspInit(void);
void OledUpdate(void);
void OledPutBuffer(int cb, unsigned char *rgbTx);
void display_led(void);

// declaration of global constant and array
#define cbOledDispMax   512 //max number of bytes in display buffer
unsigned char rgbOledBmp[cbOledDispMax];

// declaration of other functions
void user_isr(void);
void init(void);
void tetris(void);
void delay(int);