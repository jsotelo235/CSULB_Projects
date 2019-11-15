// UART.h
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018


//******************************
//	UART 1 Functions
//******************************
void UART1_Init(void);								// initialize UART 1 and 0

char UART1_InChar(void);							// Rx char function

void UART1_OutChar(char data);				// Tx char function

void UART1_OutUDec(unsigned long n);	// Tx decimal function

