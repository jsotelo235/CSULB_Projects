// UART.h
// Runs on TM4C123

// standard ASCII symbols
#define CR   0x0D
#define LF   0x0A
#define BS   0x08

void UART_Init(void);

char UART_InChar(void);

void UART_OutChar(char data);

void OutCRLF(void);

// Output String (NULL termination)
void UART_OutString(char *pt);

