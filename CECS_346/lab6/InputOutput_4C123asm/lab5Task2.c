#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

#define BLUE	0x04
#define RED		0x02
#define GREEN	0x08


unsigned long In;
//unsigned long Out;

extern void delay(void);
void PortF_Init(void);
	
int main()
{
	PortF_Init();
	
	while(1){
		delay();
		
		In = GPIO_PORTF_DATA_R&0x11;
		//Out = GPIO_PORTF_DATA_R;
	
		if(In == 0x01)
		{
			GPIO_PORTF_DATA_R = BLUE;
		}
		else if(In == 0x10)
		{
			GPIO_PORTF_DATA_R = RED;
		}
		else if(In == 0x00)
		{
			GPIO_PORTF_DATA_R = GREEN;
		}
		else if(In == 0x11)
		{
			GPIO_PORTF_DATA_R = 0;
		}
		else
		{
			GPIO_PORTF_DATA_R = BLUE+RED+GREEN;
		}
	}
}

void PortF_Init()
{
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0 

	
}



