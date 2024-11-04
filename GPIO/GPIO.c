
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
	_pac= 0b0001001;
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
	
//=================================		
 _pac2=0;//0: outout (Configh for NTC_POWER_ON/OFF)
//PAS05~PAS04:00: PA2
_pas05=1;_pas04=1;	
_ifs00=1;_ifs01=0;//(Configh for PA6 RX UART )
//=================================	
//	_pac4=1;//1: outout
////10:AS11~PAS10: PA4 Pin10: AN0
//_pas11=1;_pas10=0;
//=================================
//	_pac7=0; //0: outout
	//PAS17~PAS16:00: PA7/STPI/PTPI
	//_pas17=0;_pas16=0;
	//(Configh for Read NTC ADC)
	//PAS17~PAS16:10: AN1
	_pas17=1;_pas16=0;

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
	_pbs07=0;_pbs06=1;//01: PLRX

 //=================================== 
 // Set PA4 as LED
    _pac4 = 0;//0: outout
   //PAS11~PAS10:00 PA4/PTCK
   //_pas11=0;_Pas10=0;
   _pas10=0;_pas11=0;

//=======================================
//UART TX PAS07~PAS06: PA3 Pin 01: SDO/TX
// UART TX for debuge
//PAS17~PAS16: (PA7) 10: AN1
_pas07=0;_pas06=1;



 //=================================== 
	_pac1 = 0;//0: outout
	//PAS03~PAS02: PA1 00: PA1/INT1
	_pas03=0;_pas02=0;

 //=================================== 
	_pac0 =1;//1: Input
	
	//PA0 key  PAS01~PAS00 :00 :PA0
	_pas01=0;_pas00=0;


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



