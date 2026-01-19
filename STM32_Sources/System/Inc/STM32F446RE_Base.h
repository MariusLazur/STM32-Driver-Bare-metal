/*
 * STM32F446RE_Base.h
 *
 *  Created on: May 29, 2024
 *      Author:
 */


#ifndef STM32F446RE_BASE_H_
#define STM32F446RE_BASE_H_

#include "syscfg.h"
#include "types.h"
#include "gpio_reg.h"
#include "pwr_reg.h"
#include "rcc_reg.h"
#include "uart_reg.h"
#include "timer_reg.h"
#include "dma_reg.h"



#define SYS_FREQ 16000000UL
#define APB1_CLK SYS_FREQ


//define base busses
#define APB1PERIPH_BASE 0x40000000UL
#define APB2PERIPH_BASE 0x40010000UL
#define AHB1PERIPH_BASE 0x40020000UL
#define AHB2PERIPH_BASE 0x50000000UL
#define AHB3PERIPH_BASE 0x60000000UL

/*===========SYSCFG REGISTERS CONFIG===============*/
#define SYSCFG_BASE         (APB2PERIPH_BASE + 0x3800)
#define SYSCFG              ((SYSCFG_t *) SYSCFG_BASE)

/*===========interup events REGISTERS CONFIG===============*/
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00)
#define EXTI                  ((EXTI_t *) EXTI_BASE)
/*===========GPIO REGISTERS CONFIG===============*/

/* Configure the offset for every PORT */
#define GPIO_A_OFFSET (0x0000UL)
#define GPIO_B_OFFSET (0x0400UL)
#define GPIO_C_OFFSET (0x0800UL)
#define GPIO_D_OFFSET (0x0C00UL)
#define GPIO_E_OFFSET (0x1000UL)
#define GPIO_F_OFFSET (0x1400UL)
#define GPIO_G_OFFSET (0x1800UL)
#define GPIO_H_OFFSET (0x1C00UL)

/* Configure the base for every port */
#define GPIO_A_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_A_OFFSET))
#define GPIO_B_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_B_OFFSET))
#define GPIO_C_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_C_OFFSET))
#define GPIO_D_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_D_OFFSET))
#define GPIO_E_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_E_OFFSET))
#define GPIO_F_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_F_OFFSET))
#define GPIO_G_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_G_OFFSET))
#define GPIO_H_REG ((GPIO_t *)(AHB1PERIPH_BASE + GPIO_H_OFFSET))

/*===========RCC REGISTERS CONFIG===============*/
#define RCC_OFFSET 			(0x3800UL)
#define RCC        			((RCC_t *) (AHB1PERIPH_BASE + RCC_OFFSET))

/*===========USART REGISTERS CONFIG APB1===============*/
#define USART_2_OFFSET 		(0x4400UL)
#define USART_2        		((USART_t *) (APB1PERIPH_BASE + USART_2_OFFSET))

#define USART_3_OFFSET 		(0x4800UL)
#define USART_3        		((USART_t *) (APB1PERIPH_BASE + USART_3_OFFSET))

/*===========UART REGISTERS CONFIG for APB1===============*/
#define UART_4_OFFSET 		(0x4c00UL)
#define UART_4       		((USART_t *) (APB1PERIPH_BASE + UART_4_OFFSET))

#define USART_5_OFFSET 		(0x5000UL)
#define USART_5        		((USART_t *) (APB1PERIPH_BASE + UART_5_OFFSET))



/*===========PWR REGISTERS CONFIG===============*/
#define PWR_OFFSET          (0x7000UL)
//#define PWR                 ((PWR_ta *) (APB1PERIPH_BASE + PWR_BASE))

/*===========TIMERS REGISTERS CONFIG for APB1===============*/
#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000UL)

#define TIM_2       			((TIM_t *) (TIM2_BASE))
#define TIM_3       			((TIM_t *) (TIM3_BASE))
#define TIM_4       			((TIM_t *) (TIM4_BASE))
#define TIM_5       			((TIM_t *) (TIM5_BASE))
#define TIM_6       			((TIM_t *) (TIM6_BASE))
#define TIM_7       			((TIM_t *) (TIM7_BASE))
#define TIM_12       			((TIM_t *) (TIM12_BASE))
#define TIM_13       			((TIM_t *) (TIM13_BASE))
#define TIM_14       			((TIM_t *) (TIM14_BASE))

/*===========DMA REGISTERS CONFIG for AHB1===============*/ 
#define DMA1_OFFSET_BASE 0x6000UL
//Address offset: 0x010 + 0x018 * x, (x = 0 to 7)
#define DMA1_BASE         (AHB1PERIPH_BASE + DMA1_OFFSET_BASE)
#define DMA1_STREAM0_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x010UL)
#define DMA1_STREAM1_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x028UL)
#define DMA1_STREAM2_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x040UL)
#define DMA1_STREAM3_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x058UL)
#define DMA1_STREAM4_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x070UL)
#define DMA1_STREAM5_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x088UL)
#define DMA1_STREAM6_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x0A0UL)
#define DMA1_STREAM7_BASE (AHB1PERIPH_BASE + DMA1_OFFSET_BASE+ 0x0B8UL)

#define DMA2_OFFSET_BASE 0x6400UL
#define DMA2_BASE    (AHB1PERIPH_BASE + DMA2_OFFSET_BASE)
//Address offset: 0x010 + 0x018 * x, (x = 0 to 7)
#define DMA2_STREAM0_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x010UL)
#define DMA2_STREAM1_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x028UL)
#define DMA2_STREAM2_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x040UL)
#define DMA2_STREAM3_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x058UL)
#define DMA2_STREAM4_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x070UL)
#define DMA2_STREAM5_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x088UL)
#define DMA2_STREAM6_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x0A0UL)
#define DMA2_STREAM7_BASE (AHB1PERIPH_BASE + DMA2_OFFSET_BASE+ 0x0B8UL)

#define DMA1         (DMA_t*)DMA1_BASE
#define DMA1_STREAM0 (DMA_STREAMx_t*)DMA1_STREAM0_BASE
#define DMA1_STREAM1 (DMA_STREAMx_t*)DMA1_STREAM1_BASE
#define DMA1_STREAM2 (DMA_STREAMx_t*)DMA1_STREAM2_BASE
#define DMA1_STREAM3 (DMA_STREAMx_t*)DMA1_STREAM3_BASE
#define DMA1_STREAM4 (DMA_STREAMx_t*)DMA1_STREAM4_BASE
#define DMA1_STREAM5 (DMA_STREAMx_t*)DMA1_STREAM5_BASE
#define DMA1_STREAM6 (DMA_STREAMx_t*)DMA1_STREAM6_BASE
#define DMA1_STREAM7 (DMA_STREAMx_t*)DMA1_STREAM7_BASE

#define DMA2         (DMA_t*)DMA2_BASE
#define DMA2_STREAM0 (DMA_STREAMx_t*)DMA2_STREAM0_BASE
#define DMA2_STREAM1 (DMA_STREAMx_t*)DMA2_STREAM1_BASE
#define DMA2_STREAM2 (DMA_STREAMx_t*)DMA2_STREAM2_BASE
#define DMA2_STREAM3 (DMA_STREAMx_t*)DMA2_STREAM3_BASE
#define DMA2_STREAM4 (DMA_STREAMx_t*)DMA2_STREAM4_BASE
#define DMA2_STREAM5 (DMA_STREAMx_t*)DMA2_STREAM5_BASE
#define DMA2_STREAM6 (DMA_STREAMx_t*)DMA2_STREAM6_BASE
#define DMA2_STREAM7 (DMA_STREAMx_t*)DMA2_STREAM7_BASE

/*===========TIMERS REGISTERS CONFIG for APB2===============*/
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)

#define TIM_1       			((TIM_t *) (TIM1_BASE))
#define TIM_8       			((TIM_t *) (TIM8_BASE))
#define TIM_9       			((TIM_t *) (TIM9_BASE))
#define TIM_10       			((TIM_t *) (TIM10_BASE))
#define TIM_11       			((TIM_t *) (TIM11_BASE))


/* Memory mapping of Cortex-M4 Hardware */
#define SCS_BASE            (0xE000E000UL)

#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address               */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address                  */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address  */

#define SCnSCB              ((SCnSCB_Type    *)     SCS_BASE      )   /*!< System control Register not in SCB */
#define SCB                 ((SCB_Type       *)     SCB_BASE      )   /*!< SCB configuration struct           */
#define SysTick             ((SysTick_Type   *)     SysTick_BASE  )   /*!< SysTick configuration struct       */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct          */
                         /*!< System Control Space Base Address  */


/* Software Triggered Interrupt Register Definitions */
#define NVIC_STIR_INTID_Pos                 0                                          /*!< STIR: INTLINESNUM Position */
#define NVIC_STIR_INTID_Msk                (0x1FFUL << NVIC_STIR_INTID_Pos)            /*!< STIR: INTLINESNUM Mask */

/*@} end of group CMSIS_NVIC */



#endif /* STM32F446RE_BASE_H_ */
