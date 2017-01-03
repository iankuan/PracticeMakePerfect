#ifndef REG_H
#define REG_H

#define REG_T   volatile uint32_t
#define REG     REG_T *

/* Flash Memory Map */
#define FLASH       ((REG_T) 0x40022000)
#define FLASH_ACR   ((REG) (FLASH + 0x00))


/** RCC
 */
#define RCC             ((REG_T) 0x40021000)
                                ///FIXME: if no () would be error
#define RCC_CR          ((REG) (RCC + 0x00))
#define RCC_CFGR        ((REG) (RCC + 0x04))
#define RCC_CIR         ((REG) (RCC + 0x08))
#define RCC_APB2RSTR    ((REG) (RCC + 0x0C))
#define RCC_APB1RSTR    ((REG) (RCC + 0x10))
#define RCC_AHBENR      ((REG) (RCC + 0x14))
#define RCC_APB2ENR     ((REG) (RCC + 0x18)) ///IO clock
#define RCC_APB1ENR     ((REG) (RCC + 0x1C)) ///UART clock
#define RCC_APB1ENR     ((REG) (RCC + 0x1C))
#define RCC_BDCR        ((REG) (RCC + 0x20))
#define RCC_CSR         ((REG) (RCC + 0x24))

/** GPIO
 */
#define GPIOA           ((REG_T) 0x40010800)
#define GPIOA_CRL       ((REG) (GPIOA + 0x00))
#define GPIOA_CRH       ((REG) (GPIOA + 0x04))
#define GPIOA_IDR       ((REG) (GPIOA + 0x08))
#define GPIOA_ODR       ((REG) (GPIOA + 0x0C))
#define GPIOA_BSRR      ((REG) (GPIOA + 0x10))
#define GPIOA_BRR       ((REG) (GPIOA + 0x14))
#define GPIOA_LCKR      ((REG) (GPIOA + 0x18))

/** USART = Universal Synchronous/Asynchronous Receive/Transmitter
 */
#define USART2           ((REG_T) 0x40004400)
#define USART2_SR        ((REG) (USART2 + 0x00))///Status Reg
#define USART2_DR        ((REG) (USART2 + 0x04))///Data Reg
#define USART2_BRR       ((REG) (USART2 + 0x08))
#define USART2_CR1       ((REG) (USART2 + 0x0C))///Control Reg
#define USART2_CR2       ((REG) (USART2 + 0x10))
#define USART2_CR3       ((REG) (USART2 + 0x14))
#define USART2_GTPR      ((REG) (USART2 + 0x18))

#endif ///REG_H
