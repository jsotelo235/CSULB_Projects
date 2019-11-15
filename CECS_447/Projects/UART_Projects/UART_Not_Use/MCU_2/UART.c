// UART.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Initiliaze UART 1 and UART 0 for transmitting and receiving data

// U1Rx connected to PB0
// U1Tx connected to PB1

#include "UART.h"
#include "tm4c123gh6pm.h"

#define	IBRD_300			16666
#define	FBRD_300			43

#define IBRD_115200		43
#define FBRD_115200		26

#define IBRD_460800		10
#define FBRD_460800		54

// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// need to activate PB0 and PB1 for UART1 
void UART1_Init(void){
	
  SYSCTL_RCGCUART_R		|= 0x02; 																		// activate UART 1 clock
  SYSCTL_RCGC2_R			|= 0x02;																		// activate Port B clock
	
	// UART 1
	UART1_CTL_R					&= ~0x00000001;															// UART module 1 is disable
	UART1_IBRD_R				 = IBRD_460800;															// IBRD = int( 80MHz/ (16 * 460800)) = int(10.8506)
	UART1_FBRD_R				 = FBRD_460800;															// FBRD = int(0,8506 * 64 + 0.5) = 54
	UART1_LCRH_R				 = 0x70;																		// 8-bit word length registers and enable FIFO register
	UART1_CTL_R					|= 0x0301;																	// Enable RXE, TXE, and UARTEN registers
	
	// Port B
	GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;	// configure PB1 and PB0 as UART
	GPIO_PORTB_AFSEL_R	|= 0x03;																		// enable alt funct on PB1 and PB0
	GPIO_PORTB_DEN_R		|= 0x03;																		// enable digital I/O on PB1 and PB0
	GPIO_PORTB_AMSEL_R  &= ~0x03;																		// disable analog functionality on PB
}



// Receive char Function
char UART1_InChar(void){
		
	 if((UART1_FR_R&UART_FR_RXFE) == 0)
  {
    return((unsigned char)(UART1_DR_R&0xFF));
  } 
  else
  {
    return 0;
  }

}

// Transmit char Function
void UART1_OutChar(char data){
	while((UART1_FR_R&UART_FR_TXFF) != 0);		// wait until TXFF is 0 (UART_FR_TXFE = 0x00000020)
	
	UART1_DR_R = data;												// TX transmits 1 byte of data
	
}

// Tx decimal function
// 32-bit number to be transferred
void UART1_OutUDec(unsigned long n){
	// This function uses recursion to convert decimal number
	// of unspecified length as an ASCII string
  if(n >= 10){
    UART1_OutUDec(n/10);
    n = n%10;
  }
  UART1_OutChar(n+'0'); /* n is between 0 and 9 */
}

