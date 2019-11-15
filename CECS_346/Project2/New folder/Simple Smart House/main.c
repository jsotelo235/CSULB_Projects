//	CECS 346 Spring 2017
//	Project 2: A Simple Smart House
//	Professor: Min He
//	Student: Jose Sotelo		ID: 013969681
//	Student: Jose Pacheco	ID: 013852057
//	April 30, 2017

#include <stdint.h>
#include "stepper.h"

//	Port F Declarations
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

// Edge Trigger 
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))  // IRQ 0 to 31 Set Enable Register
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))  // IRQ 28 to 31 Priority Register

// SysTick
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))  // Sys. Handlers 12 to 15 Priority
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))  
	
#define T1ms 16000    // assumes using 16 MHz PIOSC (default setting for clock source)

// 2. Declarations Section
//   Global Variables
unsigned long SW1, SW2;  // input from PF4
unsigned long Out; // outputs to PF3,PF2,PF1 (multicolor LED)

// global variable visible in Watch window of debugger
// increments at least once per button press
volatile unsigned long FallingEdges = 0;
volatile unsigned long Counts = 0;
unsigned int i = 0;

// Initialized Function Prototypes
void PortF_Init(void);
void SysTick_Init(unsigned long period);        // initialize SysTick timer
void DisableInterrupts(void); 									// Disable interrupts
void EnableInterrupts(void);  									// Enable interrupts
long StartCritical (void);   										// previous I bit, disable interrupts
void EndCritical(long sr);    									// restore I bit to previous value
void WaitForInterrupt(void);  									// low power mode


int main(void){    
	
	//Counts = 0;
	
	// Function initialization
  PortF_Init();        					// Call initialization of port PF4 PF2
	EnableInterrupts();           // (i) Clears the I bit
	SysTick_Init(8000000);        // initialize SysTick 
	Stepper_Init();
		
  while(1){
		
		SW1 = GPIO_PORTF_DATA_R&0x10; 	// read PF4 into SW1
		SW2 = GPIO_PORTF_DATA_R&0x01;		// read PF0 into SW2
	

		GPIO_PORTF_DATA_R = 0x08;			// LED is Green
		WaitForInterrupt();
		
		/*
		The obstacle avoidance sensor detects an obstacle moving within a distance of 15 cm, 
		your embedded system will flash red LED and the stepper motor will 
		turn and point upwards.
		*/
		if(FallingEdges == 1)		// on board switch is been pressed
		{
			// turn clockwise 180 degrees
			for (i=0;i<1000; i++) {
				
				GPIO_PORTF_DATA_R = 0x02;
				Stepper_CW(10*T1ms);				// output every 10ms
				
				// check to see if if i is equal to 999
				// if so, set the flag and stops stepper motor rotation
				if(i == 999)
				{
					FallingEdges = 2;
				}
			}
			// end of clockwise rotation
		}// end of if statement that checks if falling edges is equal to 1
		
		
		/*
		The obstacle avoidance sensor detects an obstacle moving away from within a distance of 15 cm, 
		your embedded system will turn off the green LED, flash red LED until the distance is greater 
		than 15cm, stepper motor will turn and point back to downwards position.
		*/
		if(FallingEdges == 3)		// on board switch is been pressed
		{		
			// turn counter clockwise 180 degrees
			for (i=0;i<1000; i++) {
				
				GPIO_PORTF_DATA_R = 0x02;		// LED is Red
				Stepper_CCW(10*T1ms);   // output every 10ms
				
				// check to see if if i is equal to 999
				// if so, set the flag and stop the stepper motor
				if(i == 999)
				{
					FallingEdges = 0;	// set the flag to zero and wait until the flag becomes 1 again
				}
				
			}// end of counter-clockwise rotation
			
		} // end of if statement that checks to see if the flag is equal to 3
		
		if(FallingEdges == SW2)		// on board switch is been pressed
		{		
			// turn clockwise 180 degrees
			for (i=0;i<1000; i++) {
				
				GPIO_PORTF_DATA_R = 0x04;		// LED is Blue
				Stepper_CW(10*T1ms);   // output every 10ms			
			}// end of counter-clockwise rotation
			
			WaitForInterrupt();
			
			// turn counter clockwise 180 degrees
			for (i=0;i<1000; i++) {
				
				GPIO_PORTF_DATA_R = 0x04;		// LED is Blue
				Stepper_CCW(10*T1ms);   // output every 10ms				
			}// end of counter-clockwise rotation
			
			FallingEdges = 0;
		}
	}
}

// Subroutine to initialize port F pins for input and output
// PF4 and PF0 are input SW1 and SW2 respectively
// PF3,PF2,PF1 are outputs to the LED
// Inputs: None
// Outputs: None
// Notes: These five pins are connected to hardware on the LaunchPad
void PortF_Init(void){ 
	
	//add the edge trigger function
	//write a handler(delay)
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x00000020;     	// 1) F clock
  //delay = SYSCTL_RCGC2_R;          // delay
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0
	
	SYSCTL_RCGC2_R |= 0x00000020; // (a) activate clock for port F
  FallingEdges = 0;             // (b) initialize counter
  GPIO_PORTF_DIR_R &= ~0x10;    // (c) make PF4 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x10;  //     disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x10;     //     enable digital I/O on PF4   
  GPIO_PORTF_PCTL_R &= ~0x000F0000; // configure PF4 as GPIO
  GPIO_PORTF_AMSEL_R = 0;       //     disable analog functionality on PF
  GPIO_PORTF_PUR_R |= 0x10;     //     enable weak pull-up on PF4
  GPIO_PORTF_IS_R &= ~0x10;     // (d) PF4 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x10;    //     PF4 is not both edges
//  GPIO_PORTF_IEV_R &= ~0x10;    //     PF4 falling edge event
  GPIO_PORTF_ICR_R = 0x10;      // (e) clear flag4
  GPIO_PORTF_IM_R |= 0x10;      // (f) arm interrupt on PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x40000000;      // (h) enable interrupt 30 in NVIC
	
	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
	
}

// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 62.5ns (assuming 16 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
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
// Executed every 62.5ns*(period)
void SysTick_Handler(void){
  GPIO_PORTF_DATA_R ^= 0x04;       // toggle PF2
  Counts = Counts + 1;
}


// global variable visible in Watch window of debugger
// increments at least once per button press
void GPIOPortF_Handler(void){
  GPIO_PORTF_ICR_R = 0x10;      // acknowledge flag4
  FallingEdges = FallingEdges + 1;
}

// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06
