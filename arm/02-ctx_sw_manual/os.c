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
    while(*str) {
        ///FIXME: why use it?
        ///while(*(USART2_SR) & USART_SR_TXE) ;
        while(!(*(USART2_SR) & USART_SR_TXE)) ;
            *(USART2_DR) = *str++ & 0xFF;
    }

    return 0;
}

void task0(void)
{
    puts("enter the task0\n");
    while(1);
}

extern void ctx_sw(uint32_t *);

int main()
{
    init();
    /// We should store these manually
    /// p4 - p11, lr
    uint32_t stack[100];
                            ///here is the end not last entry
    uint32_t *stack_start = (stack + 100) - 16;///FIXME: why 16
    stack_start[8] = (uint32_t) task0;

    puts("os start\n");

    ctx_sw(stack_start);

    while(1) ;
}
