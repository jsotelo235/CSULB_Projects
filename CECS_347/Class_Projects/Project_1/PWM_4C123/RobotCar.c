// PWMtest.c
// Runs on TM4C123
// Jose Sotelo
// Jose Pacheco
// CECS 347
// Project 1
// October 23, 2017

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
#include "SysTick.h"
#include "PLL.h"
#include "PWM.h"

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//***********************************************************************
// Port A
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DR8R_R       (*((volatile unsigned long *)0x40004508))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
//***********************************************************************


//***********************************************************************
// Port F
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
	
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

uint16_t duty = 0;
unsigned char count = 0;

void PortF_Init(void);
void PortA_Init(void);
void DisableInterrupts(void);	// Disable interrupts
void EnableInterrupts(void);	// Enable interrupts
void WaitForInterrupt(void);  // low power mode


void PortA_Init(){
	
	unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x01;								// activate clock for port A
  delay = SYSCTL_RCGC2_R;

	GPIO_PORTA_CR_R			= 0x18;         	// allow changes to PA4 and PA3 0001 1000
	GPIO_PORTA_AMSEL_R 	&= ~0x18;  				// disable analog functionality on PA4 and PA3
	GPIO_PORTA_PCTL_R		&=~0x18;
	GPIO_PORTA_DATA_R 	|=0x18;
  GPIO_PORTA_DIR_R		= 0x18;    				// make PA4 and PA3 out
  GPIO_PORTA_AFSEL_R 	&= ~0x18;  				// disable alt funct on PA4 and PA3
  GPIO_PORTA_DEN_R		|= 0x18;     			// enable digital I/O on PA4 and PA3
}

// Color    LED(s) PortF
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08

void PortF_Init(void){
	
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     //	F clock
  delay = SYSCTL_RCGC2_R;           //	delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   //	unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           //	allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        //	disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   //	GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          //	PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        //	no alternate function
  GPIO_PORTF_PUR_R = 0x11;          //	enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          //	enable digital pins PF4-PF0    
  GPIO_PORTF_DATA_R = 0x02;         //	the robot starts stopped so led is red
    
    // Color    LED(s) PortF
    // red      R--    0x02
    // blue     --B    0x04
    // green    -G-    0x08
    
  // Interrupt Initialization
  GPIO_PORTF_IS_R &= ~0x11;						//	PF4,PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R &= ~0x11;					//	PF4,PF0 is not both edges 
  GPIO_PORTF_IEV_R &= ~0x11;					//	PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R = 0x11;						//	clear flags 4,0
  GPIO_PORTF_IM_R |= 0x11;						//	arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00400000; //	priority 2
  NVIC_EN0_R = 0x40000000;						//	enable interrupt 30 in NVIC
																			//	1000 0000 0000 0000 0000 0000 0000 0000
}

void GPIOPortF_Handler(void){
	
	SysTick_Wait10ms(30);
	
	//	SW2 is pressed
	if(GPIO_PORTF_RIS_R&0x01){
		
		GPIO_PORTF_ICR_R = 0x01;
		
		if(count % 4 == 0){
			
			GPIO_PORTF_DATA_R = 0x02;
		}
		
		if(GPIO_PORTA_DATA_R&0x18){
			
			GPIO_PORTA_DATA_R &=~0x18;
			GPIO_PORTF_DATA_R = 0x08;
		}
		else{
			GPIO_PORTA_DATA_R |= 0x18;
			GPIO_PORTF_DATA_R = 0x04;
		}
		
		duty = 40000 - duty;
	}
	
	// SW1 is pressed
	if(GPIO_PORTF_RIS_R&0x10){
		
		GPIO_PORTF_ICR_R = 0x10;
		
		count = count + 1;
		
		if(count % 4 == 0){
			duty = 2;
		}
		else if(count % 4 == 1){
			duty = 16000;
		}
		else if(count % 4 == 2){
			duty = 20000;
		}
		else if(count % 4 == 3){
			duty = 25000;
		}
		
		if(GPIO_PORTA_DATA_R&0x18){
			GPIO_PORTF_DATA_R = 0x04;
			duty = 40000 - duty;
		}
		else{
			GPIO_PORTF_DATA_R = 0x08;
		}
		
		if(count % 4 == 0){
			GPIO_PORTF_DATA_R = 0x02;
		}
	}
		
  PWM0MotorA_Duty(duty);
  PWM0MotorB_Duty(duty); 
}

int main(void){
	
  PLL_Init();                   // bus clock at 80 MHz
	SysTick_Init();
	PortF_Init();									// Port F
	PortA_Init();
  PWM0MotorA_Init(40000, duty);	// initialize PWM0, 1000 Hz, 0% duty
  PWM0MotorB_Init(40000, duty);	// initialize PWM0, 1000 Hz, 0% duty
		
  while(1){
    WaitForInterrupt();
  }
}
