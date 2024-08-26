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
	
char Data[16]={0};

//int  Data;
char RXbit=0;
extern TranferBit;
unsigned int offset0 =0;
unsigned int offset1=0;
unsigned short  RXBuffer=0;
 
void main()
{
	
	S_RCC_Init();
	S_ADC_Init();
	STimerInit();
	PTimerInit();
    TimerBaseInit();
	S_GPIO_Init();	
	IntrruptInit();
  // PLT_SerialInit(9600);//PB1 output
   UART_Init(9600);//PB1 TX
//	S_UART_Init();
   //UART_EnableInterrupts();
  	PLT0Init();
	PLT1Init();
	int i=0;
	int Counter=0;

   while(1)
   {
 
	GCC_CLRWDT();
	Data[0]= UART_Receive();
	UART_Transmit(Data[0]);
	GCC_DELAY(10000);
	GCC_CLRWDT();
	     

   }

   
}

