// ADCTestMain.c
// Jose Sotelo
// Jose Pacheco
// November 2, 2017
// Project 2: Robot Car with Distance Sensors and LCD Display
// Runs on LM4F120/TM4C123
// This program periodically samples ADC channel 1 and stores the
// result to a global variable that can be accessed with the JTAG
// debugger and viewed with the variable watch feature.
// Daniel Valvano
// October 20, 2013

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2013

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

// input signal connected to PE2/AIN1

#include "ADCSWTrigger.h"
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "Nokia5110.h"
#include "PWM.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode


unsigned short int distance_ain2, distance_ain9, distance_ain8; 

// Ain1 (PE2) 0 to 4095
// Ain2 (PE1) 0 to 4095
// Ain9 (PE4) 0 to 4095
// Ain8 (PE5) 0 to 4095
unsigned long ain1, ain2, ain8, ain9;
uint16_t duty = 0;

void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;// reload value
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
                              // enable SysTick with core clock and interrupts
  NVIC_ST_CTRL_R = 0x07;
  EnableInterrupts();
}
// Interrupt service routine
void SysTick_Handler(void){
	
		ADC_In1298(&ain2, &ain9, &ain8, &ain1);
		PWM0MotorA_Duty(ain1*9.76776557);
		PWM0MotorB_Duty(ain1*9.76776557);
}

// The digital number ADCvalue is a representation of the voltage on PE2 
// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095

int main(void){
	unsigned long volatile delay;
	
  PLL_Init();                           // 80 MHz
	SysTick_Init(1999999);
	PWM0MotorA_Init(40000, (ain1*9.76776557));
	PWM0MotorB_Init(40000, (ain1*9.76776557));

	Nokia5110_Init();
	Nokia5110_Clear();
  ADC_Init1298();         // ADC initialization PE2/AIN1
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTF_DIR_R |= 0x04;             // make PF2 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x04;          // disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x04;             // enable digital I/O on PF2
                                        // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
	 
  while(1){
    GPIO_PORTF_DATA_R |= 0x04;          // profile
    GPIO_PORTF_DATA_R &= ~0x04;

		Nokia5110_SetCursor(0,4);
		Nokia5110_OutString("PWM: ");
		Nokia5110_OutUDec((ain1 * (9.76776557)/39999) * 100);
		
		/*Nokia5110_SetCursor(0,1);
		Nokia5110_OutString("Left : ");
		Nokia5110_OutUDec(ain9);
		
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("Right: ");
		Nokia5110_OutUDec(ain8);*/
		
		distance_ain2 = (2.0421537) + (34306.07)/(ain2);
		distance_ain9 = (1.01341579) + (33451.0609)/(ain9);
		distance_ain8 = (2.0521537) + (36840.39898)/(ain8);

		Nokia5110_SetCursor(0,0);
		Nokia5110_OutString("F Dis");
		Nokia5110_SetCursor(5,0);
		Nokia5110_OutUDec(distance_ain2);
		Nokia5110_OutString("cm");
		
		Nokia5110_SetCursor(0,1);
		Nokia5110_OutString("L Dis");
		Nokia5110_SetCursor(5,1);		
		Nokia5110_OutUDec(distance_ain9);
		Nokia5110_OutString("cm");
		
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("R Dis");
		Nokia5110_SetCursor(5,2);
		Nokia5110_OutUDec(distance_ain8);
		Nokia5110_OutString("cm");
		
    /*for(delay=0; delay<100000; delay++){};*/
  }
}
 

