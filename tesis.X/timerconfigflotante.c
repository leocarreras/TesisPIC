#include "timerconfig.h"
#include <p33FJ64MC802.h>
#include <timer.h>
#include "globaldefinitions.h"
#include "pwmconfig.h"
#include "qeiconfig.h"
#include "uartconfig.h"


#define kp 0
#define ki 0
#define kd 0

#define finconteo 2500

double e_k=0,e_km1=0, y=0;
double up=0,ui=0, ui_km1=0, ud=0,u_km1=0,u_pid=0;

static int aux[finconteo];

static char str[100];

static int markfin=0, i=0;

 void _ISR __attribute__((auto_psv))_T1Interrupt(void)
{
	y=(double)Int32QEI1();
	
	/* Escalado de la entrada del encoder */
	//y=y/pulsosporvuelta*50.0/17.0*40.0*360.0*2.0;	
	

	/* Calculo error actual */
	e_k=ref-y; // en unidades de encoder
	//e_k=ref*50.0/17.0*50.0/17.0*40.0*4.0-y;

	/*if((e_k - e_km1)*(e_k - e_km1)<= 25)
		e_k = 0;*/
	

    /*Termino Proporcional*/
	up = kp*e_k;    

	/*if(up >= 50)
		up = 50;

	if(up <= -50)
		up = -50;*/

	/*Termino Integral*/
	ui = ui_km1 + e_km1*Tm1; 
	
	/*if(ui >= 50)
		ui = 50;

	if(ui <= -50)
		ui = -50;*/
	
	/*Termino Derivativo*/
	ud = kd*(e_k-e_km1)/Tm1;
	
	/*if(ud >= 50)
		ud = 50; 

	if(ud <= -50)
		ud = -50;*/

	u_pid = up + ui + ud;    
	
 	/* Actualizar variables */
	ui_km1 = ui;
	e_km1 = e_k;
	
	SetDutyPWM1(15);
	/* Reiniciar conteo y bandera de interrupcion */

    WriteTimer1(0);
    IFS0bits.T1IF = 0; //Clear Timer1 interrupt flag
}

 void Timer1Config(){
        /* Enable Timer1 Interrupt and Priority to "1" */
    ConfigIntTimer1(T1_INT_PRIOR_1 & T1_INT_ON);
    WriteTimer1(0);

    OpenTimer1(T1_ON & T1_GATE_OFF & T1_IDLE_STOP &
               T1_PS_1_64 & T1_SYNC_EXT_OFF &
               T1_SOURCE_INT, time1);
 }
