// EdgeInterrupt.c
// Runs on LM4F120 or TM4C123
// Request an interrupt on the falling edge of PF4 (when the user
// button is pressed) and increment a counter in the interrupt.  Note
// that button bouncing is not addressed.
// Daniel Valvano
// September 14, 2013

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers"
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2013
   Volume 1, Program 9.4
   
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2013
   Volume 2, Program 5.6, Section 5.5

 Copyright 2013 by Jonathan W. Valvano, valvano@mail.utexas.edu
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

// user button connected to PF4 (increment counter on falling edge)

#include "EdgeInterrupts.h"

#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))	// IRQ
#define NVIC_PRI1_R             (*((volatile unsigned long *)0xE000E404))	// IRQ set bit 7-5
	
#define GPIO_PORTE_IS_R         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_R        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_R        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_R         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_R        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_ICR_R        (*((volatile unsigned long *)0x4002441C))
		
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400)) 
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))	
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))	
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))	
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))	
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))	
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))	
	
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

// increments at least once per button press
volatile unsigned long FallingEdges = 0;

void EdgeCounter_Init(void){
	
  SYSCTL_RCGC2_R |= 0x00000010; // (a) activate clock for port E
	
  FallingEdges = 0;             // (b) initialize counter
	
	GPIO_PORTE_DEN_R		 |= 0x07;  	// 1)enable digital pins PE2-PE0
	GPIO_PORTE_AFSEL_R		= 0x00;   // 2)no alternate function
	GPIO_PORTE_DIR_R			= 0x00;		// 3) Only using inputs
	GPIO_PORTE_AMSEL_R		= 0x00;		// 4)Disable analog
  GPIO_PORTE_CR_R			 |= 0x07;  	// 5)allow changes to PE4-PE0         
	
  GPIO_PORTE_IS_R 	&= ~0x07;			// (6) PE2-PE0 is edge-triggering
  GPIO_PORTE_IBE_R	|= ~0x07;			// (7) Setting the Interrupt Both Edges to only be on rising edge
  GPIO_PORTE_IEV_R	|= 0x07;			// (8) Setting Interrupt Event
	GPIO_PORTE_IM_R		|= 0x07;      // (9) Set the arm bit interrupt
	GPIO_PORTE_ICR_R	= 0x07;				// (e) Clear the flag
	
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFFAF)|0x000000A0; // priority 5
  NVIC_EN0_R = 0x10;							// (h) enable interrupt 4 in NVIC
  EnableInterrupts();           	// (i) Clears the I bit
}

void GPIOPortE_Handler(void){
	
  GPIO_PORTE_ICR_R = 0x07;// acknowledge flag4
  FallingEdges = FallingEdges + 1;
}

