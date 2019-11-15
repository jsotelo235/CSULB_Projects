#include "tm4c123gh6pm.h"
#include <stdint.h>


// PB6/M0PWM0
// PF2/M1PWM6
void PWM0A_Init(uint16_t period, uint16_t duty){
	
  SYSCTL_RCGCPWM_R			|= 0x02;								// enable PWM1 clock           
  SYSCTL_RCGCGPIO_R 		|= 0x02;            
  while((SYSCTL_PRGPIO_R&0x02) == 0){};
  GPIO_PORTB_AFSEL_R 		|= 0x40;           
  GPIO_PORTB_PCTL_R 		&= ~0x0F000000;     
  GPIO_PORTB_PCTL_R 		|= 0x04000000;
  GPIO_PORTB_AMSEL_R 		&= ~0x40;          
  GPIO_PORTB_DEN_R 			|= 0x40;             
  SYSCTL_RCC_R 					 = 0x00100000 | (SYSCTL_RCC_R & (~0x000E0000));   
  PWM0_0_CTL_R 					 = 0;                     
  PWM0_0_GENA_R 				 = 0xC8;                 
 
		
  PWM0_0_LOAD_R					 = period - 1;		// 
  PWM0_0_CMPA_R 			   = duty - 1;             
  PWM0_0_CTL_R 					|= 0x00000001;           
  PWM0_ENABLE_R 			  |= 0x00000001;          
}


void PWM0A_Duty(uint16_t duty){
  PWM0_0_CMPA_R = duty - 1;             
}
