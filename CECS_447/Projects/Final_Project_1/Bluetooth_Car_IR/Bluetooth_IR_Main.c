// Bluetooth_Car_IR_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Final Project: Bluetooth and IR

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

#include "PLL.h"
#include "UART.h"
#include "PWM.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>

// LEDs
 #define 	RED_LED			0x02 
 #define	BLUE_LED		0x04
 #define	GREEN_LED		0x08
 
void GPIO_PORTF_Init(void);		// Initialized Port F for LEDS and Switches
void GPIO_PORTC_Init(void);		// Initialized Port C for motor direction
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

uint16_t duty [] = {25000, 37500, 49950};
uint16_t *speed = NULL;

char keyPressed; //receiving;
unsigned long count=0;

int main(void){
	
  PLL_Init();														// PLL Init routine to 50MHz
	GPIO_PORTF_Init();										// Port F Init routine
	GPIO_PORTC_Init();										// Port C Init routine
	UART0_Init();													// UART0 Init routine
	PWM_Motors_Init(50000, 0);						// Initialize PB6 and PB7 PWM to 1000Hz, 0% duty
	UART0_OutString("Hello World! \r\n");	// Display intro Message
	GPIO_PORTF_DATA_R |= RED_LED;					// Red led indicates initial speed is 50%
	
  while(1){
		
		keyPressed = UART0_InChar();				// receive char key from terminal
		
		switch(keyPressed){
			case 'r':
				UART0_OutString("Red \r\n");
				speed = &duty[0];								// 50%
				GPIO_PORTF_DATA_R |= RED_LED;
				GPIO_PORTF_DATA_R &= ~(BLUE_LED | GREEN_LED);
				break;
			case 'b':
				UART0_OutString("Blue \r\n");
				speed = &duty[1];								// 75%
				GPIO_PORTF_DATA_R |= BLUE_LED;
				GPIO_PORTF_DATA_R &= ~(RED_LED | GREEN_LED);
				break;
			case 'g':
				UART0_OutString("Green \r\n");
				speed = &duty[2];								// 100%
				GPIO_PORTF_DATA_R |= GREEN_LED;
				GPIO_PORTF_DATA_R &= ~(BLUE_LED | RED_LED);
				break;
			case 'w':													// forward
				UART0_OutString("Forward \r\n");
				PWM0_RightMotor_Duty(*speed);			
				PWM1_LeftMotor_Duty(*speed);
				GPIO_PORTC_DATA_R &= ~0xC0;
				UART0_OutUDec(*speed);					// for debugging
				UART0_OutString("\r\n");
				break;
			case 'a':													// left turn
				UART0_OutString("Left Turn \r\n");
				PWM0_RightMotor_Duty(*speed);
				PWM1_LeftMotor_Duty(0);
				GPIO_PORTC_DATA_R &= ~0xC0;
				UART0_OutUDec(*speed);					// for debugging
				UART0_OutString("\r\n");
				break;
			case 's': 												// reverse
				UART0_OutString("Reverse \r\n");
			
				if(*speed == 25000){
					PWM0_RightMotor_Duty(*speed);		
					PWM1_LeftMotor_Duty(*speed);
					GPIO_PORTC_DATA_R |= 0xC0;
					UART0_OutUDec(*speed);				// for debugging
					UART0_OutString("\r\n");					
				}
				else if(*speed == 37500){
					PWM0_RightMotor_Duty(*speed*.25);		
					PWM1_LeftMotor_Duty(*speed*.25);
					GPIO_PORTC_DATA_R |= 0xC0;
					UART0_OutUDec(*speed);				// for debugging
					UART0_OutString("\r\n");	
				}
				else if(*speed == 49950){
					PWM0_RightMotor_Duty(*speed*.25);		
					PWM1_LeftMotor_Duty(*speed*.25);	
					GPIO_PORTC_DATA_R |= 0xC0;
					UART0_OutUDec(*speed);				// for debugging
					UART0_OutString("\r\n");
				}
				break;
			case 'd':													// right turn
				UART0_OutString("Right Turn \r\n");	
				PWM0_RightMotor_Duty(0);		
				PWM1_LeftMotor_Duty(*speed);
				GPIO_PORTC_DATA_R &= ~0xC0;
				UART0_OutUDec(*speed);					// for debugging
				UART0_OutString("\r\n");
				break;
			case 'q':													// stop
				UART0_OutString("Stop\r\n");
			
				if(*speed == 25000){
					PWM0_RightMotor_Duty(0);		
					PWM1_LeftMotor_Duty(0);
					GPIO_PORTC_DATA_R &= ~0xC0;
				}
				else if(*speed == 37500){
					PWM0_RightMotor_Duty(0);		
					PWM1_LeftMotor_Duty(0);	
					GPIO_PORTC_DATA_R &= ~0xC0;
				}
				else if(*speed == 49950){
					PWM0_RightMotor_Duty(0);		
					PWM1_LeftMotor_Duty(0);
					GPIO_PORTC_DATA_R &= ~0xC0;
				}
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

// Subroutine to initialize port A for motor direction
void GPIO_PORTC_Init(void){
	
	unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x04;							// activate clock for port D
  delay = SYSCTL_RCGC2_R;							// delay
	GPIO_PORTC_CR_R			= 0xC0;         // allow changes to PC6 and PC7
	GPIO_PORTC_AMSEL_R 	&= ~0xC0;  			// disable analog functionality on PC6 and PC7
	GPIO_PORTC_PCTL_R		&=~0xC0;				// GPIO clear bit PCTL
	GPIO_PORTC_DATA_R 	|=0xC0;					// Perform I/O on the ports
  GPIO_PORTC_DIR_R		= 0xC0;    			// make PC6 and PC7 outputs
  GPIO_PORTC_AFSEL_R 	&= ~0xC0;  			// disable alt funct on PC6 and PC7
  GPIO_PORTC_DEN_R		|= 0xC0;     		// enable digital I/O on PC6 and PC7
}
