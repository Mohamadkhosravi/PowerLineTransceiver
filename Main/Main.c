#include<Main.h>

unsigned int counter=0;
unsigned int counterR=0;

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


	offset0 =PLT0InputOffsetCalibration();
	offset1 =PLT1InputOffsetCalibration();
	offset0 =PLT0AmplifierInputOffsetCalibration();	

	_pac3=0;
	_papu3=0;
	_pas06=0;
	_pas07=0;
	
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




	while(1)
   {


   	//	_pa3=1;
    //UART_Transmit(10);
      //_pa3=0;
 	
   /* if(counter<6000)
    {
   	

     _pa3=1;	
    }
    else
    {
     _pa3=0;		
    }
 	if(counter>12000)counter=0;*/
    
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
	GCC_CLRWDT();

	
   }

   
}
