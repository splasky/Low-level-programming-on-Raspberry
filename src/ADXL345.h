#ifndef _INC_ADXL345_H
#define _INC_ADXL345_H

#include "RPI.h"

#define ADXL345_ADDR        0x53
#define DATA_FORMAT         0x31
#define DATA_FORMAT_DATA    0x0B
#define POWER_CTL           0x2D
#define POWER_CTL_DATA      0x08

void ADXL345_Read(short *accData);
void ADXL345_Init(void);
void ADXL345_SetRegister(unsigned char regAddr, unsigned char regValue);

#endif
