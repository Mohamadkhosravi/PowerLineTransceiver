/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** 
 * @file NTC.c
 * @brief Implementation file for NTC temperature calculations.
 * 
 * This file provides the implementation for calculating temperature using an NTC thermistor 
 * based on the ADC readings and the Steinhart-Hart equation.
 * 
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include "NTC.h"

#ifdef _USE_MATH_H
    // If _USE_MATH_H is defined, no additional code is needed since math.h is used.
#else
/**
 * @brief Custom natural logarithm function.
 * 
 * This function calculates the natural logarithm of a number using a series expansion.
 * 
 * @param x The input value for which the logarithm is to be calculated.
 * @return The natural logarithm of the input value.
 */
double custom_log(double x) {
    int n = 0;

    if (x <= 0) {
        return -1.0; // Logarithm is not defined for non-positive numbers
    }

    float epsilon = 1e-10; // A small value for accuracy
    float result = 0.0;
    float term = (x - 1) / (x + 1);
    float term_squared = term * term;
    float term_squared_power = term_squared;
    float current_term = term;

    for (n = 1; current_term > epsilon; n++) {
        result += current_term;
        current_term = term_squared_power * term;
        term_squared_power *= term_squared;
        current_term /= 2 * n + 1;
    }

    return 2 * result;
}
#endif

float temperature(unsigned int ADCValue, float VDD) {
	//if((ADCValue<=0)||(ADCValue>4098))ADCValue=0;
    // Calculate the voltage across the NTC using the provided macros/functions.
    float VNTC = CALCULATE_VNTC(ADCValue, ADCNumerOfbits, VDD);
    // Calculate the resistance of the NTC using the provided macros/functions.
    float RNTC = CALCULATE_RNTC(VNTC, VDD, RES_CONNECTED_TO_NTC);

    // Calculate the natural logarithm of the resistance.
    float logResistance = LOG_FUNCTION(RNTC);

    // Calculate the temperature in Celsius using the Steinhart-Hart equation.
    float temperatureCelsius = 1.0 / (A + B * logResistance + C * logResistance * logResistance * logResistance) - 273.15;
    
    // Return the temperature in degrees Celsius.
    return VNTC;
}
