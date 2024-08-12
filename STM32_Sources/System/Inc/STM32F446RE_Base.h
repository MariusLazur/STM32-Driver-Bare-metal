/*
 * STM32F446RE_Base.h
 *
 *  Created on: May 29, 2024
 *      Author:
 */


#ifndef STM32F446RE_BASE_H_
#define STM32F446RE_BASE_H_


#include "types.h"
#include "gpio_reg.h"
#include "pwr_reg.h"
#include "rcc_reg.h"
#include "uart_reg.h"
#include "timer_reg.h"



#define SYS_FREQ 16000000UL
#define APB1_CLK SYS_FREQ


//define base busses
#define APB1PERIPH_BASE 0x40000000UL
#define APB2PERIPH_BASE 0x40010000UL
#define AHB1PERIPH_BASE 0x40020000UL
#define AHB2PERIPH_BASE 0x50000000UL
#define AHB3PERIPH_BASE 0x60000000UL

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


#endif /* STM32F446RE_BASE_H_ */
