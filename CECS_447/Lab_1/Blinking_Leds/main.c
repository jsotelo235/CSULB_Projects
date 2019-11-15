// main.c
// Runs on TM4C123
// Jose Sotelo
// Jose Pacheco
// CECS 447 Lab 1
// January 31, 2018

// LaunchPad built-in hardware
// SW1 left switch is negative logic PF4 on the Launchpad
// red LED connected to PF1 on the Launchpad
// blue LED connected to PF2 on the Launchpad
// green LED connected to PF3 on the Launchpad

#include "SysTick.h"

// 1. Pre-processor Directives Section
// Constant declarations to access port registers using 

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
	
//***********************************************************************
// Port F
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
	
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
		
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))
//***********************************************************************

// LEDs
 #define RED_LED		0x02 
 #define BLUE_LED		0x04
 #define GREEN_LED	0x08

// **********************************************************************
// Function Prototypes
void PORTF_Init(void);
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
//************************************************************************

unsigned char swPressed;			// Varianble used to keep track of when PF4 is pressed
unsigned char counter;				// Variable counter

// Subroutines Section
int main(void){    

	PORTF_Init();		// Port F Init
	SysTick_Init();	// initialize SysTick timer

  while(1){
		
		SysTick_Wait1sec(1);
		GPIO_PORTF_DATA_R = 0x00; // LED off
		SysTick_Wait1sec(1);
		
		if(swPressed % 4 == 0){
			GPIO_PORTF_DATA_R = RED_LED;
		}
		else if(swPressed % 4 == 1){
			GPIO_PORTF_DATA_R = BLUE_LED;
		}
		else if(swPressed % 4 == 2){
			GPIO_PORTF_DATA_R = GREEN_LED;
		}
		else if(swPressed % 4 == 3){
			
			counter+=1;
			
			if(counter % 3 == 0){
				GPIO_PORTF_DATA_R = GREEN_LED;
			}
			else if(counter % 3 == 1){
				GPIO_PORTF_DATA_R = RED_LED;	// DEFAULT color for mode 4
			}
			else if(counter %3 == 2){
				GPIO_PORTF_DATA_R = BLUE_LED;
			}
		}
  }
}

// Subroutine to initialize port F pins for input and output
void PORTF_Init(void){ 
	
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     //	F clock
  delay = SYSCTL_RCGC2_R;           //	delay     
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1E;           // allow changes to PF4, PF1, PF2 and PF3      
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x10;          // enable pullup resistors on PF4       
  GPIO_PORTF_DEN_R = 0x1E;          // 7) enable digital pins PF4, PF1, PF2 and PF3 

  // Interrupt Initialization
  GPIO_PORTF_IS_R &= ~0x10;					//	PF4 is edge-sensitive 
  GPIO_PORTF_IBE_R &= ~0x10;				//	PF4 is not both edges 
  GPIO_PORTF_IEV_R &= ~0x10;				//	PF4 falling edge event
  GPIO_PORTF_ICR_R = 0x10;					//	clear flags PF4
  GPIO_PORTF_IM_R |= 0x10;					//	arm interrupt on PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; //	priority 5
  NVIC_EN0_R = 0x40000000;					//	enable interrupt 30 in NVIC	
	EnableInterrupts();           		// (i) Clears the I bit
}

void GPIOPortF_Handler(void){
	
		GPIO_PORTF_ICR_R = 0x10;				// acknowledge the flag for PF4
		swPressed += 1;
}

// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06
