/* 
 * File:   LCDinicializacion.h
 * Author: Raúl Lozano
 *
 * Created on November 29, 2019, 11:45 AM
 */

#ifndef LCDINICIALIZACION_H
#define	LCDINICIALIZACION_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#define on PORTCbits.RC0
#define st PORTCbits.RC1
#define wr PORTCbits.RC2

void LCDinicializacion(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LCDINICIALIZACION_H */

