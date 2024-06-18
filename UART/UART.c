#include "UART.h"

//void UART_Init(unsigned int baud_rate) {
//    // Set baud rate
//    UART_SetBaudRate(baud_rate);
//    
//    // Enable UART transmitter and receiver
//    UUCR2 |= (UTXEN | URXEN);
//}
//
//void UART_Transmit(char data) {
//    // Wait for the transmitter to be ready
//    while ((UUSR & 0x02) == 0);
//    
//    // Write data to the transmit register
//    UTXR_RXR = data;
//}
//
//char UART_Receive(void) {
//    // Wait for data to be received
//    while ((UUSR & 0x01) == 0);
//    
//    // Read data from the receive register
//    return UTXR_RXR;
//}
//
//void UART_SetBaudRate(unsigned int baud_rate) {
//    // Assuming fH is the clock frequency
//    unsigned int fH = 16000000; // 16 MHz, for example
//    char brg_value = (fH / (16 * baud_rate)) - 1;
//    UBRG = brg_value;
//}
//
//void UART_EnableInterrupts(void) {
//    // Enable receiver interrupt
//    UUCR2 |= URIE;
//    // Enable transmitter interrupt
//    UUCR2 |= (UTIIE | UTEIE);
//}
//
//void UART_DisableInterrupts(void) {
//    // Disable all UART interrupts
//    UUCR2 &= ~(URIE | UTIIE | UTEIE);
//}

#include "UART.h"
#include <BA45F5240.h>

#define F_CPU 8000000 // Assuming a clock frequency of 4 MHz

void UART_Init(unsigned int baudrate) {
	
	
	//PAS07~PAS06:
	_pas06=1;
	_pas07=0;
	
	//PAS15~PAS14: PA6 Pin-Shared function selection
	_pas13=0;
	_pas14=1;
	
	/*
	_pbs06=0;
	_pbs07=1;
	
	_pbs02=0;
	_pbs03=1;*/
	
    // Set the UART mode by setting UMD bit in SIMC0 register
    //_simc0 |= (1 << 7); // Assuming UMD is the 7th bit
    
    _umd=1;
    // Calculate and set the baud rate
    unsigned int ubrr = (F_CPU / (64 * baudrate)) - 1;
   // & 0xFF; // Set the UBRG register
    _ubrg = ubrr ;
 
    if (ubrr & 0x100) {
        _uucr2 |= (1 << 0); // Set UBRGH bit if needed
    } else {
        _uucr2 &= ~(1 << 0); // Clear UBRGH bit if not needed
    }

    // Enable UART by setting UREN bit in UUCR1 register
    _uren=1;
    
   // _uucr1 |= (1 << 7); // Enable UART (UREN)
   _ubno=0;
   
   // _uucr1 |= (1 << 6); // 8-bit data transfer (UBNO = 0)
    _upren=0;
    
    //_uucr1 &= ~(1 << 5); // Disable parity (UPREN = 0)
    _uprt=1;
    
   // _uucr1 &= ~(1 << 4); // Even parity (UPRT = 0)
   _ustops=1;
   // _uucr1 &= ~(1 << 3); // One stop bit (USTOPS = 0)

    // Enable transmitter and receiver
    _utxen=1;
   // _uucr1 |= (1 << 2); // Enable transmitter (UTXEN)
   _urxen=1;
   // _uucr1 |= (1 << 1); // Enable receiver (URXEN)
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
