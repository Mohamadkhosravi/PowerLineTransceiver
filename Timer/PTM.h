	
#ifndef PTIMER_H
#define PTIMER_H
#include <Main.h>
			
	void PTimerInit(void);
	void PWMSeter(char status);
	#define BUZZER_ON   PWMSeter(1);
    #define BUZZER_OFF  PWMSeter(0);
	
	
#endif
	