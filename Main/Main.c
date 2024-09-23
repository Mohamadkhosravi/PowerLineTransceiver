#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"	
#include "ADC.h"
unsigned short *frame;
volatile char tx_busy;
void main()
{
   int Data=0;	
    S_RCC_Init();
	ADCInit();
	S_GPIO_Init();	
	IntrruptInit();
	UART_Init(9600);
	PLT0Init();
	PLT1Init();
	PLTAInit();
    InitSmokeDetection();
	int i=0;
	while(1)
	{
	//	Data= UART_Receive();
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
		_isgen=1;
		_isgs0=1;
	
		 Data=ReadADC(5);
		 GCC_DELAY(10000);
		//Data=5687;
		if(Data>498)((Data/10000)%10+0x30);
    	UART_Transmit((Data/1000)%10+0x30);
	    UART_Transmit((Data/100)%10+0x30);
		UART_Transmit((Data/10)%10+0x30);
		UART_Transmit((Data)%10+0x30);
		UART_Transmit(10);
	/*	_isgs0=0;*/
		GCC_DELAY(10000);
	/*	GCC_DELAY(5000);*/
		GCC_CLRWDT();
	}	
	
}

