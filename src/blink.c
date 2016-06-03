#include "RPI.h"
#include <stdio.h>

int main(){
    if(map_peripheral(&gpio) ==-1){
        printf("Failed to map the physical GPIO registers into the vitural memory space.\n");
        return -1;
    }

    // Define gpio 4 as output
    INP_GPIO(4);
    OUT_GPIO(4);

    for(int i=0; i<10; i++){
        GPIO_SET=1<<4;
        sleep(1);
        GPIO_CLR=1<<4;
        sleep(1);
    }
    return 0;
}
