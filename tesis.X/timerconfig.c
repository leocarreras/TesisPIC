#include "timerconfig.h"
#include <p33FJ128MC802.h>
#include <timer.h>
#include "globaldefinitions.h"
#include "pwmconfig.h"
#include "qeiconfig.h"
#include "uartconfig.h"


#define akp 15//15//6
#define aki 2
#define akd 10

#define ekp 15//15//6
#define eki 2
#define ekd 10

#define finconteo 2500

double ae_k=0,ae_km1=0, ay=0;
double aup=0,aui=0, aui_km1=0, aud=0,au_km1=0,au_pid=0;

double ee_k=0,ee_km1=0, ey=0;
double eup=0,eui=0, eui_km1=0, eud=0,eu_km1=0,eu_pid=0;

static int aux[finconteo];

char str3[30];
double refaz=0.0,refel=0.0, refazraw=0.0,refelraw=0.0;
int r=0;

char lecturaARM[100], escrituraARM[100];

static int markfin=0, i=0, c=0;

 void _ISR __attribute__((auto_psv))_T1Interrupt(void)
{
	/* Leer referencia */
	LeerReferencia();

	ay=(double)Int32QEI1();
	
	/* Escalado de la entrada del encoder */
	//y=y/pulsosporvuelta*50.0/17.0*40.0*360.0*2.0;	
	
	
	//sprintf(str3, "upid %.2f e_k %.2f\n", au_pid, ae_k);
	//puts_uart(str3);
	/* Calculo error actual */
	ae_k=2*refaz-ay; // en unidades de encoder
	//e_k=ref*50.0/17.0*40.0*4.0-y;

	/*if((e_k - e_km1)*(e_k - e_km1)<= 25)
		e_k = 0;*/
	

    /*Termino Proporcional*/
	aup = akp*ae_k;    

	/*if(up >= 50)
		up = 50;

	if(up <= -50)
		up = -50;*/

	/*Termino Integral*/
	aui = aui_km1 + ae_km1*Tm1*aki/1000; 
	
	if(aui >= 20)
		aui = 20;

	if(aui <= -20)
		aui = -20;
	
	/*Termino Derivativo*/
	aud = akd*(ae_k-ae_km1)/Tm1/1000;
	
	/*if(ud >= 50)
		ud = 50; 

	if(ud <= -50)
		ud = -50;*/

	au_pid = aup + aui + aud;    
	
 	/* Actualizar variables */
	aui_km1 = aui;
	ae_km1 = ae_k;
	
	SetDutyPWM1(au_pid);

	/******************* MOTOR 2 ***************/

	ey=(double)Int32QEI2();

	/* Calculo error actual */
	ee_k=2*refel-ey; // en unidades de encoder
	//e_k=ref*50.0/17.0*40.0*4.0-y;

	/*if((e_k - e_km1)*(e_k - e_km1)<= 25)
		e_k = 0;*/
	

    /*Termino Proporcional*/
	eup = ekp*ee_k;    

	/*if(up >= 50)
		up = 50;

	if(up <= -50)
		up = -50;*/

	/*Termino Integral*/
	eui = eui_km1 + ee_km1*Tm1*eki/1000; 
	
	if(eui >= 20)
		eui = 20;

	if(eui <= -20)
		eui = -20;
	
	/*Termino Derivativo*/
	eud = ekd*(ee_k-ee_km1)/Tm1/1000;
	
	/*if(ud >= 50)
		ud = 50; 

	if(ud <= -50)
		ud = -50;*/

	eu_pid = eup + eui + eud;    
	
 	/* Actualizar variables */
	eui_km1 = eui;
	ee_km1 = ee_k;
	
	SetDutyPWM2(eu_pid);
	
	/* Reiniciar conteo y bandera de interrupcion */

    WriteTimer1(0);
    IFS0bits.T1IF = 0; //Clear Timer1 interrupt flag
}

 void Timer1Config(){
        /* Enable Timer1 Interrupt and Priority to "1" */
    ConfigIntTimer1(T1_INT_PRIOR_1 & T1_INT_ON);
    WriteTimer1(0);

    OpenTimer1(T1_ON & T1_GATE_OFF & T1_IDLE_STOP &
               T1_PS_1_256 & T1_SYNC_EXT_OFF &
               T1_SOURCE_INT, time1);
 }

void LeerReferencia(){
	puts_uart("p");
	r=gets_uart(lecturaARM);
	sscanf(lecturaARM, "%f, %f", (float*)&refelraw,(float*)&refazraw );
	refaz=(long int)(refazraw*pulsosporvuelta*50.0/17.0/360.0);
	refel=(long int)(refelraw*pulsosporvuelta*50.0/17.0/360.0);
	sprintf(escrituraARM, "a %.1f %.0f %.0f %.0f e %.1f %.0f %.0f %.0f", refazraw, 2*refaz, ay, au_pid, refelraw, 2*refel, ey, eu_pid);
	puts_uart(escrituraARM);
	sprintf(lecturaARM, "");
	LATBbits.LATB15=~LATBbits.LATB15;
}