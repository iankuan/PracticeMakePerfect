#ifndef REG_H
#define REG_H

#define REG_T   volatile uint32_t
#define REG     REG_T *

/** RCC
 *      1. init clock
 *      2. 
 */
#define RCC             ((REG_T) 0x40021000)
                                ///FIXME: if no () would be error
#define RCC_APB2ENR     ((REG) (RCC + 0x18)) ///IO clock
#define RCC_APB1ENR     ((REG) (RCC + 0x1C)) ///UART clock

/** GPIO
 */
#define GPIOA           ((REG_T) 0x40010800)
#define GPIOA_CRL       ((REG) (GPIOA + 0x00))
#define GPIOA_CRH       ((REG) (GPIOA + 0x04))

/** USART = Universal Synchronous/Asynchronous Receive/Transmitter
 */
#define USART2           ((REG_T) 0x40004400)
#define USART2_SR        ((REG) (USART2 + 0x00))///Status Reg
#define USART2_DR        ((REG) (USART2 + 0x04))///Data Reg
#define USART2_CR1       ((REG) (USART2 + 0x0C))///Control Reg

#endif ///REG_H
