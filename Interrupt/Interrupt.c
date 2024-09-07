#include <Interrupt.h>
#include <UART.h>
void IntrruptInit(void)
{
	GLOBAL_INTERRUPT = Enable;
	#if EXTERNAL_PIN0_ISR      
	_pltc0e=EXTERNAL_PIN0_ISR;
	#endif
	
	#if EXTERNAL_PIN0_ISR      
	_int0e=EXTERNAL_PIN0_ISR;
	#endif
	
	#if EXTERNAL_PIN1_ISR      
	_int1e=EXTERNAL_PIN1_ISR;
	#endif
	
	
	#if USIM_ISR
	_usime=USIM_ISR;             
	#endif
	
	#if LVD_ISR                
	_lve=LVD_ISR;
	#endif
	
	#if ADC_ISR                
	_ade=ADC_ISR;
	#endif
	
	#if EEPROM_ISR             
	_dee=EEPROM_ISR;
	#endif
	
	#if PTM_COMPAIR_P_ISR      
	_ptmpe=PTM_COMPAIR_P_ISR;
	#endif
	
	#if PTM_COMPAIR_A_ISR      
	_ptmae=PTM_COMPAIR_A_ISR;
	#endif
	
	#if STM_COMPAIR_P_ISR      
	_stmpe=STM_COMPAIR_P_ISR;
	#endif
	
	#if STM_COMPAIR_A_ISR      
	_stmae=STM_COMPAIR_A_ISR;
	#endif
	
	#if BASE_TIMER0_ISR        
	_tb0e=BASE_TIMER0_ISR;
	#endif
	
	#if BASE_TIMER1_ISR        
	_tb1e=BASE_TIMER1_ISR;
	#endif
	
	#if PLT_COMPAIR0_ISR       
	_pltc0e=PLT_COMPAIR0_ISR;
	#endif
	
	#if PLT_COMPAIR1_ISR       
	_pltc1e=PLT_COMPAIR1_ISR;
	#endif	

	
	
	//	_tb0e = 1;  
}
 // Function to enable a specific interrupt dynamically
void EnableInterrupt(char interruptAddress)
{
    switch (interruptAddress)
    {
		#if EXTERNAL_PIN0_ISR   
		   case EXTERNAL_PIN0_ISR_ADDRESS:
		   	 _int0e = Enable;
		    break;
		#endif	
		
		#if EXTERNAL_PIN1_ISR  
	    	case EXTERNAL_PIN1_ISR_ADDRESS:
		    	_int1e = Enable;
		    break;
		#endif	
		    
		#if USIM_ISR  
			case USIM_ISR_ADDRESS:
		    	_usime = Enable;
		    break;
		#endif	
		    
		#if LVD_ISR 
			case LVD_ISR_ADDRESS:
		    	_lve = Enable;
			break;
		#endif	
		
		#if ADC_ISR       
			case ADC_ISR_ADDRESS:
		  	  _ade = Enable;
		    break;
		#endif	
		
		#if EEPROM_ISR
			case EEPROM_ISR_ADDRESS:
		  	  _dee = Enable;
		    break;
		#endif
		
		#if PTM_COMPAIR_P_ISR          
			case PTM_COMPAIR_P_ISR_ADDRESS:
		  	  _ptmpe = Enable;
		    break;
		#endif  
		
		#if PTM_COMPAIR_A_ISR     
		case PTM_COMPAIR_A_ISR_ADDRESS:
		    _ptmae = Enable;
		    break;
		#endif 
		
		#if STM_COMPAIR_P_ISR      
			case STM_COMPAIR_P_ISR_ADDRESS:
		   	 _stmpe = Enable;
		   	//	_ston=1;
		    break;
		#endif 
		    
		#if STM_COMPAIR_A_ISR        
			case STM_COMPAIR_A_ISR_ADDRESS:
		    	_stmae = Enable;
		    //	_ston=1;
		    
		    break;
		#endif 
		
		#if  BASE_TIMER0_ISR   
			case BASE_TIMER0_ISR_ADDRESS:
		   	 _tb0e = Enable;
			break;
		#endif	
		
		#if  BASE_TIMER1_ISR 	
			case BASE_TIMER1_ISR_ADDRESS:
		   	 _tb1e = Enable;
			 break;
		#endif	
		
		#if  PLT_COMPAIR0_ISR       
			case PLT_COMPAIR0_ISR_ADDRESS:
				_pltc0e = Enable;
			break;
		#endif
      	      
		    
		#if  PLT_COMPAIR1_ISR       
			case PLT_COMPAIR1_ISR_ADDRESS:
		    	_pltc1e = Enable;
		    break;
		#endif
	
      	      
        default:
            // Handle invalid interrupt type
            break;
    }

}

void DisableInterrupt(char interruptAddress)
{
    switch (interruptAddress)
    {
		#if EXTERNAL_PIN0_ISR   
		   case EXTERNAL_PIN0_ISR_ADDRESS:
		   	 _int0e = Disable;
		    break;
		#endif	
		
		#if EXTERNAL_PIN1_ISR  
	    	case EXTERNAL_PIN1_ISR_ADDRESS:
		    	_int1e = Disable;
		    break;
		#endif	
		    
		#if USIM_ISR  
			case USIM_ISR_ADDRESS:
		    	_usime = Disable;
		    break;
		#endif	
		    
		#if LVD_ISR 
			case LVD_ISR_ADDRESS:
		    	_lve = Disable;
			break;
		#endif	
		
		#if ADC_ISR       
			case ADC_ISR_ADDRESS:
		  	  _ade = Disable;
		    break;
		#endif	
		
		#if EEPROM_ISR
			case EEPROM_ISR_ADDRESS:
		  	  _dee = Disable;
		    break;
		#endif
		
		#if PTM_COMPAIR_P_ISR          
			case PTM_COMPAIR_P_ISR_ADDRESS:
		  	  _ptmpe = Disable;
		    break;
		#endif  
		
		#if PTM_COMPAIR_A_ISR     
		case PTM_COMPAIR_A_ISR_ADDRESS:
		    _ptmae = Disable;
		    break;
		#endif 
		
		#if STM_COMPAIR_P_ISR      
			case STM_COMPAIR_P_ISR_ADDRESS:
		   	 _stmpe = Disable;
		   	 //_ston=0;
		  
		   	 
		    break;
		#endif 
		    
		#if STM_COMPAIR_A_ISR        
			case STM_COMPAIR_A_ISR_ADDRESS:
		    	_stmae = Disable;
		    //	_ston=0;
		    
		    break;
		#endif 
		
		#if  BASE_TIMER0_ISR   
			case BASE_TIMER0_ISR_ADDRESS:
		   	 _tb0e = Disable;
			break;
		#endif	
		
		#if  BASE_TIMER1_ISR 	
			case BASE_TIMER1_ISR_ADDRESS:
		   	 _tb1e = Disable;
			 break;
		#endif	
		
		#if  PLT_COMPAIR0_ISR       
			case PLT_COMPAIR0_ISR_ADDRESS:
				_pltc0e = Disable;
			break;
		#endif
		    
		#if  PLT_COMPAIR1_ISR       
			case PLT_COMPAIR1_ISR_ADDRESS:
		    	_pltc1e = Disable;
		    break;
		#endif
		
      	      
        default:
            // Handle invalid interrupt type
            break;
    }
}

////=======================================================================
// External Pin 0 Interrupt Service Routine
// This function handles the interrupt from external pin 0.
// It is executed when an interrupt is triggered by external pin 0.
//=========================================================================
#if EXTERNAL_PIN0_ISR
void __attribute__((interrupt(EXTERNAL_PIN0_ISR_ADDRESS))) ExternalPin0ISR(void)
{
    // Here goes the code for External Pin 0 ISR
}
#endif


//=========================================================================
// External Pin 1 Interrupt Service Routine
// This function handles the interrupt from external pin 1.
// It is executed when an interrupt is triggered by external pin 1.
//=========================================================================
#if EXTERNAL_PIN1_ISR
void __attribute__((interrupt(EXTERNAL_PIN1_ISR_ADDRESS))) ExternalPin1ISR(void)
{
    // Here goes the code for External Pin 1 ISR
}
#endif



//=========================================================================
// Universal Serial Interface Interrupt Service Routine
// This function handles the interrupt from Universal Serial Interface (USIM).
// It is executed when an interrupt is triggered by the USIM.
//=========================================================================
#if USIM_ISR

void __attribute__((interrupt(USIM_ISR_ADDRESS))) UniversalSerialInterfaceISR(void)
{
/*	_pa3=1;
	_nop();	
	_nop();		
	_nop();	
	_nop();	
	_nop();	
	_nop();		
	_nop();	
	_nop();	
	_pa3=0;
    // Here goes the code for Universal Serial Interface ISR*/
}
#endif


//=========================================================================
// Low Voltage Detect Interrupt Service Routine
// This function handles the interrupt from Low Voltage Detector (LVD).
// It is executed when an interrupt is triggered by the LVD.
//=========================================================================
#if LVD_ISR
void __attribute__((interrupt(LVD_ISR_ADDRESS))) LowVoltageDetectISR(void)
{
    // Here goes the code for Low Voltage Detect ISR
}
#endif


//=========================================================================
// EEPROM Interrupt Service Routine
// This function handles the interrupt from EEPROM.
// It is executed when an interrupt is triggered by the EEPROM.
//=========================================================================
#if EEPROMISR
void __attribute__((interrupt(EEPROM_ISR_ADDRESS))) EEPROMISR(void)
{
    // Here goes the code for EEPROM ISR
}
#endif


//=========================================================================
// PTM Comparator P Interrupt Service Routine
// This function handles the interrupt from PTM Comparator P.
// It is executed when an interrupt is triggered by PTM Comparator P.
//=========================================================================
#if PTM_COMPAIR_P_ISR
void __attribute__((interrupt(PTM_COMPAIR_P_ISR_ADDRESS))) PTMCompairPISR(void)
{
// static int cunt=0;
///	cunt++;
//	_pb1=1;		
//	if(cunt>=8){DisableInterrupt(PTM_COMPAIR_P_ISR_ADDRESS); }

    // Here goes the code for PTM Comparator P ISR
}
#endif


//=========================================================================
// PTM Comparator A Interrupt Service Routine
// This function handles the interrupt from PTM Comparator A.
// It is executed when an interrupt is triggered by PTM Comparator A.
//=========================================================================
#if PTM_COMPAIR_A_ISR
void __attribute__((interrupt(PTM_COMPAIR_A_ISR_ADDRESS))) PTMCompairAISR(void)
{
	// _pb1=0;
	//_pb1=~_pb1;	
    // Here goes the code for PTM Comparator A ISR
}
#endif


//=========================================================================
// STM Comparator P Interrupt Service Routine
// This function handles the interrupt from STM Comparator P.
// It is executed when an interrupt is triggered by STM Comparator P.
//=========================================================================
#if STM_COMPAIR_P_ISR
void __attribute__((interrupt(STM_COMPAIR_P_ISR_ADDRESS))) STMCompairPISR(void)
{	
		   
    // Here goes the code for STM Comparator P ISR 
    
}
#endif

//=========================================================================
// STM Comparator A Interrupt Service Routine
// This function handles the interrupt from STM Comparator A.
// It is executed when an interrupt is triggered by STM Comparator A.
//=========================================================================/*
#if STM_COMPAIR_A_ISR

void __attribute__((interrupt(STM_COMPAIR_A_ISR_ADDRESS))) STMCompairAISR(void)
{ 
    PLT_HandelSerialTransmit();  
    // Here goes the code for STM Comparator A ISR
}
#endif


//=========================================================================
// Base Timer 0 Interrupt Service Routine
// This function handles the interrupt from Base Timer 0.
// It is executed when an interrupt is triggered by Base Timer 0.
//=========================================================================
#if BASE_TIMER0_ISR
void __attribute__((interrupt(BASE_TIMER0_ISR_ADDRESS))) BaseTimer0ISR(void)
{ 
 // PLT_HandelSerialTransmit();  
    // Here goes the code for Base Timer 0 ISR
}
#endif


//=========================================================================
// Base Timer 1 Interrupt Service Routine
// This function handles the interrupt from Base Timer 1.
// It is executed when an interrupt is triggered by Base Timer 1.
//=========================================================================
#if BASE_TIMER1_ISR
void __attribute__((interrupt(BASE_TIMER1_ISR_ADDRESS))) BaseTimer1ISR(void)
{
 //RXbit=1;

    // Here goes the code for Base Timer 1 ISR
}
#endif


//=========================================================================
// PLT Comparator 1 Interrupt Service Routine
// This function handles the interrupt from PLT Comparator 1.
// It is executed when an interrupt is triggered by PLT Comparator 1.
//=========================================================================
#if PLT_COMPAIR1_ISR
void __attribute__((interrupt(PLT_COMPAIR1_ISR_ADDRESS))) PLT1CompairISR(void)
{ 
//	RXbit=0;
   /*counterR++;*/
  /* frameResive<<1;*/
   //frameResive|= 0<<counterR;
   _pa1=0;
	
//	_pb1=0;
//_pb1=~_pb1;
    // Here goes the code for PLT Comparator 1 ISR
}
#endif


//=========================================================================
// PLT Comparator 0 Interrupt Service Routine
// This function handles the interrupt from PLT Comparator 0.
// It is executed when an interrupt is triggered by PLT Comparator 0.
//=========================================================================
#if PLT_COMPAIR0_ISR
void __attribute__((interrupt(PLT_COMPAIR0_ISR_ADDRESS))) PLT0CompairISR(void){
/*counterR++;*/
 _pa1=1;
/*RXbit=1;*/
//frameResive <<= 1;
//frameResive |= 1;



//_pb1=1;
    // Here goes the code for PLT Comparator 0 ISR
}
#endif

