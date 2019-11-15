// MCU2_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Project 2: UART Part 2
// Software for MCU 2

// U1Rx (VCP receive) connected to PB0
// U1Tx (VCP transmit) connected to PB1

#include "ADCSWTrigger.h"
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "UART.h"
#include <stdint.h>

// LEDs
#define RED_LED			0x02 
#define BLUE_LED		0x04
#define GREEN_LED		0x08

void DisableInterrupts(void); 						// Disable interrupts
void EnableInterrupts(void);  						// Enable interrupts
long StartCritical (void);    						// previous I bit, disable interrupts
void EndCritical(long sr);    						// restore I bit to previous value
void WaitForInterrupt(void);  						// low power mode

void GPIO_PORTF_Init(void);								// Initialized Port F
void SysTick_Init(unsigned long period);	// SysTick Initialize routine interrupt
void SysTick_InitTimer(void);							// SysTick Init Timer
void SysTick_Wait10ms(unsigned long delay);
void SysTick_Wait(unsigned long delay);
void ToggleLED(void);											// Function to toggle Red LED
					
volatile unsigned long Counts = 0;				// flag to keep track of systick interrupt
volatile unsigned long ADCValue;					// keep track of ADC value
volatile char flag = 0;										// flag to keep track of when to exit led toogle

//short delay = 0;

// The digital number ADCvalue is a representation of the voltage on PE3
// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095
int main(void){
	
	unsigned char inChar;								// keep track of the transmitted char
	
	PLL_Init();                     		// 80 MHz
	UART1_Init();												// UART 1 and 0 Init routine
  ADC0_InitSeq3_Ch0();								// ADC initialization PE3/AIN0
	GPIO_PORTF_Init();									// Port F Init routine
	SysTick_Init(1333333);							// Initialize SysTick Timer
	
  while(1){
			
			inChar = UART1_InChar();
		
			if(inChar == 'r'){
				flag = 1;												// flag is set so we could toggle the led
				UART1_OutChar('b');							// send the char to MCU1 via MCU2 UART1 to indicate LED is off
			}
			else if(flag == 0){
				GPIO_PORTF_DATA_R &= ~RED_LED;	// Red LED is off
			}
			
			if(flag == 1){
				ToggleLED();										// function used to toggle LED
				
			}
  }
}

//*********************************
//	Toggle Red LED
//*********************************
void ToggleLED(){
	
	int i = 0;
	
	for(i =0; i< 5000000; i++);						// Delay 
	
	GPIO_PORTF_DATA_R ^= RED_LED;					// toogle LEDs
}

//*********************************
//	Port F GPIO & Interrupt Init
//*********************************
void GPIO_PORTF_Init(void){ 	
	volatile unsigned long delay; 
  SYSCTL_RCGC2_R |= 0x00000020;     		// F clock
  delay = SYSCTL_RCGC2_R;           		// delay    
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   		// unlock GPIO Port F
  GPIO_PORTF_CR_R 		|= 0xF;        		// allow changes to PF3, PF2, PF1 and PF0      
  GPIO_PORTF_AMSEL_R	&= ~0x0F;       	// disable analog function
  GPIO_PORTF_PCTL_R 	&= ~0x0000FFFF; 	// GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R 		|= 0x0E;        	// PF0 as input, PF3,PF2,and PF1 as output   
  GPIO_PORTF_AFSEL_R 	&= ~0x0F;       	// no alternate function
  GPIO_PORTF_PUR_R 		|= 0x01;        	// enable pullup resistors on PF0       
  GPIO_PORTF_DEN_R 		|= 0x0F;        	// enable digital pins PF3, PF2, PF1 and PF0

  // Interrupt Initialization
  GPIO_PORTF_IS_R			&= ~0x01;					//	PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R 		&= ~0x01;					//	PF0 is not both edges 
  GPIO_PORTF_IEV_R 		&= ~0x01;					//	PF0 falling edge event
  GPIO_PORTF_ICR_R 		= 0x01;						//	clear flags PF0
  GPIO_PORTF_IM_R 		|= 0x01;					//	arm interrupt on PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; //	priority 5
  NVIC_EN0_R = 0x40000000;							//	enable interrupt 30 in NVIC	
	EnableInterrupts();           				// (i) Clears the I bit
}

void GPIOPortF_Handler(void){
	
	GPIO_PORTF_ICR_R = 0x01;							// acknowledge;
	UART1_OutChar('o');										// send the char to MCU1 via MCU2 UART1 to indicate LED is off
	flag = 0;
}

//*********************************
//	SysTick Periodic Interrupt
//*********************************
void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;         																// disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;																// reload value
  NVIC_ST_CURRENT_R = 0;      																// any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; 	// priority 2
	NVIC_ST_CTRL_R = 0x07;																			// enable SysTick with core clock and interrupts
  EnableInterrupts();
}

void SysTick_Handler(void){
	ADCValue = ADC0_InSeq3();				// Read ADC value from PE3/Ain0
	UART1_OutUDec(ADCValue);				// transmit ADC value
}

