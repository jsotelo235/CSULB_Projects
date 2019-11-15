//	CECS 346 Spring 2017
//	Project 3: Smart Stepper Car
//	Professor: Min He
//	Student: Jose Sotelo		ID: 013969681
//	Student: Jose Pacheco		ID: 013852057
//	May 12, 2017

#include <stdint.h>
#include "stepper.h"

// Port F Declarations
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))	
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
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define SYSCTL_RCGC2_GPIOF      0x00000020																	// port F Clock Gating Control

// Edge Trigger Port F
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))  // IRQ 0 to 31 Set Enable Register
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))  // IRQ 28 to 31 Priority Register

//Port D define
#define GPIO_PORTD_DIR_R        (*((volatile uint32_t *)0x40007400))
#define GPIO_PORTD_IS_R         (*((volatile uint32_t *)0x40007404))
#define GPIO_PORTD_IBE_R        (*((volatile uint32_t *)0x40007408))
#define GPIO_PORTD_IEV_R        (*((volatile uint32_t *)0x4000740C))
#define GPIO_PORTD_IM_R         (*((volatile uint32_t *)0x40007410))
#define GPIO_PORTD_MIS_R        (*((volatile uint32_t *)0x40007418))
#define GPIO_PORTD_ICR_R        (*((volatile uint32_t *)0x4000741C))
#define GPIO_PORTD_AFSEL_R      (*((volatile uint32_t *)0x40007420))
#define GPIO_PORTD_DR8R_R       (*((volatile uint32_t *)0x40007508))
#define GPIO_PORTD_DEN_R        (*((volatile uint32_t *)0x4000751C))
#define GPIO_PORTD_CR_R         (*((volatile uint32_t *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile uint32_t *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile uint32_t *)0x4000752C))
	
//NVIC define
#define NVIC_PRI0_R             (*((volatile uint32_t *)0xE000E400))	
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load values
		
#define T1ms 16000    // assumes using 16 MHz PIOSC (default setting for clock source)

#define moveForward  	0
#define moveBackwards 1	
#define Stop         	2

// Declarations Section
// Global Variables
uint8_t SW1, SW2;  // input from PF4
unsigned long Sensor;
unsigned long count_interrupts;
unsigned long ignore;

// global variable visible in Watch window of debugger
unsigned int i = 0;

// Initialized Function Prototypes
void PortF_Init(void);
void PortD_Init(void);
void Stepper_Init(void);

void SysTick_Init(void);        								// initialize SysTick timer
void EnableInterrupts(void);  									// Enable interrupts

void Stepper_Both(unsigned long delay, uint8_t direction);

// Turn car left
void Stepper_RW(unsigned long delay, uint8_t direction);

// Turn car right
void Stepper_LW(unsigned long delay, uint8_t direction);

int main(void){    
	
	Sensor = Stop;
	ignore = 0;
  PortF_Init();        					// Call initialization of port PF4 and PF0
	PortD_Init();									// Call initialization of ports PD         
	SysTick_Init();        				// initialize SysTick 
	Stepper_Init();								// motor initialize
	EnableInterrupts();
	
  while(1){
					
		if(Sensor == moveForward && ignore == 1)	// sw 1 starts the stepper motor and move forward 720 degrees
		{															
			for (i = 0; i < 3000; i++) {							// turn the motor clockwise 720 degrees
				
					Stepper_Both(10*T1ms, moveForward);	// output every 10ms				
			}
			
			for(i = 0; i < 2000; i++)								// turn left 90 degrees
			{
				Stepper_RW(10*T1ms, moveForward);
			}
			
			while(count_interrupts % 2 == 0){
				Stepper_Both(10*T1ms, moveForward);  // move until interrupt detected
			}
			
			while(count_interrupts % 2 == 1);
			
			for(i = 0; i < 3000; i++)							// move forward again
			{
				Stepper_Both(10*T1ms, moveForward);
				
			}
			count_interrupts = 0;
			Sensor = Stop;
			ignore = 0;
		}
		else if(Sensor == moveBackwards && ignore == 2)	// sw2 starts the stepper motor and moves backwards 720 degrees
		{
			for(i = 0; i < 3000; i++)											// moves backwards
			{
				Stepper_Both(10*T1ms, moveBackwards);
			}
			
			for(i = 0; i < 2000; i++)										// move 90 degrees backwards
			{
				Stepper_RW(10*T1ms, moveBackwards);
			}
			
			for(i = 0; i < 3000; i++)										// move forward again and stop
			{
					Stepper_Both(10*T1ms, moveBackwards);				
			}
			
			Sensor = Stop;
			ignore = 0;
			count_interrupts = 0;
		}
		
	}//end of while loop
}

// Subroutine to initialize port F pins for input\.,,,m,m and output
// PF4 and PF0 are input SW1 and SW2 respectively
void PortF_Init(void){ 
	
	// Port F Declarations and Sensor
  SYSCTL_RCGC2_R |= 0x00000020;			// 1) F clock
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R |= 0x11;					// allow changes to PF4 and PF0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x00;					// 5) PF4 and PF0   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R |= 0x11;					// enable pullup resistors on PF4 and PF0       
  GPIO_PORTF_DEN_R |= 0x11;					// 7) enable digital pins PF4-PF0
	
	// Interrupt initialization
  //FallingEdges = 0;             	// (b) initialize counter
  GPIO_PORTF_DIR_R &= ~0x11;    		// (c) make PF4 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x11;  		//     disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x11;     		//     enable digital I/O on PF4   
  GPIO_PORTF_PCTL_R &= ~0x000F0000; // 		 configure PF4 as GPIO
  GPIO_PORTF_AMSEL_R = 0;       		//     disable analog functionality on PF
  GPIO_PORTF_PUR_R |= 0x11;     		//     enable weak pull-up on PF4
  GPIO_PORTF_IS_R &= ~0x11;     		// (d) PF4 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x11;    		//     PF4 is not both edges
  GPIO_PORTF_IEV_R &= ~0x11;    		//     PF4 falling edge event
  GPIO_PORTF_ICR_R = 0x11;      		// (e) clear flag4
  GPIO_PORTF_IM_R |= 0x11;      		// (f) arm interrupt on PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x40000000;      		// (h) enable interrupt 30 in NVIC
	
}

// Port D is used for IR Sensor
void PortD_Init(void){
	
  SYSCTL_RCGC2_R |= 0x08;            // 1) activate port D
  GPIO_PORTD_AMSEL_R &= ~0x40;       // 3) disable analog functionality on PD6
  GPIO_PORTD_PCTL_R &= ~0x0F000000;  // 4) GPIO configure PD6 as GPIO
	GPIO_PORTD_DIR_R &= ~0x40;         // 6) make PD6 in
  GPIO_PORTD_AFSEL_R &= ~0x40;       // 6) disable alt funct on PD6
  GPIO_PORTD_DR8R_R |= 0x40;         // enable 8 mA drive
  GPIO_PORTD_DEN_R |= 0x40;          // 7) enable digital I/O on PD6
	
	//enable sensor as interrupt
	GPIO_PORTD_IS_R &= ~0x40;					// PD6 is edge-sensitive
  GPIO_PORTD_IBE_R |= 0x40;     		// PD6 is  both edges
  GPIO_PORTD_IEV_R &= ~0x40;    		// PD6 falling edge event
  GPIO_PORTD_ICR_R = 0x40;      		// clear flag4
  GPIO_PORTD_IM_R |= 0x40;      		// arm interrupt on PF6
  NVIC_PRI0_R = (NVIC_PRI0_R&0x1FFFFFFF)|0xA0000000; // (g) priority 5
  NVIC_EN0_R = 0x00000008;      		// (h) enable interrupt 3 in NVIC
	
	count_interrupts = 0;
	
}

// **************SysTick_Init*********************
void SysTick_Init(void){
	
  NVIC_ST_CTRL_R = 0;         					// disable SysTick during setup
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;	// reload value
  NVIC_ST_CURRENT_R = 0;      					// any write to current clears it
	
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC;
}

// global variable visible in Watch window of debugger
// increments at least once per button press
void GPIOPortF_Handler(void){
	
	SW1 = GPIO_PORTF_DATA_R&0x10;	// read PF4 into SW1
	SW2 = GPIO_PORTF_DATA_R&0x01;	// read PF0 into SW2
  GPIO_PORTF_ICR_R = 0x11;      // acknowledge flags
	
	if(SW1 == 0){									// if sw1 pressed move forward
		Sensor = moveForward;
		ignore = 1;
	}
	else if(SW2 == 0){
		Sensor = moveBackwards;			//if sw2 pressed moved in reverse
		ignore = 2;
	}
}

void GPIOPortD_Handler(void)
{
	GPIO_PORTD_ICR_R = 0x40;    // acknowledge flag
	
	if(Sensor == Stop){
		Sensor = moveForward;     // if already stopped, continue forward
	}
	else {
		Sensor = Stop;            // if moving, stop motors
	}
	count_interrupts += 1;			// update flag
}
