/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** 
 * @file SmokeDetector.c
 * @brief Implementation of smoke detector configuration and operations.
 * 
 * This file contains the implementation of functions to initialize the smoke detection system
 * using the AFE and OPAMP, and to read smoke levels using the ADC on the BA45F5240 microcontroller.
 * 
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include "SmokeDetector.h"
#include "ADC.h"

// Initialize the Operational Amplifiers and set the Coupling Mode (AC/DC)
void InitOPA()
{
#ifdef USE_OF_OPAMP0
    // OPAMP0 initialization
    _sda0en = OPAMP0_CONTROL;  // Enable OPAMP0
    _sda0bw1 = OPAMP0_BANDWIDTH >> 1; // Set OPAMP0 bandwidth to 600kHz
    _sda0bw0 = OPAMP0_BANDWIDTH & 1;

    // Configure coupling mode using SDSW register from the header
    _sds0 = (SDSW_AC_COUPLING_MODE & 0x01);   // Set S0 based on coupling mode
    _sds1 = (SDSW_AC_COUPLING_MODE & 0x02) >> 1;
    _sds2 = (SDSW_AC_COUPLING_MODE & 0x04) >> 2;
/*

_sds0=Close;
_sds1=Close;
_sds2=Close;*/

    // Close unused switches and open the necessary ones based on coupling mode
    _sds3 = Open;
    _sds4 = Open;

    // OPAMP0 offset mode and input reference selection
    _sda0ofm = OPAMP_NORMAL_MODE;   // Normal operation mode
    _sda0rsp = OPAMP_REF_A0NI;      // Reference input from A0NI

    // Set R1 resistance for OPAMP0
    _sdpgac0 |= 0x3F & R1;

#endif

#ifdef USE_OF_OPAMP1
    // OPAMP1 initialization
    _sda1en = OPAMP1_CONTROL;  // Enable OPAMP1
    _sda1bw1 = OPAMP1_BANDWIDTH >> 1; // Set OPAMP1 bandwidth to 600kHz
    _sda1bw0 = OPAMP1_BANDWIDTH & 1;

    // Configure coupling mode for OPAMP1 using SDSW register
    _sds5 = (SDSW_DC_COUPLING_MODE & 0x01);   // Set S5 based on coupling mode
    _sds6 = (SDSW_DC_COUPLING_MODE & 0x02) >> 1;

    // OPAMP1 offset mode and input reference selection
    _sda1ofm = OPAMP_NORMAL_MODE;   // Normal operation mode
    _sda1rsp = OPAMP_REF_A1NI;      // Reference input from A1NI

    // Set R2 and R3 resistances for OPAMP1
    _sdpgac1 |= 0x3F & R2;          // Set R2 resistance
    _sda1pga6 = R3 >> 1;            // Set R3 resistance (two bits)
    _sda1pga7 |= R3 & 1;

    // Calibration setup for OPAMP1 (Offset calibration mode)
    _sda1ofm = OPAMP_OFFSET_CAL_MODE;  // Enable offset calibration mode
    _sda1rsp = OPAMP_REF_A1PI;         // Use A1PI as reference for calibration

#endif
}

// Initialize ISINK (Sink current generator)
void InitISINK()
{
_isgen=1;	
#ifdef ISINK0_CONTOROL	
	_isgs0 = ISINK0_CONTOROL;
	_isgdata0 = ISINK0_CURRENT&0x31;
	
#endif
#ifdef ISINK1_CONTOROL	
	_isgs1 |= ISINK1_CONTOROL;
	_isgdata1 |= ISINK1_CURRENT&0x31;
#endif


/*    _isinken0 = 1;  // Enable ISINK0
    _isinken1 = 1;  // Enable ISINK1

    _isinkcfg0 = ISINK0_CURRENT_4MA;  // Set ISINK0 current to 4mA
    _isinkcfg1 = ISINK1_CURRENT_6MA;  // Set ISINK1 current to 6mA*/
}
#ifdef USE_OF_OPAMP0
// Calibrate OPAMP0 for input offset voltage
void CalibrateOPA0()
{
    unsigned char VAnOS1, VAnOS2, OffsetValue;
    unsigned char i = 0;

    // Set OPAMP0 to offset calibration mode
    _sda0ofm = OPAMP_OFFSET_CAL_MODE;  // Enable offset calibration mode
    _sda0rsp = OPAMP_REF_A0PI;  // Use A0PI as reference

    // Set system to DC coupling mode during calibration
    _sds3 = Open;    // Open S3 for DC coupling
    _sds4 = Close;   // Close S4 to apply bias

    // Find the minimum offset value
    SET_OFFSET_OPAMP0(OPAMP_OFFSET_MIN);
    while (_sda0o == 0);

    for (i = OPAMP_OFFSET_MIN; i <= OPAMP_OFFSET_MAX; i++)
    {
        SET_OFFSET_OPAMP0(i);

        if (_sda0o == 1)
        {
            VAnOS1 = i;
            break;
        }
    }

    // Set offset to maximum and reduce to find second offset value
    SET_OFFSET_OPAMP0(OPAMP_OFFSET_MAX);
    while (_sda0o == 1);

    for (i = OPAMP_OFFSET_MAX; i >= OPAMP_OFFSET_MIN; i--)
    {
        SET_OFFSET_OPAMP0(i);
        if (_sda0o == 0)
        {
            VAnOS2 = i;
            break;
        }
    }

    // Store the final offset value
    OffsetValue = (unsigned char)((VAnOS1 + VAnOS2) / 2);
    SET_OFFSET_OPAMP0(OffsetValue);

    // Restore the original coupling mode after calibration
    _sds3 = Close;   // Return to AC coupling or as configured
    _sds4 = Open;
}
#endif
// Calibrate OPAMP1 for input offset voltage
#ifdef USE_OF_OPAMP1
void CalibrateOPA1()
{
    unsigned char VAnOS1, VAnOS2, OffsetValue;
    unsigned char i = 0;

    // Set OPAMP1 to offset calibration mode
    _sda1ofm = OPAMP_OFFSET_CAL_MODE;  // Enable offset calibration mode
    _sda1rsp = OPAMP_REF_A1PI;  // Use A1PI as reference

    // Set system to DC coupling mode during calibration
    _sds3 = Open;    // Open S3 for DC coupling
    _sds4 = Close;   // Close S4 to apply bias

    // Find the minimum offset value
    SET_OFFSET_OPAMP1(OPAMP_OFFSET_MIN);
   // while (_sda1o == 0);

    for (i = OPAMP_OFFSET_MIN; i <= OPAMP_OFFSET_MAX; i++)
    {
        SET_OFFSET_OPAMP1(i);

        if (_sda1o == 1)
        {
            VAnOS1 = i;
            break;
        }
    }

    // Set offset to maximum and reduce to find second offset value
    SET_OFFSET_OPAMP1(OPAMP_OFFSET_MAX);
   // while (_sda1o == 1);

    for (i = OPAMP_OFFSET_MAX; i >= OPAMP_OFFSET_MIN; i--)
    {
        SET_OFFSET_OPAMP1(i);
        if (_sda1o == 0)
        {
            VAnOS2 = i;
            break;
        }
    }

    // Store the final offset value
    OffsetValue = (unsigned char)((VAnOS1 + VAnOS2) / 2);
    SET_OFFSET_OPAMP1(OffsetValue);

    // Restore the original coupling mode after calibration
    _sds3 = Close;   // Return to AC coupling or as configured
    _sds4 = Open;
}
#endif
// Initialize the smoke detection system (AFE, OPAMP, ISINK, ADC)
void InitSmokeDetection()
{
	
#ifdef USE_OF_OPAMP0
	CalibrateOPA0();
#endif
	
#ifdef USE_OF_OPAMP1
	CalibrateOPA1();
#endif
    InitOPA();      // Initialize Operational Amplifiers
    InitISINK();    // Initialize ISINK for current generation
    ADCInit();      // Initialize ADC for smoke sensor reading
}

// Check if the smoke level exceeds the threshold
int CheckSmokeLevel()
{
    unsigned int smokeLevel;

    // Read smoke level from OPA1 output using ADC
    smokeLevel = ReadADC(OPA1O);  // Using previously implemented ReadADC function

  /*  if (smokeLevel > SMOKE_THRESHOLD) {
        TriggerAlarm();  // Trigger alarm if smoke level is above threshold
        return 1;  // Smoke detected
    } else {
        ResetAlarm();  // Reset alarm if smoke level is below threshold
        return 0;  // No smoke detected
    }*/
}

// Trigger alarm when smoke is detected
void TriggerAlarm()
{
  //  _alarm_pin = 1;  // Activate alarm (e.g., LED or buzzer)
}

// Reset alarm when smoke level is below threshold
void ResetAlarm()
{
  //  _alarm_pin = 0;  // Deactivate alarm
}

