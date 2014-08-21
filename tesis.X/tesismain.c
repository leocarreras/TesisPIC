/* 
 * File:   tesismain.c
 * Author: Laboratorio
 *
 * Created on May 19, 2014, 2:00 PM
 */

#include "globaldefinitions.h"
#include "pwmconfig.h"
#include "qeiconfig.h"
#include "timerconfig.h"
#include "uartconfig.h"
/*
 * 
 */

// Internal Fast RC (FRC) 7.37MHz
_FOSCSEL(FNOSC_FRC);
// POSCMD_NONE: Primary Oscillator Disabled
// OSCIOFNC_ON: OSC2 pin has digital I/O function
// IOL1WAY_OFF          Allow Multiple Re-configurations
// FCKSM_CSECMD: Clock switching is enabled, Fail-Safe Clock Monitor is disabled
_FOSC(POSCMD_NONE & OSCIOFNC_ON & IOL1WAY_OFF & FCKSM_CSECMD);
_FWDT(FWDTEN_OFF);		// Watchdog timer off





/* QEI memory space */
signed long pos_high1, pos_low1, pos_high2, pos_low2;

unsigned int k=0;

extern double referencia;




int main(int argc, char** argv) {

	/* Initialize internal clock & PLL */
    InitClock();

	/* Port Function Remapping */
    PortRemapping();

	/* Port IO Configuration*/
    PortConfig();

    /* Initialize PWM */
    InitMCindependentPWM();

    SetDutyPWM1(0);

	for(k=1;k<50;k++)
		{
		LATBbits.LATB15=~LATBbits.LATB15;
		delay(200000);
		}
	
	/* Initialize & Config QEI 1 & 2 */
	QEIConfig();

	/* Initialize UART1 */
	UART1Config();



	/* Initialize Timer1 */
	Timer1Config();
	

	
// 	char test[50];
//	char test[]="test";
    while(1){
		//gets_uart(test);
		//puts_uart(test);
    }
	return (EXIT_SUCCESS);
}

