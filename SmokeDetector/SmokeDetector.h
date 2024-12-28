/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** 
 * @file SmokeDetector.h
 * @brief Header file for Smoke Detector configuration and operations.
 * 
 * This file contains detailed register configurations, macros, and function prototypes
 * for initializing and operating the smoke detection system using the AFE, OPAMP, ISINK, 
 * and ADC on the BA45F5240 microcontroller.
 * 
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#ifndef SMOKE_DETECTOR_H_
#define SMOKE_DETECTOR_H_
#include "BA45F5240.h"
#include <ADC.h>


typedef enum {
    Normal = 0,
    Detect = 1
} State;

typedef struct {
    unsigned int state : 2;
} SmokeState;


#define Disable 0
#define Enable  1

#define Open   0
#define Close  1

#define OFF    0
#define ON     1

#define USE_OF_OPAMP0   Enable
#define USE_OF_OPAMP1   Enable
#define SWITCH_CONTOROL Disable

typedef unsigned char uint8_t;
// --------- General Smoke Detection Settings ---------
#define SMOKE_THRESHOLD 4000  // Threshold for detecting smoke (can be adjusted based on requirements)

// --------- AFE Register Settings ---------
/**
 * SDSW Register Settings for controlling the OPAMP modes.
 * 
 * Mode control bits (SDS6, SDS5) define the mode of operation for the OPAMPs:
 * 00: External mode (external signals)
 * 01: AC coupling mode (reduced OPAMP1 gain due to on-resistance RON_S8)
 * 10: External mode
 * 11: DC coupling mode (connected to VBIAS, RON affects gain).
 */
#define SDSW_AC_COUPLING_MODE   0b01  // AC coupling mode
#define SDSW_DC_COUPLING_MODE   0b11  // DC coupling mode
#define SDSW_EXTERNAL_MODE      0b00  // External mode

// Switch control for SDS0-SDS6

#ifdef USE_OF_OPAMP0

#define R1  20//R1= SDA0PGA[5:0] � 100kO

#endif

#ifdef USE_OF_OPAMP1

#define  R2    25//R2= SDA1PGA[5:0] � 100kO
#define _10KR  0// 10kO
#define _20KR  1// 20kO
#define _30KR  2// 30kO
#define _40KR  3// 40kO
#define  R3   _10KR //SDA1PGA7 ~ SDA1PGA6: R3 resistance control
#endif
// --------- OPAMP Control ---------
/**
 * OPAMP Control Register (SDA0C and SDA1C)
 * Controls for enabling/disabling OPAMPs and bandwidth settings.
 */
#define OPAMP0_CONTROL  Enable
#define OPAMP1_CONTROL  Enable


// Bandwidth settings for OPAMP0 and OPAMP1
#define BANDWIDTH_5KHZ    0
#define BANDWIDTH_40KHZ   1
#define BANDWIDTH_600KHZ  2
#define BANDWIDTH_2MHZ    3

#define OPAMP0_BANDWIDTH   BANDWIDTH_2MHZ
#define OPAMP1_BANDWIDTH   BANDWIDTH_5KHZ

// --------- OPAMP Offset Calibration ---------
/**
 * OPAMP Offset Calibration Mode (SDA0VOS and SDA1VOS registers)
 * - Set the OPAMP into normal or offset calibration mode.
 * - Use the reference from A0PI/A0NI or A1PI/A1NI.
 * - Adjust the offset calibration values (6 bits: SDA0OF[5:0], SDA1OF[5:0]).
 */
#define OPAMP_OFFSET_CAL_MODE      1  // Enable offset calibration mode
#define OPAMP_NORMAL_MODE          0  // Disable offset calibration, normal operation

// Calibration reference selection
#define OPAMP_REF_A0PI             1  // Use A0PI as input reference for OPAMP0
#define OPAMP_REF_A0NI             0  // Use A0NI as input reference for OPAMP0
#define OPAMP_REF_A1PI             1  // Use A1PI as input reference for OPAMP1
#define OPAMP_REF_A1NI             0  // Use A1NI as input reference for OPAMP1

// Maximum and minimum offset values for calibration (6-bit)
#define OPAMP_OFFSET_MAX           0x3F  // Maximum value for offset calibration (63)
#define OPAMP_OFFSET_MIN           0x00  // Minimum value for offset calibration (0)
#define SET_OFFSET_OPAMP0(VALUE0)(_sda0vos|=0x3F&VALUE0);
#define SET_OFFSET_OPAMP1(VALUE1)(_sda1vos|=0x3F&VALUE1);


// --------- ISINK (Sink Current) Settings ---------
/**
 * ISINK (Sink Current) Generator Settings
 * - Configure the current settings for ISINK0 and ISINK1.
 * - These settings control the current output for specific pins.
 * -The sink current range is 50mA ~ 360mA.
 */
 
#define ISINK0_CONTOROL Enable
#define ISINK1_CONTOROL Disable
#define ISINK0_CURRENT	7  // Set ISINK0 current Current value (mA) = 50 + 10 � (ISGDATA0[4:0])
#define ISINK1_CURRENT	1  // Set ISINK1 current Current value (mA) = 50 + 10 � (ISGDATA0[4:0])





#ifdef SWITCH_CONTOROL 
typedef struct {
    uint8_t S0 : 1;
    uint8_t S1 : 1; 
    uint8_t S2 : 1;  
    uint8_t S3 : 1;  
    uint8_t S4 : 1; 
    uint8_t S5 : 1; 

} SwitchType;
#define SDA0OFM(S0, S1, S2)  (!( (S0) && (S1) && !(S2) ))
#define SDA0RSP(S0, S1, S2)  ( (S0) && !(S1) && (S2) )
#define SDA1OFM(S3, S4, S5)  (!( (S3) && (S4) && !(S5) ))
#define SDA1RSP(S3, S4, S5)  ( (S3) && !(S4) && (S5) )

#endif






// Function prototypes
void InitSmokeDetection();  // Initialize the smoke detection system
void CalibrateOPA0();       // Calibrate offset voltage for OPAMP0
void CalibrateOPA1();       // Calibrate offset voltage for OPAMP1
SmokeState CheckSmokeLevel(unsigned int *smokeLevel);     // Check if the smoke level exceeds the threshold
void TriggerAlarm();        // Trigger alarm when smoke is detected
void ResetAlarm();          // Reset alarm when smoke is not detected
void InitOPA();             // Initialize Operational Amplifiers (OPAs)
void InitISINK();           // Initialize ISINK (Sink current generator)


//===========================================================
//*@brief		: Open ISINK0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void ISINK0_ON();
void  ISINK1_ON();
void ISINK0_OFF();
void ISINK1_OFF();
void OPA_ON(void);
void OPA_OFF(void);

void SmokeDetectionOFF();

#endif // SMOKE_DETECTOR_H_

