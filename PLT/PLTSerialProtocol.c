#include <PLTSerialProtocol.h>

unsigned short PLT_SerialSend(char* data,char dataLength )
{   unsigned short frame;
    char  parity;
    char  checksum;
    char i;
    char data1[8]={0,1,0,0,0,0,0,1};

	calculate_parity_and_checksum(&data1, dataLength, &parity, &checksum);
	frame=0;
	frame |= (0 << 0); // Start bit
	for ( i = 0; i < dataLength; i++) {
		frame |= ((data1[i] & 1) << (i + 1));
	}
	
	frame |= (parity << (dataLength + 1));
	frame |= (1 << (dataLength + 2)); // Stop bit
	frame |= (checksum << (dataLength + 3)); // Checksum (assuming 4 bits for simplicity)}
	EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
	return frame;
};

 
void calculate_parity_and_checksum(char *data, char length, char *parity, char *checksum) {
    char p = 0;
    char c = 0;
    int i = 0;
    for (i = 0; i < length; i++) {
        p ^= data[i];
        c += data[i];
    }
    *parity = p & 1;
    *checksum = c;
}

void PLT_SerialInit(unsigned int baudrate){

	
	
}
	




void PLT_HandelSerialTransmit(void)
{ 

	if((frame)&1)_pa3=1;
	else _pa3=0;	
	frame=frame>>1;
	if(frame==0)
	{
	    char i=0;
	    for(i=0;i<7;i++)_nop();
		DisableInterrupt(STM_COMPAIR_A_ISR_ADDRESS); 
	
		_pa3=1;
	}
   

}
/*
unsigned short PLT_HandelSerialReceive(void)
{
    unsigned short received_frame = 0;
    char i;

    for (i = 0; i < DATA_LENGTH; i++) {

        char bit_received = ;  

        received_frame = (received_frame << 1) | bit_received;
    }

    return received_frame;
}*/