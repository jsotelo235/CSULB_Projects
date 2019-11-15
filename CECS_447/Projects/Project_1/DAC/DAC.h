// DAC.h
// Runs on LM4F120 or TM4C123
// Jose Sotelo
// Jose Pacheco
// February 26, 2018

// GPIO Ports PA2, PA3, PA4, PA5, PA6 and PA7
// are set as outputs for 6 bit DAC

//*********************************************
// DAC Initialization
//*********************************************
void DAC_Init(void);


//*******************************************
// DAC Out
//*******************************************
void DAC_Out(unsigned long data);
  


