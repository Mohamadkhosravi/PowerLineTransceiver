#include<Main.h>


unsigned int counter=0;
unsigned int counterR=0;


//INT1S1~INT1S0
/*
#pragma vector INT_ISR @ 0x04
void INT_ISR(void)
{
 _pa3=~_pa3;

}

#pragma vector TB0_ISR @ 0x08
void TB0_ISR(void)
{

TIME_BASE0_INTRRUPT_FLAG=0;
	  _pa3=~_pa3;

}

#pragma vector TB1_ISR @ 0x0c
void TB1_ISR(void)
{
TIME_BASE1_INTRRUPT_FLAG=0;

	 	 _pa3=~_pa3;

}

#pragma vector T_ISR @ 0x10
void T_ISR(void)
{

		 _pa3=~_pa3;

}

#pragma vector ST_ISR @ 0x28
void ST_ISR(void)
{
	

	 _pa3=~_pa3;
	
}



#pragma vector STB_ISR @ 0x2c
void STB_ISR(void)
{
if (_tb0f) {
        // Your interrupt handling code here
        
        // Clear the Timer Base 0 interrupt flag
        _tb0f = 0;
        _pa3=~_pa3;
    }
		 

}
//
//#pragma vector PTM_ISR @ 0x20
//void PTM_ISR(void)
//{
//
//	_pa3=~_pa3;
//	
//}
//
//#pragma vector PTMA_ISR @ 0x24
//void PTMA_ISR(void)
//{
//		_pa3=~_pa3;
//
//	//	_pa3=1;
//	/* user define */
//}


//

//#define BASE_TIMER_ISR_ADDRESS 0x30
//void __attribute__((interrupt(BASE_TIMER_ISR_ADDRESS))) BaseTimer0ISR(void)
//{
//   	_pa3=~_pa3;
//}

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
