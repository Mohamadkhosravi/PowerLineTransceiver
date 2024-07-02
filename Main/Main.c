#include<Main.h>
#include <Interrupt.h>
unsigned int counter=0;
unsigned int counterR=0;
volatile char tx_data=0b10101101;
volatile char tx_busy = 0;
volatile char bit_index = 0;
unsigned short frame;

//char IndexOfBit=0;
void main()
{
_tb0on=1;

unsigned int offset0 =0;
unsigned int offset1=0;
	S_GPIO_Init();
	S_ADC_Init();
	S_RCC_Init();
	IntrruptInit();
	TimerBaseInit();
	STimerInit();
	UART_Init(19200);
/*	offset0 =PLT0InputOffsetCalibration();
	offset1 =PLT1InputOffsetCalibration();
	offset0 =PLT0AmplifierInputOffsetCalibration();	
	_pac3=0;
	_papu3=0;
	_pas06=0;
	_pas07=0;*/
	
	
//	_int1s1=1;
//	_int1s0=0;
	
	//	
	//  	_pbc1=0;
	//	_pbs02=0;
	//	_pbs03=0;
	//	_pbpu1=0;
	unsigned char PLTState=0;

//_emi = 1;   
//_tb0e = 1;  

//EnableInterrupt(PTM_COMPAIR_P_ISR_ADDRESS);
/*DisableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);*/
PLT_SerialInit(9600);
char A=0b10011011;
counter=0;

	while(1)
   { 
   
	 frame=PLT_SerialSend('U',8);
    _wdtc=0;

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
	/*	if(PLTState)
		{
			_pa2=0;
			_pb1=0;	
		}
		else
		{
			_pa2=1;	
			_pb1=1;
		
		}*/
		
    
    
	/*UART_Transmit(PLT1Recive()+0x30);
	UART_Transmit(10);*/
	//GCC_CLRWDT();

	
   }

   
}
void softuart_transmit(char data) {
    while (tx_busy)

    tx_data = data;
    tx_busy = 1;
    bit_index = 0;

   
}