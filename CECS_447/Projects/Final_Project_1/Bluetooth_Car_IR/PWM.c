#include "tm4c123gh6pm.h"
#include <stdint.h>

// PB6/M0PWM0 Right Motor PWM
// PB7/M0PWM1 Left Motor PWM
void PWM_Motors_Init(uint16_t period, uint16_t duty){
	
  SYSCTL_RCGCPWM_R			|= 0x01;																				// enable PWM0				          
  SYSCTL_RCGCGPIO_R 		|= 0x10; 																				// Port E clock
	
  while((SYSCTL_PRGPIO_R&0x10) == 0){};
		
  GPIO_PORTE_AFSEL_R 		|= 0x30;																				// activate alt function of PE4 and PE5          
  GPIO_PORTE_PCTL_R = (GPIO_PORTF_PCTL_R&0xFF00FFFF) + 0x00440000;			// M0PWM0 (control module) PE4 and PE5
  GPIO_PORTE_AMSEL_R 		&= ~0x30;          															// disable analog funct on PE4 and PE5
  GPIO_PORTE_DEN_R 			|= 0x30; 																				// enable I/O on PB6
		 
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV; 																// use PWM divider
  SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M; 																// clear PWM divider field
  SYSCTL_RCC_R += SYSCTL_RCC_PWMDIV_2;  																// configure for /2 divider
		
  PWM0_2_CTL_R 					 = 0;  																					// re-loading down-counting mode                   
  PWM0_2_GENA_R 				 = 0xC8;               													// low on LOAD, high on CMPA down PE4
	PWM0_2_GENB_R 				 = 0xC08;               												// low on LOAD, high on CMPA down PE5
		
  PWM0_2_LOAD_R					 = period - 1;																	// cycles needed to count down to 0
  PWM0_2_CMPA_R 			   = duty - 1;  																	// count value when output rises 
	PWM0_2_CMPB_R					 = duty - 1;
  PWM0_2_CTL_R 					|= 0x00000001;           												// update PWM Generator 0
  PWM0_ENABLE_R 			  |= 0x30;          															// enable PE4/M0PWM4 and PE5/M0PWM5
}


void PWM0_RightMotor_Duty(uint16_t duty){
  PWM0_2_CMPA_R = duty - 1;        																			// count value when output rises     
}

void PWM1_LeftMotor_Duty(uint16_t duty){
  PWM0_2_CMPB_R = duty - 1;        																			// count value when output rises     
}
