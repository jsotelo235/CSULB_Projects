// ADCSWTrigger.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0 SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result.
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

#include "tm4c123gh6pm.h"

// Initializes AIN1, AIN2, AIN9, and AIN8 sampling
// 125k max sampling
// SS2 triggering event: software trigger, busy-wait sampling
// SS@ 1st sample source: AIN1 (PE2)
// SS2 2nd sample source: AIN2 (PE1)
// SS2 3rd sample source: AIN9 (PE4)
// SS2 4th sample source: AIN8 (PE5)
// SS2 interrupts: enabled after 3rd sample but not promoted to controller
void ADC_Init1298(void){
  volatile unsigned long delay;
//  SYSCTL_RCGC0_R |= 0x00010000; // 1) activate ADC0 (legacy code)
  SYSCTL_RCGCADC_R |= 0x00000001; // 1) activate ADC0
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4; // 1) activate clock for Port E
  delay = SYSCTL_RCGCGPIO_R;      // 2) allow time for clock to stabilize
  delay = SYSCTL_RCGCGPIO_R;
  GPIO_PORTE_DIR_R &= ~0x36;      // 3) make PE1, PE2, PE4, and PE5 input
  GPIO_PORTE_AFSEL_R |= 0x36;     // 4) enable alternate function on PE1, PE2, PE4, and PE5
  GPIO_PORTE_DEN_R &= ~0x36;      // 5) disable digital I/O on PE1, PE2, PE4, and PE5
                                  // 5a) configure PE4 as ?? (skip this line because PCTL is for digital only)
  GPIO_PORTE_PCTL_R = GPIO_PORTE_PCTL_R&0xFF00FF0F;
  GPIO_PORTE_AMSEL_R |= 0x36;     // 6) enable analog functionality on PE1, PE2, PE4, and PE5
  ADC0_PC_R &= ~0xF;              // 8) clear max sample rate field
  ADC0_PC_R |= 0x1;               //    configure for 125K samples/sec
  ADC0_SSPRI_R = 0x3210;          // 9) Sequencer 3 is lowest priority
  ADC0_ACTSS_R &= ~0x0004;        // 10) disable sample sequencer 2
  ADC0_EMUX_R &= ~0x0F00;         // 11) specify how ADC will be trigger. seq2 is software trigger
  ADC0_SSMUX2_R = 0x1892;         // 12) set channels for SS2
  ADC0_SSCTL2_R = 0x6000;         // 13) no D0 END0 IE0 TS0 D1 END1 IE1 TS1 D2 TS2, yes END2 IE2
  ADC0_IM_R &= ~0x0004;           // 14) disable SS2 interrupts
  ADC0_ACTSS_R |= 0x0004;         // 15) enable sample sequencer 2
}


//------------ADC_In298------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: three 12-bit result of ADC conversions
// Samples AIN8, AIN9, and AIN2
// 125k max sampling
// software trigger, busy-wait sampling
// data returned by reference
// ain2 (PE1) 0 to 4095
// ain9 (PE4) 0 to 4095
// ain8 (PE5) 0 to 4095
// ain1 (PE2) 0 to 4095
void ADC_In1298(unsigned long *ain2, unsigned long *ain9, unsigned long *ain8, unsigned long *ain1){
  ADC0_PSSI_R = 0x0004;            // 1) initiate SS2
  while((ADC0_RIS_R&0x04)==0){};   // 2) wait for conversion done
  *ain2 = ADC0_SSFIFO2_R&0xFFF;    // 3A) read first result
  *ain9 = ADC0_SSFIFO2_R&0xFFF;    // 3B) read second result
  *ain8 = ADC0_SSFIFO2_R&0xFFF;    // 3C) read third result
	*ain1 = ADC0_SSFIFO2_R&0xFFF;
   ADC0_ISC_R = 0x0004;            // 4) acknowledge completion
}


