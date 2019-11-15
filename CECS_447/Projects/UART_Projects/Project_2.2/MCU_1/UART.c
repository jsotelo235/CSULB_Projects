// UART.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018

// U0Rx connected to PA0
// U0Tx connected to PA1

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

void UART_0and1_Init(void){
	
  SYSCTL_RCGCUART_R		|= 0x03; 																		// activate UART0 and UART1
  SYSCTL_RCGC2_R			|= 0x03;																		// activate Port A and Port B
	
	// UART 0
  UART0_CTL_R 				&= ~0x00000001;															// UART module 0 is disable
  UART0_IBRD_R 				= IBRD_460800;             									// IBRD = int( 80MHz / (16 * 115,200)) = int(10.8506)
  UART0_FBRD_R 				= FBRD_460800;             									// FBRD = int(0.8506 * 64 + 0.5) = 54               
  UART0_LCRH_R 				= 0x70;																			// 8-bit word length registers and enable FIFO register
  UART0_CTL_R					|= 0x0301;       														// Enable RXE, TXE and UARTEN registers
	
	// Port A
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;	// configure PA1 and PA0 as UART
	GPIO_PORTA_AFSEL_R	|= 0x03;          													// enable alt funct on PA1 and PA0
  GPIO_PORTA_DEN_R 		|= 0x03;          													// enable digital I/O on PA1 and PA0
  GPIO_PORTA_AMSEL_R &= ~0x03;          													// disable analog functionality on PA
	
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


//*********************************************
//	UART 0 
//	None-blocking
//*********************************************
char UART0_InChar(void){
		
	 if((UART0_FR_R&UART_FR_RXFE) == 0)
  {
    return((unsigned char)(UART0_DR_R&0xFF));
  } 
  else
  {
    return 0;
  }

}


void UART0_OutChar(char data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);													// wait until TXFF is 0 (UART_FR_TXFE = 0x00000020)
	
	UART0_DR_R = data;																							// TX transmits 1 byte of data
	
}

void UART0_OutString(char *pt){
  while(*pt){
    UART0_OutChar(*pt);
    pt++;
  }
}

void UART0_OutUDec(unsigned long n){
// This function uses recursion to convert decimal number
//   of unspecified length as an ASCII string
  if(n >= 10){
    UART0_OutUDec(n/10);
    n = n%10;
  }
  UART0_OutChar(n+'0'); /* n is between 0 and 9 */
}

//*********************************************
//	UART 1
//*********************************************
void UART1_OutChar(char data){
	while((UART1_FR_R&UART_FR_TXFF) != 0);													// wait until TXFF is 0 (UART_FR_TXFE = 0x00000020)
	
	UART1_DR_R = data;																							// TX transmits 1 byte of data
	
}

void UART1_OutString(char *pt){
  while(*pt){
    UART1_OutChar(*pt);
    pt++;
  }
}

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

unsigned long UART1_InUDec(void){
	unsigned long number=0, length=0;
	char character;
  character = UART1_InChar();
  while(character != '\r'){ // accepts until <enter> is typed
// The next line checks that the input is a digit, 0-9.
// If the character is not 0-9, it is ignored and not echoed
    if((character>='0') && (character<='9')) {
      number = 10*number+(character-'0');   // this line overflows if above 4294967295
      length++;
      UART1_OutChar(character);
    }
// If the input is a backspace, then the return number is
// changed and a backspace is outputted to the screen
    else if((character=='\b') && length){
      number /= 10;
      length--;
      UART1_OutChar(character);
    }
    character = UART1_InChar();
  }
  return number;
}

