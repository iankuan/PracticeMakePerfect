#include <stdint.h>
#include "init.h"
#include "reg.h"///include <stdint.h>

void init(void)
{
    RCC_init();
    GPIOA_init();
    USART_init();
}

/* Bit definition for RCC_CR register */
#define RCC_CR_HSION    ((uint32_t) 0x00000001)     /*!< Internal High Speed clock enable */
#define RCC_CR_HSEON    ((uint32_t) 0x00010000)     /*!< External High Speed clock enable */
#define RCC_CR_HSERDY   ((uint32_t) 0x00020000)     /*!< External High Speed clock ready flag */
#define RCC_CR_CSSON    ((uint32_t) 0x00080000)     /*!< Clock Security System enable */

/* Bit definition for RCC_CFGR register */
#define RCC_CFGR_SW     ((uint32_t) 0x00000003) /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_HSE     ((uint32_t) 0x00000001) /*!< HSE selected as system clock */
#define RCC_CFGR_SWS        ((uint32_t) 0x0000000C) /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_HPRE_DIV1  ((uint32_t) 0x00000000) /*!< SYSCLK not divided */
#define RCC_CFGR_PPRE1_DIV1 ((uint32_t) 0x00000000) /*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV1 ((uint32_t) 0x00000000) /*!< HCLK not divided */

/* Bit definition for FLASH_ACR register */
#define FLASH_ACR_LATENCY   ((uint8_t) 0x03)    /*!< LATENCY[2:0] bits (Latency) */
#define FLASH_ACR_LATENCY_0 ((uint8_t) 0x00)    /*!< Bit 0 */
#define FLASH_ACR_PRFTBE    ((uint8_t) 0x10)    /*!< Prefetch Buffer Enable */

#define HSE_STARTUP_TIMEOUT ((uint16_t) 0x0500) /*!< Time out for HSE start up */

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
    *(GPIOA_ODR) = (uint32_t) (0x00000000); 
    *(GPIOA_BSRR) = (uint32_t) (0x00000000); 
    *(GPIOA_BRR) = (uint32_t) (0x00000000); 
}

void USART_init(void)
{
    *(USART2_CR1) = (uint32_t) (0x0000000C | 0x00002000);
                                ///UE: Usart Enable, TE/RE: TX/RX enable
    *(USART2_CR2) = (uint32_t) 0x00000000; 
    *(USART2_CR3) = (uint32_t) 0x00000000; 
}
