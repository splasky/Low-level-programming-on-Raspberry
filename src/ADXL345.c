#include "ADXL345.h"

void ADXL345_Init(void)
{
    BSC0_S = CLEAR_STATUS;	// Reset status bits (see #define)
    BSC0_C = BSC_C_CLEAR;   // Important
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
    BSC0_FIFO = 0x32;    	// value of first register
    BSC0_S = CLEAR_STATUS; 	// Reset status bits (see #define)
    BSC0_C = START_WRITE;   // Start Write (see #define)

    wait_i2c_done();

    BSC0_DLEN = 14;

    BSC0_S = CLEAR_STATUS;	// Reset status bits (see #define)
    BSC0_C = START_READ;   	// Start Read after clearing FIFO (see #define)

    wait_i2c_done();
    /*printf("initial:%x\n",BSC0_FIFO);*/
    /*
     *printf("x0:%x\t",(BSC0_FIFO & 0xFF));
     *printf("x1:%x\n",(BSC0_FIFO << 8) & 0xFF00) ;
     *printf("y0:%x\t",(BSC0_FIFO & 0xFF));
     *printf("y1:%x\n",(BSC0_FIFO << 8) & 0xFF00) ;
     *printf("z0:%x\t",(BSC0_FIFO & 0xFF));
     *printf("z1:%x\n",(BSC0_FIFO << 8) & 0xFF00) ;
     */
    accData[0] = (((BSC0_FIFO << 8) & 0xFF00) |(BSC0_FIFO & 0xFF));	
    accData[1] = (((BSC0_FIFO << 8) & 0xFF00) |(BSC0_FIFO & 0xFF));	
    accData[2] = (((BSC0_FIFO << 8) & 0xFF00) |(BSC0_FIFO & 0xFF));	
    
    BSC0_C = BSC_C_CLEAR; 
    wait_i2c_done();
}
