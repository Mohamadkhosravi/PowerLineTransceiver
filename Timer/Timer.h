
#include "BA45F5240.h"
#define TM_H
#ifdef TM_H

#define Enable  1
#define Disable 0

#define STIMER       Enable
#define PTIMER       Disable
#define BASE_TIMER   Enable

#define InterruptEnable      	_emi = Enable
#define InterruptDisable     	_emi = Disable
	
	
	
	
	
	
#if BASE_TIMER 


//TB1F: Time Base 1 interrupt request flag
//0: No request
//1: Interrupt request


//===========================================================
//  //TBnF: Time Base n interrupt request flag
//===========================================================

#define TIME_BASE0_INTRRUPT_FLAG  _tb0f
#define TIME_BASE1_INTRRUPT_FLAG  _tb1f


//===========================================================
//   CLKSEL1~CLKSEL0: Prescaler clock source selection
//===========================================================
#define FSYS           0 //fSYS
#define FSYS_DIVIDE_4  1 //fSYS/4
#define FSUB           2 //fSUB     

#define PRESCALER_CLOCK_SURSE_BASE_TIMER   FSYS_DIVIDE_4

//===========================================================
//             TBnON: Time Base n Control
//===========================================================
#define  TIME_BASE0  Enable
#define  TIME_BASE1  Disable

//===========================================================
//     TBn2~TBn0: Select Time Base n Time-out Period
//===========================================================
enum
{
 _256_DIVIDE_PSC , 
 _512_DIVIDE_PSC ,  
 _1024_DIVIDE_PSC,  
 _2048_DIVIDE_PSC,  
 _4096_DIVIDE_PSC,  
 _8192_DIVIDE_PSC,  
 _16384_DIVIDE_PSC , 
 _32768_DIVIDE_PSC,
 Default=0,  	
	
};
 #define TIM_BASE0_PERIOD   _32768_DIVIDE_PSC
 #define TIM_BASE1_PERIOD   Default	
//===========================================================
//    TBn2~TBn0: Select Time Base n Time-out Period
//===========================================================
	void TimerBaseInit(void);
		
#endif
	
#if STIMER
	
	 // #define _TIMER_COUNTER_MODE
	  #define COMPARE_MATCH_OUTPUT_MODE
		void STimerInit(void);
		int readSTimer(void);
		
#endif	
	
	
#if PTIMER
		
		
	void PTimerInit(void);
	void PWMSeter(char status);
	
	#define BUZZER_ON   PWMSeter(1);
    #define BUZZER_OFF  PWMSeter(0);
	
	
#endif
	


#endif
