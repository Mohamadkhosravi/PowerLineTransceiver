#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"	
#include "ADC.h"
#include "NTC.h"
#include "SmokeDetector.h"
unsigned short *frame;
volatile char tx_busy;
unsigned int temp;
#define VCC(ADC_BR)( 1.20*(4095.000/ADC_BR))
#define BUFFER_SIZE 'g' // Length of the expected string plus 1 for null termination
char buffer[BUFFER_SIZE];
int buffer_index = 0;


char* UART_ReceiveString(void);
void main()
{
     unsigned int Data=0;	
     /*unsigned int *Data;*/
     	
    float  vcc=0.0;	
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
	unsigned char Stat=0;
	int i=0;
	#define ADDRESS 5
	#define PUBLIC_ADDRESS 'Z'
	#define PRESSED_PUSHBUTTON  _pa0==0
	#define PERRESS  10
	unsigned char  pushButtonState=0;
	unsigned int PushButtonCounter=0;
   unsigned char AddresssValid=0;

   unsigned char *Buffr;
	while(1)
	{
	/*	while(1){
			_scc = 0b00000000;
			_hircc=0b00000000;
			_halt();
			GCC_CLRWDT();
			
		}*/

	  SmokeState Sm;
	 
		if (PRESSED_PUSHBUTTON) 
		{
			pushButtonState = 1;  // Set push button state to pressed
			PushButtonCounter++;
		} 	
		else 
		{
			if ((pushButtonState == 1) &&( PushButtonCounter > PERRESS)) 
			{
				PushButtonCounter=0;
				pushButtonState=0;
			/*	Stat=!Stat;*/
				_pa4=~_pa4;
				UART_Transmit('A');
				UART_Transmit('D');
				UART_Transmit('R');
				UART_Transmit('R');
				UART_Transmit('E');
				UART_Transmit('S');
				UART_Transmit('S');
				UART_Transmit('=');
				UART_Transmit(ADDRESS);
				UART_Transmit(' ');
				UART_Transmit('S');
				UART_Transmit('T');
				UART_Transmit('A');
				UART_Transmit('T');
				UART_Transmit('E');
				UART_Transmit('=');
				UART_Transmit(Stat+0x30);		
				UART_Transmit(10);	
			}
		
		}
		GCC_CLRWDT();
	Data=UART_ReceiveNonBlocking();
        	GCC_CLRWDT();
		if(Data!=0){
		
		if ((Data== ADDRESS) || (Data== PUBLIC_ADDRESS)) 
		{
		 AddresssValid=1;
		}
		
		if((AddresssValid)&&(Data=='O')){
		    UART_Transmit('A');
			UART_Transmit('D');
			UART_Transmit('R');
			UART_Transmit('R');
			UART_Transmit('E');
			UART_Transmit('S');
			UART_Transmit('S');
			UART_Transmit('=');
			UART_Transmit(ADDRESS);
			UART_Transmit(' ');
			UART_Transmit('S');
			UART_Transmit('T');
			UART_Transmit('A');
			UART_Transmit('T');
			UART_Transmit('E');
			UART_Transmit('=');
			UART_Transmit('1');		
			UART_Transmit(10);
			AddresssValid=0;
				_pa4=1;
			
		}
		if((AddresssValid)&&(Data=='C')){
			
			UART_Transmit('A');
			UART_Transmit('D');
			UART_Transmit('R');
			UART_Transmit('R');
			UART_Transmit('E');
			UART_Transmit('S');
			UART_Transmit('S');
			UART_Transmit('=');
			UART_Transmit(ADDRESS);
			UART_Transmit(' ');
			UART_Transmit('S');
			UART_Transmit('T');
			UART_Transmit('A');
			UART_Transmit('T');
			UART_Transmit('E');
			UART_Transmit('=');
			UART_Transmit('0');		
			UART_Transmit(10);
			AddresssValid=0;
			_pa4=0;
			
			}
		
	    }
		
	}
		/*	_pa4=Stat;*/
		/* if(Stat==0)
		{
	    	_pa4=1;
	     	UART_Transmit(Stat+0x30);	

		}
		else
		{
	    	UART_Transmit(Stat+0x30);	
	       _pa4=0;
		}*/
		 
	/*	 
		 
		if(Data=='O')
		{
	    	_pa4=1;
	      UART_Transmit(Data);

		}
		if(Data=='C')
		{
	    	UART_Transmit(Data);
	       _pa4=0;
		}*/
		/*UART_Transmit(Data);*/
	/*	Data=0;
		for(i=0;i<=10;i++)
		{
		 _isgs0=~_isgen;
		 
		}*/
	//	_isgen=1;
	//	_isgs0=1;?
	   
	  /*  OPA_ON();
		ISINK0_ON();*/
		
	    //Data=ReadADC(5);
	 /* _vbgren=1;*/
	
	/*	NTC_POWER_ON;
	    vcc=temperature(ReadADC(1), 3.0f);
		Data=vcc*100;*/
    //	Sm= CheckSmokeLevel(&Data);
/*
		if(Data<=0)Data=0;
		GCC_DELAY(1000);
		GCC_DELAY(1000);
		ISINK0_OFF();
		OPA_OFF();
		GCC_DELAY(1000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
		GCC_CLRWDT();
		GCC_DELAY(20000);
 	    //if(Data>498)((Data/10000)%10+0x30);
    	UART_Transmit((Data/1000)%10+0x30);
	    UART_Transmit((Data/100)%10+0x30);
		UART_Transmit((Data/10)%10+0x30);
		UART_Transmit((Data)%10+0x30);
		
		UART_Transmit(10);
		Counter++;*/
		GCC_CLRWDT();

	
	
}



char* UART_ReceiveString(void) 
{
	static unsigned char resiveBuffer[10]={0};
	static char index=0;
	static char DataValid=0;
	resiveBuffer[index]=UART_ReceiveNonBlocking();
	if(resiveBuffer[0]!= 0){
		index++;
		DataValid=1;
	}
	else if(DataValid &&(resiveBuffer[0]== 0))
	{
		return resiveBuffer;
	}

	
}
