/**
 * @file main.h
 * @brief Header file for gas and temperature monitoring system.
 *
 * This file contains macro definitions, type definitions, and function prototypes used in the main program.
 */

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

/*** Type Definitions ***/
typedef unsigned char uint8_t; /**< Unsigned 8-bit integer (0-255). */
typedef unsigned int uint16_t; /**< Unsigned 16-bit integer (0-65535). */
typedef unsigned long uint32_t; /**< Unsigned 32-bit integer (0-4294967295). */
typedef char int8_t; /**< Signed 8-bit integer (-128 to 127). */
typedef int int16_t; /**< Signed 16-bit integer (-32,768 to 32,767). */
typedef long int32_t; /**< Signed 32-bit integer (-2,147,483,648 to 2,147,483,647). */
typedef enum { False, True } bool; /**< Boolean type definition. */

/*** Macro Definitions ***/
#define ADDRESS 'g' /**< UART device address. */
#define PUBLIC_ADDRESS 'Z' /**< UART public address. */
#define PRESSED_PUSHBUTTON (_pa0 == 0) /**< Macro to check if the push button is pressed. */
#define PERRESS 10 /**< Button press threshold value. */

#define LED _pa4 /**< Macro to control the LED state. */
#define ONE_SECOND 13000 /**< System tick value for 1 second. */
#define LED_BLINKING_PERIOD 12 /**< LED blinking period in seconds. */
#define LED_BLINKING_ON_TIME 1000 /**< LED ON duration in microseconds. */
#define CHEK_STATUS_PERIOD 2 /**< Status check period in seconds. */
#define VCC(ADC_BR) (1.20 * (4095.000 / (ADC_BR))) /**< Macro to calculate voltage from ADC value. */

/*** Function Prototypes ***/
/**
 * @brief Transmit smoke and temperature information over UART.
 */
void info(void);

#endif
