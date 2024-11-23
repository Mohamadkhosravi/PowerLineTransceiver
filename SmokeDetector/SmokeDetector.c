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
    _isgdata0 = ISINK0_CURRENT;
	_sdpgac0  = R1;
	_sdpgac1  = (R3<<6)+R2;
	_sda0c = 0b01000011;
	_sda1c = 0b01000011;
	_sdsw  = 0b01110111;
}

// Initialize ISINK (Sink current generator)
void InitISINK()
{
    _isgen=1;	
	_isgs0 = ISINK0_CONTOROL;
	_isgdata0 = ISINK0_CURRENT&0x31;
	
	_isgs1 |= ISINK1_CONTOROL;
	_isgdata1 |= ISINK1_CURRENT&0x31;

}

// Calibrate OPAMP0 for input offset voltage
void CalibrateOPA0()
{
unsigned char R_TMP0,R_TMP1;
	R_TMP0 = 0x00;
	R_TMP1 = 0x00;
	_sda0vos=0b11111111;
	GCC_DELAY(2000);
	while(_sda0o)
	{
		_sda0vos--;
		GCC_DELAY(2000);
	}
	R_TMP0=_sda0vos & 0b00111111;
	_sda0vos=0b11000000;
	GCC_DELAY(2000);
	while(!_sda0o)
	{
		_sda0vos++;
		GCC_DELAY(2000);
	}
	R_TMP1=_sda0vos & 0b00111111;
	_sda0vos=(R_TMP0+R_TMP1)/2;		
    
}

// Calibrate OPAMP1 for input offset voltage

void CalibrateOPA1()
{
    unsigned char R_TMP0,R_TMP1;
	R_TMP0 = 0x00;
	R_TMP1 = 0x00;
	_sda1vos = 0b11111111;
	GCC_DELAY(2000);
	while(_sda1o)
	{
		_sda1vos--;
		GCC_DELAY(2000);
	}
	R_TMP0=_sda1vos & 0b00111111;
	_sda1vos=0b11000000;
	GCC_DELAY(2000);
	while(!_sda1o)
	{
		_sda1vos++;
		GCC_DELAY(2000);
	}
	R_TMP1=_sda1vos & 0b00111111;
	_sda1vos=(R_TMP0+R_TMP1)/2;	
	   
}

// Initialize the smoke detection system (AFE, OPAMP, ISINK, ADC)
void InitSmokeDetection()
{
	InitOPA();      // Initialize Operational Amplifiers
	CalibrateOPA0();	
	CalibrateOPA1();
	OPA_ON();
	//ADCInit();      // Initialize ADC for smoke sensor reading
}

// Check if the smoke level exceeds the threshold
SmokeState CheckSmokeLevel(unsigned int *smokeLevel)
{
    SmokeState smoke;
	OPA_ON();
	ISINK0_ON();
	GCC_DELAY(1000);
	*smokeLevel=ReadADC(5);
	GCC_DELAY(1000);
	GCC_DELAY(1000);
	ISINK0_OFF();
	OPA_OFF();
	GCC_DELAY(1000);
	GCC_CLRWDT();
	GCC_DELAY(20000);
	GCC_CLRWDT();
	GCC_DELAY(20000);
	if (*smokeLevel > SMOKE_THRESHOLD) 
	{
	   smoke.state=Detect;
	}
	else
	{
	   smoke.state=Normal;	
	}
    return smoke;
    
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


//===========================================================
//*@brief		: Open ISINK0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void ISINK0_ON()
{
	_isgdata0 = ISINK0_CURRENT;
	_isgen=1;
	_isgs0=1;
}


//===========================================================
//*@brief		: Open ISINK1
//*@param[in]	: None
//*@retval		: None
//===========================================================
void  ISINK1_ON()
{
	_isgdata1 = ISINK1_CURRENT;
	_isgen=1;
	_isgs1=1;
}


//===========================================================
//*@brief		: Close ISINK0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void ISINK0_OFF()
{
	_isgen=0;
	_isgs0=0;
}


//===========================================================
//*@brief		: Close ISINK1
//*@param[in]	: None
//*@retval		: None
//===========================================================
void ISINK1_OFF()
{
	_isgen=0;
	_isgs1=0;
}


//===========================================================
//*@brief		: Open OPA
//*@param[in]	: None
//*@retval		: None
//===========================================================
void OPA_ON(void)
{
	_sda0en = 1;
	_sda1en = 1;
	_sds0   = 1;
}


//===========================================================
//*@brief		: Close OPA
//*@param[in]	: None
//*@retval		: None
//===========================================================
void  OPA_OFF(void)
{
	_sda0en = 0;
	_sda1en = 0;
	_sds0   = 0;
}


//===========================================================
//*@brief		: Open ISINK0 Delay
//*@param[in]	: None
//*@retval		: None
//*@note		: R_ISINK0_DELAY*50us
//===========================================================
void SmokeDitectionOFF(){
	
	
	 ISINK0_OFF();
	 ISINK1_OFF();
	 OPA_OFF();
	
}