// Wall_Follower_Robot.c
// Jose Sotelo
// Jose Pacheco
// December 11, 2017
// Final Project: Wall following robot car with IR distance densors and LCD display
// Runs on TM4C123

#include "ADCSWTrigger.h"
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "PWM.h"
#include "Nokia5110.h"

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

// Port C
#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile unsigned long *)0x40006400))
#define GPIO_PORTC_AFSEL_R      (*((volatile unsigned long *)0x40006420))
#define GPIO_PORTC_DR8R_R       (*((volatile unsigned long *)0x40006508))
#define GPIO_PORTC_DEN_R        (*((volatile unsigned long *)0x4000651C))
#define GPIO_PORTC_AMSEL_R      (*((volatile unsigned long *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile unsigned long *)0x4000652C))
#define GPIO_PORTC_CR_R         (*((volatile unsigned long *)0x40006524))
//***********************************************************************

//***********************************************************************
// Port F
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
	
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
		
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))
	
void PortF_Init(void);				// GPIO Port F init
void PortC_Init(void);				// GPIO Port C init
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
void wallFollower(void);			// wall follower function

// Ain1 (PE2) 0 to 4095 (potentiometer)
// Ain2 (PE1) 0 to 4095 (middle)
// Ain9 (PE4) 0 to 4095 (left)
// Ain8 (PE5) 0 to 4095 (right)
unsigned long ain1, ain2, ain8, ain9;

// Holds the distance calculated by ain2(front distance), ain9(left sensor) and ain8(right sensor)
unsigned short int frontDistance, leftDistance, rightDistance;

// Use to acknowledge the interrupt 
unsigned char flag = 0;

// Port C Init function
void PortC_Init(){
	
	unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x04;						// activate clock for port C
  delay = SYSCTL_RCGC2_R;

	GPIO_PORTC_CR_R			= 0x30;       // allow changes to PC5 and PC4 0011 0000
	GPIO_PORTC_AMSEL_R 	&= ~0x30;			// disable analog functionality on PC5 and PC4
	GPIO_PORTC_PCTL_R		&=~0x30;
	GPIO_PORTC_DATA_R 	|=0x30;
  GPIO_PORTC_DIR_R		= 0x30;    		// make PC5 and PC4 out
  GPIO_PORTC_AFSEL_R 	&= ~0x30;  		// disable alt funct on PC5 and PC4
  GPIO_PORTC_DEN_R		|= 0x30;			// enable digital I/O on PC5 and PC4
}

// Port F init function
void PortF_Init(void){
	
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     //	F clock
  delay = SYSCTL_RCGC2_R;           //	delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   //	unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           //	allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        //	disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   //	GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          //	PF4,PF0 inputs, PF3,PF2,PF1 outputs
  GPIO_PORTF_AFSEL_R = 0x00;        //	no alternate function
  GPIO_PORTF_PUR_R = 0x11;          //	enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          //	enable digital pins PF4-PF0    
  GPIO_PORTF_DATA_R = 0x02;         //	the robot starts stopped so led is red
        
  // Interrupt Initialization
  GPIO_PORTF_IS_R &= ~0x11;					//	PF4,PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R &= ~0x11;				//	PF4,PF0 is not both edges 
  GPIO_PORTF_IEV_R &= ~0x11;				//	PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R = 0x11;					//	clear flags 4,0
  GPIO_PORTF_IM_R |= 0x11;					//	arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; //	priority 5
  NVIC_EN0_R = 0x40000000;					//	enable interrupt 30 in NVIC
																		//	1000 0000 0000 0000 0000 0000 0000 0000
}

// GPIO_PortF Handler
// TODO: Handle Port F to start motors
// Color    LED(s) PortF
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
void GPIOPortF_Handler(void){
	
		GPIO_PORTF_ICR_R = 0x10;	// acknowledge the flag
		flag += 1;
}

// Median function
// helper function for ReadADCMedianFilter() but works for general use
unsigned long median(unsigned long u1, unsigned long u2, unsigned long u3){
unsigned long result;
  if(u1>u2)
    if(u2>u3)   result=u2;     // u1>u2,u2>u3       u1>u2>u3
      else
        if(u1>u3) result=u3;   // u1>u2,u3>u2,u1>u3 u1>u3>u2
        else      result=u1;   // u1>u2,u3>u2,u3>u1 u3>u1>u2
  else
    if(u3>u2)   result=u2;     // u2>u1,u3>u2       u3>u2>u1
      else
        if(u1>u3) result=u1;   // u2>u1,u2>u3,u1>u3 u2>u1>u3
        else      result=u3;   // u2>u1,u2>u3,u3>u1 u2>u3>u1
  return(result);
}

// This function samples AIN2 (PE1), AIN9 (PE4), AIN8 (PE5) and
// returns the results in the corresponding variables.  Some
// kind of filtering is required because the IR distance sensors
// output occasional erroneous spikes.  This is a median filter:
// y(n) = median(x(n), x(n-1), x(n-2))
// Assumes: ADC initialized by previously calling ADC_Init298()
void ReadADCMedianFilter(unsigned long *ain1, unsigned long *ain2, unsigned long *ain9, unsigned long *ain8){
  //                   x(n-2)        x(n-1)
  static unsigned long ain2oldest=0, ain2middle=0;
  static unsigned long ain9oldest=0, ain9middle=0;
  static unsigned long ain8oldest=0, ain8middle=0;
	static unsigned long ain1oldest=0, ain1middle=0;
	
  // save some memory; these do not need to be 'static'
  //            x(n)
  unsigned long ain2newest;
  unsigned long ain9newest;
  unsigned long ain8newest;
	unsigned long ain1newest;
  ADC_In1298(&ain1newest, &ain2newest, &ain9newest, &ain8newest); // sample  AIN1(PE2) AIN2(PE1), AIN9 (PE4), AIN8 (PE5)
  *ain2 = median(ain2newest, ain2middle, ain2oldest);
  *ain9 = median(ain9newest, ain9middle, ain9oldest);
  *ain8 = median(ain8newest, ain8middle, ain8oldest);
	*ain1 = median(ain1newest, ain1middle, ain1oldest);
  ain2oldest = ain2middle; ain9oldest = ain9middle; ain8oldest = ain8middle; ain1oldest = ain1middle;
  ain2middle = ain2newest; ain9middle = ain9newest; ain8middle = ain8newest; ain1middle = ain1newest;
}

void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;// reload value
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
                              // enable SysTick with core clock and interrupts
  NVIC_ST_CTRL_R = 0x07;
  EnableInterrupts();
}

// Interrupt service routine
void SysTick_Handler(void){
	ReadADCMedianFilter(&ain2, &ain9, &ain8, &ain1);
}

// The digital number ADCvalue is a representation of the voltage on PE2 
// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095

int main(void){
	
	unsigned long volatile delay;
	
  PLL_Init();                           	// 80 MHz
	Nokia5110_Init();												// initialize Nokia 5110 LCD
	Nokia5110_Clear();											// Clear the Nokia 5110 LCD
	PortC_Init();														// Initialize Port C
	PortF_Init();														// Initialize Port F
	SysTick_Init(1999999);									// Initialize SysTick Init 
  ADC_Init1298();													// ADC initialization for AIN2, AIN9, AIN8, AIN1
	
	//duty = (ain1 *(39999/4095));					// initialize duty cycle
	PWM0MotorL_Init(40000, ain1*9.76777);		// Initialize the left motor
	PWM0MotorR_Init(40000, ain1*9.76777);		// Initialize the right motor	 
	
  while(1){
		
		//******************************************
		//	Calibrating IR Sensors
		//	Used Inverse Regression Formula
		//	to find distance by measuring the ADC
		//	values from the three sensor
		//******************************************
		leftDistance = (-26.8310553) + (91376.4929)/(ain9);	// Left Distance
		frontDistance = (2.0421537) + (34306.07)/(ain2);		// Middle Distance
		rightDistance = (2.0521537) + (36840.39898)/(ain8); // Right Distance
		
		if(flag % 2 == 1){
			GPIO_PORTF_DATA_R = 0x08;	// Set the on board LED to be green
			
			if(leftDistance >= 60 ) { 
				PWM0MotorL_Duty(ain1*9.76777* 0);		// PWM is 0
				PWM0MotorR_Duty(ain1*9.76777*.7);		// PWM is decreased by 70%
			}
			
			if(rightDistance >= 60 ) {
				PWM0MotorL_Duty(ain1*9.76777* .7);	// PWM is decreased by 70%
				PWM0MotorR_Duty(ain1*9.76777*	0);		// PWM is 0			
			} 
			
			if(frontDistance >= 60) {
				PWM0MotorL_Duty(ain1*9.76777);			// PWM is full speed
				PWM0MotorR_Duty(ain1*9.76777);			// PWM is full speed
			}
			
			if(leftDistance <= 30) { 
				PWM0MotorL_Duty(ain1*9.76777*.9);		// PWM is decreased by 90%
				PWM0MotorR_Duty(ain1*9.76777*.3); 	// PWM is decreased by 30%
			}
			
			if(rightDistance <= 30) {
				PWM0MotorL_Duty(ain1*9.76777*.3);		// PWM is decreased by 30%
				PWM0MotorR_Duty(ain1*9.76777*.9); 	// PWM is decreased by 90%
			} 	
		}
		else if(flag % 2 == 0){
			GPIO_PORTF_DATA_R = 0x02;							// Set the on board LED to Red
			PWM0MotorL_Duty(0);										// PWM is 0 motors are off
			PWM0MotorR_Duty(0); 									// PWm is 0 motors are off
		}
		
		//**********************
		// NOKIA 5110 LCD
		//**********************
		Nokia5110_SetCursor(0,0);														// Set the cursor to be the 1st line
		Nokia5110_OutString("F Dis");												// Front Distance
		Nokia5110_SetCursor(5,0);														// Set the cursor
		Nokia5110_OutUDec(frontDistance);										// Display front distance
		Nokia5110_OutString("cm");													// String cm
		
		Nokia5110_SetCursor(0,1);														// Set the cursor to be the 2nd line
		Nokia5110_OutString("L Dis");												// Left Distance
		Nokia5110_SetCursor(5,1);														// Set cursor	
		Nokia5110_OutUDec(leftDistance);										// Display left distance
		Nokia5110_OutString("cm");													// String cm
		
		Nokia5110_SetCursor(0,2);														// Set the cursor to be the 3rd line
		Nokia5110_OutString("R Dis");												// Right Distance
		Nokia5110_SetCursor(5,2);														// Set the cursor
		Nokia5110_OutUDec(rightDistance);										// Display right distance
		Nokia5110_OutString("cm");													// String cm
		
		Nokia5110_SetCursor(0,4);														// Set the cursor to be the 4th line
		Nokia5110_OutString("PWM: ");												// String to Display on Nokia LCD
		Nokia5110_OutUDec((ain1* 9.76777)/39999 * 100);			// Display PMW percentage
  }
}
