#include "ADXL345.h"

void ADXL345_Init(void)
{
    ADXL345_SetRegister(DATA_FORMAT,DATA_FORMAT_DATA);
    ADXL345_SetRegister(POWER_CTL,POWER_CTL_DATA);
}

void ADXL345_SetRegister(unsigned const char regAddr,unsigned const char regValue)
{
    BSC0_A = ADXL345_ADDR;

    BSC0_DLEN = 2;
    BSC0_FIFO = (unsigned const char)regAddr;
    BSC0_FIFO = (unsigned const char)regValue;

    BSC0_S = CLEAR_STATUS; // Reset status bits
    BSC0_C = START_WRITE;  // Start write

    wait_i2c_done();
}

void ADXL345_Read(short *accData)
{
    BSC0_DLEN = 1;    		// one byte
    BSC0_FIFO = 0x00;    	// value of first register
    BSC0_S = CLEAR_STATUS; 	// Reset status bits (see #define)
    BSC0_C = START_WRITE;   // Start Write (see #define)

    wait_i2c_done();

    BSC0_DLEN = 14;

    BSC0_S = CLEAR_STATUS;	// Reset status bits (see #define)
    BSC0_C = START_READ;   	// Start Read after clearing FIFO (see #define)

    wait_i2c_done();
    printf("initial:%d",BSC0_FIFO = 0x00);
    printf("x0:%d\t",BSC0_FIFO = 0x32);
    printf("x1:%d\n",BSC0_FIFO = 0x33);
    printf("y0:%d\t",BSC0_FIFO = 0x34);
    printf("y1:%d\n",BSC0_FIFO = 0x35);
    printf("z0:%d\t",BSC0_FIFO = 0x36);
    printf("z1:%d\n",BSC0_FIFO = 0x37);
    /*
     *short tmp;
	 *int tmpAddr[]={0x32,0x33,0x34,0x35,0x36,0x37};
     *for(int i=0; i < 3; i++)// Accelerometer
     *{
	 *accData[i] = ((BSC0_FIFO = tmpAddr[1+i*2]) << 8 &0xFF00) |(BSC0_FIFO = tmpAddr[0+i*2] & 0xFF) ;	
     *}
     */
}
