#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"	
#include "ADC.h"
#include "NTC.h"
#include "SmokeDetector.h"
unsigned short *frame;
volatile char tx_busy;
unsigned int temp;
#define VCC(ADC_BR)( 1.20*(4095.000/ADC_BR))
void main()
{
    unsigned int Data=0;	
    float  vcc=0.0;	
    S_RCC_Init();
	ADCInit();
	S_GPIO_Init();	
	IntrruptInit();
	UART_Init(9600);
	PLT0Init();
	PLT1Init();
	PLTAInit();
	InitSmokeDetection();
  unsigned int Counter;
	int i=0;

	while(1)
	{
		
      unsigned int *D;
	  SmokeState Sm;
	  
	 /* while(1){
		_pa3=0;
		GCC_CLRWDT();
        GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);	
		GCC_CLRWDT();
		_pa3=1;
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
	  	}*/
	  

		// Data= UART_Receive();
		Data=UART_ReceiveNonBlocking();
    	GCC_DELAY(5000);
		if(Data=='O')
		{
	    	_pa4=1;
	      UART_Transmit(Data);

		}
		if(Data=='C')
		{
	    	UART_Transmit(Data);
	       _pa4=0;
		}
		Data='N';
		/*UART_Transmit(Data);*/
	/*	Data=0;
		for(i=0;i<=10;i++)
		{
		 _isgs0=~_isgen;
		 
		}*/
	//	_isgen=1;
	//	_isgs0=1;?
	   
	  /*  OPA_ON();
		ISINK0_ON();*/
		
	    //Data=ReadADC(5);
	 /* _vbgren=1;*/
	
		NTC_POWER_ON;
		/*vcc=temperature(ReadADC(1), 3.0f);
		Data=vcc*100;*/
/*		Sm= CheckSmokeLevel(&Data);

		if(Data<=0)Data=0;
		GCC_DELAY(1000);
		GCC_DELAY(1000);
		ISINK0_OFF();
		OPA_OFF();
		GCC_DELAY(1000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);*/
 	   /* if(Data>498)((Data/10000)%10+0x30);
    	UART_Transmit((Data/1000)%10+0x30);
	    UART_Transmit((Data/100)%10+0x30);
		UART_Transmit((Data/10)%10+0x30);
		UART_Transmit((Data)%10+0x30);*/
		
		UART_Transmit(10);
		Counter++;
		GCC_CLRWDT();
		
		
			
	}	
	
}

