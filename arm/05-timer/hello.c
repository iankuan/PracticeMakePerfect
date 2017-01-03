#include <stdint.h>

#include "reg.h"
#include "init.h"


#define USART_SR_TXE ((uint16_t) 0x0080)

/* USART TXE Flag
 * This flag is cleared when data is written to USARTx_DR and
 * set when that data is transferred to the TDR
 */

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
