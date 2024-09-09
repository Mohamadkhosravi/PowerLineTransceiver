#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"	

unsigned short *frame;
volatile char tx_busy;
void main()
{
    uint8_t Data=0;	
    S_RCC_Init();
	S_ADC_Init();
	S_GPIO_Init();	
	IntrruptInit();
	UART_Init(9600);
	PLT0Init();
	PLT1Init();
	PLTAInit();
	while(1)
	{
		Data= UART_Receive();
		GCC_DELAY(5000);
		if(Data=='O')
		{
	    	_pa3=1;	
		}
		if(Data=='C')
		{
	    	_pa3=0;	
		}
		
		UART_Transmit(Data);
		GCC_DELAY(5000);
		GCC_CLRWDT();
	}	
	
}

