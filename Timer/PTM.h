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
//=========================================================================
#define PTIMER_CLOCK    PT_SYS   
//=========================================================================

// PTM Operating Modes
#define PTM_COMPARE_MATCH_OUTPUT_MODE          0
#define PTM_CAPTURE_INPUT_MODE                 1  
#define PTM_PWM_OR_SINGLE_PULSE_OUTPUT_MODE    2
#define PTM_TIMER_COUNTER_MODE                 3
//=========================================================================
#define PTM_MODE     PTM_COMPARE_MATCH_OUTPUT_MODE 
//=========================================================================

// PTM External Pins Function
//Compare Match Output Mode
#define PTM_NO_CHANGE       0
#define PTM_OUTPUT_LOW      1
#define PTM_OUTPUT_HIGH     2
#define PTM_TOGGLE_OUTPUT   3
//PWM Output Mode/Single Pulse Output Mode
#define PTM_PWM_INACTIVE          0
#define PTM_PWM_ACTIVE            1
#define PTM_PWM_OUTPUT            2
#define PTM_SINGLE_PULSE_OUTPUT   3
//=========================================================================
#define PTM_PIN_FUNCTION   PTM_NO_CHANGE
//=========================================================================

//Compare Match Output Mode
#define PTM_INITIAL_LOW 0
#define PTM_INITIAL_HIGH 1
//PWM Output Mode/Single Pulse Output Mode
#define PTM_ACTIVE_LOW 0
#define PTM_ACTIVE_HIGH 1
//=========================================================================
#define PTM_OUTPUT_MODE  PTM_INITIAL_LOW
//=========================================================================

// PTM Counter On/Off Control
#define PTM_COUNTER_OFF     0
#define PTM_COUNTER_ON      1

//=========================================================================
#define PTM_COUNTER         PTM_COUNTER_ON
//=========================================================================

// PTM Output Polarity
#define PTM_NON_INVERT      0
#define PTM_INVERT          1
//=========================================================================
#define PTM_OUTPUT_POLARITY  PTM_NON_INVERT
//=========================================================================
/*
// PTM PWM Duty/Period Control
#define PTM_DUTY            1
#define PTM_PERIOD          0
#define PTM_PWM_DUTY        PTM_DUTY
*/
// PTM Capture Trigger Source Selection*/
//=========================================================================
#define PTM_PTPI_INPUT 0
#define PTM_PTCK_INPUT 1
#define PTM_CAPTURE_TRIGGER  PTM_PTPI_INPUT
//=========================================================================

// PTM Comparator Clear Condition Selection
#define PTM_COMPARE_MATCH_P 0
#define PTM_COMPARE_MATCH_A 1
//=========================================================================
#define PTM_SELECT_CLEAR_COMPARE_MATCH    PTM_COMPARE_MATCH_P
//=========================================================================

// Select PTM Counter clear condition in capture input mode only
#define PTM_COMPARE_P_MATCH 0
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_RISING_EDGE 1
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_FALING_EDGE 2
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_DUAL_EDGE   3
//=========================================================================
#define PTM_SELECT_CLEAR_CONDITION_IN_CAPTURE_INPUT  PTM_COMPARE_P_MATCH
//=========================================================================
// PTM counter value latch edge flag
#define FALLING_EDGE_TRIAGE_COUNTER_LATCH 0
#define RISING_EDGE_TRIAGE_COUNTER_LATCH  1
//=========================================================================
#define COUNTER_VALUE_LATCH_EDGE  FALLING_EDGE_TRIAGE_COUNTER_LATCH
//=========================================================================

// PTM CCRA Low & High Byte Mask
//=========================================================================
#define PTM_CCRA_LOW_BYTE_MASK 0x01  // Mask for PTM CCRA low byte MAX=0xFF
#define PTM_CCRA_HIGH_BYTE_MASK 0 // Mask for PTM CCRA high byte MAX=0x3
//=========================================================================


// PTM CCRB Low & High Byte Mask
//=========================================================================
#define PTM_CCRB_LOW_BYTE_MASK 0x01  // Mask for PTM CCRB low byte MAX=0xFF
#define PTM_CCRB_HIGH_BYTE_MASK 0// Mask for PTM CCRB high byte MAX=0x3
//=========================================================================


// PTM CCRP Low & High Byte Mask
//=========================================================================
#define PTM_CCRP_LOW_BYTE_MASK 0x01  // Mask for PTM CCRP low byte  MIN =1 MAX=0xFF
#define PTM_CCRP_HIGH_BYTE_MASK 1 // Mask for PTM CCRP high byte MIN =1 MAX=0x3
//=========================================================================



void PTimerInit(void);

void PWMSeter(char status);
unsigned int readPTimer(void);   // Function to read STM timer value
#endif
