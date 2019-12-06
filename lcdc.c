#include <xc.h>
#include "LCDinicializacion.h"

#pragma config PLLDIV = 1       
#pragma config FOSC = INTOSC_HS 
#pragma config WDT = OFF        
#pragma config MCLRE = OFF      
#pragma config LVP = OFF 
#pragma PBADEN = OFF
#define _XTAL_FREQ 4000000L


void inst(){
    __delay_ms(10);
    on = 1;
    __delay_ms(10);
    on = 0;  
}



void main(){
    OSCCON = 0x62;
    INTCON2bits.RBPU = 0;
    ADCON1 = 0x0F; 
    CMCON=0xFF;
    CVRCONbits.CVREN=0;
    
    //incialización de puertos  B, C, D
    LATB  = 0;  
    LATC = 0;
    LATD = 0;

    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    
    TRISB = 0xF0;
    TRISC = 0x00;   
    TRISD = 0x00;
    
    //se limpian las variables
    on = 0;
    st = 0;
    wr = 0;
    
    
 LCDinicializacion();
    
     
while(1){
    st=1;
    __delay_ms(250);
    PORTB = 0;
    
    if(PORTB < 0xF0)
    {   
        //columna 4
        if (PORTBbits.RB7 == 0)
        {        
            PORTBbits.RB0 = 1;
            if (PORTBbits.RB7 == 1){
                PORTD = '4';
                inst();
                }
                PORTBbits.RB0 = 0;
                PORTBbits.RB1 = 1;

            if (PORTBbits.RB7 == 1){
                PORTD = '8';
                inst();}
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;

            if (PORTBbits.RB7 == 1){
                PORTD = 'C';
                inst();}
                PORTBbits.RB2 = 0;
                PORTBbits.RB3 = 1;

            if (PORTBbits.RB7 == 1){
                PORTD = '0';
                inst();}
                PORTBbits.RB7 = 0;
        }
         //columna 3 
        if (PORTBbits.RB6 == 0)
        {        
            PORTBbits.RB0 = 1;
            if (PORTBbits.RB6 == 1){
                PORTD = '3';
                inst();
                }
                PORTBbits.RB0 = 0;
                PORTBbits.RB1 = 1;

            if (PORTBbits.RB6 == 1){
                PORTD = '7';
                inst();
                }
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;

            if (PORTBbits.RB6 == 1){
                PORTD = 'B';
                inst();
                }
                PORTBbits.RB2 = 0;
                PORTBbits.RB3 = 1;

            if (PORTBbits.RB6 == 1){
                PORTD = 'F';
                inst();
                }
                PORTBbits.RB7 = 0;
        }
        //columna 2 
        if (PORTBbits.RB5 == 0)
        {        
            PORTBbits.RB0 = 1;
                if (PORTBbits.RB5 == 1){
                PORTD = '2';
                inst();
                }
                PORTBbits.RB0 = 0;
                PORTBbits.RB1 = 1;

            if (PORTBbits.RB5 == 1){
                PORTD = '6';
                inst();
                }
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;

            if (PORTBbits.RB5 == 1){
                PORTD = 'A';
                inst();
                }
                PORTBbits.RB2 = 0;
                PORTBbits.RB3 = 1;

            if (PORTBbits.RB5 == 1){
                PORTD = 'E';
                inst();
                PORTBbits.RB5 = 0;
        }
      }
      //columna 1 
        if (PORTBbits.RB4 == 0)
        {        
            PORTBbits.RB0 = 1;
            if (PORTBbits.RB4 == 1){
                PORTD = '1';
                inst();
                }
                PORTBbits.RB0 = 0;
                PORTBbits.RB1 = 1;

            if (PORTBbits.RB4 == 1){
                PORTD = '5';
                inst();
                }
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;

            if (PORTBbits.RB4 == 1){
                PORTD = '9';
                inst();
                }
                PORTBbits.RB2 = 0;
                PORTBbits.RB3 = 1;

            if (PORTBbits.RB4 == 1){
                PORTD = 'D';
                inst();
                }
                PORTBbits.RB4 = 0;
                
      }
    }
  }
}

   
