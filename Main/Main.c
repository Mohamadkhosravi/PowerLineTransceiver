/*#include<Main.h>*/
#include <main.h>
struct 
{
 unsigned int TemperatureValue;
 unsigned int  SmokeValue;	
}situation;


uint32_t    SecTick=0;
uint8_t     SecondsCounterLED=0;
uint8_t     SecondsCounterCheckStatus=0;
uint16_t    i=0;
uint8_t     pushButtonState=0;
uint8_t     AddresssValid=0;
uint32_t    PushButtonCounter=0;
uint8_t     LEDState=0;	

	
unsigned short *frame;
volatile char tx_busy;

void main()
{
    char Data=0;

    S_RCC_Init();
	S_GPIO_Init();	
	InterruptInit();
	UART_Init(9600);
	PLT0Init();
	PLT1Init();
	LED=0;
	while(1)
	{
		SmokeState Sm;
		if (PRESSED_PUSHBUTTON) {
			
		/*	pushButtonState = 1;  // Set push button state to pressed
			PushButtonCounter++;
		*/
		} 	
		else {
			
			if ((pushButtonState == 1) && ( PushButtonCounter > PERRESS)) {
				
				GCC_DELAY(10000);
				PLTAInit();	

			}
		
		}
		GCC_CLRWDT();
		Data=UART_ReceiveNonBlocking();
		GCC_CLRWDT();
	
		if(Data!=0){
			
		 	UART_Transmit(Data);
			if ((Data== ADDRESS) || (Data== PUBLIC_ADDRESS)) {
					
				AddresssValid=1; 
			 
			}	
			if((AddresssValid)&&(Data=='O')){
			
				GCC_DELAY(10000);
				PLTAInit();	
				UART_Transmit('O');
				info();
				AddresssValid=0;
		
			}
			if((AddresssValid)&&(Data=='C')){
				
				GCC_DELAY(10000);
				PLTAInit();	
				UART_Transmit('C');
				info();
				AddresssValid=0;
			
			}
			if((AddresssValid)&&(Data=='L')){
			    LEDState=1;
				AddresssValid=0;
			}	
			if((AddresssValid)&&(Data=='H')){
			    LEDState=0;
				AddresssValid=0;
			}	
		}
	    LED=LEDState;
		PLTAOFF();
		SecTick++;
		if(SecTick > ONE_SECOND ){
			
			SecondsCounterLED++;
			SecondsCounterCheckStatus++;
			SecTick=0;
		}
		
		if(SecondsCounterCheckStatus >= CHEK_STATUS_PERIOD){
			
			ADCInit();
			NTC_POWER_ON;
			situation.TemperatureValue=(temperature(ReadADC(1), 3.0f));
			NTC_POWER_OFF;
			InitSmokeDetection();
			CheckSmokeLevel(&situation.SmokeValue);
			if(situation.SmokeValue==0)	UART_Transmit('F');
			SmokeDetectionOFF();
			ADC_Inactive();	
			SecondsCounterCheckStatus=0;	
		 
			
		}
		if( SecondsCounterLED >= LED_BLINKING_PERIOD){
			
			LED=1;
			GCC_DELAY(LED_BLINKING_ON_TIME);
			LED=0;	
			SecondsCounterLED=0;
		}
	}
	
	
	
}


void info(void){
	
		UART_Transmit((situation.SmokeValue/1000)%10+0x30);
		UART_Transmit((situation.SmokeValue/100)%10+0x30);
		UART_Transmit((situation.SmokeValue/10)%10+0x30);
		UART_Transmit((situation.SmokeValue)%10+0x30);
		UART_Transmit('T');	
		UART_Transmit('=');
		UART_Transmit((situation.TemperatureValue/1000)%10+0x30);
		UART_Transmit((situation.TemperatureValue/100)%10+0x30);
		UART_Transmit((situation.TemperatureValue/10)%10+0x30);
		UART_Transmit((situation.TemperatureValue)%10+0x30);	
		UART_Transmit(10);
		AddresssValid=0;
	
}