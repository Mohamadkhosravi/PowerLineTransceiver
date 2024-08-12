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

unsigned char Data;

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
	S_ADC_Init();
	STimerInit();
	PTimerInit();
	TimerBaseInit();
	IntrruptInit();
	S_GPIO_Init();	
	PLT0Init();
	PLT1Init();
    PLT_SerialInit(9600);//PB1 output
 //UART_Init(9600);//PB1 TX
   while(1)
   {
    
   // UART_Transmit('m');

         

           
         //  counter++;
       /*    if(counter<1000)
           {*/
        	EnableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
			EnableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
			DisableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
			frame=0;
	        while(counterR<11)
			EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
			DisableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
			DisableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
			Data=&frameResive;
			PLT_SerialSend(&Data,frame);
			frameResive=0;
			Data=0;
			counterR=0;
           //	Data=receiveSerialData();
         	GCC_DELAY(25000);
           	
			//Data='m';
		    
		
	
         /*  }*/
          /* else if(counter>=1000)
           {*/
         /*  
           if(Data=!0){
	    	DisableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
			DisableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
			UART_Transmit('D');
			UART_Transmit('=');
			UART_Transmit((char)Data);	
			Data=0;
	    	EnableInterrupt(PLT_COMPAIR1_ISR_ADDRESS);
			EnableInterrupt(PLT_COMPAIR0_ISR_ADDRESS);
           }*/
        /*   }
           if(counter>=2000)counter=0;
	*/
		/*	if(Data2==-1)UART_Transmit('1');
			else if(Data==-2)UART_Transmit('2');
			else if(Data==-3)UART_Transmit('3');
			else if(Data==-4)UART_Transmit('4');
			else{*/
		
		/*	}*/
			
	

     
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
/*
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
/*
*/
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

        if (RXbit == 1) 
        {
            data |= 1;
        } else if (RXbit == 1) 
        {
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