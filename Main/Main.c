#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"

unsigned int counter=0;
unsigned int counterR=0;
volatile char tx_data=0b10101101;
volatile char tx_busy = 0;
volatile char bit_index = 0;

unsigned short frame;
char RXbit=0;
extern TranferBit;
//char IndexOfBit=0;

bool PLTState=False;
unsigned int offset0 =0;
unsigned int offset1=0;
 
 
void main()
{
	
	S_RCC_Init();
	S_ADC_Init();
	STimerInit();
	PTimerInit();
	TimerBaseInit();
	UART_Init(19200);
	IntrruptInit();
	S_GPIO_Init();	
	
	offset0 =PLT0InputOffsetCalibration();
	offset1 =PLT1InputOffsetCalibration();
	offset0 =PLT0AmplifierInputOffsetCalibration();	
	_int1s1=1;
	_int1s0=0;
	
	//	
 	_pbc1=0;
	_pbs02=0;
	_pbs03=0;
	_pbpu1=0;
//	unsigned char PLTState=0;

//_emi = 1;   
//_tb0e = 1;  

   /*	EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
   	EnableInterrupt(PTM_COMPAIR_A_ISR_ADDRESS);
	EnableInterrupt(PTM_COMPAIR_P_ISR_ADDRESS);*/
    PLT_SerialInit(9600);

	while(1)
   {
   	
     RXbit=0;
     frame=PLT_SerialSend('M',8);

    _pb1=RXbit;


    //GCC_DELAY(20000);
    
    // _pb1=(TranferBit^_pb1)?TranferBit:_pb1;
  //	_pb1=TranferBit;
	//_clrwdt();

		//void softuart_transmit(A); 
	/*	if(counter==0)A=1;
		if(counter==0)A=0;
		if(counter==0)A=0;
		if(counter==0)A=1;
		if(counter==0)A=0;
		if(counter==0)A=0;
		if(counter==0)A=0;
		if(counter==0)A=1;
	
		
		
		DisabaleInterrupt(STM_COMPAIR_P_ISR_ADDRESS);*/
		
	/*	_stmpe=DISABLE;     
		_stmae=Disable;*/
      // PLT_SerialTransmit(1);
	
      

    //UART_Transmit(10);
      //_pa3=0;
 /*
 	_clrwdt();
 	_clrwdt1();
 	_clrwdt2();	*/	
 	
//_pa3=1;	
    
	/*    if(PLT0Recive()==0&&PLT1Recive()==0)
	    {
			//UART_Transmit("1");
			PLTState=True;
		
	    }
	    else
	    {
			PLTState=False;
			//UART_Transmit("0");
	    }
    
    //UART_Transmit(PLTState);
		if(PLTState)
		{
			/*_pa2=0;
			_pb1=0;	*/
			//_pa3=0;
/*		}
		else
		{
        	//_pa3=1;	
         //_pa2=1;	
			//_pb1=1;
		
		}
*/
   // asm("clr wdt");
    
	/*UART_Transmit(PLT1Recive()+0x30);
	UART_Transmit(10);*/
	GCC_CLRWDT();
	
   }

   
}
void softuart_transmit(char data) {
    while (tx_busy)

    tx_data = data;
    tx_busy = 1;
    bit_index = 0;

   
}