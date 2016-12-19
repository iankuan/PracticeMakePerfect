#include <stdint.h>

#include "reg.h"
#include "init.h"


#define USART_SR_TXE ((uint16_t) 0x0080)

int puts(const char *str)
{
    while(*str)
        ///FIXME: why use it?
        ///while(*(USART2_SR) & USART_SR_TXE) ;
        while(*(USART2_SR) & USART_SR_TXE)
            *(USART2_DR) = *str++ & 0xFF;

    return 0;
}

int main()
{
    init();

    puts("Hello Pracetice~!\n");

    while(1) ;
}
