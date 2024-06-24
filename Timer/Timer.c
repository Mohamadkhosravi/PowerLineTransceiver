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

