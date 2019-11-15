// SysTick.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize the SysTick module, wait at least a
// designated number of clock cycles, and wait approximately a multiple
// of 10 milliseconds using busy wait.  After a power-on-reset, the
// LM4F120 gets its clock from the 16 MHz precision internal oscillator,
// which can vary by +/- 1% at room temperature and +/- 3% across all
// temperature ranges.  You may increase precition later by adding PLL.  
// Modified by Dr. Min He: removed PLL.
// Daniel Valvano
// September 11, 2013

/* This example accompanies the books
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2013
   Volume 1, Program 4.7
   
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2013
   Program 2.11, Section 2.6

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

#include "SysTick.h"

#define NVIC_SYS_PRI3_R			(*((volatile unsigned long *) 0xE000ED20))	// SysTick Handlers 12 to 15 priority
#define NVIC_ST_CRTL_R			(*((volatile unsigned long *) 0xE000E010))
#define NVIC_ST_RELOAD_R		(*((volatile unsigned long *) 0xE000E014))
#define NVIC_ST_CURRENT_R		(*((volatile unsigned long *) 0xE000E018))

volatile unsigned long Counts = 0;

void SysTick_Init(unsigned long period){
	
	NVIC_ST_CRTL_R = 0;																								// 1) disable SysTick during setup
	NVIC_ST_RELOAD_R = period - 1;																		// 2) reload value to register
	NVIC_ST_CURRENT_R = 0;																						// 3) value to clear the counter
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x40000000;		// 4) Set to priority
	NVIC_ST_CRTL_R = 0x07;																						// 5) Enable SysTick with core clock
	
	EnableInterrupts();
}

void SysTick_Handler(void){
	Counts += 1;
}

