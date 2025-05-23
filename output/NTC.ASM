; Generated by holtek-gcc v3.19, Mon Dec 30 10:52:37 2024
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
public _GetTemperatureFromSteinhart
#pragma debug scope 2 1
#line 101 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
_GetTemperatureFromSteinhart .section 'code'
_GetTemperatureFromSteinhart proc
public _GetTemperatureFromSteinhart_2
    local _GetTemperatureFromSteinhart_2 db 11 dup(?)	; 3,8
#pragma debug variable 28 2 _GetTemperatureFromSteinhart_2+0 "resistance"
#line 103 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,_GetTemperatureFromSteinhart_2[0]
	mov _log_2[1],a
	mov a,_GetTemperatureFromSteinhart_2[1]
	mov _log_2[2],a
	mov a,_GetTemperatureFromSteinhart_2[2]
	mov _log_2[3],a
	clr _log_2[0]
	call _log
	mov a,rd
	mov re,a
	mov a,rc
	mov rd,a
	mov a,rb
	mov rc,a
#line 104 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,re
	mov rg,a
	mov a,rd
	mov rf,a
	mov a,rc
	mov re,a
	clr rd
	mov a,rg
	mov _builtin_holtek_mant12p[0],a
	mov a,rf
	mov _builtin_holtek_mant1[2],a
	mov a,re
	mov _builtin_holtek_mant1[1],a
	mov a,rd
	mov _builtin_holtek_mant1[0],a
	mov a,57
	mov _builtin_holtek_mant12p[1],a
	mov a,90
	mov _builtin_holtek_mant2[2],a
	mov a,86
	mov _builtin_holtek_mant2[1],a
	mov a,127
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtmul
	mov a,_builtin_holtek_mant12p[0]
	mov _GetTemperatureFromSteinhart_2[6],a
	mov a,_builtin_holtek_mant1[2]
	mov _GetTemperatureFromSteinhart_2[5],a
	mov a,_builtin_holtek_mant1[1]
	mov _GetTemperatureFromSteinhart_2[4],a
	mov a,_builtin_holtek_mant1[0]
	mov _GetTemperatureFromSteinhart_2[3],a
	mov a,_GetTemperatureFromSteinhart_2[6]
	mov _builtin_holtek_mant12p[0],a
	mov a,_GetTemperatureFromSteinhart_2[5]
	mov _builtin_holtek_mant1[2],a
	mov a,_GetTemperatureFromSteinhart_2[4]
	mov _builtin_holtek_mant1[1],a
	mov a,_GetTemperatureFromSteinhart_2[3]
	mov _builtin_holtek_mant1[0],a
	mov a,58
	mov _builtin_holtek_mant12p[1],a
	mov a,167
	mov _builtin_holtek_mant2[2],a
	mov a,109
	mov _builtin_holtek_mant2[1],a
	mov a,98
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtadd
	mov a,_builtin_holtek_mant12p[0]
	mov _GetTemperatureFromSteinhart_2[6],a
	mov a,_builtin_holtek_mant1[2]
	mov _GetTemperatureFromSteinhart_2[5],a
	mov a,_builtin_holtek_mant1[1]
	mov _GetTemperatureFromSteinhart_2[4],a
	mov a,_builtin_holtek_mant1[0]
	mov _GetTemperatureFromSteinhart_2[3],a
	mov a,rg
	mov _builtin_holtek_mant12p[0],a
	mov a,rf
	mov _builtin_holtek_mant1[2],a
	mov a,re
	mov _builtin_holtek_mant1[1],a
	mov a,rd
	mov _builtin_holtek_mant1[0],a
	mov a,52
	mov _builtin_holtek_mant12p[1],a
	mov a,90
	mov _builtin_holtek_mant2[2],a
	mov a,74
	mov _builtin_holtek_mant2[1],a
	mov a,98
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtmul
	mov a,_builtin_holtek_mant12p[0]
	mov _GetTemperatureFromSteinhart_2[10],a
	mov a,_builtin_holtek_mant1[2]
	mov _GetTemperatureFromSteinhart_2[9],a
	mov a,_builtin_holtek_mant1[1]
	mov _GetTemperatureFromSteinhart_2[8],a
	mov a,_builtin_holtek_mant1[0]
	mov _GetTemperatureFromSteinhart_2[7],a
	mov a,_GetTemperatureFromSteinhart_2[10]
	mov _builtin_holtek_mant12p[0],a
	mov a,_GetTemperatureFromSteinhart_2[9]
	mov _builtin_holtek_mant1[2],a
	mov a,_GetTemperatureFromSteinhart_2[8]
	mov _builtin_holtek_mant1[1],a
	mov a,_GetTemperatureFromSteinhart_2[7]
	mov _builtin_holtek_mant1[0],a
	mov a,rg
	mov _builtin_holtek_mant12p[1],a
	mov a,rf
	mov _builtin_holtek_mant2[2],a
	mov a,re
	mov _builtin_holtek_mant2[1],a
	mov a,rd
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtmul
	mov a,_builtin_holtek_mant12p[0]
	mov _GetTemperatureFromSteinhart_2[10],a
	mov a,_builtin_holtek_mant1[2]
	mov _GetTemperatureFromSteinhart_2[9],a
	mov a,_builtin_holtek_mant1[1]
	mov _GetTemperatureFromSteinhart_2[8],a
	mov a,_builtin_holtek_mant1[0]
	mov _GetTemperatureFromSteinhart_2[7],a
	mov a,_GetTemperatureFromSteinhart_2[10]
	mov _builtin_holtek_mant12p[0],a
	mov a,_GetTemperatureFromSteinhart_2[9]
	mov _builtin_holtek_mant1[2],a
	mov a,_GetTemperatureFromSteinhart_2[8]
	mov _builtin_holtek_mant1[1],a
	mov a,_GetTemperatureFromSteinhart_2[7]
	mov _builtin_holtek_mant1[0],a
	mov a,rg
	mov _builtin_holtek_mant12p[1],a
	mov a,rf
	mov _builtin_holtek_mant2[2],a
	mov a,re
	mov _builtin_holtek_mant2[1],a
	mov a,rd
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
	mov a,_GetTemperatureFromSteinhart_2[6]
	mov _builtin_holtek_mant12p[0],a
	mov a,_GetTemperatureFromSteinhart_2[5]
	mov _builtin_holtek_mant1[2],a
	mov a,_GetTemperatureFromSteinhart_2[4]
	mov _builtin_holtek_mant1[1],a
	mov a,_GetTemperatureFromSteinhart_2[3]
	mov _builtin_holtek_mant1[0],a
	mov a,rg
	mov _builtin_holtek_mant12p[1],a
	mov a,rf
	mov _builtin_holtek_mant2[2],a
	mov a,re
	mov _builtin_holtek_mant2[1],a
	mov a,rd
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtadd
	mov a,_builtin_holtek_mant12p[0]
	mov rh,a
	mov a,_builtin_holtek_mant1[2]
	mov rg,a
	mov a,_builtin_holtek_mant1[1]
	mov rf,a
	mov a,_builtin_holtek_mant1[0]
	mov re,a
	clr ra
	clr rb
	mov a,-128
	mov rc,a
	mov a,63
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
	mov a,rf
	mov rc,a
	mov a,rg
	mov rd,a
	mov a,rh
	mov re,a
#line 105 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,re
	mov rg,a
	mov a,rd
	mov rf,a
	mov a,rc
	mov re,a
	clr rd
	mov a,rg
	mov _builtin_holtek_mant12p[0],a
	mov a,rf
	mov _builtin_holtek_mant1[2],a
	mov a,re
	mov _builtin_holtek_mant1[1],a
	mov a,rd
	mov _builtin_holtek_mant1[0],a
	mov a,67
	mov _builtin_holtek_mant12p[1],a
	mov a,136
	mov _builtin_holtek_mant2[2],a
	mov a,147
	mov _builtin_holtek_mant2[1],a
	mov a,51
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtsub
	mov a,_builtin_holtek_mant12p[0]
	mov rg,a
	mov a,_builtin_holtek_mant1[2]
	mov rf,a
	mov a,_builtin_holtek_mant1[1]
	mov re,a
	mov a,_builtin_holtek_mant1[0]
	mov rd,a
	mov a,rg
	mov _builtin_holtek_mant12p[0],a
	mov a,rf
	mov _builtin_holtek_mant1[2],a
	mov a,re
	mov _builtin_holtek_mant1[1],a
	mov a,rd
	mov _builtin_holtek_mant1[0],a
	mov a,65
	mov _builtin_holtek_mant12p[1],a
	mov a,32
	mov _builtin_holtek_mant2[2],a
	mov a,0
	mov _builtin_holtek_mant2[1],a
	mov a,0
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtdiv
	mov a,_builtin_holtek_mant12p[0]
	mov rg,a
	mov a,_builtin_holtek_mant1[2]
	mov rf,a
	mov a,_builtin_holtek_mant1[1]
	mov re,a
	mov a,_builtin_holtek_mant1[0]
	mov rd,a
#line 107 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,rg
	mov rc,a
	mov a,rf
	mov rb,a
	mov a,re
	mov ra,a
	ret
_GetTemperatureFromSteinhart endp
#line 107 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
#pragma debug scope 1 1
public _temperature
#pragma debug scope 3 1
#line 121 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
_temperature .section 'code'
_temperature proc
public _temperature_2
    local _temperature_2 db 9 dup(?)	; 5,4
#pragma debug variable 12 3 _temperature_2+0 "ADCValue"
#pragma debug variable 28 3 _temperature_2+2 "VDD"
#line 125 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,_temperature_2[1]
	mov _builtin_holtek_mant1[1],a
	mov a,_temperature_2[0]
	mov _builtin_holtek_mant1[0],a
	clr _builtin_holtek_signs.0
	call _builtin_holtek_uitod
	mov a,_builtin_holtek_mant12p[0]
	mov rg,a
	mov a,_builtin_holtek_mant1[2]
	mov rf,a
	mov a,_builtin_holtek_mant1[1]
	mov re,a
	mov a,_builtin_holtek_mant1[0]
	mov rd,a
	mov a,rg
	mov _builtin_holtek_mant12p[0],a
	mov a,rf
	mov _builtin_holtek_mant1[2],a
	mov a,re
	mov _builtin_holtek_mant1[1],a
	mov a,rd
	mov _builtin_holtek_mant1[0],a
	mov a,69
	mov _builtin_holtek_mant12p[1],a
	mov a,127
	mov _builtin_holtek_mant2[2],a
	mov a,224
	mov _builtin_holtek_mant2[1],a
	mov a,0
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_dtdiv
	mov a,_builtin_holtek_mant12p[0]
	mov _temperature_2[8],a
	mov a,_builtin_holtek_mant1[2]
	mov _temperature_2[7],a
	mov a,_builtin_holtek_mant1[1]
	mov _temperature_2[6],a
	mov a,_builtin_holtek_mant1[0]
	mov _temperature_2[5],a
	mov a,_temperature_2[2]
	mov re,a
	mov a,_temperature_2[3]
	mov rf,a
	mov a,_temperature_2[4]
	mov rg,a
	clr rd
	mov a,_temperature_2[8]
	mov _builtin_holtek_mant12p[0],a
	mov a,_temperature_2[7]
	mov _builtin_holtek_mant1[2],a
	mov a,_temperature_2[6]
	mov _builtin_holtek_mant1[1],a
	mov a,_temperature_2[5]
	mov _builtin_holtek_mant1[0],a
	mov a,rg
	mov _builtin_holtek_mant12p[1],a
	mov a,rf
	mov _builtin_holtek_mant2[2],a
	mov a,re
	mov _builtin_holtek_mant2[1],a
	mov a,rd
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
#line 128 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,_temperature_2[4]
	mov _builtin_holtek_mant1[2],a
	mov a,_temperature_2[3]
	mov _builtin_holtek_mant1[1],a
	mov a,_temperature_2[2]
	mov _builtin_holtek_mant1[0],a
	mov a,re
	mov _builtin_holtek_mant2[2],a
	mov a,rd
	mov _builtin_holtek_mant2[1],a
	mov a,rc
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_ftsub
	mov a,_builtin_holtek_mant1[2]
	mov rh,a
	mov a,_builtin_holtek_mant1[1]
	mov rg,a
	mov a,_builtin_holtek_mant1[0]
	mov rf,a
	mov a,re
	mov _builtin_holtek_mant1[2],a
	mov a,rd
	mov _builtin_holtek_mant1[1],a
	mov a,rc
	mov _builtin_holtek_mant1[0],a
	mov a,rh
	mov _builtin_holtek_mant2[2],a
	mov a,rg
	mov _builtin_holtek_mant2[1],a
	mov a,rf
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_ftdiv
	mov a,_builtin_holtek_mant1[2]
	mov re,a
	mov a,_builtin_holtek_mant1[1]
	mov rd,a
	mov a,_builtin_holtek_mant1[0]
	mov rc,a
#line 133 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
	mov a,re
	mov _builtin_holtek_mant1[2],a
	mov a,rd
	mov _builtin_holtek_mant1[1],a
	mov a,rc
	mov _builtin_holtek_mant1[0],a
	mov a,65
	mov _builtin_holtek_mant2[2],a
	mov a,32
	mov _builtin_holtek_mant2[1],a
	mov a,0
	mov _builtin_holtek_mant2[0],a
	call _builtin_holtek_ftmul
	mov a,_builtin_holtek_mant1[2]
	mov _GetTemperatureFromSteinhart_2[2],a
	mov a,_builtin_holtek_mant1[1]
	mov _GetTemperatureFromSteinhart_2[1],a
	mov a,_builtin_holtek_mant1[0]
	mov _GetTemperatureFromSteinhart_2[0],a
	call _GetTemperatureFromSteinhart
	ret
_temperature endp
#line 133 "c:\users\tech\desktop\powerlinetransceiver\NTC\NTC.c"
#pragma debug scope 1 1
extern _log_2:byte
extern _log:near
extern _builtin_holtek_mant1:byte
extern _builtin_holtek_mant2:byte
extern _builtin_holtek_mant12p:byte
extern _builtin_holtek_dtmul:near
extern _builtin_holtek_dtadd:near
extern _builtin_holtek_dtdiv:near
extern _builtin_holtek_dtsub:near
extern _builtin_holtek_signs:byte
extern _builtin_holtek_uitod:near
extern _builtin_holtek_ftsub:near
extern _builtin_holtek_ftdiv:near
extern _builtin_holtek_ftmul:near

; 
; Generated by holtek-gcc v3.19, Mon Dec 30 10:52:37 2024
; Rebuild 718
; end of file
