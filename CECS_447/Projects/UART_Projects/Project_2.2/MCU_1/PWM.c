#include "tm4c123gh6pm.h"
#include <stdint.h>

// PF2/M1PWM6
// PF2 BLUE LED
void PWM1_PF2_Init(uint16_t period, uint16_t duty){
	
  SYSCTL_RCGCPWM_R			|= 0x02;																				// enable PWM1				          
  SYSCTL_RCGCGPIO_R 		|= 0x20; 																				// Port F clock
	
  while((SYSCTL_PRGPIO_R&0x20) == 0){};
		
  GPIO_PORTF_AFSEL_R 		|= 0x04;																				// activate alt function of PF2            
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF) + 0x00000500;			// PWM1
  GPIO_PORTF_AMSEL_R 		&= ~0x04;          															// disable analog funct on PF2
  GPIO_PORTF_DEN_R 			|= 0x04; 																				// enable I/O on PF2
		 
	SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV; 																// use PWM divider
  SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M; 																// clear PWM divider field
  SYSCTL_RCC_R += SYSCTL_RCC_PWMDIV_2;  																// configure for /2 divider
		
  PWM1_3_CTL_R 					 = 0;  																					// re-loading down-counting mode                   
  PWM1_3_GENA_R 				 = 0xC8;               													// low on LOAD, high on CMPA down  
  PWM1_3_LOAD_R					 = period - 1;																	// cycles needed to count down to 0
  PWM1_3_CMPA_R 			   = duty - 1;  																	// count value when output rises           
  PWM1_3_CTL_R 					|= 0x00000001;           												// update PWM Generator 3
  PWM1_ENABLE_R 			  |= 0x40;          															// enable PF2/M1PWM6
}


void PWM1_PF2_Duty(uint16_t duty){
  PWM1_3_CMPA_R = duty - 1;        																			// count value when output rises     
}
