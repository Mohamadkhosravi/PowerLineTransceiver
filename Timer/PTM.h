#ifndef PTIMER_H
#define PTIMER_H

#include <Main.h>

// PTM Counter Clock Selection
#define PT_SYS_DIVIDE_4     0
#define PT_SYS              1
#define PT_H_DIVIDE_16      2
#define PT_H_DIVIDE_64      3
#define PT_SUB1             4
#define PT_SUB2             5
#define PT_STCK_RISING      6
#define PT_STCK_FALLING     7
#define PTIMER_CLOCK        PT_SYS_DIVIDE_4

// PTM Comparator P Match Period
#define PTM_1024_CLOCKS     0
#define PTM_128_CLOCKS      1
#define PTM_256_CLOCKS      2
#define PTM_384_CLOCKS      3
#define PTM_512_CLOCKS      4
#define PTM_640_CLOCKS      5
#define PTM_768_CLOCKS      6
#define PTM_896_CLOCKS      7
#define PTM_PERIOD          PTM_1024_CLOCKS

// PTM Operating Modes
#define PTM_COMPARE_MATCH_OUTPUT_MODE   0
#define PTM_TIMER_COUNTER_MODE          1
#define PTM_CAPTURE_INPUT_MODE          2
#define PTM_PWM_OUTPUT_MODE             3
#define PTM_SINGLE_PULSE_OUTPUT_MODE    4
#define PTM_MODE            PTM_COMPARE_MATCH_OUTPUT_MODE

// PTM External Pins Function
#define PTM_NO_CHANGE       0
#define PTM_OUTPUT_LOW      1
#define PTM_OUTPUT_HIGH     2
#define PTM_TOGGLE_OUTPUT   3
#define PTM_PIN_FUNCTION   PTM_NO_CHANGE

// PTM Counter On/Off Control
#define PTM_COUNTER_ON      1
#define PTM_COUNTER_OFF     0
#define PTM_COUNTER         PTM_COUNTER_ON

// PTM Output Polarity
#define PTM_NON_INVERT      0
#define PTM_INVERT          1
#define PTM_OUTPUT_POLARITY PTM_NON_INVERT

// PTM PWM Duty/Period Control
#define PTM_DUTY            1
#define PTM_PERIOD          0
#define PTM_PWM_DUTY        PTM_DUTY

// PTM Comparator Clear Condition Selection
#define PTM_COMPARE_MATCH_P 0
#define PTM_COMPARE_MATCH_A 1
#define PTM_SELECT_COMPARE_MATCH    PTM_COMPARE_MATCH_P

void PTimerInit(void);
void PWMSeter(char status);

#endif
