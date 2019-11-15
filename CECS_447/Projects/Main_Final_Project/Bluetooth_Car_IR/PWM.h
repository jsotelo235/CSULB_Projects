// PWM.h
// Runs on TM4C123
// Jose Sotelo
// April 02, 2018
// Final Project

#include <stdint.h>

// Output on PE4 and PE5/M0PWM4 and M0PWM5
void PWM_Motors_Init(uint16_t period, uint16_t duty);

// change duty cycle of PE4
void PWM0_RightMotor_Duty(uint16_t duty);

// change duty cycle of PE5
void PWM1_LeftMotor_Duty(uint16_t duty);
