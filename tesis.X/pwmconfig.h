/* 
 * File:   pwmconfig.h
 * Author: Laboratorio
 *
 * Created on May 19, 2014, 12:22 PM
 */

#ifndef PWMCONFIG_H
#define	PWMCONFIG_H

/* Included files list */
#include "globaldefinitions.h"

/*! \def A1    
\brief Macro que define un pin de sentido de giro del motor de acimut        
*/
#define A1 LATAbits.LATA0
/*! \def B1    
\brief Macro que define un pin de sentido de giro del motor de acimut        
*/
#define B1 LATAbits.LATA1

/*! \def A2    
\brief Macro que define un pin de sentido de giro del motor de elevacion      
*/
#define A2 LATAbits.LATA2
/*! \def B2    
\brief Macro que define un pin de sentido de giro del motor de elevacion      
*/
#define B2 LATAbits.LATA3

#ifdef	__cplusplus
extern "C" {
#endif

void InitMCindependentPWM();

void SetDutyPWM1(double);

void SetDutyPWM2(double);

void SetAzSpin(int);

void SetElSpin(int);

#ifdef	__cplusplus
}
#endif

#endif	/* PWMCONFIG_H */

