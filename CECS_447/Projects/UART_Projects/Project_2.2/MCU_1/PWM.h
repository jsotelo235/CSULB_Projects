// MCU1_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Project 2: UART Part 2

#include <stdint.h>

// Output on PF2/M1PWM6
void PWM1_PF2_Init(uint16_t period, uint16_t duty);

// change duty cycle of PF2
void PWM1_PF2_Duty(uint16_t duty);
