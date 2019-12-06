#include <xc.h>
#define Enable PORTCbits.RC2
#define RW PORTCbits.RC1
#define RS PORTCbits.RC0

void Enviar(void){
    __delay_ms(1);
    Enable=1;
    __delay_ms(1);
     Enable =0;
     __delay_ms(250);
     PORTD=0x01;
     return;
    }

void tecla_1(){PORTD='1';Enviar();}
void tecla_2(){PORTD='2';Enviar();}
void tecla_3(){PORTD='3';Enviar();}
void tecla_4(){PORTD='A';Enviar();}
void tecla_5(){PORTD='4';Enviar();}
void tecla_6(){PORTD='5';Enviar();}
void tecla_7(){PORTD='6';Enviar();}
void tecla_8(){PORTD='B';Enviar();}
void tecla_9(){PORTD='7';Enviar();}
void tecla_10(){PORTD='8';Enviar();}
void tecla_11(){PORTD='9';Enviar();}
void tecla_12(){PORTD='C';Enviar();}
void tecla_13(){PORTD='*';Enviar();}
void tecla_14(){PORTD='0';Enviar();}
void tecla_15(){PORTD='#';Enviar();}
void tecla_16(){PORTD='D';Enviar();}

void columna1(){
    PORTB=0x0E;
    if(PORTBbits.RB7==1){
        PORTB=0x0D;
        if(PORTBbits.RB7==1){
            PORTB=0x0B;
            if(PORTBbits.RB7==1){
                PORTB=0x07; 
                if(PORTBbits.RB7==1){
                    return;
                }
                else{tecla_1();}
            }
            else{tecla_5();}
        }  
        else{tecla_9();}
    }
    else{tecla_13();}
}


void columna2(){
    PORTB=0x0E;
    if(PORTBbits.RB6==1){
        PORTB=0x0D;
        if(PORTBbits.RB6==1){
            PORTB=0x0B;
            if(PORTBbits.RB6==1){
                PORTB=0x07; 
                if(PORTBbits.RB6==1){
                    return;
                }
                else{tecla_2();}
            }
            else{tecla_6();}
        }
        else{tecla_10();}
    }
    else{tecla_14();}
}    
    
void columna3(){
    PORTB=0x0E;
    if(PORTBbits.RB5==1){
        PORTB=0x0D;
        if(PORTBbits.RB5==1){
            PORTB=0x0B;
            if(PORTBbits.RB5==1){
                PORTB=0x07; 
                if(PORTBbits.RB5==1){
                    return;
                }
                else{tecla_3();}
            }
            else{tecla_7();}
        }
        else{tecla_11();}
    }
    else{tecla_15();}
}    

void columna4(){
    PORTB=0x0E;
    if(PORTBbits.RB4==1){
        PORTB=0x0D;
        if(PORTBbits.RB4==1){
            PORTB=0x0B;
            if(PORTBbits.RB4==1){
                PORTB=0x07; 
                if(PORTBbits.RB4==1){
                    return;
                } 
                else{tecla_4();}
            }
            else{tecla_8();}
        }
        else{tecla_12();}
    }
    else{tecla_16();}
} 


void columna(){
    if (PORTBbits.RB7==0){columna1();TRISB=0xF0;}
    else if (PORTBbits.RB6==0){columna2();TRISB=0xF0;}
    else if (PORTBbits.RB5==0){columna3();TRISB=0xF0;}
    else if (PORTBbits.RB4==0){columna4();TRISB=0xF0;}
    return;
}
void main(void) {
    OSCCON=0x62;
    ADCON1=0x0F;
    CMCON=0xFF; //Comparator off
    CVRCONbits.CVREN=0;
    
    
        PORTC=0;
        PORTB=0;
        PORTD=0;
        LATB=0;
        LATD=0;
        LATC=0;
        
        
        TRISB=0xF0;
        TRISBbits.RB7=1;
        TRISBbits.RB6=1;
        TRISBbits.RB5=1;
        TRISBbits.RB4=1;
        TRISBbits.RB3=0;
        TRISBbits.RB2=0;
        TRISBbits.RB1=0;
        TRISBbits.RB0=0;
        TRISD=0x00;
        TRISC=0x00;
        INTCON2bits.RBPU=0;
     
        RS=0; //Instrucciones
     RW=0; //Read
    
     
    __delay_ms(200);
     PORTD=0x30;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
//
     
     __delay_ms(5);
     PORTD=0x30;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
     
     
     __delay_us(200);
     PORTD=0x30;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
    
     
     __delay_us(200);
     PORTD=0x38;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
    
     
     __delay_us(100);
     PORTD=0x08;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
   
     __delay_us(100);
     PORTD=0x01;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
 
     
     __delay_ms(5);
     PORTD=0x06;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;
    
     
     __delay_us(100);
     PORTD=0x0F;
     __delay_ms(250);
    Enable=1;
    __delay_ms(250);
     Enable =0;

     __delay_us(100);
     
     
    while (1){
       // PORTCbits.RC1=1;
        RS=1;
        __delay_ms(100);
        if(PORTB<0xF0){
               columna();
               PORTB=0XF0;
               PORTD=0x01;
               RS=0;
               __delay_ms(250);
                Enable=1;
                __delay_ms(250);
                Enable =0;
               
        }
    }
}