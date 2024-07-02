	
#include<STM.h>

void STimerInit(void) {
    // STPAU: STM Counter Pause Control
    // 0: Run, 1: Pause
    _stpau = 0; // Set STM counter to run mode

    // Select STM Counter Clock
    _stck0 =  STIMER_CLOCK & 1;
    _stck1 = (STIMER_CLOCK >> 1) & 1;
    _stck2 = (STIMER_CLOCK >> 2) & 1;

    // STON: STM Counter On/Off Control
    _ston = STM_COUNTER; // Turn on STM counter

    // Set STM Comparator P Match Period
    _strp0 = STM_PERIOD & 1;
    _strp1 = (STM_PERIOD >> 1) & 1;
    _strp2 = (STM_PERIOD >> 2) & 1;

    // Set STM Operating Mode
    _stm0 = STM_MODE & 1;
    _stm1 = (STM_MODE >> 1) & 1;

    // Set STM Pin Function
    _stio0 = STM_PIN_FUNCTION & 1;
    _stio1 = (STM_PIN_FUNCTION >> 1) & 1;

    // Compare Match Output Mode
    _stoc =OUTPUT_MODE;//Output Control
    
    // Set STM Output Polarity
    _stpol = OUTPUT_POLARITY;

    // Set STM PWM Duty/Period Control
    _stdpx = STM_PWM_DUTY;

    // Set STM Compare Clear Condition
    _stcclr = SELECT_CLEAR_COMPARE_MATCH;

    // Set STM Comparator CCRA Low Byte
    _stmal = STM_CCRA_LOW_BYTE_MASK;

    // Set STM Comparator CCRA High Byte
    _stmah = STM_CCRA_HIGH_BYTE_MASK & 3;
    
}

int readSTimer(void) 
{
    // Read STM Timer Value
    return ((_stmdl) | (_stmdh << 8));
}
