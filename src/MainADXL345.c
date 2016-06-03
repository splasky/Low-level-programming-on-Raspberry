#include "ADXL345.h"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    // Map memory areas 
    if(map_peripheral(&gpio) == -1){
        printf("Failed to map the physical GPIO registers into the vitural memory space.\n");
        return -1;
    }

     /* BSC0 is on GPIO 0 & 1 */
    i2c_init();
		
    ADXL345_Init();
    printf("ADXL345 initialized.\n");

    short accData[3];

    int i=0;
    while(i<10)
    {
        // Read ADXL345 sensor
        ADXL345_Read(&accData[0]);
        print("Acclerometer x: d",accData[0]);        
        print("Acclerometer y: d",accData[1]);        
        print("Acclerometer z: d",accData[2]);        
    }
    return 0;
}
