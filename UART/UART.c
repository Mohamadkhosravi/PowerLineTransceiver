
#include "UART.h"
#include <BA45F5240.h>

void UART_Init(unsigned int baudrate){
	
	

	//PAS15~PAS14: PA6 Pin-Shared function selection(PLT RX)
//	_pas13=0;
//	_pas14=1;
//	
	


	//PAS15~PAS14: PA6 Pin-Shared function selection(PLT TX)	
	_pbs02=0;
	_pbs03=1;	
	
	
/*
 //port A3 Share function PAS07~PAS06 TX(LED PIN):
	_pas06=1;
	_pas07=0;*/
	
//PAS15~PAS14: PA6 Pin-Shared function selection RX ()
	_pas14=0;
	_pas15=1;
	


//	UMD: UART mode selection bit
//0: SPI or I2C mode
//1: UART mode
	_umd=1;
	_ubrgh = SPEED_BAUDRATE;
	unsigned int ubrr =(F_CPU / (CONSTANT_NUMBER * baudrate)) - 1.0;
	_ubrg = ubrr & 0xFF ;
	// Enable UART by setting UREN bit in UUCR1 register
	_uren=1; // Enable UART (UREN)	
	_ubno=DATA_TRANSFER;
	_upren=PARITY;
	_uprt=TYPE_OF_PARITY;
	_ustops=STOP_BIT; 
	_utxen=TRANSMITTER;
	_urxen=RECEIVER;
}

void UART_Transmit(char data) {
    // Wait for empty transmit buffer
    while (!(_uusr & (1 << 1))); // Wait until UTXIF is set
    _utxr_rxr = data; // Put data into buffer, sends the data
}

char UART_Receive(void) {
    // Wait for data to be received
    while (!(_uusr & (1 << 0))); // Wait until URXIF is set
    return _utxr_rxr; // Get and return received data from buffer
}

void UART_EnableInterrupts(void) {
	//    // Enable receiver interrupt
	  _uucr2 |= _urie;
	//    // Enable transmitter interrupt
	_uucr2 |= (_utiie | _uteie);
}
void UART_DisableInterrupts(void) {
//    // Disable all UART interrupts
      _uucr2 &= ~(_urie | _utiie | _uteie);
}