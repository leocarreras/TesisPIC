#include "qeiconfig.h"
#include <qei.h>

extern signed long pos_high1, pos_low1, pos_high2, pos_low2;

void QEIConfig(void){
    POS1CNT = POS2CNT = 0;			// in p33FJ128MC802.h
	MAX1CNT = MAX2CNT = 0xFFFF;		// in p33FJ128MC802.h
	// void OpenQEI(unsigned int config1, unsigned int config2);
	// for rotary incremental encoder:  E6J-CWZ1C
	OpenQEI1(QEI_DIR_SEL_CNTRL & QEI_EXT_CLK & QEI_INDEX_RESET_DISABLE
			& QEI_GATED_ACC_DISABLE & QEI_NORMAL_IO & QEI_INPUTS_NOSWAP
			& QEI_MODE_x2_MATCH & QEI_UP_COUNT & QEI_IDLE_STOP
			, 0);

	OpenQEI2(QEI_DIR_SEL_CNTRL & QEI_EXT_CLK & QEI_INDEX_RESET_DISABLE
			& QEI_GATED_ACC_DISABLE & QEI_NORMAL_IO & QEI_INPUTS_NOSWAP
			& QEI_MODE_x2_MATCH & QEI_UP_COUNT & QEI_IDLE_STOP
			, 0);

	// Enable QEI Interrupt and Priority to "2" and "3"
	ConfigIntQEI1(QEI_INT_PRI_2 & QEI_INT_ENABLE);
	ConfigIntQEI2(QEI_INT_PRI_3 & QEI_INT_ENABLE);

	pos_high1 = pos_high2 = 0;	// intialize QEI Interrupt
}

void __attribute__((__interrupt__)) _QEI1Interrupt(void)
{
	QEI1CONbits.UPDN == 1 ? pos_high1++ : pos_high1--;	// motor CCW or CW
	IFS3bits.QEI1IF = 0; 	// Clear QEI interrupt flag
}

void __attribute__((__interrupt__)) _QEI2Interrupt(void)
{
	QEI2CONbits.UPDN == 1 ? pos_high2++ : pos_high2--;	// motor CCW or CW
	IFS4bits.QEI2IF = 0; 	// Clear QEI interrupt flag
}

signed long Int32QEI1()
{
	// unsigned int ReadQEI(void);
	// This function read the position count value from the POSCNT register.
	pos_low1 = (signed long)ReadQEI1();
	return (pos_high1 << 16 | pos_low1);
}

signed long Int32QEI2()
{
	// unsigned int ReadQEI(void);
	// This function read the position count value from the POSCNT register.
	pos_low2 = (signed long)ReadQEI2();
	return (pos_high2 << 16 | pos_low2);
}
