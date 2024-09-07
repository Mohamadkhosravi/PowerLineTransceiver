#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"

unsigned int counter=0;
unsigned char counterR=0;
volatile char tx_data=0b10101101;
unsigned char Data1;
volatile char bit_index = 0;
unsigned short *frame;
unsigned short frameResive=0;
volatile char tx_busy = 0;

unsigned short *frame1=0;
unsigned char receiveSerialData(void);
/*unsigned char *Data1;*/
	
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
   PLT_SerialInit(9600);//PB1 output
   UART_Init(19200);//PB1 TX
//	S_UART_Init();
   //UART_EnableInterrupts();
  	PLT0Init();
	PLT1Init();
    PLTAInit();
	int i=0;
	int Counter=0;

   while(1)
   {
//	DisableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);
//	DisableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
//
//	GCC_CLRWDT();
//	Data[0]= UART_Receive();
//	UART_Transmit(Data[0]);
//     GCC_DELAY(10000);
//     i++;
//    if(i>20)
//    {
//    DisableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
//	DisableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
//	EnableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);
//	EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
   Data1='m';
	PLT_SerialSend(&Data1,frame);

	Data1='S';
	PLT_SerialSend(&Data1,frame);
	

	
	
	/*EnableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
	EnableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
	GCC_DELAY(5000);
	i=0;
    }*/
	GCC_CLRWDT();

 
   }

  
}

