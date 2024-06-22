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
	UART_Init(19200);

offset0 =PLT0InputOffsetCalibration();
offset1 =PLT1InputOffsetCalibration();
offset0 =PLT0AmplifierInputOffsetCalibration();	

	while(1)
   {
    UART_Transmit(10);
   
    if(PLT0Recive()==0&&PLT1Recive()==0)
    {
       UART_Transmit("1");
    }
    else
    {
     UART_Transmit("0");
    }
    
		
		
		UART_Transmit(PLT1Recive()+0x30);
		UART_Transmit(10);
		GCC_CLRWDT();
		GCC_DELAY(1000);
		

	}
   
}