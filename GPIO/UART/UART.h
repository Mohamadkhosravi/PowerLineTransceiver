#ifndef UART_H
#define UART_H

#define ENABLE           	  1
#define DISABLE               0

#define TRANSMITTER      ENABLE
#define RECEIVER         ENABLE

//============================================
// Assuming a clock frequency 
//============================================
#define F_CPU            4000000 
//============================================
// Calculate and set the baud rate
// UBRGH: Baud Rate speed selection
//============================================
#define LOW_SPEED             0
#define HIGH_SPEEAD           1
#define SPEED_BAUDRATE   LOW_SPEED


#if SPEED_BAUDRATE
	#define CONSTANT_NUMBER 16.00
#else
	#define CONSTANT_NUMBER 64.00
#endif
//============================================
//UBNO: Number of data transfer bits selection
//============================================
#define _8_BIT_DATA_TRANSFER  0
#define _9_BIT_DATA_TRANSFER  1

#define DATA_TRANSFER    _8_BIT_DATA_TRANSFER 
//============================================
//UPREN: Parity function enable control
//UPRT: Parity type selection bit
//============================================
#define PARITY           DISABLE

#define EVEN_PARITY           0
#define ODD_PARITY            1
#define TYPE_OF_PARITY   ODD_PARITY

//============================================
//USTOPS: Number of Stop bits selection
//============================================
#define ONE_STOP_BIT          0
#define TWO_STOP_BIT          1
#define STOP_BIT         ONE_STOP_BIT

//============================================
//UTXBRK: Transmit break character
/*
0: No break character is transmitted
1: Break characters transmit*/
//============================================
#define UART_ERROR          -1
#define UART_FRAMING_ERROR  -2
#define UART_PARITY_ERROR   -3
#define UART_OVERRUN_ERROR  -4




void UART_Init(unsigned int baudrate);
void UART_Transmit(char data);
void S_UART_Init();
void S_UART_SendData( unsigned char Data);
unsigned char S_UART_ReceiveData();
void UART_EnableInterrupts(void);

#endif // UART_H
