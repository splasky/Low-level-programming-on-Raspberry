#include "ADXL345.h"

void ADXL345_Init(void)
{
    ADXL345_SetRegister(DATA_FORMAT,DATA_FORMAT_DATA);
    ADXL345_SetRegister(POWER_CTL,POWER_CTL_DATA);
}

void ADXL345_SetRegister(unsigned char regAddr, unsigned char regValue)
{
    BSC0_A = ADXL345_ADDR;

    BSC0_DLEN = 2;
    BSC0_FIFO = (unsigned char)regAddr;
    BSC0_FIFO = (unsigned char)regValue;

    BSC0_S = CLEAR_STATUS; // Reset status bits
    BSC0_C = START_WRITE;  // Start write

    wait_i2c_done();
}

void ADXL345_Read(short *accData)
{
    BSC0_DLEN = 1;    		// one byte
    BSC0_FIFO = 0x32;    	// value of first register
    BSC0_S = CLEAR_STATUS; 	// Reset status bits (see #define)
    BSC0_C = START_WRITE;   // Start Write (see #define)

    wait_i2c_done();

    BSC0_DLEN = 14;

    BSC0_S = CLEAR_STATUS;	// Reset status bits (see #define)
    BSC0_C = START_READ;   	// Start Read after clearing FIFO (see #define)

    wait_i2c_done();

    short tmp;

    for(int i=0; i < 3; i++)// Accelerometer
    {
	tmp = BSC0_FIFO << 8;	
	tmp += BSC0_FIFO;
	accData[i] = tmp; 
    }
}
