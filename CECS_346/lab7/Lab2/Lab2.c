// ***** 0. Documentation Section *****
//Lab2 CECS 346
// Runs on LM4F120/TM4C123 
// Jose Sotelo
// February 3, 2017

// east/west red light connected to PB5
// east/west yellow light connected to PB4
// east/west green light connected to PB3
// north/south facing red light connected to PB2
// north/south facing yellow light connected to PB1
// north/south facing green light connected to PB0
// pedestrian detector connected to PE2 (1=pedestrian present)
// north/south car detector connected to PE1 (1=car present)
// east/west car detector connected to PE0 (1=car present)
// "walk" light connected to PF3 (built-in green LED)
// "don't walk" light connected to PF1 (built-in red LED)

// 1. Pre-processor Directives Section
// Constant declarations to access port registers using 
// symbolic names instead of addresses
#include "TExaS.h"

//Port B used to control LED switches
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
//#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

//Port E used for switches
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC)) 
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400)) 
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))	
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))	
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))	
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))	
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))	
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))	
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//	Function Prototypes
void PortB_Init(void);
void PortE_Init(void);
void EnableInterrupts(void);
void Delay(void);

// ***** 2. Global Declarations Section *****
unsigned long SW_1;  // input for PortE
unsigned long SW_2;  // input for PortE

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// ***** 3. Subroutines Section *****

int main(void){ 
  unsigned long LED;
	
	TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210,ScopeOff); // activate grader and set system clock to 80 MHz
	
	
	PortB_Init();
	PortE_Init();
	EnableInterrupts();
	
	GPIO_PORTB_DATA_R = 0x04;	// setting led to red
	
  while(1){
		
		SW_1 = GPIO_PORTE_DATA_R&0x01;	//declaring switch 1
		SW_2 = GPIO_PORTE_DATA_R&0x02;	//declaring switch 2
		
		Delay();	//100ms
		
	/*	if(SW_1 == 0x01)
		{
			GPIO_PORTB_DATA_R = 0x02;
			Delay();
		}
		
		if(SW_2 == 0x02)
		{
			if(GPIO_PORTB_DATA_R == 0x02)
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x02;
			}
		}
		
		if(SW_1 == 0x01)
		{
			GPIO_PORTB_DATA_R = 0x01;
			Delay();
		}
		
		if(SW_2 == 0x02)
		{
			if(GPIO_PORTB_DATA_R == 0x01 )
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x01;
			}
		}
		
		
		if(SW_1 == 0x01)
		{
			GPIO_PORTB_DATA_R = 0x04;
			Delay();
		}
		
		if(SW_2 == 0x02)
		{
			if(GPIO_PORTB_DATA_R == 0x04)
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x04;
			}
		}*/
		
		if(SW_1 == 1)
		{
			 if(GPIO_PORTB_DATA_R == 0x04){ 
				GPIO_PORTB_DATA_R = 0x02;  // LED is green
				Delay();
			 }
			 else if(GPIO_PORTB_DATA_R == 0x02)
			 {
				 GPIO_PORTB_DATA_R = 0x01;
				 Delay();
			 }
			 else if(GPIO_PORTB_DATA_R == 0x01)
			 {
				 GPIO_PORTB_DATA_R = 0x04;
				 Delay();
			 }
		}
	
		if(SW_2 == 2)
		{
			
			LED = GPIO_PORTB_DATA_R;
			GPIO_PORTB_DATA_R = 0;
			Delay();
			GPIO_PORTB_DATA_R = LED;
			Delay();
			/*if(GPIO_PORTB_DATA_R == 0x04)
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x04;
			}
			else if(GPIO_PORTB_DATA_R == 0x02)
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x02;
			}
			else if(GPIO_PORTB_DATA_R == 0x01)
			{
				GPIO_PORTB_DATA_R = 0x00;
				Delay();
				GPIO_PORTB_DATA_R = 0x01;
			}*/
		}
	}
}

void PortB_Init(void){ 
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x00000002;     // 1) B clock
  delay = SYSCTL_RCGC2_R;           // delay   
  //GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTB_CR_R = 0x07;           // allow changes to PF4-0       
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R = 0x07;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function
  //GPIO_PORTB_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTB_DEN_R = 0x07;          // 7) enable digital pins PF4-PF0        
}

void PortE_Init(void){ 
	
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) B clock
  delay = SYSCTL_RCGC2_R;           // delay   
  //GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTE_CR_R = 0x03;           // allow changes to PF4-0       
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function
  //GPIO_PORTB_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTE_DEN_R = 0x03;          // 7) enable digital pins PF4-PF0        
}

// Subroutine to wait 0.2 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){	
	
	unsigned long volatile time;
  time = 2*(727240/91) / 2; 
  while(time){
 		time--;
  }
}

