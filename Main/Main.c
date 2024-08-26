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
//	S_ADC_Init();
//	STimerInit();
//	PTimerInit();
//	TimerBaseInit();
	S_GPIO_Init();	
//	PLT0Init();
//	PLT1Init();
// PLT_SerialInit(9600);//PB1 output
	UART_Init(9600);//PB1 TX
	IntrruptInit();
	int i=0;
	int Counter=0;
	EnableInterrupt(USIM_ISR_ADDRESS);

   while(1)
   {

	GCC_CLRWDT();
	UART_Transmit('m');
	GCC_DELAY(10000);
	GCC_CLRWDT();
	     

   }

   
}

