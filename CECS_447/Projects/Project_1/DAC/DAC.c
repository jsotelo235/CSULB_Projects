// DAC.c
// Runs on LM4F120 or TM4C123
// Jose Sotelo
// Jose Pacheco
// February 26, 2018

#include "DAC.h"
#include "tm4c123gh6pm.h"

//********************************************
// Initialize 6-bit DAC 
//********************************************
void DAC_Init(void){
	
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     	// A clock
  delay = SYSCTL_RCGC2_R;           	// delay  
  GPIO_PORTA_DIR_R |= 0xFC;          	// PA2-PA7 as outputs	
  GPIO_PORTA_CR_R |= 0xFC;           	// allow changes to PA2-PA7 
  GPIO_PORTA_AFSEL_R &= ~0xFC;        // no alternate function	
  GPIO_PORTA_AMSEL_R &= ~0xFC;        // disable analog function
  GPIO_PORTA_DEN_R |= 0xFC;          	// enable digital pins PA2-PA7
  GPIO_PORTA_PCTL_R &= ~0xFC ;   			// GPIO clear bit PCTL  
  GPIO_PORTA_PUR_R &= ~0xFC;          // disable pullup resistors on PA2-PA7        
}


//*******************************************
// output to DAC
//*******************************************
void DAC_Out(unsigned long data){
	
	GPIO_PORTA_DATA_R = data;
}
