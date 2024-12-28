#ifndef _MAIN_H_
#define _MAIN_H_

#include "BA45F5240.h"
#include <PLT.h>
#include <UART.h>
#include <Interrupt.h>
#include <GPIO.h>	
#include "ADC.h"
#include "NTC.h"
#include "SmokeDetector.h"


typedef  unsigned char   uint8_t;  //0~255
typedef  unsigned int    uint16_t; //0~65535
typedef  unsigned long   uint32_t; //0~4294967295
typedef  char   int8_t;  //-128~127
typedef  int    int16_t; //-32 768~32 767
typedef  long   int32_t; //-2147483648~2147483647
typedef  enum{False,True} bool;


#define ADDRESS 'g'
#define PUBLIC_ADDRESS 'Z'
#define PRESSED_PUSHBUTTON  _pa0==0
#define PERRESS  10

#define LED         _pa4
#define ONE_SECOND  13000//tic 
#define LED_BLINKING_PERIOD   12 //sec
#define LED_BLINKING_ON_TIME  1000//us
#define CHEK_STATUS_PERIOD    2 //sec
#define VCC(ADC_BR)( 1.20*(4095.000/ADC_BR))



void info(void);


#endif