
#include "GPIO.h"

//
////===========================================================
////*@brief		: GPIO Init
////*@param[in]	: None
////*@retval		: None
////===========================================================
//void S_GPIO_Init()
//{
//	_pa = 0b00000000;
//	_pac= 0b00010001;
//	_papu=0b00000001;
//	_pawu=0b00000001;
//	_pas0=0b10000000;
//	_pas1=0b10010010;
//	
//	_pb = 0b00000000;
//	_pbc= 0b00000100;
//	_pbpu=0b00000100;
//	_pbs0=0b00001000;
//	_pbs1=0b00000000;
//	
//	_ifs0=0b00000000;
//
//}


void S_GPIO_Init()
{
//	_pa = 0b00000000;
	_pac= 0b00010001;
	_papu=0b00000001;
	_pawu=0b00000001;
	_pas0=0b00000000;
	_pas1=0b10010010;
	
   // _pb = 0b00000000;
	_pbc= 0b00000100;
	_pbpu=0b00000100;
	_pbs0=0b01000000;
	_pbs1=0b00000000;
	
	_ifs0=0b00000000;
	
	
	
//=====================================
	// Set PA6 as UART RX (input)
	_pac6 =1;//1: Input
	_pas15 = 1;_pas14 = 0;//PAS15~PAS14:10: SDI/SDA/RX
	_papu6=  1;  
//================================
	//(PLT TX)output
	_pbc1=0;// Set PB1 as UART TX (output 0 ) 
	_pbs03=1;_pbs02=0;//PAS03~PAS02:10: SDO/TX
//================================ 
	//PB3 RX (PLTRX)
	_pbc3=1;// Set PB3 as UART RX (input 1 )
	_pbs07=1;_pbs06=0;//PAS07~PAS06:10: SDI/SDA/RX

 //=================================== 
 // Set PA3 as UART TX (output)
   /* _pbs02 = 0;
    _pbs03 = 1;
*/
}	
	

	


//	_pac3=0;
//	_papu3=0;
//	_pas06=0;
//	_pas07=0;
//
//void S_GPIO_Init()
//{
//	_pa = 0b00000000;
//	_pac= 0b00000001;//I/O pin=input 1,output0.
//   
//	_papu=0b00000001;
//	_pawu=0b00000001;
//	_pas0=0b00000000;//PAS07~PAS06: PA3 Pin-Shared function selection 11: AN3
//	_pas1=0b10010000;
//	
//	_pb = 0b00000000;
//	_pbc= 0b00000100;//I/O pin=input 1,output0.
//    _pb3=1;
//	_pbpu=0b00000100;//PxPUn: I/O Port x Pin pull-high function control=> 0: Disable
//	
//	_pbs0=0b01000100;//PBS07~PBS06: PB3 Pin-Shared function selection 01: PLRX
//	_pbs1=0b00000000;
//	
//	_ifs0=0b00100010;
//	
//
//}


