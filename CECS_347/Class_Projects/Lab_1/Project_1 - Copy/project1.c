// ***** 1. Pre-processor Directives Section *****
#include "pll.h"
#define LIGHT       			(*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
	
#define SENSOR					(*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
	
#define P_LED				    (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))

#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))



// FUNCTION PROTOTYPES: Each subroutine defined
void PortB_Init(void); 
void PortE_init(void); 
void PortF_Init(void);  
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void WaitForInterrupt(void);  // low power mode
volatile unsigned long Counts = 0;
void SysTick_Init(unsigned long pr);

unsigned long flag; 
unsigned long current_s; //index to current state
unsigned long input;
// ***** 3. Subroutines Section *****
void PortB_Init(void)
{
	volatile unsigned long delay;
	delay = SYSCTL_RCGC2_R;		    // allow time for clock to stabilize
	SYSCTL_RCGC2_R  	|= 0x02; 	// 1) Activate Port-B
	GPIO_PORTB_DIR_R   = 0x3F;  	// 2) PB5,PB4,PB3,PB2,PB1, PB0 are outputs
	GPIO_PORTB_DEN_R   = 0x3F; 	    // 3) Digital enable digital I/O 
	GPIO_PORTB_CR_R    = 0x3F; 	    // 4) Allow changes to PB2, PB-1, PB-0
	GPIO_PORTB_AFSEL_R = 0x00; 	    // 5) Disable alt function 
	GPIO_PORTB_AMSEL_R = 0x00;	    // 6) Disable analog function 
}
#define GPIO_PORTE_IS_R         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_R        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_R        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_R         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_R        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_MIS_R        (*((volatile unsigned long *)0x40024418))
#define GPIO_PORTE_ICR_R        (*((volatile unsigned long *)0x4002441C))
#define NVIC_PRI1_R             (*((volatile unsigned long *)0xE000E404))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))

void PortE_Init(void)
{
	volatile unsigned long delay;
	delay = SYSCTL_RCGC2_R;         // allow time for clock to stabilize
	SYSCTL_RCGC2_R     |= 0x10;     // 1) Activate Port-E
	GPIO_PORTE_DIR_R    = 0x00;     // 2) PE will be used as input switches (No Outputs) 
	GPIO_PORTE_DEN_R   |= 0x07;     // 3) Digital enable digital I/O on PE2-0
	GPIO_PORTE_CR_R    |= 0x07;     // 4) Allow changes to PE2-0 
	GPIO_PORTE_AFSEL_R  = 0x00;     // 5) Disable alt function
	GPIO_PORTE_AMSEL_R  = 0x00;	    // 6) Disable analog funtion 
	
	
	// Edge-Triggered Interrupt Init 
    GPIO_PORTE_IS_R     &= ~0x07;   // (d) PE2-0 is edge-sensitive
    GPIO_PORTE_IBE_R    &= ~0x07;   //     PE2-0 is not both edges
    GPIO_PORTE_IEV_R    |= 0x07;    //     PE2-0 falling edge event
    GPIO_PORTE_ICR_R    = 0x07;     // (e) clear flag
    GPIO_PORTE_IM_R     |= 0x07;    // (f) arm interrupt on PE2-0
    NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFFAF)|0x000000A0; // (g) priority 5
    NVIC_EN0_R  = 0x00000010;       // (h) enable interrupt 30 in NVIC
    EnableInterrupts();             // (i) Clears the I bit
}
void PortF_Init(void)
{
	volatile unsigned long delay;
	delay = SYSCTL_RCGC2_R;    	    // allow time for clock to stabilize
	SYSCTL_RCGC2_R  	|= 0x20; 	// 1) Activate Port-F
	GPIO_PORTF_DIR_R   = 0x0A;  	// 2) PF3 & PF1 will be used as output LEDS 
	GPIO_PORTF_DEN_R   = 0x0A;  	// 3) Digital enable digital I/O 
	GPIO_PORTF_CR_R    = 0x0A; 	    // 4) Allow changes 
	GPIO_PORTF_AFSEL_R = 0x00; 	    // 5) Disable alt function
	GPIO_PORTF_AMSEL_R = 0x00;	    // 6) Disable analog funtion 
}
struct State 
{
	unsigned long T_Out;    //  PB5-3: N/S Lights	| PB2-0: E/W Lights 
	unsigned long P_Out;    //  PF3: Green Walk     | PF1: Don't Walk
	unsigned long Time;
	unsigned long Next[8]; 	
    //  0x01 means pedestrians and no cars,
    //  0x02 means cars on E/W and no pedestrians,	
    //  0x03 means pedestrians and cars on E/W,
    //  0x04 means cars on N/S and no pedestrians,
    //  0x05 means pedestrians and cars on N/S,
    //  0x06 means cars on N/S and E/W,
    //  0x07 means pedestrians and cars on E/W and N/S,
 };
typedef const struct State STyp; // Makes code more portable...
#define goN   		0
#define waitN 		1
#define goE   		2
#define waitE 		3
#define goP			4 
#define	waitPon1	5
#define	waitPoff1	6
#define	waitPon2	7
#define	waitPoff2	8

 // FSM definition: 
 // Based on input N, E, P; PE2-0
 STyp FSM[9] = 
 {                          //No cars,      Ped,            E,              Ped&E, 			N, 				Ped&N, 			N&E, 		ALL 			
	 {0x21, 0x02,  	60, 	{goN,           waitN,          waitN, 			waitN,			goN, 			waitN, 			waitN, 		waitN}}, 		//in goN state
	 {0x11, 0x02, 	20, 	{goE,           goP,            goE, 			goP, 			goE, 			goP, 			goE, 		goE}}, 			//in waitN state
	 {0x0C, 0x02, 	60, 	{goE,           waitE, 			goE, 			waitE, 			waitE, 			waitE, 			waitE, 		waitE}}, 		//in goE state
	 {0x0A, 0x02, 	20,		{goN,           goP,            goN, 	 		goP, 			goN, 			goP, 			goN, 		goP}}, 			//in waitE state
	 {0x09, 0x08, 	60,		{goP,           goP,            waitPon1, 	    waitPon1, 	    waitPon1, 	    waitPon1,		waitPon1, 	waitPon1}}, 	//in goP state
	 {0x09, 0x02, 	5,		{waitPoff1,     waitPoff1,      waitPoff1,	    waitPoff1, 	    waitPoff1,	    waitPoff1,		waitPoff1, 	waitPoff1}},	//in waitPon1 state
	 {0x09, 0x00, 	5,		{waitPon2,      waitPon2 ,      waitPon2,  	    waitPon2, 		waitPon2, 	    waitPon2, 		waitPon2, 	waitPon2}}, 	//in waitPoff1 state
	 {0x09, 0x02, 	5,		{waitPoff2,     waitPoff2,      waitPoff2, 	    waitPoff2,		waitPoff2,	    waitPoff2, 		waitPoff2, 	waitPoff2}},	//in waitPon2 state
	 {0x09, 0x00, 	5,		{goN,           goE, 		    goE, 	 		goE, 		    goN, 			goN, 			goN, 		goN}}, 			//in waitPoff2 state
 }; 
 
#define NVIC_SYS_PRI3_R         (*((volatile unsigned long *)0xE000ED20))  // Sys. Handlers 12 to 15 Priority
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

 void SysTick_Init(unsigned long period){
  NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = period-1;  // reload value
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF)
                                     | 0x40000000; // priority 2
  NVIC_ST_CTRL_R = 0x07; // enable SysTick with core clock and interrupts
  EnableInterrupts();
}
 // ==================================
 // Interrupt service routine
 // Executed every 25ns*(period)
 // ==================================
void SysTick_Handler(void){
		  Counts += 1;
}
 // ==================================
 // Main
 // ==================================
void GPIOPortE_Handler(void){
		GPIO_PORTE_ICR_R = 0x07;    // acknowledge
		input = SENSOR; 
		//flag = 0; 
}

int main(void)
{ 
	PLL_Init();
	current_s = goN; 
	PortB_Init(); 
	PortE_Init(); 
	PortF_Init();
	SysTick_Init(4000000);  // initialize SysTick timer
	EnableInterrupts();
  while(1)
	{
		Counts  = 0;
		flag    = 1;
		// output based on current state
		LIGHT = FSM[current_s].T_Out ; 
		// output pedestrian lights 
		P_LED = FSM[current_s].P_Out;
		// delay is equal to the .1s period x FSM[current_s.Time)
		while( Counts < FSM[current_s].Time );
		//change state based on input and current state		
		current_s = FSM[current_s].Next[input]; 
	}
}



