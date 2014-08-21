/* 
 * File:   uartconfig.h
 * Author: Laboratorio
 *
 * Created on May 21, 2014, 10:47 AM
 */

#ifndef UARTCONFIG_H
#define	UARTCONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "globaldefinitions.h"

#define BAUDRATE 9600
#define BRGVAL  (int)((FCY/BAUDRATE)/16)-1

void UART1Config(void);

void CRLF(void);

int gets_uart(char *buf);

void puts_uart(char *s);

#ifdef	__cplusplus
}
#endif

#endif	/* UARTCONFIG_H */

