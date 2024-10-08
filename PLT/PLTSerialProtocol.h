#ifndef PLT_SERIAL_PROTOCOL_H
#define PLT_SERIAL_PROTOCOL_H
#include <Main.h>
extern unsigned short *frame;
extern volatile char tx_busy;
extern char RXbit;
#define ENABLE           	 1
#define DISABLE              0 

        
/*=============================================================
| Start | Data                  | Parity | Stop | CRC         |
|-------|-----------------------|--------|------|-------------|
| 1     |d7 d6 d5 d4 d3 d2 d1 d0| 1      | 1    | c3 c2 c1 c0 |
 ==============================================================*/

#define TX_PIN      _pb1	
#define RX_BIT       ADDRESS_PLT_RECEIVE

//===============================================================
#define START_BIT             0
//===============================================================
#define  MAX_DATA_SIZE        9
//===============================================================
#define _8_BIT_DATA_TRANSFER  8
#define _9_BIT_DATA_TRANSFER  9
#define DATA_TRANSFER    	 _8_BIT_DATA_TRANSFER 
//===============================================================
#define PARITY            DISABLE
//===============================================================
#define EVEN_PARITY           0
#define ODD_PARITY            1
#define TYPE_OF_PARITY   ODD_PARITY
//===============================================================
#define ONE_STOP_BIT          1
#define TWO_STOP_BIT          2
#define STOP_BIT         ONE_STOP_BIT
//===============================================================


void PLT_SerialInit(unsigned int baudrate);
void PLT_HandelSerialTransmit(void);
unsigned short PLT_SerialSend(unsigned char *data, unsigned short *frame);
char PLT_SerialReceive(void);
void calculate_parity_and_checksum(char *data, char length, char *parity, char *checksum);




#endif