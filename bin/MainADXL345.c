#include "../src/ADXL345.h"
#include "../src/RPI.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    // Map memory areas 
    if(map_peripheral(&gpio) == -1){
        printf("Failed to map the physical GPIO registers into the vitural memory space.\n");
        return -1;
    }
     if(map_peripheral(&bsc0) == -1){
        printf("Failed to map the physical GPIO registers into the vitural memory space.\n");
        return -1;
    }
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
        printf("Acclerometer x: %d\t",accData[0]);        
        printf("Acclerometer y: %d\t",accData[1]);        
        printf("Acclerometer z: %d\t\n",accData[2]);   
        sleep(1);  
        i++;   
    }
    
    unmap_peripheral(&gpio);
	unmap_peripheral(&bsc0);
    
    return 0;
}

