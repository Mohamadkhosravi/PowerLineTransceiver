#include"Timer.h"

#if BASE_TIMER 

	void TimerBaseInit(void)
	{
      _pscr = PRESCALER_CLOCK_SURSE_BASE_TIMER;
	 _tb0on = TIME_BASE0;
	 _tb1on = TIME_BASE1;
	 _tb0c |= TIM_BASE0_PERIOD;
     _tb1c |= TIM_BASE1_PERIOD;
	 InterruptEnable;
		  
	}
#endif

#if  STIMER
	void STimerInit(void){
	
			
		/*********************
		STPAU: STM Counter Pause Control
		0: Run
		1: Pause
		*/
		_stpau=0;
		 // Select STM Counter Clock
	    _stck0 = STIMER_CLOCK & 1;
	    _stck1 = (STIMER_CLOCK >> 1) & 1;
	    _stck2 = (STIMER_CLOCK >> 2) & 1;
		//STON: STM Counter On/Off Control
		_ston =1;	
		// Set STM Comparator P Match Period
		_strp0 = STM_PERIOD & 1;
		_strp1 = (STM_PERIOD >> 1) & 1;
		_strp2 = (STM_PERIOD >> 2) & 1;
		// Set STM Operating Mode
	
	// STM Operating Modes
		_stio0=STM_MODE&1;
		_stio1=(STM_MODE >> 1) & 1;
					
		_stio0=STM_PIN_FUNCTION&1;
		_stio1=(STM_PIN_FUNCTION>>1)&1;

		_stoc = STM_COUNTER ;
		_stpol =OUTPUT_POLARITY;
		_stdpx=	STM_PWM_DUTY;					
		_stcclr = SELECT_COMPARE_MATCH;		
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
			

		
		
		
	}
	
	int readSTimer(void){	
		return((_stmdl)|(_stmdh<<8));
			
	}
#endif	
