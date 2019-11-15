// Timer0.h
// Runs on LM4F120/TM4C123
// Use Timer0 in 32-bit periodic mode to request interrupts at a periodic rate
// Daniel Valvano
// March 20, 2014


#ifndef __TIMER0INTS_H__ // do not include more than once
#define __TIMER0INTS_H__

// ***************** Timer0_Init ****************
// Activate Timer0 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (1/clockfreq)
// Outputs: none
void Timer0_Init(void(*task)(void), unsigned long period);

#endif // __TIMER2INTS_H__
