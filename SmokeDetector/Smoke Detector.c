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

/*#include "SmokeDetector.h"
#include "ADC.h"

// Initialize the Operational Amplifiers and ISINK
void InitOPA()
{
    // OPAMP0 initialization
    _sda0en = 1;  // Enable OPAMP0
    _sda0bw1 = 1; // Set OPAMP0 bandwidth to 600kHz
    _sda0bw0 = 0;

    // OPAMP1 initialization
    _sda1en = 1;  // Enable OPAMP1
    _sda1bw1 = 1; // Set OPAMP1 bandwidth to 600kHz
    _sda1bw0 = 0;
}

// Initialize ISINK (Sink current generator)
void InitISINK()
{
    _isinken0 = 1;  // Enable ISINK0
    _isinken1 = 1;  // Enable ISINK1
    _isinkcfg0 = 0b010;  // Set ISINK0 current to 4mA
    _isinkcfg1 = 0b011;  // Set ISINK1 current to 6mA
}

// Calibrate OPAMP0 for input offset voltage
void CalibrateOPA0()
{
    unsigned int VAnOS1, VAnOS2;
    
    // Set OPAMP0 to offset calibration mode
    _sda0ofm = 1;  // Enable offset calibration mode
    _sda0rsp = 1;  // Use A0PI as reference
    
    // Find the minimum offset value
    _sda0of = 0x00;
    while (_sda0o == 0);
    
    for (unsigned int i = 0; i < 64; i++)
    {
        _sda0of = i;
        if (_sda0o == 1)
        {
            VAnOS1 = i;
            break;
        }
    }

    // Set offset to maximum and reduce to find second offset value
    _sda0of = 0x3F;
    while (_sda0o == 1);
    
    for (unsigned int i = 63; i >= 0; i--)
    {
        _sda0of = i;
        if (_sda0o == 0)
        {
            VAnOS2 = i;
            break;
        }
    }

    // Store the final offset value
    _sda0of = (VAnOS1 + VAnOS2) / 2;
}

// Calibrate OPAMP1 for input offset voltage
void CalibrateOPA1()
{
    unsigned int VAnOS1, VAnOS2;

    // Set OPAMP1 to offset calibration mode
    _sda1ofm = 1;  // Enable offset calibration mode
    _sda1rsp = 1;  // Use A1PI as reference

    // Find the minimum offset value
    _sda1of = 0x00;
    while (_sda1o == 0);

    for (unsigned int i = 0; i < 64; i++)
    {
        _sda1of = i;
        if (_sda1o == 1)
        {
            VAnOS1 = i;
            break;
        }
    }

    // Set offset to maximum and reduce to find second offset value
    _sda1of = 0x3F;
    while (_sda1o == 1);

    for (unsigned int i = 63; i >= 0; i--)
    {
        _sda1of = i;
        if (_sda1o == 0)
        {
            VAnOS2 = i;
            break;
        }
    }

    // Store the final offset value
    _sda1of = (VAnOS1 + VAnOS2) / 2;
}

// Initialize the smoke detection system (AFE, OPAMP, ISINK, ADC)
void InitSmokeDetection()
{
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

    if (smokeLevel > SMOKE_THRESHOLD) {
        TriggerAlarm();  // Trigger alarm if smoke level is above threshold
        return 1;  // Smoke detected
    } else {
        ResetAlarm();  // Reset alarm if smoke level is below threshold
        return 0;  // No smoke detected
    }
}

// Trigger alarm when smoke is detected
void TriggerAlarm()
{
   // Activate alarm (e.g., LED or buzzer)
}

// Reset alarm when smoke level is below threshold
void ResetAlarm()
{
     // Deactivate alarm
}
