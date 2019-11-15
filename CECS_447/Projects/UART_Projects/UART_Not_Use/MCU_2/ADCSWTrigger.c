// ADCSWTrigger.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018

#include "tm4c123gh6pm.h"
#include <stdint.h>


void ADC0_InitSeq3_Ch0(void){ 
	
	volatile unsigned long delay;
	
	SYSCTL_RCGCADC_R			|= 0x01;									// activate ADC0
	SYSCTL_RCGCGPIO_R			|= SYSCTL_RCGCGPIO_R4;		// activate clock for Port E
	delay = SYSCTL_RCGCGPIO_R;											// delay
	
	GPIO_PORTE_DIR_R			&= ~0x08;									// make PE3 as input
	GPIO_PORTE_AFSEL_R		|= 0x08;									// enable alt funct on PE3
	GPIO_PORTE_DEN_R			&= ~0x08;									// disable digital I/O on PE3
	GPIO_PORTE_AMSEL_R		|= 0x08;									// enable analog fuct on PE3
	
	ADC0_PC_R							|= 0x1;										// configure for 125k sample rate		
	ADC0_SSPRI_R					 = 0x0123;								// SS3 is highest priority
	ADC0_ACTSS_R					&= ~0x08;									// disable Sample Sequencer 3
	ADC0_EMUX_R						&= ~0xF000;								// Sample Sequencer is software trigger
	ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0) + 0;	// clear SS3 field and set Ain0
	ADC0_SSCTL3_R					 = 0x0006;								// NO TS0 D0,yes IE0 END0
	ADC0_IM_R							&= ~0x08;									// disable SS3 interrupt
	ADC0_ACTSS_R					|= 0x08;									// enable sample sequencer 
}


unsigned long ADC0_InSeq3(void){
	
	unsigned long result;
	ADC0_PSSI_R = 0x08;															// initiate SS3
	while((ADC0_RIS_R&0x08) == 0){};								// wait for conversion done (SS3 raw interrupt)
	result = ADC0_SSFIFO3_R&0xFFF;									// read 12-bit result (0 to 11 bits)
	ADC0_ISC_R = 0x0008;														// acknowledge completion (clear sample sequencer interrupt)
	return result;
}
