#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"	
#include "ADC.h"
#include "SmokeDetector.h"
unsigned short *frame;
volatile char tx_busy;
unsigned int temp;
#define VCC(ADC_BR)( 1.20*(4095.000/ ADC_BR))
void main()
{
   int Data=0;	
    float  vcc=0;	
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
		//Data= UART_Receive();
		//Data=UART_ReceiveNonBlocking();
	/*	GCC_DELAY(5000);
		if(Data=='O')
		{
	    	_pa3=1;	
		}
		if(Data=='C')
		{
	    	_pa3=0;	
		}*/
	/*	Data=0;
		for(i=0;i<=10;i++)
		{
		 _isgs0=~_isgen;
		 
		}*/
	//	_isgen=1;
	//	_isgs0=1;?
	   
	    OPA_ON();
		ISINK0_ON();
		
	    //Data=ReadADC(5);
	  
	    _pa7=1;
	    vcc=VCC(ReadADC(4));
	    Data =vcc*100;
	 /*   Data=ReadADC(1);
	   Data=temperature(Data, 5);*/
	   if(Data<=0)Data=0;
		GCC_DELAY(1000);
		GCC_DELAY(1000);
		ISINK0_OFF();
		OPA_OFF();
		GCC_DELAY(1000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
 	    if(Data>498)((Data/10000)%10+0x30);
    	UART_Transmit((Data/1000)%10+0x30);
	    UART_Transmit((Data/100)%10+0x30);
		UART_Transmit((Data/10)%10+0x30);
		UART_Transmit((Data)%10+0x30);
		UART_Transmit(10);
		Counter++;
		GCC_CLRWDT();
	}	
	
}

