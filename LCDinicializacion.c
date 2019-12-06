#include <xc.h>
#include "LCDinicializacion.h"
#define _XTAL_FREQ 4000000L

void LCDinicializacion(void)
{
    //paso 1
     __delay_ms(100); 
    PORTD = 0x30;   
    //paso 2
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 2
    __delay_ms(10);  
    PORTD = 0x30;    
    //paso 3
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 3
    __delay_us(100);  
    PORTD = 0x30;    
    //paso 4
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 5
    __delay_us(100);  
    PORTD = 0x38;    
    //paso 6
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 7
    __delay_us(100); 
    PORTD = 0x08;    
    //paso 8
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 9
    __delay_us(100);     
    PORTD = 0x01;    
    //paso 10
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 11
    __delay_ms(10);  
    PORTD = 0x06;    
    //paso 12
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
    
    //paso 13 
    __delay_us(100);  
    PORTD = 0x0F;
    //paso 14 
    __delay_ms(50);
    on = 1;
    __delay_ms(50);
    on = 0;  
}
