#include <xc.h>

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
//====================================================
#pragma config	FOSC = INTOSCIO_EC  //CONFIG1H (0-3) = 0010: Internal oscillator, port function on RA6, EC used by USB (INTIO)..
#pragma config	MCLRE = ON          // CONFIG3H.7 = 1: Pin de RESET habilitado y Entrada RE3 desactivado.
#pragma config	PBADEN = OFF        // CONFIG3H.1 = 0: PORTB.0 -- PORTB.4 as Digital I/O.
#pragma config	LVP = OFF           // CONFIG3H.2 = 0: Single-Supply ICSP disabled  so that PORTB.5 works as Digital I/O.

//PICIT-3 DEBUGGER SETUP CONFIGURATION BITS
//=========================================
#pragma config	WDT = OFF           // CONFIG2H (0) = 0: Watchdog Timer Disabled.

unsigned char ons = 0;
unsigned char acc = 0;

#define Button1 PORTBbits.RB0
#define Button2 PORTBbits.RB1
#define LED PORTBbits.RB2

void One_Shot(void);
void Reset_One_Shot(void);
void Delay(void);

void main(void){

   //CLOCK FREQUENCY CONFIGURATION
   //============================
   OSCCON = 0x60;                       // 4 MHz internal oscillator

   //DISABLE PORT's ANALOG FUNCTIONS
   //===============================
   CMCON = 0xFF;                        // Comparators OFF, to use PORT_Ds LSN
   CVRCONbits.CVREN = 0;                // Comparator Voltge Reference Module OFF
   ADCON1 = 0x0F;                       // All ports as DIGITAL I/O

   //CONFIGURATION OF PORTS A & B
   //============================
   PORTB = 0X00;
   LATB = 0X00;
   TRISBbits.TRISB0 = 1; // PORTB.0 as Input
   TRISBbits.TRISB1 = 1; // PORTB.1 as Input
   TRISBbits.TRISB2 = 0; // PORTB.3 as Output

   //TURN-ON LED
   //===========
   while(1){
       if (Button1 == 1) // IF RB0 ON THEN trigger the One-Shot.
       One_Shot();
       if (ons == 1) // IF One-Shot?s Trigger is ON THEN Reset-One-Shot
       Reset_One_Shot();
       if (Button2 == 1){ // IF Reset ON THEN:
       LED = 0; // Turn-OFF LED.
       acc = 0; // Restart Counter.
       }
    }  
  }
    void One_Shot(){
    if (ons == 1) // IF One-Shot has been triggered THEN EXIT.
    return;
    Delay(); // Eliminate Bouncing.
    if (Button1 == 1){ // IF RB0 still ON THEN:
    acc++; // Increase Counter.
    if (acc == 3) // IF Counter = 5 Then Turn-ON LED.
    LED= 1;
    ons = 1; // Turn-ON one-shot flag.
    }
  }
void Reset_One_Shot(){
    if (Button1 == 0) // IF RB0 OFF THEN Eliminate Bouncing
    Delay();
    else // ELSE EXIT
    return;
    if (Button1 == 0) // IF RB0 OFF THEN reset one-shot flag.
    ons = 0;
    }



void Delay(){
    unsigned char L1REG = 0;
    unsigned char L2REG;
    while(L1REG++ < 13){
    L2REG = 0;
    while(L2REG++ < 255);

    }
}