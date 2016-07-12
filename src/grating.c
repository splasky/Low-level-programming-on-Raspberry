#include <stdio.h>
#include "grating.h"

uint32_t Grating_Read(void){
   if(map_peripheral(&gpio)==-1){
       printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
       return -1;
   }
    INP_GPIO(17);
    uint32_t re = GPIO_GET(17);
    printf("%d",re?1:0); 
    return 0;
}

