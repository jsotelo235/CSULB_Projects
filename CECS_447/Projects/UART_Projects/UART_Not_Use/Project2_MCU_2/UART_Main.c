// UART_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Project 2: UART Part 2
// Software for MCU 2

// U1Rx (VCP receive) connected to PB0
// U1Tx (VCP transmit) connected to PB1
// 

#include "PLL.h"
#include "UART.h"
#include "ADC.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

// LEDs
 #define RED_LED		0x02 
 #define BLUE_LED		0x04
 #define GREEN_LED	0x08
 
void GPIO_PORTF_Init(void);		// Initialized Port F
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

int main(void){
	
	unsigned char charReceive;
	
  PLL_Init();									// PLL Init routine
	GPIO_PORTF_Init();					// Port F Init routine
	UART1_Init();								// UART1 Init routine
		
  while(1){
		
		charReceive = UART1_InChar();
		
		if(charReceive == 'r'){
			
			GPIO_PORTF_DATA_R |= RED_LED;
		}
	}
}

// Subroutine to initialize port F pins for input and output
void GPIO_PORTF_Init(void){ 
	
	volatile unsigned long delay; 
  SYSCTL_RCGC2_R |= 0x00000020;     		// F clock
  delay = SYSCTL_RCGC2_R;           		// delay    
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   		// unlock GPIO Port F
  GPIO_PORTF_CR_R 		|= 0x1F;        	// allow changes PF1 and PF0      
  GPIO_PORTF_AMSEL_R	&= ~0x1F;       	// disable analog function
  GPIO_PORTF_PCTL_R 	&= ~0x000F000F; 	// GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R 		|= 0x0E;        	// PF0 as input, PF1 as output   
  GPIO_PORTF_AFSEL_R 	&= ~0x1F;       	// no alternate function
  GPIO_PORTF_PUR_R 		|= 0x11;        	// enable pullup resistors on PF0       
  GPIO_PORTF_DEN_R 		|= 0x1F;        	// enable digital pins PF0 and PF1 

  // Interrupt Initialization
  GPIO_PORTF_IS_R			&= ~0x01;					//	PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R 		&= ~0x01;					//	PF0 is not both edges 
  GPIO_PORTF_IEV_R 		&= ~0x01;					//	PF0 falling edge event
  GPIO_PORTF_ICR_R 		= 0x01;						//	clear flags PF4 and PF0
  GPIO_PORTF_IM_R 		|= 0x01;					//	arm interrupt on PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; //	priority 5
  NVIC_EN0_R = 0x40000000;							//	enable interrupt 30 in NVIC	
	EnableInterrupts();           				// (i) Clears the I bit
}

void GPIOPortF_Handler(void){
	
	GPIO_PORTF_ICR_R = 0x01;				 // acknowledge flag
}


