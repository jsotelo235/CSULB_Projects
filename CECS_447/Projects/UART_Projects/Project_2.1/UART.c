// UART.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// March 19, 2018

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

#include "UART.h"
#include "tm4c123gh6pm.h"

#define	IBRD_300			16666
#define	FBRD_300			43

#define IBRD_115200		43
#define FBRD_115200		26

#define IBRD_460800		10
#define FBRD_460800		54

// Initialize the UART for 115,200 baud rate (assuming 80 MHz UART clock),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
void UART_Init(void){
  SYSCTL_RCGC1_R			|= 0x00000001; 															// activate UART0
  SYSCTL_RCGC2_R			|= 0x00000001;															// activate port A
  UART0_CTL_R 				&= ~0x0000001;															// disable UART
  UART0_IBRD_R 				= IBRD_460800;             									// IBRD = int( 80MHz / (16 * 115,200)) = int(43.4027)
  UART0_FBRD_R 				= FBRD_460800;             									// FBRD = int(0.4027 * 64 + 0.5) = 26               
  UART0_LCRH_R 				= 0x0070;																		// 8-bit word length, enable FIFO
  UART0_CTL_R					|= 0x0301;       														// enable UART	
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;	// configure PA1-0 as UART
	GPIO_PORTA_AFSEL_R	|= 0x03;          													// enable alt funct on PA1-0
  GPIO_PORTA_DEN_R 		|= 0x03;          													// enable digital I/O on PA1-0
  GPIO_PORTA_AMSEL_R &= ~0x03;          													// disable analog functionality on PA
}

//Non-blocking receive for characters for new input, then return ASCII code
char UART_InChar(void){
		
	 if((UART0_FR_R&UART_FR_RXFE) == 0)
  {
    return((unsigned char)(UART0_DR_R&0xFF));
  } 
  else
  {
    return 0;
  }

}

// Busy-Wait for buffer to be not full, then output
void UART_OutChar(char data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);													// wait until TXFF is 0 (UART_FR_TXFE = 0x00000020)
	
	UART0_DR_R = data;																							// TX transmits 1 byte of data
	
}

// Routine performs carriage return and line feed
void OutCRLF(void){
  UART_OutChar(CR);
  UART_OutChar(LF);
}

//------------UART_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void UART_OutString(char *pt){
  while(*pt){
    UART_OutChar(*pt);
    pt++;
  }
}


