#include <stdio.h>
#include "grating.h"

uint32_t Grating_Read(void){
   if(map_peripheral(&gpio)==-1){
       printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
       return -1;
   }
    INP_GPIO(17);
    OUT_GPIO(17);
    printf("%d",GPIO_SET=1<<17); 
    return 0;
}

