#include <stdint.h>
#include "semi.h"

#define STDOUT 1

int main()
{
    char msg[] = "Hello Semihost~!\n";
    
    uint32_t param[] = { STDOUT, (uint32_t) msg, sizeof(msg)};

    semi_call(SYS_WRITE, (void *) param);

    while(1) ;
}
