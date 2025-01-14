// Timer0.c
// Runs on LM4F120/TM4C123
// Use TIMER0 in 32-bit periodic mode to request interrupts at a periodic rate
// Daniel Valvano
// March 20, 2014


#include "tm4c123gh6pm.h"

void (*PeriodicTask)(void);   // user function

// ***************** Timer0_Init ****************
// Activate TIMER0 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
void Timer0_Init(void(*task)(void), unsigned long period){
  SYSCTL_RCGCTIMER_R |= 0x01;   											// 0) activate TIMER0
  PeriodicTask = task;          											// user function
  TIMER0_CTL_R = 0x00000000;   		 										// 1) disable TIMER0A during setup
  TIMER0_CFG_R = 0x00000000;    											// 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   											// 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = period-1;    											// 4) reload value
  TIMER0_TAPR_R = 0;            											// 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    											// 6) clear TIMER0A timeout flag
  TIMER0_IMR_R = 0x00000001;    											// 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x80000000; 	// 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<19;           											// 9) enable IRQ 19 in NVIC
  TIMER0_CTL_R = 0x00000001;    											// 10) enable TIMER0A
}

void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;									// acknowledge TIMER0A timeout
  (*PeriodicTask)();                									// execute user task
}



