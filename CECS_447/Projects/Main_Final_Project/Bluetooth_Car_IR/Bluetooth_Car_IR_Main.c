// Bluetooth_Car_IR_Main.c
// Runs on TM4C123
// Jose Sotelo
// April 02, 2018
// Final Project

// U0Rx connected to PA0
// U0Tx connected to PA1

// U1Rx connected to PB0
// U1Tx connected to PB1

#include "PLL.h"
#include "UART.h"
#include "PWM.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>

// I/O Port bit-specific addressing is 
// used to access port data register
#define LED (*((volatile unsigned long *)0x40025038))		// PF3, PF2, and PF1 data registers
#define IR_SIGNAL (*((volatile unsigned long *)0x40007200))	// PD7 data register
#define DIRECTION (*((volatile unsigned long *)0x40006300))	// PC6 and PC7 data registers
	
// LEDs
#define RED_LED			0x02 
#define	BLUE_LED		0x04
#define	GREEN_LED		0x08

void SysTick_Init(unsigned long period);	// SysTick Initialization routine
void GPIO_PORTF_Init(void);					// Initialized Port F for LEDS 
void GPIO_PORTC_Init(void);					// Initialized Port C for motor direction
void GPIO_PORTD_Init(void);					// Initialized Port D for sending IR signal

// duty array contains the PWM duty
// pointer used to point to the next val in the duty array
uint16_t duty [] = {25000, 37500, 49950};	
uint16_t *speed = NULL;	

unsigned long IR_timer = 0;    		// counter tracking IR time

int main(void){
	
	char keyPressed = NULL;
	
  PLL_Init();						// PLL Init routine to 50MHz
	UART1_Init();					// UART1 Init routine for HC-05 bluetooth module communication
	GPIO_PORTF_Init();				// Port F Init routine for LEDs
	GPIO_PORTC_Init();				// Port C Init routine for motor directions
	GPIO_PORTD_Init();				// Port D Init routine for infrared signal transmission
	PWM_Motors_Init(50000, 0);		// Initialize PE4 and PE5 Module 0 PWM2 to 1000Hz, 0% duty
	SysTick_Init(657);        		// initialize SysTick timer to generate a 38KHz square wave
	
  while(1){
		keyPressed = UART1_InChar();
		
		switch(keyPressed){
			case 'r':
				UART1_OutString("50% Speed \r\n");					// Display current speed
				speed = &duty[0];									// 50%
				LED |= RED_LED;										// RED LED is on
				LED &= ~(BLUE_LED | GREEN_LED);						// Unnecessary LEDs are turned off
				UART1_OutString("\r\n");											
				break;
			case 'b':
				UART1_OutString("75% Speed \r\n");					// Display current speed			
				speed = &duty[1];									// 75%
				LED |= BLUE_LED;									// Blue LED is on
				LED &= ~(RED_LED | GREEN_LED);						// Unnecessary LEDs are turned off
				UART1_OutString("\r\n");												
				break;
			case 'g':
				UART1_OutString("100% Speed \r\n");					// Display current speed
				speed = &duty[2];									// 100%
				LED |= GREEN_LED;									// Green LED is on
				LED &= ~(BLUE_LED | RED_LED);						// Unnecessary LEDs are turned off
				UART1_OutString("\r\n");
				break;
			case 'w':												// Forward
				UART1_OutString("\r\n");												
				UART1_OutString("Forward \r\n");					// Display current action : Forward
				PWM0_RightMotor_Duty(*speed);						// PWM right motor speed
				PWM1_LeftMotor_Duty(*speed);						// PWM left motor speed
				DIRECTION &= ~0xC0;									// Motor direction pins
				UART1_OutUDec(*speed);								// Display current speed
				UART1_OutString("\r\n");												
				break;
			case 'a':												// Left Turn
				UART1_OutString("\r\n");												
				UART1_OutString("Left Turn \r\n");					// Display current action: Left Turn
				PWM0_RightMotor_Duty(*speed);						// PWM right motor speed
				PWM1_LeftMotor_Duty(0);								// PWM left motor speed
				DIRECTION &= ~0xC0;									// Motor direction pins
				UART1_OutUDec(*speed);								// Display current speed
				UART1_OutString("\r\n");												
				break;
			case 's':												// Reverse
				UART1_OutString("\r\n");													
				UART1_OutString("Reverse \r\n");					// Display current action: Reverse
			
				if(*speed == 25000){														
					PWM0_RightMotor_Duty(*speed);					// PWM right motor speed 
					PWM1_LeftMotor_Duty(*speed);					// PWM left motor speed
					DIRECTION |= 0xC0;								// Motor direction pins are set high for reverse action
					UART1_OutUDec(*speed);							// Display current speed	
					UART1_OutString("\r\n");											
				}
				else if(*speed == 37500){
					PWM0_RightMotor_Duty(*speed*.25);				// PWM right motor speed
					PWM1_LeftMotor_Duty(*speed*.25);				// PWM left motor speed
					DIRECTION |= 0xC0;								// Motor direction pins are set high for reverse action
					UART1_OutUDec(*speed);							// Display current speed	
					UART1_OutString("\r\n");											
				}
				else if(*speed == 49950){
					PWM0_RightMotor_Duty(*speed*.25);				// PWM right motor speed
					PWM1_LeftMotor_Duty(*speed*.25);				// PWM left motor speed
					DIRECTION |= 0xC0;								// Motor direction pins are set high for reverse action
					UART1_OutUDec(*speed);							// Display current speed
					UART1_OutString("\r\n");											
				}
				break;
			case 'd':												// Right Turn
				UART1_OutString("\r\n");												
				UART1_OutString("Right Turn \r\n");					// Right turn
				PWM0_RightMotor_Duty(0);							// PWM is set to off
				PWM1_LeftMotor_Duty(*speed);						// PWM left motor speed
				DIRECTION &= ~0xC0;									// Motor direction pins are set low for forward direction
				UART1_OutUDec(*speed);								// Display current speed
				UART1_OutString("\r\n");												
				break;
			case 'q':												// Stop
				UART1_OutString("\r\n");												
				UART1_OutString("Stop\r\n");						// Stop
				if(*speed == 25000){
					PWM0_RightMotor_Duty(0);						// PWM right motor is off
					PWM1_LeftMotor_Duty(0);							// PWM left motor is off
					DIRECTION &= ~0xC0;								// Motor direction pins are set low
				}
				else if(*speed == 37500){
					PWM0_RightMotor_Duty(0);						// PWM right motor is off
					PWM1_LeftMotor_Duty(0);							// PWM left motor is off
					DIRECTION &= ~0xC0;								// Motor direction pins are set low
				}
				else if(*speed == 49950){
					PWM0_RightMotor_Duty(0);						// PWM right motor is off
					PWM1_LeftMotor_Duty(0);							// PWM left motor is off
					DIRECTION &= ~0xC0;								// Motor direction pins are set low
				}
				break;
			case 'i':
				UART1_OutString("Sending IR signal \r\n");			// Message displaying IR signal transmission
				NVIC_ST_CTRL_R = 0x07;								// enable SysTick with core clock and interrupts
				break;
			default:
				PWM0_RightMotor_Duty(0);							// PWM right motor is off	
				PWM1_LeftMotor_Duty(0);								// PWM left motor is off
				DIRECTION &= ~0xC0;									// Motor direction pins are set low
				NVIC_ST_CTRL_R = 0x05;
				LED &= ~(RED_LED | BLUE_LED | GREEN_LED); 			// ALL LEDs off
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
  GPIO_PORTF_CR_R 		|= 0x0E;        // allow changes to PF3, PF2 and PF1     
  GPIO_PORTF_AMSEL_R	&= ~0x0E;       // disable analog function
  GPIO_PORTF_PCTL_R 	&= ~0x0000FFF0; // GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R 		|= 0x0E;        // PF4 and PF0 as input, PF3,PF2,and PF1 as outputs   
  GPIO_PORTF_AFSEL_R 	&= ~0x0E;       // no alternate function    
  GPIO_PORTF_DEN_R 		|= 0x0E;        // enable digital pins PF3, PF2 and PF1 
}

// Subroutine to initialize port A for motor direction
// PC6 (green wire)	h bridge connection A-1B
// PC7 (yellow wire) h bridge connection B-1B
void GPIO_PORTC_Init(void){
	
	unsigned long volatile delay;
	
  SYSCTL_RCGC2_R |= 0x04;					// activate clock for port C
  delay = SYSCTL_RCGC2_R;					// delay
  GPIO_PORTC_LOCK_R		 = 0x4C4F434B;		// Unlock GPIO PC6 and PC7
  GPIO_PORTC_CR_R		|= 0xC0;        	// allow changes to PC6 and PC7
  GPIO_PORTC_AMSEL_R 	&= ~0xC0;  			// disable analog functionality on PC6 and PC7
  GPIO_PORTC_PCTL_R		&=~0xFF000000;		// GPIO clear bit PCTL
  GPIO_PORTC_DIR_R		|= 0xC0;    		// make PC6 and PC7 outputs
  GPIO_PORTC_AFSEL_R 	&= ~0xC0;  			// disable alt funct on PC6 and PC7
  GPIO_PORTC_DEN_R		|= 0xC0;     		// enable digital I/O on PC6 and PC7
}

// Subroutine to initialized port D7 for IR signal transmission
void GPIO_PORTD_Init(void){
	
	unsigned long volatile delay;
	
  SYSCTL_RCGC2_R |= 0x08;					// activate clock for port D
  delay = SYSCTL_RCGC2_R;					// delay
  GPIO_PORTD_LOCK_R		 = 0x4C4F434B;		// Unlock GPIO Port D
  GPIO_PORTD_CR_R		|= 0x80;        	// allow changes to PD7
  GPIO_PORTD_AFSEL_R 	&= ~0x80;  			// disable alt funct on PD7
  GPIO_PORTD_PCTL_R		&= ~0xF0000000;		// GPIO clear bit PCTL
  GPIO_PORTD_AMSEL_R 	&= ~0x80;  			// disable analog functionality on PD7
  GPIO_PORTD_DIR_R		|= 0x80;    		// make PD7 as an output
  GPIO_PORTD_DEN_R		|= 0x80;     		// enable digital I/O on PD7                   
}

void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;         									// disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;									// reload value
  NVIC_ST_CURRENT_R = 0;      									// any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000;	// priority 2
  NVIC_ST_CTRL_R = 0x05;										// disable SysTick with core clock and interrupts
}

// SysTick Handler Interrupts
// performs IR protocol: JYU-447
// IR frequency: 38KHz
// Start pulse: 2ms high, 1ms low
// Logical 1: 1ms high, 500us low
// Logical 0: 500us highm 500us low
// Command: Start + 0'b10 + 0'b1010
void SysTick_Handler(void){
	
	if(IR_timer < 152){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 228 && IR_timer < 304){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 342 && IR_timer < 380){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 418 && IR_timer < 494){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 532 && IR_timer < 570){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 608 && IR_timer < 684){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 722 && IR_timer < 760){
		IR_SIGNAL ^= 0x80;
	}
	else if(IR_timer >= 1520){
		IR_timer = 0;
	}
	else{
		IR_SIGNAL = 0x00;
	}
	
	IR_timer++;
}
