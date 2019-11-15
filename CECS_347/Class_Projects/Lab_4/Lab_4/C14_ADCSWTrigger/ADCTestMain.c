// ADCTestMain.c
// Jose Sotelo
// Jose Pacheco
// November 2, 2017
// Lab 4
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

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
void DistanceTableLookUp(int);

volatile unsigned long ADCvalue;
unsigned short int distance;

typedef struct {int x; int y;} lookUp;

lookUp Table[13] = 
 {
	 {10, 3440},
	 {15, 2350},
	 {20, 1597},
	 {25, 1374},
	 {30, 1152},
	 {35, 961},
	 {40, 892},
	 {45, 832},
	 {50, 768},
	 {55, 668},
	 {60, 590},
	 {65, 521},
	 {70, 426}
 };
 
// The digital number ADCvalue is a representation of the voltage on PE4 
// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095

 int main(void){unsigned long volatile delay;
  PLL_Init();                           // 80 MHz
	Nokia5110_Init();
	Nokia5110_Clear();
  ADC0_InitSWTriggerSeq3_Ch1();         // ADC initialization PE2/AIN1
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
    ADCvalue = ADC0_InSeq3();
    GPIO_PORTF_DATA_R &= ~0x04;
		Nokia5110_SetCursor(0,0);
		Nokia5110_OutString("ADC:");
		Nokia5110_OutUDec(ADCvalue);
		distance = (2.0421537) + (34306.07)/(ADCvalue);
	

		Nokia5110_SetCursor(0,1);
		Nokia5110_OutString("Dist:");
		Nokia5110_OutUDec(distance);
		
		DistanceTableLookUp(distance);
    for(delay=0; delay<100000; delay++){};
  }
}
 
void DistanceTableLookUp(int dist){
	
	if(dist <= 12){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[0].x);
	}
	else if(dist <=16 && dist > 12){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[1].x);
	}
	else if(dist <= 21 && dist > 16){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[2].x);
	}
	else if(dist <= 26 && dist > 21){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[3].x);
	}
	else if(dist <= 33 && dist > 26){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[4].x);
	}
	else if(dist <= 39 && dist > 33){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[5].x);
	}
	else if(dist <= 43 && dist > 39){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[6].x);
	}
	else if(dist <= 45 && dist > 43){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[7].x);
	}
	else if(dist <= 47 && dist > 45){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[8].x);
	}
	else if(dist <= 50 && dist > 47){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[9].x);
	}
	else if(dist <= 52 && dist > 50){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[10].x);
	}
	else if(dist <= 55 && dist > 53){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[11].x);
	}
	else if(dist <= 66 && dist > 55){
		Nokia5110_SetCursor(0,2);
		Nokia5110_OutString("True");
		Nokia5110_OutUDec(Table[12].x);
	}

}
