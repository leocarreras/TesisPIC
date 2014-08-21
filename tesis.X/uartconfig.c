#include "uartconfig.h"
#include <p33FJ128MC802.h>
#include <uart.h>

void UART1Config(void){
    // UART initializing, 115.2kbps at Fosc=80MHz
	// ubrg = (80000000/4) / (16*115200) -1 = 9.85 = 10
	// ubrg = (80000000/4) / (16*57600) -1 = 20.93 = 21
	// ubrg = (80000000/4) / (16*9600) -1 = 129.2 = 129
	//OpenUART1(UMODEValue, USTAValue, 10);

	U1MODEbits.UARTEN = 1;	// 1 = UART is enabled. <Must>
	U1MODEbits.USIDL  = 1;	// 1 = Discontinue operation when device enters Idle mode
	/*
	U1MODEbits.IREN   = 0;	// 0 = IrDA encoder and decoder are disabled
	U1MODEbits.RTSMD  = 1;	// 1 = UxRTS is in Simplex mode
	U1MODEbits.UEN    = 0;	// 00 = UxTX and UxRX pins are enabled and used;
	U1MODEbits.WAKE   = 1;	// 1 = Wake-up enabled
	U1MODEbits.LPBACK = 0;	// 0 = Loopback mode is disabled.
	U1MODEbits.ABAUD  = 0;	// 0 = Baud rate measurement disabled or completed
	U1MODEbits.URXINV = 0;	// 1 = UxRX Idle state is ?e0?f <Must 0>
	U1MODEbits.BRGH   = 0;	// 0 = Low-speed mode
	U1MODEbits.PDSEL  = 0;	// 00 = 8-bit data, no parity
	U1MODEbits.STSEL  = 0;	// 0 = 1 Stop bit
	*/
	//U1STAbits.UTXISEL1 = 1;	// 1 = Interrupt when a character is transferred
	U1STAbits.UTXINV   = 0;	// 1 = UxTX Idle state is ?e0?f <Must 0>
	//U1STAbits.UTXISEL0 = 1;	// 1 = Interrupt when a character is transferred
	//U1STAbits.UTXBRK   = 0;	// 0 = Sync Break transmission is disabled or completed ?K?{
	U1STAbits.UTXEN    = 1;	// 1 = UART transmitter enabled, <Must>
	// U1STAbits.UTXBF  = 1;	// 1 = Transmit buffer is full(Read Only)
	// U1STAbits.TRMT   = 1;	// 1 = Transmit shift register is empty(Read Only)
	//U1STAbits.URXISEL  = 3;	// 11 =Interrupt flag bit is set when Receive Buffer is full
	//U1STAbits.ADDEN    = 1;	// 1 = Address Detect mode enabled.
	// U1STAbits.RIDLE  = 1;	// 1 = Receiver is Idle(Read Only)
	// U1STAbits.PERR   = 1;	// 1 = Parity error has been detected(Read Only)
	// U1STAbits.FERR   = 1;	// 1 = Framing Error has been detected(Read Only)
	// U1STAbits.OERR   = 1;	// 1 = Receive buffer has overflowed(Read/Clear Only)
	// U1STAbits.URXDA  = 1;	// 1 = Receive buffer has data,(Read Only)

	// (Fosc= 79.2MHz = PLL 43/4 * FRC 7.37MHz)
	//U1BRG = (int)((3960000.0/115200.0)/16.0)-1;		// ((FCY/BAUDRATE)/16)-1;
	U1BRG = BRGVAL;//21;	// 115200 bps, U1BRG = 259;	for 9600 bps
}

// CR, LF output function
void CRLF(void)
{
	WriteUART1(0x0d);		// output CR
	while(BusyUART1());		// wait transmition
	WriteUART1(0x0a);		// output LF
	while(BusyUART1());		// wait transmition
}

int gets_uart(char *buf)
{
	int i = 0, wdg=100;

	do {
		while(!DataRdyUART1());		// this is essential
		//while(!DataRdyUART1()&&wdg)wdg--;
		//if(wdg) wdg=50;
		//else {return 0;}
		buf[i++] = getcUART1();
		//putcUART1(buf[i-1]);		// echo input character
	} while (buf[i-1] != 0x0a);		// CR: 0x0d, LF: 0x0a
	buf[i-1] = '\0';
	return i;
}

void puts_uart(char *s)
{
	putsUART1((unsigned int*)s);	// void putsUART1(unsigned int *buffer);
	while(BusyUART1());		// Wait for transmission to complete, DS51456C-page 158
        CRLF();
}
