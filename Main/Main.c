#include<Main.h>
#include <Interrupt.h>
#include "BA45F5240.h"

unsigned int counter=0;
unsigned int counterR=0;
volatile char tx_data=0b10101101;

volatile char bit_index = 0;
unsigned short frame=0;
volatile unsigned short frameResive=0;
volatile char tx_busy = 0;

unsigned short *frame1=0;
unsigned char receiveSerialData(void);
unsigned char Data1=0b10101101;	
unsigned char *Data;
char RXbit=0;
extern TranferBit;
//char IndexOfBit=0;

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
	
	IntrruptInit();
	S_GPIO_Init();	
	UART_Init(9600);
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
	unsigned char PLTState=0;

	PLT_SerialInit(9600);
	/*offset0 =PLT0InputOffsetCalibration();
	offset1 =PLT1InputOffsetCalibration();*/
	
	_emi=1;
	unsigned int cunt=0;
	offset0 =	PLT0Recive();
	offset1 =	PLT1Recive();

	PLT0Init();
	PLT1Init();


   while(1)
   {

    // Data=receiveSerialData();
   // Data=PLT_SerialSend('m',8,frame); 
     
	/*	if(PLT_SerialSend('u',frame1)){
			 frame=*frame1;
		} 
		
		if (PLT_SerialSend('M', &frame1)) {
			frame = frame1;
		
		} 
		else 
		{
		
		}*/
		
	    

	GCC_CLRWDT();
         
	//	_pb1=1;

	if(PLT0Recive()==0&&PLT1Recive()==0)
	{
		PLTState=1;
	//	_pa3=1;
	//	_pb1=0;
	}
	else
	{
		PLTState=0;
	//	_pa3=1;
	//	_pb1=1;
	}


	/* if(tx_busy==0){
	
	frame=0b01010101;
	tx_busy=1;	
	//EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);	
	}
	
	
	/*      if(PLT1Recive()==0)
	{
	
    UART_Transmit("1");
	PLTState=1;
	_pb1=1;
	}
	else
	{
	PLTState=0;
	_pb1=0;
	}*/
	
	
	
	//UART_Transmit(PLTState);
	

	
	/*UART_Transmit(PLT1Recive()+0x30);*/
/*	UART_Transmit(10);
	UART_Transmit('U');
	GCC_DELAY(1000);
	UART_Transmit('A');
	GCC_DELAY(1000);
	UART_Transmit('R');
	GCC_DELAY(1000);
	UART_Transmit('T');
	GCC_DELAY(1000);*/
   }

   
}
unsigned char receiveSerialData(void) {
    unsigned char data = 0;
    int i;

    for (i = 0; i < 8; i++) {
        data <<= 1; 

        if (PLT0Recive() == 1) {
            data |= 1;
        } else if (PLT1Recive() == 1) {
            data |= 0; 
            }
    }

    return data;
}


void softuart_transmit(char data) {
    while (tx_busy)

    tx_data = data;
    tx_busy = 1;
    bit_index = 0;

   
}