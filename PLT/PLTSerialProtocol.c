#include <PLTSerialProtocol.h>


void PLT_SerialSend(char* data)
{  
frame.dataLength=8;
frame.data[0]=data[0];
frame.data[1]=data[1];
frame.data[2]=data[2];
frame.data[3]=data[3];
frame.data[4]=data[4];
frame.data[5]=data[5];
frame.data[6]=data[6];
frame.data[7]=data[7];
	/*frame.data[1]=0;
    frame.data[2]=1;
	frame.data[3]=0;
	frame.data[4]=1;
	frame.data[5]=0;
	frame.data[6]=1;
	frame.data[7]=0;*/
    calculate_parity_and_checksum(frame.data, frame.dataLength, &frame.parity, &frame.checksum);
    EnableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);
    //while(TranferBit);
   // TX_PIN=1;

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
	frame.startBit=0;

	
}


void PLT_HandelSerialTransmit(void)
{  

	static char IndexOfBit=0;
    TranferBit=1;
	if(IndexOfBit>10)
	{
		TranferBit=0;
		IndexOfBit=0;
		DisableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);
	}
	switch (IndexOfBit) {
	    case 0:
	        TX_PIN=frame.startBit;
	    break;
	    
	    case 1 ... 8:
	         TX_PIN=frame.data[IndexOfBit-1];
	    break;
	    
	    case 9:
	        TX_PIN=frame.parity;
	    break;
	    
	    
	    case 10:
	        TX_PIN=1; // Send stop bit
	        break;
	    case 11:
	        if (frame.checksum & 1) 
	        {
	            TX_PIN=1;
	        }
	        else 
	        {
	            TX_PIN=0;
	        }
	        frame.checksum >>= 1; // Shift checksum to the right for the next bit
	    break;
	}
	
	
	IndexOfBit++;


};
