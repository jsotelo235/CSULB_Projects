// Main.c
// Runs on LM4F120 or TM4C123
// Jose Sotelo
// Jose Pacheco
// March 6, 2018

#include "DAC.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"

// LEDs for debugging
#define RED_LED		0x02 
#define BLUE_LED	0x04
#define GREEN_LED	0x08

// Frequency Notes
// N = 6
// Calculation (16MHz)/(Note Frequency*2^N)
#define C_NOTE	959		
#define D_NOTE	854		
#define E_NOTE	761	
#define F_NOTE	719	  
#define G_NOTE	641 	
#define A_NOTE	571	
#define B_NOTE	509		

#define ROW (*((volatile unsigned long *) 0x4000703C))	// GPIO D DATA
#define COL (*((volatile unsigned long *) 0x400063C0))	// GPIO C DATA

// Sine Wave Table
const unsigned char sine_wave[64] = { 
32,35,38,41,44,47,50,52,
55,57,59,60,62,63,63,63,
63,63,63,63,62,60,59,57,
55,52,50,47,44,41,38,35,
32,29,26,23,20,17,14,12,
9,7,5,4,2,1,1,0,
0,0,1,1,2,4,5,7,
9,12,14,17,20,23,26,29
};

// Triangle Wave Table
const uint8_t triangle_wave [64] ={
32,34,36,38,40,42,43,45,
47,49,51,53,55,57,59,61,
62,61,59,57,55,53,51,49,
47,45,43,42,40,38,36,34,
32,30,28,26,24,22,21,19,
17,15,13,11,9,7,5,3,
2,3,5,7,9,11,13,15,
17,19,21,22,24,26,28,30
};

// Square Wave Table
const uint8_t square_wave [64] = {
0,63,63,63,63,63,63,63,
63,63,63,63,63,63,63,63,
63,63,63,63,63,63,63,63,
63,63,63,63,63,63,63,63,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0
};

// Function Prototypes
void PORTF_Init(void);
void DisableInterrupts(void); 									// Disable interrupts
void EnableInterrupts(void);  									// Enable interrupts
long StartCritical (void);   										// previous I bit, disable interrupts
void EndCritical(long sr);    									// restore I bit to previous value
void WaitForInterrupt(void);  									// low power mode

void SysTick_Init(unsigned long);								// SysTick
void GPIO_PORTF_Init(void);											// Port F used to toogle between modes
void Piano_Keys_Init(void);											// Piano Keys Init
void SysTickKeyFrequency(unsigned long period);	// NVIC_ST_RELOAD value
unsigned char Read_Piano_Key(void);							// Return the key pressed
void Delay10ms(void);														// wait 10ms for switches to stop bouncing

short swPressed = 0;														// Variable used to keep track of current button press

int main(void){ 
	
	DAC_Init();																		// Initialize Port A
	GPIO_PORTF_Init();														// Initialize Port F
	Piano_Keys_Init();														// Initialize Port C and D
	SysTick_Init(C_NOTE);													// Iniatialize each wave at 262 Hz
	EnableInterrupts();
	
  while(1){
		if(swPressed % 4 == 0){
			SysTickKeyFrequency(C_NOTE);	// 262 Hz
		}
		else if(swPressed % 4 == 3){
			GPIO_PORTF_DATA_R = RED_LED | GREEN_LED | BLUE_LED; // for debugging
			
			NVIC_ST_CTRL_R = 0x05;	// disable NVIC Interrupt
			
			switch(Read_Piano_Key()){
			case '1':
				SysTickKeyFrequency(C_NOTE);	// 262 Hz
				break;
			case '2':
				SysTickKeyFrequency(D_NOTE); // 294 Hz
				break;
			case '3':
				SysTickKeyFrequency(E_NOTE); // 330 Hz
				break;
			case '4':
				SysTickKeyFrequency(F_NOTE); // 349 Hz
				break;
			case '5':
				SysTickKeyFrequency(G_NOTE); // 392 Hz
				break;
			case '6':
				SysTickKeyFrequency(A_NOTE); // 440 Hz
				break;
			case '7':
				SysTickKeyFrequency(B_NOTE); // 494 Hz
				break;
			}
		}		
		Delay10ms();  // remove switch bounce 
	}          
}


// Initialize PF4 and Interrupt
void GPIO_PORTF_Init(){
	
	SYSCTL_RCGC2_R |= 0x00000020;												// activate the clock for port F
	GPIO_PORTF_LOCK_R = 0x4C4F434B;     								// 2) unlock GPIO Port F
	GPIO_PORTF_DIR_R |= 0x0E;           								// PF0 as input and PF3, PF3, and PF1 are outputs
	GPIO_PORTF_CR_R |= 0x0F;          									// allow changes to PF0
	GPIO_PORTF_AFSEL_R &= ~0x0F;        								// no alternate function
	GPIO_PORTF_AMSEL_R &= ~0x0F;        								// disable analog function
	GPIO_PORTF_DEN_R |= 0x0F;          									// enable digital pins PF0
	GPIO_PORTF_PCTL_R &= ~0x0F;   											// GPIO clear bit PCTL
	GPIO_PORTF_PUR_R |= 0x01;          									// enable pullup resistors on PF0 
        
        
	// Interrupt Initialization
  GPIO_PORTF_IS_R &= ~0x01;														//	PF0 is edge-sensitive 
  GPIO_PORTF_IBE_R &= ~0x01;													//	PF0 is not both edges 
  GPIO_PORTF_IEV_R &= ~0x01;													//	PF0 falling edge event
  GPIO_PORTF_ICR_R = 0x01;														//	clear flags PF0
  GPIO_PORTF_IM_R |= 0x01;														//	arm interrupt on PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000;	//	priority 5
  NVIC_EN0_R = 0x40000000;														//	enable interrupt 30 in NVIC
}

// ISR routine for edge-triggered interrupts on Port F
void GPIOPortF_Handler(void){
		
	GPIO_PORTF_ICR_R = 0x01;
	swPressed+=1;
}


// Piano Key Ports Initialization
void Piano_Keys_Init(void){
	
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x0000000c;     // C and D clock
  delay = SYSCTL_RCGC2_R;           // delay
	
	// Port C as outputs
	GPIO_PORTC_CR_R |= 0xF0;          // allow changes to PC4, PC5, PC6 and PC7   
  GPIO_PORTC_AMSEL_R &= ~0xF0;      // disable analog function
  GPIO_PORTC_PCTL_R &= ~0xF0;   		// GPIO clear bit PCTL  
  GPIO_PORTC_DIR_R |= 0xF0;         // PC4, PC5, PC6 and PC7 output   
  GPIO_PORTC_AFSEL_R &= ~0xF0;      // no alternate function      
  GPIO_PORTC_DEN_R |= 0xF0;         // enable digital pins PC4, PC5, PC6 and PC7
	
	// Port D as inputs
  GPIO_PORTD_CR_R |= 0x0F;          // allow changes to PD0, PD1, PD2 and PD3     
  GPIO_PORTD_AMSEL_R &= ~0x0F;      // disable analog function
  GPIO_PORTD_PCTL_R &= ~0x0F;   		// GPIO clear bit PCTL  
  GPIO_PORTD_DIR_R &= ~0x0F;        // PD0, PD1, PD2 and PD3 inputs   
  GPIO_PORTD_AFSEL_R &= ~0x0F;      // no alternate function      
  GPIO_PORTD_DEN_R |= 0x0F;         // enable digital pins PD0, PD1, PD2 and PD3
	GPIO_PORTD_PUR_R |= 0x0F;					// Pull up resistor on PD0, PD1, PD2 and PD3
}


// The function reads the key pressed
// from 4x4 matrix keypad.
// Port D is the rows (Inputs)
// Port C is the columns (Outputs)
unsigned char Read_Piano_Key(void){
	
	COL |=  0xF0;
	COL &= ~0x10;	// column 1
	
	if(ROW == 0x0E){
		return '1';
	}
	else if(ROW == 0x0D){
		return '2';
	}
	else if(ROW == 0x0B){
		return '3';
	}
	
	
	COL |=  0xF0;
	COL &= ~0x20;	// column 2
	
	if(ROW == 0x0E){
		return '4';
	}
	else if(ROW == 0x0D){
		return '5';
	}
	else if(ROW == 0x0B){
		return '6';
	}
	
	COL |=  0xF0;
	COL &= ~0x40;	// column 3
	
	if(ROW == 0x0E){
		return '7';
	}
	else
			return 0;
}

// Initialize SysTick
void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;						// disable SysTick during Set up    											
  NVIC_ST_RELOAD_R = period-1;	// reload value											
  NVIC_ST_CURRENT_R = 0;				// any write to current clears it
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x4000000;
	NVIC_ST_CTRL_R = 0x07;
}


// ISR Routine
void SysTick_Handler(void){
	
	// Variable Index used to step through the arrays.
	// The Static modifier for the variable Index
	// causes the allocation to be in permanent RAM
	// with a one-time initialization to 0
	static uint8_t Index = 0;
	
	switch(swPressed%5){
		case 0:
				GPIO_PORTF_DATA_R = RED_LED;		// for debugging
				DAC_Out(triangle_wave[Index] << 2);
			break;
		case 1:
				GPIO_PORTF_DATA_R = BLUE_LED;		// for debugging
				DAC_Out(sine_wave[Index] << 2);
			break;
		case 2:
				GPIO_PORTF_DATA_R = GREEN_LED;	// for debugging
				DAC_Out(square_wave[Index] << 2);
			break;
		case 3:
			// Piano mode
			DAC_Out(sine_wave[Index] << 2);
			break;
	}
	
	// Change the Index variable
	// once per SysTick
	// 0x3F = 63
	Index = (Index+1)&0x3F;
}

// Function used to play the frequency of a note
void SysTickKeyFrequency(unsigned long period){
	NVIC_ST_RELOAD_R = period-1;	// reload value
	NVIC_ST_CTRL_R = 0x07;
}

// wait 10ms for switches to stop bouncing
void Delay10ms(void){
	
	unsigned long volatile time;
  time = 14545;  // 10msec
  while(time){
		time--;
  }
}
