#ifndef STIMER_H
#define STIMER_H

#include <Main.h>  // Assuming this includes necessary main header file

//#define TIMER_COUNTER_MODE
//#define COMPARE_MATCH_OUTPUT_MODE

// STM Counter Clock Selection
#define FSYS_DIVIDE_4   0
#define FSYS            1
#define FH_DIVIDE_16    2
#define FH_DIVIDE_64    3
#define FSUB1           4
#define FSUB2           5
#define STCK_RISING     6
#define STCK_FALLING    7
#define STIMER_CLOCK    FSYS_DIVIDE_4  // Default STM counter clock selection

// STM Comparator P Match Period
#define STM_1024_CLOCKS 0
#define STM_128_CLOCKS  1
#define STM_256_CLOCKS  2
#define STM_384_CLOCKS  3
#define STM_512_CLOCKS  4
#define STM_640_CLOCKS  5
#define STM_768_CLOCKS  6
#define STM_896_CLOCKS  7
#define STM_PERIOD      STM_1024_CLOCKS  // Default STM comparator P match period

// STM Operating Modes
#define COMPARE_MATCH_OUTPUT_MODE   0
#define TIMER_COUNTER_MODE          1
#define CAPTURE_INPUT_MODE          2
#define PWM_OUTPUT_MODE             3
#define SINGLE_PULSE_OUTPUT_MODE    4
#define STM_MODE        COMPARE_MATCH_OUTPUT_MODE  // Default STM operating mode

// STM External Pins Function
#define NO_CHANGE       0
#define OUTPUT_LOW      1
#define OUTPUT_HIGH     2
#define TOGGLE_OUTPUT   3
#define STM_PIN_FUNCTION    NO_CHANGE  // Default STM external pins function

// STM Counter On/Off Control
#define STM_COUNTER_OFF 0
#define STM_COUNTER_ON  1
#define STM_COUNTER     STM_COUNTER_ON  // Default STM counter on/off control

// STM Output Polarity
#define STM_NON_INVERT  0
#define STM_INVERT      1
#define OUTPUT_POLARITY STM_NON_INVERT  // Default STM output polarity

// STM PWM Duty/Period Control
#define STM_DUTY        1
#define STM_PERIOD      0
#define STM_PWM_DUTY    STM_DUTY  // Default STM PWM duty/period control

// STM Compare Match Selection
#define STM_COMPARE_MATCH_P 0
#define STM_COMPARE_MATCH_A 1
#define SELECT_COMPARE_MATCH STM_COMPARE_MATCH_P  // Default STM compare match selection

// STM CCRA Low Byte Mask
#define STM_CCRA_LOW_BYTE_MASK 0xFF  // Mask for STM CCRA low byte

// STM CCRA High Byte Mask
#define STM_CCRA_HIGH_BYTE_MASK 0x3  // Mask for STM CCRA high byte

// Function declarations
void STimerInit(void);  // Function to initialize STM
int readSTimer(void);   // Function to read STM timer value

#endif  // End of STIMER_H
