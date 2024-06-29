#ifndef RCC_H__
#define RCC_H__
#include "BA45F5240.h"
#define  Enable  1
#define  Disable 0
#define _HIRCC_4M  Enable 
#define _HIRCC_8M  Disable

void S_RCC_Init();
void S_Timebase_Init();


#endif  
