#include "BA45F5240.h"
#include <PLT.h>
//#include <A_SOFTDEBUG_DRV.h>
#include <Main.h>
#include <UART.h>

void main()
{

unsigned int counter=0;
unsigned int offset0 =0;
unsigned int offset1=0;

	S_GPIO_Init();
	S_ADC_Init();
	S_RCC_Init();
	S_Timebase_Init();
	UART_Init(9600);

offset0 =PLT0InputOffsetCalibration();
offset1 =PLT1InputOffsetCalibration();
	while(1)
   {
    UART_Transmit('U'); 
   	counter++;
   	GCC_CLRWDT();
   
	 /*if(PLT1Recive())_pa3=1;
	 else _pa3=0;*/
   
	}
   
}