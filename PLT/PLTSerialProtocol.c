#include <PLTSerialProtocol.h>

unsigned short PLT_SerialSend(char* data,char dataLength )
{   unsigned short frame;
    char  parity;
    char  checksum;
    char i;
     char data1[8]={0,1,0,1,0,1,0,1};
    calculate_parity_and_checksum(&data1, dataLength, &parity, &checksum);
    // Construct the frame
    frame = 0;
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


//_pa3=~_pa3;


	_pa3=(frame)&1;
	if(frame==0)
	{
	 DisableInterrupt(STM_COMPAIR_A_ISR_ADDRESS); 
	}
    frame=((frame)>>1);

//  frame= frame>> 1; 
//  bitCount++;
}
//}
//flag=1;
//	a=a>>1;
//	if(IndexOfBit%2)_pa3=1;
//	else _pa3=0;
  /* ++IndexOfBit;
   if(IndexOfBit>=10)IndexOfBit=0;
   */
   
   /* char validatinBit=0;
	static char IndexOfBit=0;
    TranferBit=1;
	if(IndexOfBit>10)
	{
		TranferBit=0;
		IndexOfBit=0;
		DisableInterrupt(BASE_TIMER0_ISR_ADDRESS);
	    // DisableInterrupt(STM_COMPAIR_P_ISR_ADDRESS);
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
	
if(validatinBit==0)	
	IndexOfBit++;
	validatinBit=1;


};
*/
