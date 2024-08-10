
#include "UART.h"
#include <BA45F5240.h>

void UART_Init(unsigned int baudrate){
	

    // Set PA6 as UART RX (input)
    _pac6 = 1;
    _pas13 = 0;
    _pas14 = 1;
    _pas15 = 1;
    _papu6=  1;
   //=============
   //(PLT TX)output
 _pbc1=0; 
/*
PBS03~PBS02: PB1 Pin-Shared function selection
00: PB1
01: PLTX
10: SDO/TX
11: PB1
*/
_pbs02=0;
_pbs03=1;
   
//   ====================== 
    //PB3 RX (PLTRX)
   /*
   PxCn: I/O Port x Pin type selection
0: Output
1: Input
*/ 
 /*
    // Set PB3 as UART RX (input)
    _pbc3=1;
    //pin shair rx
	 /*   
	Bit 7~6 PBS07~PBS06: PB3 Pin-Shared function selection
	00: PB3
	01: PLRX
	10: SDI/*/
/*	_pbs06=0;
	_pbs07=0;
*/
 //=================================== 
 // Set PA3 as UART TX (output)
 /*   _pas06 = 0;
    _pas07 = 0;
    _pbs02 = 0;
    _pbs03 = 1;
*/
  



//	//PAS15~PAS14: PA6 Pin-Shared function selection(PLT RX)
//	_pas13=0;
//	_pas14=1;
//	
	


	//PAS15~PAS14: PA6 Pin-Shared function selection(PLT TX)	
   
//	
	

 //port A3 Share function PAS07~PAS06 TX(LED PIN):
/*	_pas06=1;
	_pas07=0;*/
//	
//
//	_pac6=1;//RX INPUT	
////PAS15~PAS14: PA6 Pin-Shared function selection RX ()
//	_pas14=0;
//	_pas15=1;
	

    // Enable UART, TX, and RX
 /*   _uren = 1;
    _utxen = 1;
    _urxen = 1;	*/


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
	  /*  _utxen = 1;
	    _urxen = 0;	*/	
    // Wait for empty transmit buffer
    while (!(_uusr & (1 << 1))); // Wait until UTXIF is set
    _utxr_rxr = data; // Put data into buffer, sends the 
    
	  /*  _utxen = 0;
	    _urxen = 1;	*/
    
}
/*
char UART_Receive(void) {
    // Wait for data to be received
    while (!(_uusr & (1 << 0))); // Wait until URXIF is set
    return _utxr_rxr; // Get and return received data from buffer
}*/
/*
char UART_Receive(void) {
    // Wait for data to be received
    while (!(_uusr & (1 << 0))); // Wait until URXIF is set
    char receivedData = _utxr_rxr; // Get received data from buffer
    
    // Clear the receive flag (URXIF)
    _uusr &= ~(1 << 0);
    
    return receivedData; // Return received data
}*/
int UART_Receive(void)
{
//	 _utxr_rxr=0;
  // Wait for data to be received
   // while (!(_urxif)); // Wait until URXIF is set
 	_acc=0;
	if(_urxif)					//Receive Data Finish?
	{
		_acc = _utxr_rxr;
	}
	return _acc;
  

    // Check for parity error
    if (_uperr)
    {
        _uperr = 0; // Clear parity error flag
        return UART_PARITY_ERROR;
    }

    // Check for overrun error
    if (_uoerr)
    {
        _uoerr = 0; // Clear overrun error flag
        return UART_OVERRUN_ERROR;
    }
  // Check for framing error
    if (_uferr)
    {
        _uferr = 0; // Clear framing error flag
        return UART_FRAMING_ERROR;
    }
    // Get and return received data from buffer
    return _utxr_rxr;
   
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



/*
//===========================================================
//*@brief		: UART Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _UART_DRIVER
void S_UART_Init()
{
	_simc0=0b11110000;
	_uucr2=0b11100100;
	_uucr1=0b10000000;
	_ubrg =0x33;				//baud
	
	_usime=0;
	_usimf=0;
}
#endif


#if _UART_DRIVER
void S_UART_SendData( unsigned char Data)
{
	_utxr_rxr=Data;
	while(!_utidle);			//Send Data Finish£¿
}
#endif


//===========================================================
//*@brief		: UART Receive Data
//*@param[in]	: None
//*@retval		: ACC
//===========================================================
#if _UART_DRIVER
unsigned char S_UART_ReceiveData()
{
	_acc=0;
	if(_urxif)					//Receive Data Finish?
	{
		_acc = _utxr_rxr;
	}
	return _acc;
}
#endif
*/