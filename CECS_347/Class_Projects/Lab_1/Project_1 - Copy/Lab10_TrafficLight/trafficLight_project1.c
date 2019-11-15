// ***** 0. Documentation Section *****
// Project 1 CECS 346
// Runs on	TM4C123 
// Jose Sotelo	013969681
// Jose Pacheco 013852057
// February 24, 2017

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

#include "SysTick.h"

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//Port B
#define	Light						        (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))

//Port E
#define sensor						      (*((volatile unsigned long *)0x400243FC)) 
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400)) 
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))	
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))	
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))	
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))	
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))	
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))	

//Port F
#define p_LED							      (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

	
// Linked data structure
struct State {
  unsigned long Out; 		//output
	unsigned long p_Out;	//out for pedestrain light
  unsigned long Time;		//time wait 
  unsigned long Next[8];	//next state
}; 

typedef const struct State TrafficLightState;
#define	goS					0
#define	waitS				1
#define	goW					2
#define	waitW				3
#define goP					4
#define wPOn1				5
#define wPOff1			6		
#define	wPOn2				7
#define	wPOff2			8
	
//declare traffic light FSM
TrafficLightState FSM[9] =
{
//out		//out //wait //No Car	    //Ped			//West		//West&Ped		 //South			//SouthPed	//South&West		//All
 {0x21, 0x02, 6000, {goS, 			waitS, 			waitW, 			waitW, 				goS,		 		goP, 				waitS, 				waitS}},	//goS				
 {0x22, 0x02, 2000, {goW, 			goP, 				goW, 				goW, 					goW, 				goP, 				goW, 					goW}},		//waitS					 							
 {0x0C, 0x02, 6000, {goW, 			waitW, 			waitW, 			waitW, 				goW, 		 		waitW, 	  	waitW,		 		waitW}},	//goW							
 {0x14, 0x02, 2000, {goS, 			goP, 				goS, 				goS, 					goS, 				goS, 				goS, 			 		goS}},		//waitW
 {0x24, 0x02, 500,  {goP, 			goP, 				wPOn1, 			wPOn1, 				wPOn1, 			wPOn1,			wPOn1, 				wPOn1}},	//goP
 {0x24, 0x02, 8000, {wPOff1, 	 	wPOff1, 	 	wPOff1, 		wPOff1, 			wPOff1, 		wPOff1, 		wPOff1, 			wPOff1}},	//waitPOn_1
 {0x24, 0x02, 500,  {wPOn2, 		wPOn2, 			wPOn2, 			wPOn2,				wPOn2, 			wPOn2,	 		wPOn2, 				wPOn2 }},	//waitPOff_1
 {0x24, 0x02, 8000, {wPOff2, 	 	wPOff2, 	 	wPOff2, 		wPOff2, 			wPOff2, 		wPOff2, 		wPOff2, 			wPOff2}},	//waitPOn_2
 {0x24, 0x02, 500,  {goS,		 	  goS, 				goW, 				goS, 					goS, 				goW, 				goW, 					goS}}			//waitPOff_2
};	

unsigned long currentState;
unsigned long Input;

//	Function Prototypes
void PortB_Init(void);
void PortE_Init(void);
void PortF_Init(void);

int main(void){ 

	PortB_Init();
	PortE_Init();
	PortF_Init();
	SysTick_Init();
	
	currentState = goS;
	
  while(1){
		
		p_LED = FSM[currentState].p_Out;
		Light	= FSM[currentState].Out;
		SysTick_Wait10ms(FSM[currentState].Time);
		Input	= sensor;
		currentState = FSM[currentState].Next[Input];
	}
}


void PortB_Init(void){
	
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x00000002;     // 1) B clock
  delay = SYSCTL_RCGC2_R;           // delay     
  GPIO_PORTB_CR_R = 0x3F;           //       
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R = 0x3F;          // 5) 
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function      
  GPIO_PORTB_DEN_R = 0x3F;          // 7)        
}

void PortE_Init(void){ 
	
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) B clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTE_CR_R = 0x07;           // allow changes to PE4-0       
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function     
  GPIO_PORTE_DEN_R = 0x07;          // 7) enable digital pins PF4-PF0        
}

void PortF_Init(void) {
	volatile unsigned long delay;
	
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay     
  GPIO_PORTF_CR_R = 0x0A;           // allow changes to PF3 & PF1     
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_DIR_R = 0x0A;          // 5) PF3 & PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function       
  GPIO_PORTF_DEN_R = 0x0A;          // 7) enable digital pins PF3 & PF1
}


