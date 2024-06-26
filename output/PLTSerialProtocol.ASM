; Generated by holtek-gcc v3.19, Sat Jun 29 23:05:00 2024
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
public _calculate_parity_and_checksum
#pragma debug scope 2 1
#line 30 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
_calculate_parity_and_checksum .section 'code'
_calculate_parity_and_checksum proc
public _calculate_parity_and_checksum_2
    local _calculate_parity_and_checksum_2 db 7 dup(?)	; 7,0
#pragma debug pointer 42 7 2
#pragma debug variable 42 2 _calculate_parity_and_checksum_2+0 "data"
#pragma debug variable 7 2 _calculate_parity_and_checksum_2+2 "length"
#pragma debug variable 42 2 _calculate_parity_and_checksum_2+3 "parity"
#pragma debug variable 42 2 _calculate_parity_and_checksum_2+5 "checksum"
#line 34 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr rb
	clr rc
#line 32 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr ra
#line 31 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr rf
_L2:
#line 34 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_calculate_parity_and_checksum_2[2]
	mov rd,a
	clr re
	sz acc.7
	set re
	mov a,rb
	sub a,rd
	mov a,rc
	sbc a,re
	snz sc
	jmp _L5
#line 35 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,rb
	add a,_calculate_parity_and_checksum_2[0]
	mov mp,a
	mov a,rc
	adc a,_calculate_parity_and_checksum_2[1]
	mov sbp,a
	call _Crom2Prom
	mov rd,a
	mov a,rd
	xorm a,rf
#line 36 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,rd
	addm a,ra
#line 34 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	inc rb
	sz z
	inc rc
	jmp _L2
_L5:
#line 38 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,1
	andm a,rf
	mov a,_calculate_parity_and_checksum_2[3]
	mov mp,a
	mov a,_calculate_parity_and_checksum_2[4]
	mov sbp,a
	mov a,rf
	mov ir,a
#line 39 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_calculate_parity_and_checksum_2[5]
	mov mp,a
	mov a,_calculate_parity_and_checksum_2[6]
	mov sbp,a
	mov a,ra
	mov ir,a
	ret
_calculate_parity_and_checksum endp
#line 39 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
#pragma debug scope 1 1
public _PLT_SerialSend
#pragma debug scope 3 1
#line 5 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
_PLT_SerialSend .section 'code'
_PLT_SerialSend proc
public _PLT_SerialSend_2
    local _PLT_SerialSend_2 db 2 dup(?)	; 2,0
#pragma debug pointer 43 7 3
#pragma debug variable 43 3 _PLT_SerialSend_2+0 "data"
#line 6 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,8
	mov _frame[3],a
	clr _frame[4]
#line 7 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_PLT_SerialSend_2[0]
	mov rb,a
	mov a,_PLT_SerialSend_2[1]
	mov rc,a
	mov a,rb
	mov mp,a
	mov a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[5],a
#line 8 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,1
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[6],a
#line 9 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,2
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[7],a
#line 10 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,3
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[8],a
#line 11 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,4
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[9],a
#line 12 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,5
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[10],a
#line 13 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,6
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[11],a
#line 14 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,7
	add a,rb
	mov mp,a
	mov a,0
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov _frame[12],a
#line 22 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,low (offset _frame+14)
	mov _calculate_parity_and_checksum_2[5],a
	mov a,high (offset _frame+14)
	mov _calculate_parity_and_checksum_2[6],a
	mov a,low (offset _frame+17)
	mov _calculate_parity_and_checksum_2[3],a
	mov a,high (offset _frame+17)
	mov _calculate_parity_and_checksum_2[4],a
	mov a,8
	mov _calculate_parity_and_checksum_2[2],a
	mov a,low (offset _frame+5)
	mov _calculate_parity_and_checksum_2[0],a
	mov a,high (offset _frame+5)
	mov _calculate_parity_and_checksum_2[1],a
	call _calculate_parity_and_checksum
#line 23 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,40
	call _EnableInterrupt
	ret
_PLT_SerialSend endp
#line 23 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
#pragma debug scope 1 1
public _PLT_SerialInit
#pragma debug scope 4 1
#line 42 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
_PLT_SerialInit .section 'code'
_PLT_SerialInit proc
public _PLT_SerialInit_2
    local _PLT_SerialInit_2 db 2 dup(?)	; 2,0
#pragma debug variable 12 4 _PLT_SerialInit_2+0 "baudrate"
#line 43 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr _frame[0]
	ret
_PLT_SerialInit endp
#line 43 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
#pragma debug scope 1 1
___pa equ [20]
public _PLT_HandelSerialTransmit
#pragma debug scope 5 1
#line 50 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
_PLT_HandelSerialTransmit .section 'code'
_PLT_HandelSerialTransmit proc
    local _PLT_HandelSerialTransmit_2 db 1 dup(?)	; 0,1
#line 53 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,1
	mov _TranferBit[0],a
#line 54 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,10
	sub a,___IndexOfBit_2000[0]
	snz sc
	jmp _L9
#line 56 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr _TranferBit[0]
#line 57 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr ___IndexOfBit_2000[0]
#line 58 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,40
	call _DisableInterrupt
_L9:
#line 60 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,___IndexOfBit_2000[0]
	mov _PLT_HandelSerialTransmit_2[0],a
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,0
	sz z
	jmp _L11
	sub a,(1)-(0)
	sz z
	jmp _L12
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,2
	sz z
	jmp _L12
	sub a,(3)-(2)
	sz z
	jmp _L12
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,4
	sz z
	jmp _L12
	sub a,(5)-(4)
	sz z
	jmp _L12
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,6
	sz z
	jmp _L12
	sub a,(7)-(6)
	sz z
	jmp _L12
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,8
	sz z
	jmp _L12
	sub a,(9)-(8)
	sz z
	jmp _L13
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,10
	sz z
	jmp _L14
	mov a,_PLT_HandelSerialTransmit_2[0]
	sub a,11
	snz z
	jmp _L10
	jmp _L43
_L11:
#line 62 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_frame[0]
	and a,1
	mov ra,a
	jmp _L42
_L12:
#line 66 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_PLT_HandelSerialTransmit_2[0]
	mov rb,a
	clr rc
	sz acc.7
	set rc
	mov a,low (offset _frame+4)
	add a,rb
	mov mp,a
	mov a,high (offset _frame+4)
	adc a,rc
	mov sbp,a
	call _Crom2Prom
	mov ra,a
	mov a,1
	andm a,ra
_L42:
	swapa ra
	rr acc
	and a,0f8h
	mov ra,a
	clr [20].3
	mov a,ra
	orm a,[20]
#line 67 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	jmp _L10
_L13:
#line 70 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_frame[17]
	and a,1
	mov ra,a
	jmp _L42
_L14:
#line 75 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	set [20].3
#line 76 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	jmp _L10
_L43:
#line 78 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,_frame[14]
	mov rb,a
	mov a,_frame[15]
	mov rc,a
	snz rb.0
	jmp _L16
#line 80 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	set [20].3
	jmp _L17
_L16:
#line 84 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	clr [20].3
_L17:
#line 86 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	mov a,rb
	mov rd,a
	mov a,rc
	mov re,a
	clr c
	rrc re
	rrc rd
	mov a,rd
	mov _frame[14],a
	mov a,re
	mov _frame[15],a
_L10:
#line 91 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
	inca _PLT_HandelSerialTransmit_2[0]
	mov ___IndexOfBit_2000[0],a
	ret
_PLT_HandelSerialTransmit endp
#line 91 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
#pragma debug scope 1 1
@HCCINIT	.section 'data'
#line 52 "c:\users\tech\desktop\powerlinetransceiver\PLT\PLTSerialProtocol.c"
@HCCINIT___IndexOfBit_2000 .section 'data'
___IndexOfBit_2000 label byte
#pragma debug variable 7 5 ___IndexOfBit_2000 "IndexOfBit"
	db 0
@ROMDATA_BASE .section inpage 'code'
	db 0
@HCCINIT___IndexOfBit_2000 .section 'data'
#line 48 "C:\Users\Tech\Desktop\PowerLineTransceiver\PLT/PLTSerialProtocol.h"
public _frame
@HCCINIT0_frame .section 'data'
_frame	db 18 dup(0)
#pragma debug struct_begin 44 "PLTSerialProtocol"
#pragma debug field 0 8 "startBit"
#pragma debug field 0 8 "address"
#pragma debug field 0 8 "control"
#pragma debug field 0 10 "dataLength"
#pragma debug field 1 8 9 "data"
#pragma debug field 0 10 "checksum"
#pragma debug field 0 8 "stopBit"
#pragma debug field 0 8 "parity"
#pragma debug struct_end
#pragma debug variable 44 1 _frame "frame"

@HCCINIT .section 'data'
#line 30 "C:\Users\Tech\Desktop\PowerLineTransceiver\PLT/PLTSerialProtocol.h"
public _timerCuonter
@HCCINIT0_timerCuonter .section 'data'
_timerCuonter	db 2 dup(0)
#pragma debug variable 12 1 _timerCuonter "timerCuonter"

@HCCINIT .section 'data'
public _TranferBit
#line 28 "C:\Users\Tech\Desktop\PowerLineTransceiver\PLT/PLTSerialProtocol.h"
@HCCINIT_TranferBit .section 'data'
_TranferBit label byte
#pragma debug variable 7 1 _TranferBit "TranferBit"
	db 1
@ROMDATA_BASE .section inpage 'code'
	db 1
@HCCINIT_TranferBit .section 'data'
#pragma debug struct_begin 45 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 46 ""
#pragma debug field 2 45 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 46 1 ___pa "__pa" 1
extern _EnableInterrupt:near
extern _DisableInterrupt:near

; 
; Generated by holtek-gcc v3.19, Sat Jun 29 23:05:00 2024
; Rebuild 718
; end of file
