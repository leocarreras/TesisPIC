/* 
 * File:   qeiconfig.h
 * Author: Laboratorio
 *
 * Created on May 19, 2014, 12:33 PM
 */

#ifndef QEICONFIG_H
#define	QEICONFIG_H


#ifdef	__cplusplus
extern "C" {
#endif
    
void QEIConfig(void);

void __attribute__((__interrupt__)) _QEI1Interrupt(void);

void __attribute__((__interrupt__)) _QEI2Interrupt(void);

signed long Int32QEI1();

signed long Int32QEI2();


#ifdef	__cplusplus
}
#endif

#endif	/* QEICONFIG_H */

