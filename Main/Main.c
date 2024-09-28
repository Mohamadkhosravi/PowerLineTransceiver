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
    unsigned int Counter;
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
	//	_isgen=1;
		_isgs0=1;
     	GCC_DELAY(1000);
		 Data=ReadADC(5);
		// _isgen=0;
		_isgs0=0;
		GCC_CLRWDT();
		GCC_DELAY(200000);
		GCC_CLRWDT();
		GCC_DELAY(200000);
		//Data=5687;
//		while(Counter>=10000){
//		if(Data>498)((Data/10000)%10+0x30);
//    	UART_Transmit((Data/1000)%10+0x30);
//	    UART_Transmit((Data/100)%10+0x30);
//		UART_Transmit((Data/10)%10+0x30);
//		UART_Transmit((Data)%10+0x30);
//		UART_Transmit(10);
//		Counter++;
//		}
		Counter=0;
	/*	GCC_DELAY(5000);*/
		GCC_CLRWDT();
	}	
	
}

