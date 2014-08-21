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



#ifdef	__cplusplus
extern "C" {
#endif

void InitMCindependentPWM();

void SetDutyPWM1(double);

void SetDutyPWM2(double);

#ifdef	__cplusplus
}
#endif

#endif	/* PWMCONFIG_H */

