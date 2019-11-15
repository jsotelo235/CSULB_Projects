// PWMtest.c
// Runs on TM4C123
// Jose Sotelo
// CECS 347
// Lab 2
// Combined software PWM with Hardware PWM
// October 9, 2017

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
  Program 6.7, section 6.3.2

 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
#include <stdint.h>
#include "PLL.h"
#include "PWM.h"

#define SYSCTL_RCGC2_R        	(*((volatile unsigned long *)0x400FE108))
	
//***********************************************************************************
// Port F
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
	
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
		
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))
//***********************************************************************************

//***********************************************************************************
// Port B
#define	GPIO_PORTB_DATA_R				(*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R				(*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R			(*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_R				(*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R				(*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CR_R					(*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R			(*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R				(*((volatile unsigned long *)0x4000552C))

#define GPIO_PORTB_IS_R         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_R        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_R        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_R         (*((volatile unsigned long *)0x40005410))	
#define GPIO_PORTB_RIS_R        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_MIS_R        (*((volatile unsigned long *)0x40005418))
#define GPIO_PORTB_ICR_R        (*((volatile unsigned long *)0x4000541C))

#define NVIC_PRI0_R             (*((volatile unsigned long *)0xE000E400))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
//**************************************************************************************

void PortB_Init(void);
void DisableInterrupts(void);	// Disable interrupts
void EnableInterrupts(void);	// Enable interrupts
void WaitForInterrupt(void);  // low power mode

uint16_t duty = 20000;

unsigned long H,L;

void Motor_Init(void){
	H = L = 40000;                // 50%
  NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = L-1;       // reload value for 500us
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
  NVIC_ST_CTRL_R = 0x00000007;  // enable with core clock and interrupts
	NVIC_EN0_R = 0x40000000;
}

void PortB_Init(void){
	
	volatile unsigned long delay;
	
	delay = SYSCTL_RCGC2_R;					// allow time for clock to stabilize
	SYSCTL_RCGC2_R			|= 0x02;		// Activate Port B clock
	GPIO_PORTB_DIR_R		&= ~0x03;		// Port B is used as input
	GPIO_PORTB_DEN_R		|= 0x03;		// Digital Enable I/O on PB0 and PB1 
	GPIO_PORTB_CR_R			|= 0x03;		// Allow changes to PB0 and PB1
	GPIO_PORTB_AFSEL_R 	&= ~0x03;		// Disable alt function
	GPIO_PORTB_AMSEL_R	&= ~0x03;		// Disable analog function
	GPIO_PORTB_PCTL_R		&= ~0x03;
	
	// Edge-Triggered Interrupt
	GPIO_PORTB_IS_R			&= ~0x03;		// PB0 and PB1 is edge-sensitive
	GPIO_PORTB_IBE_R		&= ~0x03;		// PB0 and PB1 is not both edges
	GPIO_PORTB_IEV_R		&= ~0x03;		// PB0 and PB1 falling edge event
	GPIO_PORTB_ICR_R		= 0x03;			// clear flag
	GPIO_PORTB_IM_R			|= 0x03;		// arm interrupt on PB0 and PB1
	
	NVIC_PRI0_R =	0x00002000;				// priority 1
	NVIC_EN0_R	= 0x00000002;				// Enable interrupt 2 in NVIC
	
	EnableInterrupts();
	
}

void GPIOPortB_Handler(void){
	
	if(GPIO_PORTB_RIS_R&0x01){  		// SW2 touch
		
    GPIO_PORTB_ICR_R = 0x01;  		// acknowledge flag0
		
    if(duty < 36000){
			duty = duty + 4000;
		}
		
    PWM6A_Duty(duty);    				// 10%
  }
	
  if(GPIO_PORTB_RIS_R&0x02){		// SW1 touch
		
    GPIO_PORTB_ICR_R = 0x02;		// acknowledge flag4
		
    if (duty >= 4000){
			duty = duty - 4000;				// below 10% and the LED will turn off. 
		}

    PWM6A_Duty(duty);						// 10%
  }
}

void SysTick_Handler(void){
		
  if(GPIO_PORTF_DATA_R&0x02){   // toggle PF1
    GPIO_PORTF_DATA_R &= ~0x02; // make PF1 low
    NVIC_ST_RELOAD_R = H-1;     // reload value for low phase
  }
	else if(!(GPIO_PORTF_DATA_R & 0x02 ) && (L < 72000)){
		GPIO_PORTF_DATA_R |= 0x02;  // make PF1 high
    NVIC_ST_RELOAD_R = L-1;     // reload value for high phase
	}
}

void Switch_Init(void){  
	
	unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x00000020;					// (a) activate clock for port F
  delay = SYSCTL_RCGC2_R;
	
  GPIO_PORTF_LOCK_R		= 0x4C4F434B;			// unlock GPIO Port F
  GPIO_PORTF_CR_R			= 0x1F;         	// allow changes to PF4,0
  GPIO_PORTF_DIR_R		= 0x02;    				// (c) make PF4 and PF0 in, PF1 out
  GPIO_PORTF_AFSEL_R 	&= ~0x1F;  				// disable alt funct on PF4,0
  GPIO_PORTF_DEN_R		|= 0x1F;     			// enable digital I/O on PF4,0
  GPIO_PORTF_PCTL_R 	&= ~0x000F000F; 	// configure PF4,0 as GPIO
  GPIO_PORTF_AMSEL_R 	&= ~0x1F;  				// disable analog functionality on PF4,0
	GPIO_PORTF_PUR_R 		|= 0x11;     			// enable weak pull-up on PF4,0
	
  GPIO_PORTF_IS_R 		&= ~0x11;     		// (d) PF4,PF0 is edge-sensitive
  GPIO_PORTF_IBE_R 		&= ~0x11;    			// PF4,PF0 is not both edges
  GPIO_PORTF_IEV_R 		&= ~0x11;    			// PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R 		= 0x11;      			// (e) clear flags 4,0
  GPIO_PORTF_IM_R 		|= 0x11;      		// (f) arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00400000; // (g) priority 2
  NVIC_EN0_R	= 0x40000000;      				// (h) enable interrupt 30 in NVIC
}

// L range: 8000,16000,24000,32000,40000,48000,56000,64000,72000
// power:   10%    20%   30%   40%   50%   60%   70%   80%   90%
void GPIOPortF_Handler(void){ // called on touch of either SW1 or SW2
	
  if(GPIO_PORTF_RIS_R&0x01){  // SW2 touch
    GPIO_PORTF_ICR_R = 0x01;  // acknowledge flag0
    if(L>8000) L = L-8000;    // slow down
  }
  if(GPIO_PORTF_RIS_R&0x10){  // SW1 touch
    GPIO_PORTF_ICR_R = 0x10;  // acknowledge flag4
    if(L<72000) L = L+8000;   // speed up
  }
  H = 80000-L; // constant period of 1ms, variable duty cycle
}

int main(void){
	DisableInterrupts();
  PLL_Init();           		// bus clock at 80 MHz
	Motor_Init();         		// output from PF, SysTick interrupts
  Switch_Init();        		// arm PF4, PF0 for falling edge interrupts
	EnableInterrupts();
	PortB_Init();							// Port B
  PWM6A_Init(40000, duty);	// initialize PWM0, 1000 Hz, 50% duty
	
  while(1){
    WaitForInterrupt();
  }
}
