; Generated by holtek-gcc v3.19, Mon Oct 07 16:57:24 2024
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
___pa equ [20]
public _main
#pragma debug scope 2 1
#line 11 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
IFDEF WITH_DEFAULT_STARTUP
extern _main_initial0:near
extern _main_startup:near
ENDIF

ROMBANK 0 @start
@start .section com_l 'code'
_main_startup1:
@start .section com_e 'code'
	jmp _main

_main .section 'code'
_main proc
    local _main_2 db 2 dup(?)
#line 14 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _S_RCC_Init
#line 15 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _ADCInit
#line 16 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _S_GPIO_Init
#line 17 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _IntrruptInit
#line 18 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,-128
	mov _UART_Init_2[0],a
	mov a,37
	mov _UART_Init_2[1],a
	call _UART_Init
#line 19 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _PLT0Init
#line 20 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _PLT1Init
#line 21 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _PLTAInit
#line 22 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _InitSmokeDetection
_L3:
#line 47 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _OPA_ON
#line 48 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _ISINK0_ON
#line 52 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	set [20].7
#line 53 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,4
	call _ReadADC
	mov a,rb
	mov _builtin_holtek_mant1[1],a
	mov a,ra
	mov _builtin_holtek_mant1[0],a
	clr _builtin_holtek_signs.0
	call _builtin_holtek_uitod
	mov a,_builtin_holtek_mant12p[0]
	mov rh,a
	mov a,_builtin_holtek_mant1[2]
	mov rg,a
	mov a,_builtin_holtek_mant1[1]
	mov rf,a
	mov a,_builtin_holtek_mant1[0]
	mov re,a
	clr ra
	mov a,-16
	mov rb,a
	mov a,127
	mov rc,a
	mov a,69
	mov rd,a
	mov a,rd
	mov _builtin_holtek_mant12p[0],a
	mov a,rc
	mov _builtin_holtek_mant1[2],a
	mov a,rb
	mov _builtin_holtek_mant1[1],a
	mov a,ra
	mov _builtin_holtek_mant1[0],a
	mov a,rh
	mov _builtin_holtek_mant12p[1],a
	mov a,rg
	mov _builtin_holtek_mant2[2],a
	mov a,rf
	mov _builtin_holtek_mant2[1],a
	mov a,re
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtdiv
	mov a,_builtin_holtek_mant12p[0]
	mov rh,a
	mov a,_builtin_holtek_mant1[2]
	mov rg,a
	mov a,_builtin_holtek_mant1[1]
	mov rf,a
	mov a,_builtin_holtek_mant1[0]
	mov re,a
	mov a,rh
	mov _builtin_holtek_mant12p[0],a
	mov a,rg
	mov _builtin_holtek_mant1[2],a
	mov a,rf
	mov _builtin_holtek_mant1[1],a
	mov a,re
	mov _builtin_holtek_mant1[0],a
	mov a,63
	mov _builtin_holtek_mant12p[1],a
	mov a,153
	mov _builtin_holtek_mant2[2],a
	mov a,153
	mov _builtin_holtek_mant2[1],a
	mov a,154
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtmul
	mov a,_builtin_holtek_mant12p[0]
	mov rg,a
	mov a,_builtin_holtek_mant1[2]
	mov rf,a
	mov a,_builtin_holtek_mant1[1]
	mov re,a
	mov a,_builtin_holtek_mant1[0]
	mov rd,a
	mov a,re
	mov rc,a
	mov a,rf
	mov rd,a
	mov a,rg
	mov re,a
#line 54 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,re
	mov _builtin_holtek_mant1[2],a
	mov a,rd
	mov _builtin_holtek_mant1[1],a
	mov a,rc
	mov _builtin_holtek_mant1[0],a
	mov a,66
	mov _builtin_holtek_mant2[2],a
	mov a,200
	mov _builtin_holtek_mant2[1],a
	mov a,0
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_ftmul
	mov a,_builtin_holtek_mant1[2]
	mov re,a
	mov a,_builtin_holtek_mant1[1]
	mov rd,a
	mov a,_builtin_holtek_mant1[0]
	mov rc,a
	clr _builtin_holtek_mant12p[0]
	mov a,re
	mov _builtin_holtek_mant1[2],a
	mov a,rd
	mov _builtin_holtek_mant1[1],a
	mov a,rc
	mov _builtin_holtek_mant1[0],a
	call _builtin_holtek_ftol
	mov a,_builtin_holtek_mant12p[0]
	mov rg,a
	mov a,_builtin_holtek_mant1[2]
	mov rf,a
	mov a,_builtin_holtek_mant1[1]
	mov re,a
	mov a,_builtin_holtek_mant1[0]
	mov rd,a
	mov a,rd
	mov _main_2[0],a
	mov a,re
	mov _main_2[1],a
	snz re.7
	jmp _L2
	clr _main_2[0]
	clr _main_2[1]
_L2:
#line 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000>263690
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000of the argument exceeds the maxinum 263690'
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000<0
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000 of the argument exceeds the mininum 0'
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==0
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	JMP $
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==1
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==2
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==3
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000<8) AND (1000>3)
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAY3 + 7 -1000
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0404h) AND (1000>7)
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,1000/4-1
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX3 + 3 -(1000 MOD 4)
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0x40B) AND (1000> 0403h)
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0 
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX6 + 0x40a -1000
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)>256)
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY5 +5- (((1000-9)%0402h)%6)
	ENDIF
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)<=256)
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,((1000-9)%0402h)/4+1
;# 58 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY3 +3-(((1000-9)%0402h)%4)
	ENDIF
#line 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000>263690
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000of the argument exceeds the maxinum 263690'
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000<0
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000 of the argument exceeds the mininum 0'
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==0
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	JMP $
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==1
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==2
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==3
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000<8) AND (1000>3)
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAY3 + 7 -1000
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0404h) AND (1000>7)
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,1000/4-1
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX3 + 3 -(1000 MOD 4)
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0x40B) AND (1000> 0403h)
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0 
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX6 + 0x40a -1000
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)>256)
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY5 +5- (((1000-9)%0402h)%6)
	ENDIF
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)<=256)
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,((1000-9)%0402h)/4+1
;# 59 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY3 +3-(((1000-9)%0402h)%4)
	ENDIF
#line 60 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _ISINK0_OFF
#line 61 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	call _OPA_OFF
#line 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000>263690
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000of the argument exceeds the maxinum 263690'
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000<0
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 1000 of the argument exceeds the mininum 0'
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==0
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	JMP $
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==1
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==2
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 1000==3
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000<8) AND (1000>3)
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAY3 + 7 -1000
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0404h) AND (1000>7)
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,1000/4-1
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX3 + 3 -(1000 MOD 4)
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000< 0x40B) AND (1000> 0403h)
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0 
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX6 + 0x40a -1000
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)>256)
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY5 +5- (((1000-9)%0402h)%6)
	ENDIF
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)<=256)
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(1000-9)/0402h
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,((1000-9)%0402h)/4+1
;# 62 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY3 +3-(((1000-9)%0402h)%4)
	ENDIF
#line 63 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 63 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	clr wdt
#line 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000>263690
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 20000of the argument exceeds the maxinum 263690'
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000<0
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 20000 of the argument exceeds the mininum 0'
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==0
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	JMP $
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==1
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==2
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==3
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000<8) AND (20000>3)
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAY3 + 7 -20000
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000< 0404h) AND (20000>7)
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,20000/4-1
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX3 + 3 -(20000 MOD 4)
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000< 0x40B) AND (20000> 0403h)
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0 
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX6 + 0x40a -20000
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)>256)
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(20000-9)/0402h
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY5 +5- (((20000-9)%0402h)%6)
	ENDIF
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)<=256)
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(20000-9)/0402h
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,((20000-9)%0402h)/4+1
;# 64 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY3 +3-(((20000-9)%0402h)%4)
	ENDIF
#line 65 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 65 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	clr wdt
#line 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000>263690
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 20000of the argument exceeds the maxinum 263690'
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000<0
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	ERRMESSAGE 'the value 20000 of the argument exceeds the mininum 0'
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==0
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	JMP $
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==1
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==2
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF 20000==3
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	NOP
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000<8) AND (20000>3)
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAY3 + 7 -20000
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000< 0404h) AND (20000>7)
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,20000/4-1
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX3 + 3 -(20000 MOD 4)
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000< 0x40B) AND (20000> 0403h)
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0 
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYX6 + 0x40a -20000
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)>256)
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(20000-9)/0402h
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,0
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY5 +5- (((20000-9)%0402h)%6)
	ENDIF
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	IF (20000 >= 0x40b) AND ((((20000-9)%0402h)/4+1)<=256)
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,(20000-9)/0402h
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV _builtin_holtek_delay_2,A
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	MOV A,((20000-9)%0402h)/4+1
;# 66 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	CALL __DELAYY3 +3-(((20000-9)%0402h)%4)
	ENDIF
#line 68 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,_main_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_main_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,232
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,3
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[4]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[5]
	mov rc,a
	mov a,48
	addm a,rb
	mov a,rb
	call _UART_Transmit
#line 69 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,_main_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_main_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,100
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[4]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[5]
	mov rc,a
	mov a,48
	addm a,rb
	mov a,rb
	call _UART_Transmit
#line 70 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,_main_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_main_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[4]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[5]
	mov rc,a
	mov a,48
	addm a,rb
	mov a,rb
	call _UART_Transmit
#line 71 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,_main_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_main_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[4]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[5]
	mov rc,a
	mov a,48
	addm a,rb
	mov a,rb
	call _UART_Transmit
#line 72 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
	mov a,10
	call _UART_Transmit
#line 74 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
;# 74 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c" 1
	clr wdt
	jmp _L3
	jmp $
_main endp

@dummy proc
	call _main
@dummy endp

#line 74 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
#pragma debug scope 1 1
#line 8 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
public _temp
@HCCINIT0_temp .section 'data'
_temp	db 2 dup(0)
#pragma debug variable 12 1 _temp "temp"

@HCCINIT .section 'data'
#line 7 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
public _tx_busy
@HCCINIT0_tx_busy .section 'data'
_tx_busy	db 0
#pragma debug variable 7 1 _tx_busy "tx_busy"

@HCCINIT .section 'data'
#line 6 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
public _frame
@HCCINIT0_frame .section 'data'
_frame	db 2 dup(0)
#pragma debug pointer 42 10 1
#pragma debug variable 42 1 _frame "frame"

@HCCINIT .section 'data'
#pragma debug struct_begin 43 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 44 ""
#pragma debug field 2 43 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 44 1 ___pa "__pa" 1
#line 11 "c:\users\tech\desktop\powerlinetransceiver\Main\Main.c"
@code .section at 0 'code'
	jmp _main_startup1

extern _S_RCC_Init:near
extern _ADCInit:near
extern _S_GPIO_Init:near
extern _IntrruptInit:near
extern _UART_Init_2:byte
extern _UART_Init:near
extern _PLT0Init:near
extern _PLT1Init:near
extern _PLTAInit:near
extern _InitSmokeDetection:near
extern _OPA_ON:near
extern _ISINK0_ON:near
extern _ReadADC:near
extern _builtin_holtek_mant1:byte
extern _builtin_holtek_mant12p:byte
extern _builtin_holtek_signs:byte
extern _builtin_holtek_uitod:near
extern _builtin_holtek_mant2:byte
extern _builtin_holtek_dtdiv:near
extern _builtin_holtek_dtmul:near
extern _builtin_holtek_ftmul:near
extern _builtin_holtek_ftol:near
extern _ISINK0_OFF:near
extern _OPA_OFF:near
extern _builtin_holtek_divmodhi4:near
extern _builtin_holtek_udivmodhi4_2:byte
extern _builtin_holtek_udivmodhi4:near
extern _UART_Transmit:near

; 
; Generated by holtek-gcc v3.19, Mon Oct 07 16:57:24 2024
; Rebuild 718
; end of file
