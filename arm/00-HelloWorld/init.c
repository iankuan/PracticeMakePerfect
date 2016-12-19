#include <stdint.h>
#include "init.h"
#include "reg.h"///include <stdint.h>

void init(void)
{
    RCC_init();
    GPIOA_init();
    USART_init();
}

void RCC_init(void)
{
    *(RCC_APB1ENR) |= (uint32_t) (0x00020000);
    *(RCC_APB2ENR) |= (uint32_t) (0x00000001 | 0x00000004);
                                ///Alternate function IO, IO port A clock enable
}

void GPIOA_init(void)
{//TODO: Why floating point???
    *(GPIOA_CRL) = (uint32_t) (0x00004B00);///PA3: input floating, PA2: output Push-pull with 50MHz
    *(GPIOA_CRH) = (uint32_t) (0x44444444);///reset value
}

void USART_init(void)
{
    *(USART2_CR1) = (uint32_t) (0x0000000C | 0x00002000);
                                ///UE: Usart Enable, TE/RE: TX/RX enable
}
