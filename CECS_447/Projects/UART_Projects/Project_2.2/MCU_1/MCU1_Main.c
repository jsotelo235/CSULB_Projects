// MCU1_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Project 2: UART Part 2

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

#include "PLL.h"
#include "UART.h"
#include "PWM.h"
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


// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095

int main(void){
	
	char keyPressed,
			 receiveChar;
	
	unsigned int ADCValue;
	
  PLL_Init();													// PLL Init routine
	GPIO_PORTF_Init();									// Port F Init routine
	UART_0and1_Init();									// UART0 Init routine
	PWM1_PF2_Init(4096,1000);
	UART0_OutString("MCU1-MCU2 \r\n");	// Display intro Message

  while(1){
		
			keyPressed = UART0_InChar();		// receive char key from terminal
			receiveChar = UART1_InChar();		// receive char key from MCU2
			
			if(keyPressed == 'r'){
				UART0_OutString("\r\n");									// carraige return and new line
				UART0_OutString("Key pressed: r \r\n");		// display message that a key has been pressed
				UART1_OutChar('r');												// transmit the char to MCU 2 via UART1
				UART0_OutString("\r\n");									// carriage return and new line			
			}
			
			if(receiveChar == 'b'){											// Receive char b, then sent blinking message
				UART0_OutString("Red LED is blinking \r\n");
			}
			else if(receiveChar == 'o'){								// Receive char o, then sent off message
				UART0_OutString("Red LED is off \r\n");
			}
			else{
				ADCValue = UART1_InUDec();								// receive dec
				
				UART0_OutString("ADC Value: ");						// Display ADC Value string
				UART0_OutUDec(ADCValue);									// ADC Value
				UART0_OutString("\r\n");									// newline	

					if(ADCValue <= 0){
						PWM1_PF2_Duty(0);											// PWM for PF2
					}
					else{
						PWM1_PF2_Duty(ADCValue);							// PWM for PF2
					}
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
}
