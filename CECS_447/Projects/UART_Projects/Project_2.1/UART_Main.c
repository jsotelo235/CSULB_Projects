// UART_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// March 19, 2018
// Project 2: UART

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
// 1) Sending Characters from the serial terminal to the microcontroller
// 2) Switch 1 turns on all LEDs and send message to terminal
// 3) Switch 2 turns off all LEDs and send message to terminal

#include "PLL.h"
#include "UART.h"
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

volatile uint8_t SW1, SW2;		// semaphores

int main(void){
	
	unsigned char green = 'g',	// char 'g' for green LED
								red	  = 'r',	// char 'r' for red LED
								blue	= 'b',	// char 'b' for blue LED
								keyPress;
	
  PLL_Init();									// PLL Init routine
	GPIO_PORTF_Init();					// Port F Init routine
	UART_Init();								// UART0 Init routine
	
	UART_OutString("Hello World!");																						// intro message to terminal
	OutCRLF();
	UART_OutString("Press g for green, r for red and b for blue.");						// intro message to terminal
	OutCRLF();
	UART_OutString("Press SW1 for all LEDs on, press SW2 for all LEDs off");	// intro message to terminal
	OutCRLF();	
	
  while(1){
		keyPress = UART_InChar();
		
		if(keyPress == green){																	// keyPresshar 'g' is pressed on terminal, display the color green
			
			if(GPIO_PORTF_DATA_R &GREEN_LED){
				GPIO_PORTF_DATA_R  ^= (GREEN_LED);					// Green LED is on	
				UART_OutString("Green LED is off");					// Send message to terminal
			}
			else{
				UART_OutString("Green LED is on");					// Send message to terminal			
				GPIO_PORTF_DATA_R  ^= GREEN_LED;						// Green LED is on
			}
			
			OutCRLF();																		// <CR> <LF>
		}
		else if(keyPress == red){															// char 'r' is presssed on terminal, display the color red
			
			if(GPIO_PORTF_DATA_R &RED_LED){
				GPIO_PORTF_DATA_R  ^= (RED_LED);						// Green LED is on	
				UART_OutString("Red  LED is off");					// Send message to terminal
			}
			else{
				UART_OutString("Red  LED is on");						// Send message to terminal
				GPIO_PORTF_DATA_R  ^= RED_LED;							// Red LED is on
			}
			OutCRLF();
		}
		else if(keyPress == blue){															// char 'b' is pressed on terminal display the color red
			
			if(GPIO_PORTF_DATA_R &BLUE_LED){
				GPIO_PORTF_DATA_R  ^= (BLUE_LED);						// Green LED is on
				UART_OutString("Blue LED is off");					// Send message to terminal
			}
			else{
				UART_OutString("Blue LED is on");						// Send message to terminal
				GPIO_PORTF_DATA_R  ^= BLUE_LED;							// Blue LED is on
			}	
			OutCRLF();	
		}
  }
}

// Subroutine to initialize port F pins for input and output
void GPIO_PORTF_Init(void){ 	
	volatile unsigned long delay; 
  SYSCTL_RCGC2_R |= 0x00000020;     	// F clock
  delay = SYSCTL_RCGC2_R;           	// delay    
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock GPIO Port F
  GPIO_PORTF_CR_R 		|= 0x1F;        // allow changes to PF4, PF3, PF2, PF1 and PF0      
  GPIO_PORTF_AMSEL_R	&= ~0x1F;       // disable analog function
  GPIO_PORTF_PCTL_R 	&= ~0x000F000F; // GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R 		|= 0x0E;        // PF4 and PF0 as input, PF3,PF2,and PF1 as output   
  GPIO_PORTF_AFSEL_R 	&= ~0x1F;       // no alternate function
  GPIO_PORTF_PUR_R 		|= 0x11;        // enable pullup resistors on PF4 and PF0       
  GPIO_PORTF_DEN_R 		|= 0x1F;        // enable digital pins PF4, PF1, PF2 and PF3 

  // Interrupt Initialization
  GPIO_PORTF_IS_R			&= ~0x11;					//	PF4 and PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R 		&= ~0x11;					//	PF4 is not both edges 
  GPIO_PORTF_IEV_R 		&= ~0x11;					//	PF4 falling edge event
  GPIO_PORTF_ICR_R 		= 0x11;						//	clear flags PF4 and PF0
  GPIO_PORTF_IM_R 		|= 0x11;					//	arm interrupt on PF4 and PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; //	priority 5
  NVIC_EN0_R = 0x40000000;							//	enable interrupt 30 in NVIC	
	EnableInterrupts();           				// (i) Clears the I bit
}

void GPIOPortF_Handler(void){
	
		if(GPIO_PORTF_RIS_R&0x10){																// poll PF4
			GPIO_PORTF_ICR_R = 0x10;																// acknowledge flag
			UART_OutString("All LEDs have been turned on");					// Send message to terminal
			OutCRLF();																							// <CR> <LF>
			GPIO_PORTF_DATA_R |= (RED_LED + GREEN_LED + BLUE_LED);	// all LEDs on
		}
		
		if(GPIO_PORTF_RIS_R&0x01){																// poll PF0
			GPIO_PORTF_ICR_R = 0x01;																// acknowledge flag
			UART_OutString("All LEDs have been turned off");				// Send message to terminal
			OutCRLF();																							// <CR> <LF>
			GPIO_PORTF_DATA_R &= ~(RED_LED + GREEN_LED + BLUE_LED);	// all LEDs off
		}
}


