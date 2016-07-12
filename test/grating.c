#include "../src/grating.h"
#include <stdint.h>
int main(void)
{
    uint32_t re=0;
    re=Grating_Read();
    if(re==0)return 0;
    return -1;
}
