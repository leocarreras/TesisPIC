/*! \file globaldefinitions.h     
\brief Archivo de definiciones globales.         
Todos los parámetros globales y las funciones de configuración
son declaradas aquí. */

#ifndef GLOBALDEFINITIONS_H
#define	GLOBALDEFINITIONS_H

/*! \def FOSC    
\brief Macro que retorna la frecuencia del oscilador principal.        
*/
#define FOSC 79227500
/*! \def FCY    
\brief Macro que retorna la frecuencia de instrucción.        
*/
#define FCY FOSC/2
/*! \def FREC    
\brief Macro que retorna la frecuencia de PWM.        
*/
#define FREC 19500
/*! \def periodo    
\brief Macro que retorna el periodo de PWM.        
*/
#define periodo FCY/FREC*2
/*! \def Tm1   
\brief Macro que retorna el tiempo de muestreo.        
*/
#define Tm1 100//200  //En milisegundos
/*! \def time1
\brief Macro que retorna el conteo necesario para cumplir con el tiempo de muestreo.        
*/
#define time1 FCY/256*Tm1/1000+1
/*! \def pulsosporvuelta
\brief Macro que retorna el número de pulsos por vuelta del encoder usado.        
*/
#define pulsosporvuelta 1024

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <p33FJ128MC802.h>

/*! \fn void InitClock()     
\brief Inicia el reloj del sistema.
     
Se configura el pre y post escalado del PLL, el divisor PLL y se inicia el reloj interno FRC.  */

void InitClock();

/*! \fn void PortRemapping()     
\brief Asigna los pines del puerto remapeable.
     
Configura los perifericos PWM, QEI y UART para la operación.  

*/

void PortRemapping();

/*! \fn void PortConfig()     
\brief Asigna salidas y entradas de los puertos.
     
Configura los puertos. Se asignan salidas y entradas.  

*/

void PortConfig();

/*! \fn void delay(long time)     
\brief Asigna un retardo.
\param time Contador de tiempo.

Computa un retardo como una cuenta regresiva sobre una variable.  

*/
void delay(long);

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALDEFINITIONS_H */

