/* 
 * File:   timerconfig.h
 * Author: Laboratorio
 *
 * Created on May 20, 2014, 2:45 PM
 */

#ifndef TIMERCONFIG_H
#define	TIMERCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "globaldefinitions.h"

void _ISR __attribute__((auto_psv))_T1Interrupt(void);

 void Timer1Config();

void LeerReferencia();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERCONFIG_H */

