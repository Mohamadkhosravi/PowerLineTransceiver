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


// Initialize the Operational Amplifiers and ISINK
void InitOPA()
{SwitchType switches;
	
    // OPAMP0 initialization
    _sda0en =  OPAMP0_CONTROL;  // Enable OPAMP0
    _sda0bw1 = OPAMP0_BANDWIDTH >> 1; // Set OPAMP0 bandwidth to 600kHz
    _sda0bw0 = OPAMP0_BANDWIDTH & 1;

    // OPAMP1 initialization
    _sda1en = OPAMP1_CONTROL;  // Enable OPAMP1
    _sda1bw1 = OPAMP1_BANDWIDTH >> 1; // Set OPAMP1 bandwidth to 600kHz
    _sda1bw0 = OPAMP1_BANDWIDTH & 1;
    /*
    
    Sw.S0=0;
    Sw.S1=0;
    Sw.S2=1;
    
    Sw.S3=0;
    Sw.S4=0;
    Sw.S5=1;*/
    
    
	/*_sda0ofm=SDA0OFM(Sw.S0, Sw.S1, Sw.S2);  
	_sda0rsp=SDA0RSP(Sw.S0, Sw.S1, Sw.S2);  
	_sda1ofm=SDA1OFM(Sw.S3, Sw.S4, Sw.S5); 
	_sda1rsp=SDA1RSP(Sw.S3, Sw.S4, Sw.S5);*/


}

// Initialize ISINK (Sink current generator)
void InitISINK()
{/*

    _isinken0 = 1;  // Enable ISINK0
    _isinken1 = 1;  // Enable ISINK1*/
//    _isinkcfg0 = ISINK0_CURRENT_4MA;  // Set ISINK0 current to 4mA
  //  _isinkcfg1 = ISINK1_CURRENT_6MA;  // Set ISINK1 current to 6mA
}

// Calibrate OPAMP0 for input offset voltage
void CalibrateOPA0()
{
    unsigned char VAnOS1, VAnOS2, OffsetValue;
    unsigned char i=0;
  
    // Set OPAMP0 to offset calibration mode
    _sda0ofm = OPAMP_OFFSET_CAL_MODE;  // Enable offset calibration mode
    _sda0rsp = OPAMP_REF_A0PI;  // Use A0PI as reference
    
    // Find the minimum offset value
     SET_OFFSET_OPAMP0(OPAMP_OFFSET_MIN);
    while (_sda0o == 0);
    
    for ( i = OPAMP_OFFSET_MIN; i <= OPAMP_OFFSET_MAX; i++)
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
      OffsetValue=(char)(VAnOS1 + VAnOS2) / 2;
      SET_OFFSET_OPAMP0(OffsetValue);
}

// Calibrate OPAMP1 for input offset voltage
void CalibrateOPA1()
{
  unsigned char VAnOS1, VAnOS2, OffsetValue;
  unsigned char i=0;
  
    // Set OPAMP0 to offset calibration mode
    _sda1ofm = OPAMP_OFFSET_CAL_MODE;  // Enable offset calibration mode
    _sda1rsp = OPAMP_REF_A1PI;  // Use A0PI as reference
    
    // Find the minimum offset value
     SET_OFFSET_OPAMP1(OPAMP_OFFSET_MIN);
    while (_sda1o == 0);
    
    for ( i = OPAMP_OFFSET_MIN; i <= OPAMP_OFFSET_MAX; i++)
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
    while (_sda1o == 1);
    
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
      OffsetValue=(char)(VAnOS1 + VAnOS2) / 2;
      SET_OFFSET_OPAMP1(OffsetValue);
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

  /*  // Read smoke level from OPA1 output using ADC
      smokeLevel = ReadADC(OPA1O);  // Using previously implemented ReadADC function

   if (smokeLevel > SMOKE_THRESHOLD) {
        TriggerAlarm();  // Trigger alarm if smoke level is above threshold
        return 1;  // Smoke detected
    } else {
     ResetAlarm();  */
}