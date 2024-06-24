		
#include<PTM.h>


	void PTimerInit(void)
	{
		/*	
		Bit 6~4 PTCK2~PTCK0: Select PTM Counter clock
		000: fSYS/4
		001: fSYS
		010: fH/16
		011: fH/64
		100: fSUB
		101: fSUB
		110: PTCK rising edge clock
		111: PTCK falling edge clock	
			
		*/
		
		_ptck0=0;
		_ptck1=1;
		_ptck2=0;
		/************************
		Bit 7~6 PTM1~PTM0: Select PTM Operating Mode
		00: Compare Match Output Mode
		01: Capture Input Mode
		10: PWM Output Mode or Single Pulse Output Mode
		11: Timer/Counter Mode	
		*/
		_ptm0=0;
		_ptm1=1;	
		
		/*PTIO1~PTIO0: Select PTM External Pins Function/
		PWM Output Mode/Single Pulse Output Mode
		00: PWM output inactive state
		01: PWM output active state
		10: PWM output
		11: Single pulse output*/
		
		/*_ptio0=0;
		_ptio1=1;*/
		
		
		_ptio0=0;
		_ptio1=0;
		
		
		/*PTOC: PTM PTP Output control bit
		PWM Output Mode/Single Pulse Output Mode
		0: Active low
		1: Active high*/
		_ptoc=0;
		/*
		PTPOL: PTM PTP Output polarity Control
		0: Non-invert
		1: Invert*/
		_ptpol=0;
		/*PTCAPTS: PTM Capture Trigger Source Selection
		0: From PTPI input
		1: From PTCK input*/
		
		_ptcapts=0;
		
		
		/*
		PTCCLR: Select PTM Counter clear condition
		0: PTM Comparator P match
		1: PTM Comparator A match
		*/
		_ptcclr=1;
		
		
		
		
	}
	
	
	 void PWMSeter(char status)
	 {
	 	if(status==1)
	 	{
		 	//==================
			//PTM CCRA Low Byte
			 _ptmal=37;
			//PTM CCRA High Byte Register 
			_ptmah=0b00;
			//==================
			//*********************
			//==================
			
			//PTM CCRP Low Byte Register
			_ptmrpl=00;
			//PTM CCRP High Byte Register
			_ptmrph=0b00;
			
			//==================		
			/************************
			
			
			PTPAU: PTM Counter Pause Control
			0: Run
			1: Pause	
			*/	
			_ptpau=0;
			
			/*PTON: PTM Counter On/Off Control
			0: Off
			1: On
			*/
		   _pton=1;
			
	 	}
	 	else if(status==0)
	 	{
			_ptpau=1;
			_pton=0;
			_ptmrpl=0;
			_ptmal=0;
	 	}
	 	
	 }
