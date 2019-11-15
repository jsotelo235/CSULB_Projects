// PeriodicSysTickInts.h

void SysTick_Init(unsigned long period);
// Interrupt service routine
// Executed every 62.5ns*(period)
void SysTick_Handler(void);