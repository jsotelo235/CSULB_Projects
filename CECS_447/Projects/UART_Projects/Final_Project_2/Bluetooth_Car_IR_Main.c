// Bluetooth_Car_IR_Main.c
// Runs on TM4C123

// U0Rx connected to PA0
// U0Tx connected to PA1

// U1Rx connected to PB0
// U1Tx connected to PB1

#include "PLL.h"
#include "UART.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>

// LEDs
#define RED_LED			0x02 
#define	BLUE_LED		0x04
#define	GREEN_LED		0x08

uint16_t duty [] = {25000, 37500, 49950};
uint16_t *speed = NULL;

void GPIO_PORTF_Init(void);		// Initialized Port F for LEDS and Switches

int main(void){
	
	char keyPressed = NULL;

  PLL_Init();
  UART1_Init();              // initialize UART1
	GPIO_PORTF_Init();
	

  while(1){

		keyPressed = UART1_InChar();
		
		switch(keyPressed){
			case 'r':
				GPIO_PORTF_DATA_R |= RED_LED;
				GPIO_PORTF_DATA_R &= ~(BLUE_LED | GREEN_LED);
				break;
			case 'b':
				GPIO_PORTF_DATA_R |= BLUE_LED;
				GPIO_PORTF_DATA_R &= ~(RED_LED | GREEN_LED);
				break;
			case 'g':
				GPIO_PORTF_DATA_R |= GREEN_LED;
				GPIO_PORTF_DATA_R &= ~(BLUE_LED | RED_LED);
				break;
			case 'w':
				break;
			case 'a':
				break;
			case 's':
				break;
			case 'd':
				break;
			case 'q':
				break;
		}

  }
}

// Subroutine to initialize port F pins for input and output
void GPIO_PORTF_Init(void){ 	
	volatile unsigned long delay; 
  SYSCTL_RCGC2_R |= 0x00000020;     	// activate clock for port F
  delay = SYSCTL_RCGC2_R;           	// delay    
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock GPIO Port F
  GPIO_PORTF_CR_R 		|= 0x1F;        // allow changes to PF4, PF3, PF2, PF1 and PF0      
  GPIO_PORTF_AMSEL_R	&= ~0x1F;       // disable analog function
  GPIO_PORTF_PCTL_R 	&= ~0x000F000F; // GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R 		|= 0x0E;        // PF4 and PF0 as input, PF3,PF2,and PF1 as output   
  GPIO_PORTF_AFSEL_R 	&= ~0x1F;       // no alternate function
  GPIO_PORTF_PUR_R 		|= 0x11;        // enable pullup resistors on PF4 and PF0       
  GPIO_PORTF_DEN_R 		|= 0x1F;        // enable digital pins PF4, PF1, PF2 and PF3 
}
