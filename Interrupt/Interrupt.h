
#ifndef ISR_H__
#define ISR_H__
#include "BA45F5240.h"

#define Enable 1
#define Disable 0
extern unsigned short frame;
#define InterruptEnable      	1
#define InterruptDisable     	0

#define GLOBAL_INTERRUPT        _emi
#define EXTERNAL_PIN0_ISR      Disable
#define EXTERNAL_PIN0_ISR      Disable
#define USIM_ISR               Disable
#define LVD_ISR                Disable
#define ADC_ISR                Disable
#define EEPROM_ISR             Disable
#define PTM_COMPAIR_P_ISR      Disable
#define PTM_COMPAIR_A_ISR      Disable
#define STM_COMPAIR_P_ISR      Enable
#define STM_COMPAIR_A_ISR      Enable
#define BASE_TIMER0_ISR        Disable
#define BASE_TIMER1_ISR        Disable
#define PLT_COMPAIR1_ISR       Disable

void EnableInterrupt(char interrupt_type);
void DisableInterrupt(char interrupt_type);

 void update(unsigned short fr);

// Interrupt Vector Addresses
#define PLT_COMPAIR0_ISR_ADDRESS   0x04 // Priority 0 (High)
#define EXTERNAL_PIN0_ISR_ADDRESS  0x08 // Priority 1
#define EXTERNAL_PIN1_ISR_ADDRESS  0x0C // Priority 2
#define USIM_ISR_ADDRESS           0x10 // Priority 3 Universal Serial Interface
#define LVD_ISR_ADDRESS            0x14 // Priority 4 Low Voltage Detector
#define ADC_ISR_ADDRESS            0x18 // Priority 5 Analog to Digital Converter
#define EEPROM_ISR_ADDRESS         0x1C // Priority 6
#define PTM_COMPAIR_P_ISR_ADDRESS  0x20 // Priority 7
#define PTM_COMPAIR_A_ISR_ADDRESS  0x24 // Priority 8
#define STM_COMPAIR_P_ISR_ADDRESS  0x28 // Priority 9
#define STM_COMPAIR_A_ISR_ADDRESS  0x2C // Priority 10
#define BASE_TIMER0_ISR_ADDRESS    0x30 // Priority 11
#define BASE_TIMER1_ISR_ADDRESS    0x34 // Priority 12
#define PLT_COMPAIR1_ISR_ADDRESS   0x38 // Priority 13 (Low)







void IntrruptInit(void);
void __attribute__((interrupt(EXTERNAL_PIN0_ISR_ADDRESS))) ExternalPin0ISR(void);
void __attribute__((interrupt(EXTERNAL_PIN1_ISR_ADDRESS))) ExternalPin1ISR(void);
void __attribute__((interrupt(USIM_ISR_ADDRESS))) UniversalSerialInterfaceISR(void);
void __attribute__((interrupt(LVD_ISR_ADDRESS))) LowVoltageDetectISR(void);
void __attribute__((interrupt(EEPROM_ISR_ADDRESS))) EEPROMISR(void);
void __attribute__((interrupt(PTM_COMPAIR_P_ISR_ADDRESS))) PTMCompairPISR(void);
void __attribute__((interrupt(PTM_COMPAIR_A_ISR_ADDRESS))) PTMCompairAISR(void);
void __attribute__((interrupt(STM_COMPAIR_P_ISR_ADDRESS))) STMCompairPISR(void);
void __attribute__((interrupt(STM_COMPAIR_A_ISR_ADDRESS))) STMCompairAISR(void);
void __attribute__((interrupt(BASE_TIMER0_ISR_ADDRESS))) BaseTimer0ISR(void);
void __attribute__((interrupt(BASE_TIMER1_ISR_ADDRESS))) BaseTimer1ISR(void);
void __attribute__((interrupt(PLT_COMPAIR1_ISR_ADDRESS))) PLT1CompairISR(void);
void __attribute__((interrupt(PLT_COMPAIR0_ISR_ADDRESS))) PLT0CompairISR(void);
#endif