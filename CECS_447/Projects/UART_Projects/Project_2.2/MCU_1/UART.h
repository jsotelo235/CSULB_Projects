// UART.h
// Runs on TM4C123

void UART_0and1_Init(void);				// initialize UART0 and UART1

//*****************************
//	UART 0 Functions
//*****************************
char UART0_InChar(void);						// Wait for new serial port input

void UART0_OutChar(char data);  		// letter is an 8-bit ASCII character to be transferred

void UART0_OutString(char *pt);			// pointer to a NULL-terminated string to be transferred

void UART0_OutUDec(unsigned long n);// Tx dec function

//*****************************
//	UART 1 Functions
//*****************************
char UART1_InChar(void);						// Transmit input

unsigned long UART1_InUDec(void);		// Receive input

void UART1_OutChar(char data);  		// letter is an 8-bit ASCII character to be transferred

void UART1_OutString(char *pt);			// pointer to a NULL-terminated string to be transferred


