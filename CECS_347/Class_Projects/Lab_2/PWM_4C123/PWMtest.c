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

#define SYSCTL_RCGC2_R        	(*((volatile unsigned long *)0x400FE108))
	
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

void PortB_Init(void);
void DisableInterrupts(void);	// Disable interrupts
void EnableInterrupts(void);	// Enable interrupts
void WaitForInterrupt(void);  // low power mode

uint16_t duty = 20000;

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
	
	NVIC_PRI0_R =	0x00002000;			// priority 1
	NVIC_EN0_R	= 0x00000002;				// Enable interrupt 2 in NVIC
	
	EnableInterrupts();
	
}

void GPIOPortB_Handler(void){
	
	if(GPIO_PORTB_RIS_R&0x01){  		// SW2 touch
		
    GPIO_PORTB_ICR_R = 0x01;  		// acknowledge flag0
		
    if(duty < 36000){
			duty = duty + 4000;
		}
		
    PWM6A_Duty(duty);    					// 10%
  }
	
  if(GPIO_PORTB_RIS_R&0x02){  							// SW1 touch
		
    GPIO_PORTB_ICR_R = 0x02;  							// acknowledge flag4
		
    if (duty >= 4000){
			duty = duty - 4000; 	// below 10% and the LED will turn off. 
		}

    PWM6A_Duty(duty);    										// 10%
  }
}

int main(void){
	DisableInterrupts();
  PLL_Init();                     // bus clock at 80 MHz
	EnableInterrupts();
	PortB_Init();										// Port B
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
