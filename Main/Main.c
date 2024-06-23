#include "BA45F5240.h"
#include <PLT.h>
//#include <A_SOFTDEBUG_DRV.h>

#include <UART.h>

 unsigned int counterR=0;
#pragma vector TB0_ISR @ 0x30
void TB0_ISR(void)
{

 	_nop();
	_pa3 = 1;	/* user define */
}
#pragma vector TB1_ISR @ 0x34
void TB1_ISR(void)
{
 _nop();
	/* user define */
 _pa3 = 0;
}


	
//		
//void TB0_ISR(void);
//void TB1_ISR(void);
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
//
_pac3=0;
_papu3=0;
_pas06=0;
_pas07=0;
//	
//  	_pbc1=0;
//	_pbs02=0;
//	_pbs03=0;
//	_pbpu1=0;
	unsigned char PLTState=0;

	
	_nop();
	

	
	
	while(1)
   {
    //UART_Transmit(10);
     
  /* 	
    if(counterR<6000)
    {
   
     _pa3=1;	
    }
    else
    {
     _pa3=0;		
    }
    */
    
 /*
    
    if(PLT0Recive()==0&&PLT1Recive()==0)
    {
		//UART_Transmit("1");
		PLTState=1;
	
    }
    else
    {
		PLTState=0;
		//UART_Transmit("0");
    }*/
    
    //UART_Transmit(PLTState);
  /*  if(PLTState)
    {
    	_pa2=0;
    	_pb1=0;	
    }
    else
    {
     _pa2=1;	
     _pb1=1;
    
    }
    */
    
    
	/*UART_Transmit(PLT1Recive()+0x30);
	UART_Transmit(10);*/
	GCC_CLRWDT();

	

	}
   
}
