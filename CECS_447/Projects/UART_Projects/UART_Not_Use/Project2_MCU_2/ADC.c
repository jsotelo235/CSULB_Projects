
#include "ADC.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

void ADC_Init(void){
	
		SYSCTL_RCGCGPIO_R			|= 0x10;									// Enable the port clock for PE3
		while((SYSCTL_RCGCGPIO_R&0x10) == 0){};					// delay
		GPIO_PORTE_DIR_R			&= ~0x10;									// make PE3 as input
		GPIO_PORTE_AFSEL_R		|= 0x10;									// enable alt funct on PE3
		GPIO_PORTE_DEN_R			&= ~0x10;									// disable digital I/O on PE3
		GPIO_PORTE_AMSEL_R		|= 0x10;									// enable analog fuct on PE3
	
		SYSCTL_RCGCADC_R			|= 0x01;									// activate ADC0
		ADC0_PC_R							 = 0x01;									// configure for 125k
		ADC0_SSPRI_R					 = 0x0123;								// SS3 is highest priority
		ADC0_ACTSS_R					&= ~0x08;									// disable Sample Sequencer 3
		ADC0_EMUX_R						&= ~0xF000;								// Sample Sequencer is software trigger
		ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0) + 4;	// clear SS3 field and set Ain4
		ADC0_SSCTL3_R					 = 0x0006;								// NO TS0 D0,yes IE0 END0
		ADC0_IM_R							&= ~0x08;									// disable SS3 interrupt
		ADC0_ACTSS_R					|= 0x08;									// enable sample sequencer 
}

uint32_t ADC_InSeq(void){
	uint32_t result;
	ADC0_PSSI_R = 0x08;																// initiate ss3
	while((ADC0_RIS_R&0x08) == 0){};									// wait for conversion done
	result = ADC0_SSFIFO3_R&0xFFF;										// read 12-bit result
	ADC0_ISC_R = 0x08;																// acknowledge completion
	return result;
}

