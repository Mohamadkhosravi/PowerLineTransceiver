#include"Timer.h"

#ifdef BASETIMER 

	void timerBaseInit(void)
	{
		
		/*
		CLKSEL1~CLKSEL0: Prescaler clock source selection
		00: fSYS
		01: fSYS/4
		1x: fSUB 
		*/  
		_pscr=0b00000001;
		
		/*  
		Bit 7 TBnON: Time Base n Control
		0: Disable
		1: Enabl 
		Bit 6~3 Unimplemented, read as “0
		Bit 2~0 TBn2~TBn0: Select Time Base n Time-out Period
		
		000: 28/fPSC
		001: 29/fPSC
		010: 210/fPSC
		011: 211/fPSC
		100: 212/fPSC
		101: 213/fPSC
		110: 214/fPSC
		111: 215/fPSC
		
		*/  
		_tb0c=0b00000000;
		_tb1c=0b10000111;
		
		_tb1e=1;
		_tb1f=0;
		
		_tb0e=1;
		_tb0f=0;
		
		_emi=1;
		  
	}
#endif

#ifdef  STIMER
	void STimerInit(void){
	
			
		/*********************
		STPAU: STM Counter Pause Control
		0: Run
		1: Pause
		*/
		_stpau=0;
		
		/********************
		STCK2~STCK0: Select STM Counter Clock
		000: fSYS/4
		001: fSYS
		010: fH/16
		011: fH/64
		100: fSUB
		101: fSUB
		110: STCK rising edge clock
		111: STCK falling edge clock
		*/
		_stck0=0;
		_stck1=0;
		_stck2=0;
		
		/*
		STON: STM Counter On/Off Control
		0: Off
		1: On
		This bit controls the overall on/off function of the STM
		*/
		_ston =1;
		
		/*		
		STRP2~STRP0: STM CCRP 3-bit register, compared with the STM counter bit 9~bit 7
		Comparator P Match Period =
		000: 1024 STM clocks
		001: 128 STM clocks
		010: 256 STM clocks
		011: 384 STM clocks
		100: 512 STM clocks
		101: 640 STM clocks
		110: 768 STM clocks
		111: 896 STM clocks
		*/		
		_strp0=0;
		_strp1=0;
		_strp2=0;
		
		#ifdef  _TIMER_COUNTER_MODE
			/*
			STM1~STM0: Select STM Operating Mode
			00: Compare Match Output Mode
			01: Capture Input Mode
			10: PWM Output Mode or Single Pulse Output Mode
			11: Timer/Counter Mode
			
			*/	
			_stm0=1;
			_stm1=1;
			/*
			STIO1~STIO0: Select STM External Pins Function
			Compare Match Output Mode
			STIO1~STIO0: Select STM External Pins Function
			Compare Match Output Mode
			00: No change
			01: Output low
			10: Output high
			11: Toggle output
			...	
			*/
			_stio0=0;
			_stio1=0;
				
		#endif
		#ifdef COMPARE_MATCH_OUTPUT_MODE
			/*
			STM1~STM0: Select STM Operating Mode
			00: Compare Match Output Mode
			01: Capture Input Mode
			10: PWM Output Mode or Single Pulse Output Mode
			11: Timer/Counter Mode
			*/	
			
			_stm0=0;
			_stm1=0;
			
			/*
			STIO1~STIO0: Select STM External Pins Function
			Compare Match Output Mode
			STIO1~STIO0: Select STM External Pins Function
			Compare Match Output Mode
			00: No change
			01: Output low
			10: Output high
			11: Toggle output
			...	
			*/
			
			_stio0=0;
			_stio1=0;
			
			/*
			STOC: STP Output Control
			Compare Match Output Mode
			0: Initial low
			1: Initial high
			*/
			_stoc =1;
			
			/*	STPOL: STP Output Polarity Control
			0: Non-invert
			1: Invert
		    */
		    
			_stpol =0;
			
			/*		
			STDPX: STM PWM Duty/Period Control
			0: CCRP – period; CCRA – duty
			1: CCRP – duty; CCRA – perio*d
			*/
			
			_stdpx=1;		
					
			/*
			STCCLR: STM Counter Clear Condition Selection
			0: Comparator P match
			1: Comparator A match
			This bit is used to select the
			*/
			_stcclr = 1;		
			/*
			D7~D0: STM CCRA Low Byte Register bit 7 ~ bit 0
			STM 10-bit CCRA bit 7 ~ bit 0
			*/
			_stmal=0b11111111;
			
			/*
			D9~D8: STM CCRA High Byte Register bit 1 ~ bit 0
			STM 10-bit CCRA bit 9 ~ bit 8
			*/
			_stmah=0b11;
	
	        _stmae=1;
	    	_stmaf=1;
			
		#endif
		
		
		
	}
	
	int readSTimer(void){	
		return((_stmdl)|(_stmdh<<8));
			
	}
#endif	
	
	
#ifdef PTIMER

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
		
		_ptio0=0;
		_ptio1=1;
		
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
			 _ptmal=18;
			//PTM CCRA High Byte Register 
			_ptmah=0b00;
			//==================
			//*********************
			//==================
			
			//PTM CCRP Low Byte Register
			_ptmrpl=37;
			//PTM CCRP High Byte Register
			_ptmrph=0b00;
			
			//==================		
			/************************
			/*
			
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
#endif	 