/*
 * STM32F446RE_Base.h
 *
 *  Created on: May 29, 2024
 *      Author:
 */

#include "types.h"
#include "gpio_reg.h"
#include "pwr_reg.h"
#include "rcc_reg.h"



#ifndef STM32F446RE_BASE_H_
#define STM32F446RE_BASE_H_

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


/*===========PWR REGISTERS CONFIG===============*/
#define PWR_OFFSET          (0x7000UL)
//#define PWR                 ((PWR_ta *) (APB1PERIPH_BASE + PWR_BASE))

#endif /* STM32F446RE_BASE_H_ */
