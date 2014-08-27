#include "globaldefinitions.h"
#include <p33FJ128MC802.h>



void InitClock()
{
	/* Section 48. Oscillator(Part V) - dsPIC33F FRM	03 Jan 2014			**
	** Example 48-2: Code Example for Using PLL with 7.37 MHz Internal FRC 	*/
	// Configure PLL prescaler, PLL postscaler, and PLL divisor
	PLLFBD = 41; // M = 43
	CLKDIVbits.PLLPRE=0; // N1 = 2
	CLKDIVbits.PLLPOST=0; // N2 = 2
	// Initiate clock switch to internal FRC with PLL (NOSC = 0b001)
	__builtin_write_OSCCONH(0x01);
	__builtin_write_OSCCONL(0x01);
	// Wait for clock switch to occur
	while (OSCCONbits.COSC != 0b001);
	// Wait for PLL to lock
	while(OSCCONbits.LOCK!=1) {};
}

void PortRemapping()
{
	// 	remapping of ports
	RPOR1bits.RP3R = 3;		// Asign UART TX to Pin7(RP3)
	RPINR18bits.U1RXR = 2;	// Asign UART RX to Pin6(RP2)
	RPINR14bits.QEA1R = 11;	// Asign QEI1 Phase A to Pin22(RP11)
	RPINR14bits.QEB1R = 10;	// Asign QEI1 Phase B to Pin21(RP10)
	RPINR16bits.QEA2R =  9;	// Asign QEI2 Phase A to Pin18(RP9)
	RPINR16bits.QEB2R =  8;	// Asign QEI2 Phase B to Pin17(RP8)
}

void PortConfig()
{
	AD1PCFGL = 0xFFFC;	// PORTA<1:0> analog, others digital (reset state=analog)
    LATA = 0;
    TRISA = 0x00;	// set PORTA<4:0> = ---0 1111 = 0x0F RA4:SPIN1
    LATB = 0;		// RB15:EN1, EB13:EN2, RB6:SPIN2, RB5:LED2, RB4:LED1, RB3:TX, RB2:RX
    TRISB = 0x0F87;	// PORTB<15:0> = 0000 1111 1000 0111 = 0x8F87
}

// delay function, time [us]
void delay(long time)
{
	while(time--);
}
