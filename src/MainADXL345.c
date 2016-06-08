#include "ADXL345.h"
#include "RPI.h"
#include <stdlib.h>
#include <stdlib.h>
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

	dump_bsc_status();
    
    short accData[3];

    int i=0;
    while(i<10)
    {
        // Read ADXL345 sensor
        ADXL345_Read(&accData[0]);
        printf("Acclerometer x: %d",accData[0]);        
        printf("Acclerometer y: %d",accData[1]);        
        printf("Acclerometer z: %d",accData[2]);   
        sleep(5);     
    }
    return 0;
}*/
