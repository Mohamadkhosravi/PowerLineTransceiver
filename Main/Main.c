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
#define BUFFER_SIZE 12 // Length of the expected string plus 1 for null termination
char buffer[BUFFER_SIZE];
int buffer_index = 0;
char* UART_ReceiveString(void);

unsigned long Counter=0;
unsigned int CounterLED=0;
unsigned int CounterStatusCheck=0;


unsigned char Stat=0;
int i=0;
#define ADDRESS 'g'
#define PUBLIC_ADDRESS 'Z'
#define PRESSED_PUSHBUTTON  _pa0==0
#define PERRESS  10
unsigned char  pushButtonState=0;
unsigned int PushButtonCounter=0;
unsigned char AddresssValid=0;

struct 
{
 unsigned int TemperatureValue;
 unsigned int SmokeValue;	
}situation;


void main()
{
    unsigned int Data=0;		
    float  vcc=0.0;	
    S_RCC_Init();
	S_GPIO_Init();	
	IntrruptInit();
	UART_Init(9600);
	PLT0Init();
	PLT1Init();
	_pa4=0;
	while(1)
	{
		SmokeState Sm;
		if (PRESSED_PUSHBUTTON) 
		{
		/*	pushButtonState = 1;  // Set push button state to pressed
			PushButtonCounter++;
		*/
		} 	
		else {
			
			if ((pushButtonState == 1) &&( PushButtonCounter > PERRESS)) {
				
			/*	PushButtonCounter=0;
				pushButtonState=0;
				Stat=!Stat;
				_pa4=~_pa4;
				GCC_DELAY(10000);
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
				UART_Transmit(10);	*/
			}
		
		}
		GCC_CLRWDT();
		Data=UART_ReceiveNonBlocking();
		GCC_CLRWDT();
	
		if(Data!=0){
			
		 	UART_Transmit(Data);
			if ((Data== ADDRESS) || (Data== PUBLIC_ADDRESS)) {
					
				AddresssValid=1; 
			 
			}	
			if((AddresssValid)&&(Data=='O')){
				/*_pa4=1;*/
				GCC_DELAY(10000);
				PLTAInit();
			  /*  UART_Transmit('A');
				UART_Transmit('D');
				UART_Transmit(ADDRESS);*/
		
			/*	UART_Transmit('S');	*/
			/*	UART_Transmit('m');	*/
				/*UART_Transmit('=');*/
				UART_Transmit((situation.SmokeValue/1000)%10+0x30);
				UART_Transmit((situation.SmokeValue/100)%10+0x30);
				UART_Transmit((situation.SmokeValue/10)%10+0x30);
				UART_Transmit((situation.SmokeValue)%10+0x30);
			/*	UART_Transmit(10);*/
			    UART_Transmit('T');	
				UART_Transmit('=');
				UART_Transmit((situation.TemperatureValue/1000)%10+0x30);
				UART_Transmit((situation.TemperatureValue/100)%10+0x30);
				UART_Transmit((situation.TemperatureValue/10)%10+0x30);
				UART_Transmit((situation.TemperatureValue)%10+0x30);	
				UART_Transmit(10);
				AddresssValid=0;
			
			}
			if((AddresssValid)&&(Data=='C')){
			/*	_pa4=0;*/
				GCC_DELAY(10000);
				PLTAInit();
			/*	UART_Transmit('A');
				UART_Transmit('D');
				UART_Transmit(ADDRESS);*/
			/*	UART_Transmit(' ');
				UART_Transmit('S');
				UART_Transmit('T');
				UART_Transmit('=');
				UART_Transmit('1');	
				UART_Transmit('S');	
				UART_Transmit('m');	
				UART_Transmit('=');
				UART_Transmit((situation.SmokeValue/1000)%10+0x30);
				UART_Transmit((situation.SmokeValue/100)%10+0x30);
				UART_Transmit((situation.SmokeValue/10)%10+0x30);
				UART_Transmit((situation.SmokeValue)%10+0x30);
				UART_Transmit('T');	
				UART_Transmit('=');
				UART_Transmit((situation.TemperatureValue/1000)%10+0x30);
				UART_Transmit((situation.TemperatureValue/100)%10+0x30);
				UART_Transmit((situation.TemperatureValue/10)%10+0x30);
				UART_Transmit((situation.TemperatureValue)%10+0x30);	
				UART_Transmit(10);*/
				AddresssValid=0;
			
			}
			
		}
		PLTAOFF();
		Counter++;
		if(Counter>13000)
		{
		
			CounterLED++;
			CounterStatusCheck++;
			Counter=0;
		}
		if(CounterStatusCheck>=2)
		{
			
			ADCInit();
			NTC_POWER_ON;
			situation.TemperatureValue=(temperature(ReadADC(1), 3.0f));
			NTC_POWER_OFF;
			InitSmokeDetection();
			CheckSmokeLevel(&situation.SmokeValue);
			SmokeDitectionOFF();
			ADC_Inactive();	
			CounterStatusCheck=0;	
		 
			
		}
		if(CounterLED>=12)
		{
			_pa4=1;
			GCC_DELAY(1000);
			_pa4=0;	
			CounterLED=0;
		}
	}
	
	
	
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
