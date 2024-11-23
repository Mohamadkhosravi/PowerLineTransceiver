#ifndef STIMER_H
#define STIMER_H

#include <Main.h>  // Assuming this includes necessary main header file

// STM Counter Clock Selection
#define ST_FSYS_DIVIDE_4   0
#define ST_FSYS            1
#define ST_FH_DIVIDE_16    2
#define ST_FH_DIVIDE_64    3
#define ST_FSUB1           4
#define ST_FSUB2           5
#define ST_STCK_RISING     6
#define ST_STCK_FALLING    7
//=========================================================================
#define STIMER_CLOCK    ST_FSYS  
//=========================================================================

// STM Comparator P Match Period
#define STM_1024_CLOCKS 0
#define STM_128_CLOCKS  1
#define STM_256_CLOCKS  2
#define STM_384_CLOCKS  3
#define STM_512_CLOCKS  4
#define STM_640_CLOCKS  5
#define STM_768_CLOCKS  6
#define STM_896_CLOCKS  7
//=========================================================================
#define STM_PERIOD    STM_1024_CLOCKS 
//=========================================================================

// STM Operating Modes
#define STM_COMPARE_MATCH_OUTPUT_MODE   0
#define STM_TIMER_COUNTER_MODE          1
#define STM_CAPTURE_INPUT_MODE          2
#define STM_PWM_OUTPUT_MODE             3
#define STM_SINGLE_PULSE_OUTPUT_MODE    4
//=========================================================================
#define STM_MODE     STM_COMPARE_MATCH_OUTPUT_MODE 
//=========================================================================

// STM External Pins Function
//Compare Match Output Mode
#define NO_CHANGE       0
#define OUTPUT_LOW      1
#define OUTPUT_HIGH     2
#define TOGGLE_OUTPUT   3
//PWM Output Mode/Single Pulse Output Mode
#define PWM_OUTPUT_INACTIVE_STATE 0
#define PWM_OUTPUT_ACTIVE_STATE   1
#define PWM_OUTPUT                2
#define SINGLE_PULSE_ACTIVE_STATE 3
//Capture Input Mode
#define INPUT_CAPTURE_AT_RISING_EDGE           0
#define INPUT_CAPTURE_AT_FULLING_EDGE          1
#define INPUT_CAPTURE_BOTH_RISING_FULLING_EDGE 2
#define INPUT_CAPTURE_DISABLE                  3
//=========================================================================
#define STM_PIN_FUNCTION    NO_CHANGE 
//=========================================================================

//Compare Match Output Mode
#define INITIAL_LOW 0
#define INITIAL_HIGH 1
//PWM Output Mode/Single Pulse Output Mode
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1
//=========================================================================
#define  STM_OUTPUT_MODE  INITIAL_LOW
//=========================================================================

// STM Counter On/Off Control
#define STM_COUNTER_OFF 0
#define STM_COUNTER_ON  1
//=========================================================================
#define STM_COUNTER     STM_COUNTER_ON  
//=========================================================================

// STM Output Polarity
#define STM_NON_INVERT  0
#define STM_INVERT      1
//=========================================================================
#define  STM_OUTPUT_POLARITY STM_NON_INVERT 
//=========================================================================

// STM PWM Duty/Period Control
#define STM_DUTY        1
#define STM_PERIOD      0
//=========================================================================
#define STM_PWM_DUTY    STM_DUTY  
//=========================================================================

// STM Comparator Clear Condition Selection
#define STM_COMPARE_MATCH_P 0
#define STM_COMPARE_MATCH_A 1
//=========================================================================
#define STM_SELECT_CLEAR_COMPARE_MATCH  STM_COMPARE_MATCH_P  
//=========================================================================

// STM CCRA Low Byte Mask
//=========================================================================
#define STM_CCRA_LOW_BYTE_MASK 0xFF// Mask for STM CCRA low byte Max=0xFF Min=1
//=========================================================================
// STM CCRA High Byte Mask
//=========================================================================
#define STM_CCRA_HIGH_BYTE_MASK 0x03 // Mask for STM CCRA high byte Max=0x03
//=========================================================================


// Function declarations
void STimerInit(void);  // Function to initialize STM
unsigned int readSTimer(void);   // Function to read STM timer value

#endif  // End of STIMER_H
