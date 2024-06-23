#ifndef PLT_SERIAL_PROTOCOL_H
#define PLT_SERIAL_PROTOCOL_H

#define ENABLE           	  1
#define DISABLE               0

#define TX_PIN       _pa3
#define RX_BIT       ADDRESS_PLT_RECEIVE

#define _8_BIT_DATA_TRANSFER  8
#define _9_BIT_DATA_TRANSFER  9
#define  MAX_DATA_SIZE        9

#define DATA_TRANSFER    _8_BIT_DATA_TRANSFER 

#define PARITY            ENABLE

#define EVEN_PARITY           0
#define ODD_PARITY            1

#define TYPE_OF_PARITY   ODD_PARITY


#define ONE_STOP_BIT          1
#define TWO_STOP_BIT          2
#define STOP_BIT         ONE_STOP_BIT



//for budrate
unsigned int timerCuonter; 

// Structure for the serial protocol frame

struct PLTSerialProtocol
{
    unsigned char startBit;          // Start bit
    unsigned char address;           // Address of the target device
    unsigned char control;           // Control field (e.g., frame type)
    unsigned short dataLength;       // Length of the data payload
    unsigned char data[MAX_DATA_SIZE]; // Data payload
    unsigned short checksum;         // Checksum for error detection
    unsigned char stopBit;           // Stop bit
 
};

  struct PLTSerialProtocol frame;








void PLT_SerialInit(unsigned int baudrate);
void PLT_SerialTransmit(char data);
char PLT_SerialReceive(void);






#endif