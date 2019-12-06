list P=18F4585	
#include "p18f4585.inc"
    
CONFIG OSC = IRCIO67 ; CONFIG1H (0-3) = 0010: INTIO2 oscillator, Internal oscillator block, port function on RA6 and RA7.
CONFIG MCLRE = ON ; CONFIG3H.7 = 1: Pin de RESET habilitado y Entrada RE3 desactivado.
CONFIG PBADEN = OFF ; CONFIG3H.1 = 0: PORTB.0 -- PORTB.4 as Digital I/O.
CONFIG LVP = OFF ; CONFIG3H.2 = 0: Single-Supply ICSP disabled so that PORTB.5 works as Digital I/O.

CONFIG WDT = OFF
    
    
L1REG	EQU 0x10 ; Delays loop 1.
L2REG	EQU 0x11 ; Delays loop 2.
ACC	EQU 0x20 ; Counter Accumulator
SHOT	EQU 0x30 ; One-Shot Trigger
RB0	EQU 0x00 ; PORTB BIT #0
RB1	EQU 0x01 ; PORTB BIT #1

#define Button1 PORTB, RB0, A
#define Button2 PORTB, RB1, A
#define LED PORTB, RB3, A
   
#define ONS SHOT,0,  A

ORG 0X00000
;CLOCK FREQUENCY CONFIGURATION
; ============================
main: MOVLW B'01100000'		    ; 4 MHz internal oscillator
MOVWF OSCCON, A			    ; Oscilator configuration

; DISABLE PORT's ANALOG FUNCTIONS
SETF CMCON,A ; Comparators OFF, to use PORT_D's LSN
BCF CVRCON,CVREN,A ; Comparator Voltge Reference Module OFF
MOVLW 0x0F ; All ports as DIGITAL I/O
MOVWF ADCON1,A
    
; CONFIGURATION OF PORT B
; ========================
CLRF PORTB, A ; Initialize PORTB
CLRF LATB, A ; Clear PORTB
BSF TRISB, RB0 , A ; RB0 as Input
BSF TRISB, RB1 , A ; RB1 as Input
BCF TRISB, RB3 , A ; RB3 as Output   

; MAIN PROGRAM
; ==============
    MOVLW D'5' ;Load Counter's Accumulator
    MOVWF ACC
loop: BTFSC Button1 ; Check IF RB0 is ON, then One-Shot
    RCALL One_Shot
    BTFSC ONS ; Check IF One-Shot?s Trigger is ON, THEN Reset-One-Shot
    RCALL Reset_One_Shot
    BTFSS Button2 ; Check IF RB1 is ON THEN Clear
    BRA loop

clear:	BCF LED ; Apaga LED
	MOVLW D'5' ; Load Counter s Accumulator
	MOVWF ACC
	BRA loop
; One-Shot Subroutine
; ===================
One_Shot:   BTFSC ONS ; IF One-Shot's Trigger OFF THEN Continue
	    RETURN ; Else EXIT
	    RCALL Delay ; Eliminate Push Button's Bouncing
	    BTFSS Button1 ; IF RB0 still ON THEN Count and Set Trigger
	    RETURN ; ELSE EXIT
Count:
    DCFSNZ ACC,1,A ; Counter--, and IF Counter = 0
    BSF LED ; THEN Turn ON LED
    BSF ONS 
    
     Reset One-Shot Subroutine
; =====================
Reset_One_Shot:
    BTFSC Button1 ; IF RB0 ON THEN Exit
    RETURN
    RCALL Delay ; Eliminate Push Button's Bouncing
    BTFSS Button1 ; IF RB0 still OFF
    BCF ONS ; THEN Trigger OFF
    RETURN ; ELSE Exit
; Delay Subroutine
; =============
Delay: MOVLW D'13' ; Load first loop
    MOVWF L1REG
Loop1: MOVLW D'255'; Load second loop
    MOVWF L2REG
Loop2: 
     DECF L2REG,1,A ; Decrement L2Reg
    BNZ Loop2 ; IF L2Reg != 0 THEN goto Loop2
    DECF L1REG,1,A ; Decrement L1Reg
    BNZ Loop1 ; IF L1Reg != 0 THEN goto Loop1
    RETURN

END
    