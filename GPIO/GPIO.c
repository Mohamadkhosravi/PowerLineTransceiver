
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
	_pa = 0b00000000;
	_pac= 0b00010001;
	_papu=0b00001001;
	_pawu=0b00001001;
	_pas0=0b00000000;
	_pas1=0b10010010;
	
   // _pb = 0b00000000;
	_pbc= 0b00000100;
	_pbpu=0b00000100;
	_pbs0=0b01000000;
	_pbs1=0b00000000;


//=====================================
	// Set PA6 as UART RX (input)
	_pac6 =1;//1: Input
	_pas15 = 1;_pas14 = 0;//PAS15~PAS14:10: SDI/SDA/RX
/*	_papu6=  1;  */
//================================
/*	//(PLT TX)output
	_pbc1=0;// Set PB1 as UART TX (output 0 ) 
	_pbs03=1;_pbs02=0;//PAS03~PAS02:10: SDO/TX*/
	
//PBS03~PBS02: PB1 Pin-Shared function selection 01: PLTX
  _pbs03=0;_pbs02=1;
//================================ 
/*	///PB3 RX (PLTRX)
	_pbc3=1;// Set PB3 as UART RX (input 1 )
	_pbs07=1;_pbs06=0;//PAS07~PAS06:10: SDI/SDA/RX*/

 //=================================== 

	/*Bit 1~0 IFS01~IFS00: SDI/SDA/RX input source pin selection
	00: SDI/SDA/RX on PA2
	01: SDI/SDA/RX on PA6
	10: SDI/SDA/RX on PB3
	11: SDI/SDA/RX on PA2*/
     _ifs0=0b00000000;
	_ifs01=0;_ifs00=1;
//========================================================	
//// Set PA3 as UART TX (output)
////PAS07~PAS06: PA3 Pin-Shared function selection :01: SDO/TX
 //port A3 Share function PAS07~PAS06 TX(LED PIN):
	_pas06=1;
	_pas07=0;
}	
	

	




