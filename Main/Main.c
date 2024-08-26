#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"

unsigned int counter=0;
unsigned char counterR=0;
volatile char tx_data=0b10101101;

volatile char bit_index = 0;
unsigned short *frame;
unsigned short frameResive=0;
volatile char tx_busy = 0;

unsigned short *frame1=0;
unsigned char receiveSerialData(void);
unsigned char *Data1;	

unsigned char Data[16];

//int  Data;
char RXbit=0;
extern TranferBit;
//char IndexOfBit=0;

unsigned int offset0 =0;
unsigned int offset1=0;
 unsigned short  RXBuffer=0;
 
void main()
{
	
	S_RCC_Init();
	/*	S_ADC_Init();
	STimerInit();
	PTimerInit();
	TimerBaseInit();*/
	IntrruptInit();
	GPIO_Init();	
	/*	PLT0Init();
	PLT1Init();
	PLT_SerialInit(9600);//PB1 output*/
	UART_Init(9600);//PB1 TX
	while(1)
	{_pa3=1;
	//UART_Receive();
     UART_Transmit("U");
     GCC_DELAY(1000);
     GCC_CLRWDT();
	
	}

   
}
