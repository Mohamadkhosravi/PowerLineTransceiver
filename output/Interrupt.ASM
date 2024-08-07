; Generated by holtek-gcc v3.19, Sat Aug 03 18:07:40 2024
; 
; Configuration:
;       with long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
; SFR address of long-instruction arch:
;    mp0 = -1,1,0
;    mp1 = 4,3,2
;    mp2 = 14,13,12
;    tbp = 9,7,8
;    acc = 5
;    pcl = 6
;    status = 10
;    bp = 11
;    intc = 72
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [4]
acc equ [5]
bp equ [11]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
cz equ [10].6
sc equ [10].7
intc equ [72]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
___intc0 equ [72]
___intc2 equ [74]
___intc3 equ [75]
public _IntrruptInit
#pragma debug scope 2 1
#line 4 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
_IntrruptInit .section 'code'
_IntrruptInit proc
#line 5 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [72].0
#line 31 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [74].0
#line 35 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [74].1
#line 55 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [72].1
#line 59 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [75].2
	ret
_IntrruptInit endp
#line 59 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
public _EnableInterrupt
#pragma debug scope 3 1
#line 68 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
_EnableInterrupt .section 'code'
_EnableInterrupt proc
    local _EnableInterrupt_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _EnableInterrupt_2[0],a
#pragma debug variable 7 3 _EnableInterrupt_2+0 "interruptAddress"
#line 69 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	mov a,ra
	sub a,4
	sz z
	jmp _L4
	sub a,(32)-(4)
	sz z
	jmp _L5
#line 69 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	mov a,ra
	sub a,36
	sz z
	jmp _L6
	mov a,ra
	sub a,56
	snz z
	jmp _L2
#line 152 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [75].2
#line 153 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L2
_L5:
#line 109 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [74].0
#line 110 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L2
_L6:
#line 115 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [74].1
#line 116 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L2
_L4:
#line 145 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [72].1
_L2:
	ret
_EnableInterrupt endp
#line 145 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
public _DisableInterrupt
#pragma debug scope 4 1
#line 165 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
_DisableInterrupt .section 'code'
_DisableInterrupt proc
    local _DisableInterrupt_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisableInterrupt_2[0],a
#pragma debug variable 7 4 _DisableInterrupt_2+0 "interruptAddress"
#line 166 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	mov a,ra
	sub a,4
	sz z
	jmp _L11
	sub a,(32)-(4)
	sz z
	jmp _L12
#line 166 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	mov a,ra
	sub a,36
	sz z
	jmp _L13
	mov a,ra
	sub a,56
	snz z
	jmp _L9
#line 248 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	clr [75].2
#line 249 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L9
_L12:
#line 206 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	clr [74].0
#line 207 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L9
_L13:
#line 212 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	clr [74].1
#line 213 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	jmp _L9
_L11:
#line 242 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	clr [72].1
_L9:
	ret
_DisableInterrupt endp
#line 242 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
public _PTMCompairPISR
#pragma debug scope 5 1
#line 334 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
@PTMCompairPISR_code .section at 32 'code'
_PTMCompairPISR:
ifdef INTERRUPT_DELAY
	nop
endif
	reti
#line 334 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
public _PTMCompairAISR
#pragma debug scope 6 1
#line 352 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
@PTMCompairAISR_code .section at 36 'code'
_PTMCompairAISR:
ifdef INTERRUPT_DELAY
	nop
endif
	reti
#line 352 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
___pb equ [24]
public _PLT1CompairISR
#pragma debug scope 7 1
#line 425 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
@PLT1CompairISR_code .section at 56 'code'
ifdef INTERRUPT_DELAY
	nop
endif
	mov r1,a
	mov a,status
ifndef INTERRUPT_DELAY
	mov r2,a
endif
	jmp _PLT1CompairISR
#pragma debug scope 1 1
@dummy56 proc
	call _PLT1CompairISR
@dummy56 endp
#pragma debug scope 8 1
_PLT1CompairISR .section 'code'
_PLT1CompairISR proc
ifdef INTERRUPT_DELAY
	mov r2,a
endif
#line 426 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	clr [24].1
	mov a,r2
	mov status,a
	mov a,r1
	reti
_PLT1CompairISR endp

#line 426 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
public _PLT0CompairISR
#pragma debug scope 9 1
#line 439 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
@PLT0CompairISR_code .section at 4 'code'
ifdef INTERRUPT_DELAY
	nop
endif
	mov r1,a
	mov a,status
ifndef INTERRUPT_DELAY
	mov r2,a
endif
	jmp _PLT0CompairISR
#pragma debug scope 1 1
@dummy4 proc
	call _PLT0CompairISR
@dummy4 endp
#pragma debug scope 10 1
_PLT0CompairISR .section 'code'
_PLT0CompairISR proc
ifdef INTERRUPT_DELAY
	mov r2,a
endif
#line 440 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
	set [24].1
	mov a,r2
	mov status,a
	mov a,r1
	reti
_PLT0CompairISR endp

#line 440 "c:\users\tech\desktop\powerlinetransceiver\Interrupt\Interrupt.c"
#pragma debug scope 1 1
#pragma debug struct_begin 42 "__pb_bits"
#pragma debug field 21 8 0 1 "__pb0" ;0,1
#pragma debug field 21 8 0 1 "__pb1" ;1,1
#pragma debug field 21 8 0 1 "__pb2" ;2,1
#pragma debug field 21 8 0 1 "__pb3" ;3,1
#pragma debug field 21 8 0 1 "__pb4" ;4,1
#pragma debug field 21 8 0 3 ;5,3
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___pb "__pb" 1
#pragma debug struct_begin 44 "__intc0_bits"
#pragma debug field 21 8 0 1 "__emi" ;0,1
#pragma debug field 21 8 0 1 "__pltc0e" ;1,1
#pragma debug field 21 8 0 1 "__int0e" ;2,1
#pragma debug field 21 8 0 1 "__int1e" ;3,1
#pragma debug field 21 8 0 1 "__pltc0f" ;4,1
#pragma debug field 21 8 0 1 "__int0f" ;5,1
#pragma debug field 21 8 0 1 "__int1f" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___intc0 "__intc0" 1
#pragma debug struct_begin 46 "__intc2_bits"
#pragma debug field 21 8 0 1 "__ptmpe" ;0,1
#pragma debug field 21 8 0 1 "__ptmae" ;1,1
#pragma debug field 21 8 0 1 "__stmpe" ;2,1
#pragma debug field 21 8 0 1 "__stmae" ;3,1
#pragma debug field 21 8 0 1 "__ptmpf" ;4,1
#pragma debug field 21 8 0 1 "__ptmaf" ;5,1
#pragma debug field 21 8 0 1 "__stmpf" ;6,1
#pragma debug field 21 8 0 1 "__stmaf" ;7,1
#pragma debug struct_end
#pragma debug union_begin 47 ""
#pragma debug field 2 46 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 47 1 ___intc2 "__intc2" 1
#pragma debug struct_begin 48 "__intc3_bits"
#pragma debug field 21 8 0 1 "__tb0e" ;0,1
#pragma debug field 21 8 0 1 "__tb1e" ;1,1
#pragma debug field 21 8 0 1 "__pltc1e" ;2,1
#pragma debug field 21 8 0 1 ;3,1
#pragma debug field 21 8 0 1 "__tb0f" ;4,1
#pragma debug field 21 8 0 1 "__tb1f" ;5,1
#pragma debug field 21 8 0 1 "__pltc1f" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___intc3 "__intc3" 1
extern r1:byte
extern r2:byte

; 
; Generated by holtek-gcc v3.19, Sat Aug 03 18:07:40 2024
; Rebuild 718
; end of file
