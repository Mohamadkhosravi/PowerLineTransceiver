
#include "BA45F5240.h"
#define BTM_H
#ifdef BTM_H

//TBnON: Time Base 0 & 1 Control
#define Enable  1
#define Disable 0
//===========================================================
#define  TIME_BASE0  Enable
#define  TIME_BASE1  Enable
//===========================================================

//Timer base Interrupts Status and control
//===========================================================
#define InterruptEnable      	_emi = Enable
#define InterruptDisable     	_emi = Disable
#define TIME_BASE0_INTRRUPT_FLAG  _tb0f
#define TIME_BASE1_INTRRUPT_FLAG  _tb1f
//===========================================================

// CLKSEL1~CLKSEL0: Prescaler clock source selection
#define TB_FSYS           0 //fSYS
#define TB_FSYS_DIVIDE_4  1 //fSYS/4
#define TB_FSUB           2 //fSUB     
//===========================================================
#define PRESCALER_CLOCK_SURSE_BASE_TIMER   TB_FSUB
//===========================================================

// TBn2~TBn0: Select Time Base n Time-out Period
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
//===========================================================
 #define TIM_BASE0_PERIOD   Default
 #define TIM_BASE1_PERIOD   Default	
//===========================================================

// Function declaration
void TimerBaseInit(void);
		







#endif
