// MCU1_Main.c
// Runs on TM4C123
// Jose Sotelo and Jose Pacheco
// April 02, 2018
// Project 2: UART Part 2

#include <stdint.h>

// Output on PE4 and PE5/M0PWM4 and M0PWM5
void PWM_Motors_Init(uint16_t period, uint16_t duty);

// change duty cycle of PE4
void PWM0_RightMotor_Duty(uint16_t duty);

// change duty cycle of PE5
void PWM1_LeftMotor_Duty(uint16_t duty);
