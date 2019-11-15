// Stepper.c
// Runs on LM4F120/TM4C123
// Provide functions that step the motor once clockwise, step
// once counterclockwise, and initialize the stepper motor
// interface.
// Daniel Valvano
// September 12, 2013
// Modified by Dr. Min He April 28, 2017

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2015
   Example 4.1, Programs 4.4, 4.5, and 4.6
   Hardware circuit diagram Figure 4.27

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
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

// change port to either a or b
// PD3 connected to driver for stepper motor coil A
// PD2 connected to driver for stepper motor coil A'
// PD1 connected to driver for stepper motor coil B
// PD0 connected to driver for stepper motor coil B'

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "systick.h"

//uint8_t is a 8 bit datatype
struct State{
  uint8_t Out;     // Output
  uint8_t Next[2]; // CW/CCW
};
typedef const struct State StateType;

#define clockwise 0        // Next index
#define counterclockwise 1 // Next index

#define FORWARD 4000
#define REVERSE 4000
#define TURN 500

#define STEPPER  (*((volatile uint32_t *)0x400053FC)) //port d data register with access the pins

//	State machine for both motor wheels
StateType bothWheels_fsm[4]={	
	{0x1C,{1,3}},
  {0x36,{2,0}},
  {0x63,{3,1}},
  {0xC1,{0,2}}
};

// State machine for right motor wheel
StateType rightWheel_fsm[4]={
	{0x10,{1,3}},
  {0x30,{2,0}},
  {0x60,{3,1}},
  {0xC0,{0,2}}
};

// State machine for left motor wheel
StateType leftWheel_fsm[4]={
  {0x0C,{1,3}},						
  {0x06,{2,0}},
  {0x03,{3,1}},
  {0x01,{0,2}}
};

unsigned char s; // current state
	
// Move 1.8 degrees clockwise, delay is the time to wait after each step
void Stepper_Both(unsigned long delay, uint8_t move){
	
  s = bothWheels_fsm[s].Next[move]; 
  STEPPER = bothWheels_fsm[s].Out; // step motor
  SysTick_Wait(delay);
}

// Move 1.8 degrees right motor, delay is wait after each step
void Stepper_RW(unsigned long delay, uint8_t move){
	
	s = rightWheel_fsm[s].Next[move]; 
  STEPPER = rightWheel_fsm[s].Out; // step motor
  SysTick_Wait(delay); 
}

// Move 1.8 degree left motor, delay is wait adter each step
void Stepper_LW(unsigned long delay, uint8_t move)
{
	s = leftWheel_fsm[s].Next[move]; // counter clock wise circular
  STEPPER = leftWheel_fsm[s].Out; // step motor
  SysTick_Wait(delay); 
	
}

// Initialize Stepper interface
void Stepper_Init(void){
	
  SYSCTL_RCGC2_R |= 0x02;            // 1) activate port B
  s = 0; 
  GPIO_PORTB_AMSEL_R &= ~0xFF;       // 3) disable analog functionality on PB7-0
  GPIO_PORTB_PCTL_R &= ~0xFFFFFFF;   // 4) GPIO configure PB7-0
  GPIO_PORTB_DIR_R |= 0xFF;          // 5) make PB7-0 out
  GPIO_PORTB_AFSEL_R &= ~0xFF;       // 6) disable alt funct on PB7-0
  GPIO_PORTB_DR8R_R |= 0xFF;         // enable 8 mA drive
  GPIO_PORTB_DEN_R |= 0xFF;          // 7) enable digital I/O on PB7-0
}
