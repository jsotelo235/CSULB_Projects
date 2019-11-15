// UART.h
// Runs on TM4C123



void UART1_Init(void);

char UART1_InChar(void);

void UART1_OutChar(char data);

// Output String (NULL termination)
void UART1_OutString(char *pt);

