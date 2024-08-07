/*#include "A_USE_MACRO.h"*/
#include "RCC.h"


//===========================================================
//*@brief		: RCC Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_RCC_Init()
{
	_scc = 0b00000000;
	#if _HIRCC_8M
		_hircc=0b00001001;
	#elif _HIRCC_4M
		_hircc=0b00000101;
	#else
		_hircc=0b00000001;
	#endif
	
	_wdtc =0b10101111;

}


//===========================================================
//*@brief		: Timebase Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_Timebase_Init()
{
	_pscr=0b00000010;
	_tb0c=0b10000111;
	_tb1c=0b10000000;
	
	_tb1e=1;
	_tb1f=0;
	
	_tb0e=1;
	_tb0f=1;
	
	_emi=1;
  
}


