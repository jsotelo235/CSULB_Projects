// ***** 0. Documentation Section *****
// Project 1 CECS 346
// Runs on	TM4C123 
// Jose Sotelo	ID: 013969681
// Jose Pacheco ID: 013852057
// March 3, 2017
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
#define Sensor						      (*((volatile unsigned long *)0x400243FC)) 
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400)) 
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))	
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))	
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))	
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))	
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))	
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))	

//Port F
#define P_LED							      (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))

//Function Prototypes
void PortB_Init(void);
void PortE_Init(void);
void PortF_Init(void);
	
// Linked data structure
struct State {
  unsigned long Out; 		//output
	unsigned long P_Out;	//out for pedestrain light
  unsigned long Time;		//time wait 
  unsigned long Next[8];	//next state
}; 

typedef const struct State TrafficLightState;
#define	goS					0			//go south
#define	waitS				1			//wait south
#define	goW					2			//go west
#define	waitW				3			//wait west
#define goP					4			//go pedestrain
#define wPOn1				5			//wait pedestrain on 1
#define wPOff1			6			//wait pedestrain off 1
#define	wPOn2				7			//wait pedestrain on 2
#define	wPOff2			8			//wait pedestrain off 2
	
//declare traffic light FSM
TrafficLightState FSM[9] =
{
//out		out   wait   No Car		   Ped			 W					Ped & W        S 				 Ped & S      S & W					 ALL
 {0x21, 0x08, 12, {goS, 			waitS, 			waitS, 			waitS, 				goS,		 		waitS, 			waitS, 				waitS}},	//goS				
 {0x11, 0x08, 4,  {goW, 			goP, 				goW, 				goP, 					goW, 				goP, 				goW, 					goW}},		//waitS					 							
 {0x0C, 0x08, 12, {goW, 			waitW, 			goW, 			  waitW, 				waitW, 		 	waitW, 	  	waitW,		 		waitW}},	//goW							
 {0x0A, 0x08, 4,  {goS, 			goP, 				goS, 				goP, 					goS, 				goP, 				goS, 			 		goP}},		//waitW
 {0x09, 0x02, 12, {goP, 			goP, 				wPOn1, 			wPOn1, 				wPOn1, 			wPOn1,			wPOn1, 				wPOn1}},	//goP
 {0x09, 0x08, 1,  {wPOff1, 	 	wPOff1, 	 	wPOff1, 		wPOff1, 			wPOff1, 		wPOff1, 		wPOff1, 			wPOff1}},	//waitPOn1
 {0x09, 0x00, 1,  {wPOn2, 		wPOn2, 			wPOn2, 			wPOn2,				wPOn2, 			wPOn2,	 		wPOn2, 				wPOn2 }},	//waitPOff1
 {0x09, 0x08, 1,  {wPOff2, 	 	wPOff2, 	 	wPOff2, 		wPOff2, 			wPOff2, 		wPOff2, 		wPOff2, 			wPOff2}},	//waitPOn2
 {0x09, 0x00, 1,  {goS,		 	  goW, 				goW, 				goW, 					goS, 				goS, 				goS, 					goS}}			//waitPOff2
};	

unsigned long currentState;		//keeps track of the current state the FSM is currently at
unsigned long Input;					//input that changes the current state of the FSM

int main(void){ 

	PortB_Init();			//function initializes the B ports
	PortE_Init();			//function initializes the E ports
	PortF_Init();			//function initializes the F ports
	SysTick_Init();		//SysTick module
	
	currentState = goS;	//initial current state set to go south
	
  while(1){
		
		Light	= FSM[currentState].Out;										//led lights up depending on the current state
		P_LED = FSM[currentState].P_Out;							 	 //pedestrain turn on output
		SysTick_Wait10ms(FSM[currentState].Time);				//wait function according to state
		Input	= Sensor;															 	 //Input is based on current state
		currentState = FSM[currentState].Next[Input];	//current state in the FSM depending on next state
	}
}

//Port B function definition
void PortB_Init(void){
	
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x02;     			  //1)B clock
  delay = SYSCTL_RCGC2_R;            //delay
	GPIO_PORTB_DIR_R		= 0x3F;				//2)PB0-PB5 activate
	GPIO_PORTB_DEN_R		= 0x3F;			 //3)Enable Digital I/0
  GPIO_PORTB_CR_R			= 0x3F;     //4)Activate port B   
  GPIO_PORTB_AFSEL_R	= 0x00;   //5) no alternate function 
	GPIO_PORTB_AMSEL_R	= 0x00;	 //6)Disable analog 
}

//Port E function definition
void PortE_Init(void){ 
	
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x10;     				//1)E clock
  delay = SYSCTL_RCGC2_R;           	//delay   
	GPIO_PORTE_DIR_R			= 0x00;				//2)Outputs
	GPIO_PORTE_DEN_R		 |= 0x07;       //3)enable digital pins PF4-PF0 
  GPIO_PORTE_CR_R			 |= 0x07;       //4)allow changes to PE4-0         
  GPIO_PORTE_AFSEL_R		= 0x00;       //6)no alternate function
	GPIO_PORTE_AMSEL_R		= 0x00;				//7)Disable analog
}

//Port F function definition
void PortF_Init(void) {
	
	volatile unsigned long delay;
	
	SYSCTL_RCGC2_R |= 0x20;     			//1)F clock
  delay = SYSCTL_RCGC2_R;           //delay
	GPIO_PORTF_DIR_R			= 0x0A;    	//2)PF3 & PF1 output 
  GPIO_PORTF_DEN_R			= 0x0A;     //3)enable digital pins PF3 & PF1	
  GPIO_PORTF_CR_R				= 0x0A;     //4)allow changes to PF3 & PF1       
  GPIO_PORTF_AFSEL_R		= 0x00;     //6)no alternate function
	GPIO_PORTF_AMSEL_R		= 0x00;     //3)disable analog function	
}


