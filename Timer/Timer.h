
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
//#define FSYS           0 //fSYS
//#define FSYS_DIVIDE_4  1 //fSYS/4
//#define FSUB           2 //fSUB     

#define PRESCALER_CLOCK_SURSE_BASE_TIMER   0

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
		

	


//#define TIMER_COUNTER_MODE
#define COMPARE_MATCH_OUTPUT_MODE

// STM Counter Clock Selection
// STM Counter Clock Selection
enum {
    FSYS_DIVIDE_4, 
    FSYS, 
    FH_DIVIDE_16, 
    FH_DIVIDE_64, 
    FSUB1, 
    FSUB2, 
    STCK_RISING, 
    STCK_FALLING
};
#define STIMER_CLOCK   FSYS_DIVIDE_4

// STM Comparator P Match Period
enum
{
    STM_1024_CLOCKS,
    STM_128_CLOCKS,
    STM_256_CLOCKS,
    STM_384_CLOCKS,
    STM_512_CLOCKS,
    STM_640_CLOCKS,
    STM_768_CLOCKS,
    STM_896_CLOCKS
};
#define STM_PERIOD  STM_1024_CLOCKS

// STM Operating Modes
#define COMPARE_MATCH_OUTPUT_MODE   0
#define TIMER_COUNTER_MODE          1
#define CAPTURE_INPUT_MODE          2
#define PWM_OUTPUT_MODE             3
#define SINGLE_PULSE_OUTPUT_MODE    4

#define STM_MODE  COMPARE_MATCH_OUTPUT_MODE

// STM External Pins Function
#define NO_CHANGE   0
#define OUTPUT_LOW  1
#define OUTPUT_HIGH 2
#define TOGGLE_OUTPUT 3

#define STM_PIN_FUNCTION  NO_CHANGE


#define STM_COUNTER_ON 1
#define STM_COUNTER_OFF 0
#define STM_COUNTER STM_COUNTER_ON

// STM Output Polarity
#define STM_NON_INVERT    0
#define STM_INVERT        1
#define OUTPUT_POLARITY STM_NON_INVERT

// STM PWM Duty/Period Control
#define STM_DUTY   1
#define STM_PERIOD  0
#define STM_PWM_DUTY STM_DUTY

/*
STCCLR: STM Counter Clear Condition Selection
0: Comparator P match
1: Comparator A match
This bit is used to select the
*/

#define  STM_COMPARE_MATCH_P 0
#define  STM_COMPARE_MATCH_A 1
#define  SELECT_COMPARE_MATCH STM_COMPARE_MATCH_P






void STimerInit(void);
int readSTimer(void);







#endif
