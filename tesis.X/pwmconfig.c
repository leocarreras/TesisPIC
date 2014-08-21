#include "pwmconfig.h"
#include <p33FJ128MC802.h>
#include <pwm.h>



void InitMCindependentPWM()
{
	/* PWM time base operates in a Free Running mode */
	P1TCONbits.PTMOD = 0b00;				// On reset 0x0000

	/* PWM time base input clock period is TCY (1:1 prescale) */
	/* PWM time base output post scale is 1:1 */
	/* PxTCON: PWM Time Base Control Register */
	P1TCONbits.PTCKPS = 0b00;				// On reset 0x0000
	P1TCONbits.PTOPS  = 0b00;				// On reset 0x0000

	/* Choose PWM time period based on input clock selected */
	/* Refer to Equation 14-1 */
	P1TPER = (periodo+1)/2 - 1;				// Selectable

	/* MCPWM Module Output Mode Selection     			*
	 * PWM I/O pairs 1 to 3 are in independennt mode         	*
	 * PWM pins are enabled for PWM output 				*/
	PWM1CON1bits.PMOD1 = 1;		// 1=PWM I/O pin pair is in Independent Output mode, On reset 0
	PWM1CON1bits.PMOD2 = 1;		// 1 = PWM I/O pin pair is in Independent Output mode
	PWM2CON1bits.PMOD1 = 1;		// 1=PWM I/O pin pair is in Independent Output mode, On reset 0
	//PWM1CON1bits.PMOD3 = 0;	// On reset 0 in complementary mode
	PWM1CON1bits.PEN1H = 1;		// 1 = PWMxHy pin is enabled for PWM output
	PWM1CON1bits.PEN2H = 1;		// 1 = PWMxHy pin is enabled for PWM output
	PWM1CON1bits.PEN3H = 0;		// 0 = PWM1H3 pin disabled; I/O pin becomes general purpose I/O
	PWM1CON1bits.PEN1L = 0;		// 0 = PWM1L1 pin disabled; I/O pin becomes general purpose I/O
	PWM1CON1bits.PEN2L = 0;		// 0 = PWM1L2 pin disabled; pin becomes general purpose I/O
	PWM1CON1bits.PEN3L = 0;		// 0 = PWM1L3 pin disabled; I/O pin becomes general purpose I/O
	PWM2CON1bits.PEN1H = 0;		// 0 = PWM2H1 pin disabled; I/O pin becomes general purpose I/O
	PWM2CON1bits.PEN1L = 0;		// 0 = PWM2L1 pin disabled; I/O pin becomes general purpose I/O

	/* Immediate update of PWM enabled */
	PWM1CON2bits.IUE = 1;		// On reset 0

	/* PxOVDCON: Override Control Register */
	/* This register is used for enabling the output override feature and for PWM output pin control selection. */
	/* PWM I/O pin controlled by PWM Generator */
	//P1OVDCONbits.POVD3H = 1;	// On reset 1
	//P1OVDCONbits.POVD2H = 1;	// On reset 1
	//P1OVDCONbits.POVD1H = 1;	// On reset 1
	//P1OVDCONbits.POVD3L = 1;	// On reset 1
	//P1OVDCONbits.POVD2L = 1;	// On reset 1
	//P1OVDCONbits.POVD1L = 1;	// On reset 1

	/* Initialize duty cycle values for PWM1, PWM2 and PWM3 signals */
	P1DC1 = 0;				// On reset 0
	P1DC2 = 0;				// On reset 0
	//P1DC3 = 200;				// On reset 0

	P1TCONbits.PTEN = 1;		// On reset 0
}

void SetDutyPWM1(double duty){
	
	if(duty>50) duty=50;
	if(duty<-50) duty=-50; 
	
	P1DC1=periodo*((int)duty+50)/100;	
}

void SetDutyPWM2(double duty){
	
	if(duty>50) duty=50;
	if(duty<-50) duty=-50; 
	
	P1DC2=periodo*((int)duty+50)/100;	
}
