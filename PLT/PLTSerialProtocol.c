#include <PLTSerialProtocol.h>
unsigned short PLT_SerialSend(unsigned char *data, unsigned short *frame)
{
    char parity = 0;
    char checksum = 0;
    char i;
    char data1[8]={0};

    // Convert the character to its binary representation
    for (i = 0; i < 8; i++) {
        data1[i] = (*data >> i) & 1;
    }
    if (tx_busy == 0)
    {
        tx_busy = 1;
        calculate_parity_and_checksum(data1, 8, &parity, &checksum);
        *frame = 0;
        *frame |= (0 << 0); // Start bit
        for (i = 0; i < 8; i++) {
            *frame |= ((data1[i] & 1) << (i + 1));
        }

      /*  *frame |= (parity << 9); // Parity bit
        *frame |= (1 << 10); // Stop bit
        *frame |= (checksum << 11); // Checksum (assuming 4 bits for simplicity)*/
        EnableInterrupt(STM_COMPAIR_A_ISR_ADDRESS);
        return 1;
    }
    else
    {
        return 0;
    }
}
 
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

	_pbc1=0;
	_pbs02=0;
	_pbs03=0;
	_pbpu1=0;	
	
}
	




void PLT_HandelSerialTransmit(void)
{ 
	
	if((*frame)&1)TX_PIN=1;
	else 
	{
	    TX_PIN=0;
		if((*frame==0))
		{
			char i=0;
			for(i=0;i<7;i++)_nop();
			DisableInterrupt(STM_COMPAIR_A_ISR_ADDRESS); 
			_pb1=1;
			TX_PIN=0;
		
		}
	
	}
   	*frame=*frame>>1;


}
/*
unsigned short PLT_HandelSerialReceive(void)
{   
       if(PLT0Recive()==0&&PLT1Recive()==0)
	    {
		
		
	    }
	    else
	    {
			//PLTState=False;
			//UART_Transmit("0");
	    }
}

*/

/*
unsigned short received_frame = 0;
    char i;

    for (i = 0; i < DATA_LENGTH; i++) {

        char bit_received = ;  

        received_frame = (received_frame << 1) | bit_received;
    }

    return received_frame;
*/