// PWMtest.c
// Runs on TM4C123
// Jose Sotelo
// CECS 347
// Lab 2
// October 7, 2017

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

#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DR8R_R       (*((volatile unsigned long *)0x40004508))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
	
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
	
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
	
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))

void PortB_Init(void);
void DisableInterrupts(void);	// Disable interrupts
void EnableInterrupts(void);	// Enable interrupts
void WaitForInterrupt(void);  // low power mode

uint16_t duty = 20000;

void PortF_Init(void){
	
unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x20;					// (a) activate clock for port F
  delay = SYSCTL_RCGC2_R;
	
  GPIO_PORTF_LOCK_R		= 0x4C4F434B;			// unlock GPIO Port F
  GPIO_PORTF_CR_R			= 0x11;         	// allow changes to PF4 and PF0
  GPIO_PORTF_DIR_R		= 0x00;    				// (c) make PF4 and PF0 in, PF1 out
  GPIO_PORTF_AFSEL_R 	&= ~0x11;  				// disable alt funct on PF4 and PF0
  GPIO_PORTF_DEN_R		|= 0x11;     			// enable digital I/O on PF4 and PF0
  GPIO_PORTF_PCTL_R 	&= ~0x000F000F; 	// configure PF4,0 as GPIO
  GPIO_PORTF_AMSEL_R 	&= ~0x11;  				// disable analog functionality on PF4 and PF0
	GPIO_PORTF_PUR_R 		|= 0x11;     			// enable weak pull-up on PF4,0
	
  GPIO_PORTF_IS_R 		&= ~0x11;     		// (d) PF4,PF0 is edge-sensitive
  GPIO_PORTF_IBE_R 		&= ~0x11;    			// PF4,PF0 is not both edges
  GPIO_PORTF_IEV_R 		&= ~0x11;    			// PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R 		= 0x11;      			// (e) clear flags 4,0
  GPIO_PORTF_IM_R 		|= 0x11;      		// (f) arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00400000; // (g) priority 2
  NVIC_EN0_R	= 0x40000000;      				// (h) enable interrupt 30 in NVIC
	
	EnableInterrupts();
	
}

void GPIOPortF_Handler(void){
	
	if(GPIO_PORTF_RIS_R&0x02){  		// SW1 touch
		
    GPIO_PORTF_ICR_R = 0x02;  		// acknowledge flag0
		
    if(duty < 36000){
			duty = duty + 4000;
		}
		
    PWM6A_Duty(duty);    					// 10%
  }
	
}

int main(void){
	DisableInterrupts();
  PLL_Init();                     // bus clock at 80 MHz
	EnableInterrupts();
	PortF_Init();										// Port B
  PWM6A_Init(40000, duty);       	// initialize PWM0, 1000 Hz, 50% duty
//  PWM0B_Init(40000, 10000);         // initialize PWM0, 1000 Hz, 25% duty
//  PWM0A_Duty(4000);    // 10%
//  PWM0A_Duty(10000);   // 25%
//  PWM0A_Duty(30000);   // 75%
//  PWM0B_Duty(4000);    // 10%
//  PWM0B_Duty(10000);   // 25%
//  PWM0B_Duty(30000);   // 75%


//  PWM0A_Init(4000, 2000);         // initialize PWM0, 10000 Hz, 50% duty
//  PWM0A_Init(1000, 900);          // initialize PWM0, 40000 Hz, 90% duty
//  PWM0A_Init(1000, 100);          // initialize PWM0, 40000 Hz, 10% duty
//  PWM0A_Init(40, 20);             // initialize PWM0, 1 MHz, 50% duty
//  PWM0B_Init(4000, 2000);         // initialize PWM0, 10000 Hz, 50% duty
//  PWM0B_Init(1000, 900);          // initialize PWM0, 40000 Hz, 90% duty
//  PWM0B_Init(1000, 100);          // initialize PWM0, 40000 Hz, 10% duty
//  PWM0B_Init(40, 20);             // initialize PWM0, 1 MHz, 50% duty
	
  while(1){
    WaitForInterrupt();
  }
}
