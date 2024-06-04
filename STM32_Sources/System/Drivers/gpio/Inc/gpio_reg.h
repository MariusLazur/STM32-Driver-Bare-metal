
#ifndef STM32_PROJECT_GPIO_REG_H
#define STM32_PROJECT_GPIO_REG_H

#include "types.h"

typedef struct {
	__IO GPIOx_MODER; /*GPIO port mode register*/
	__O GPIOx_OTYPER;
	__IO GPIOx_OSPEEDR;
	__IO GPIOx_PUPDR;
	__I GPIOx_IDR;
	__O GPIOx_ODR;
	__IO GPIOx_BSRR;
	__IO GPIOx_LCKR;
	__IO GPIOx_AFR[2];
//__IO GPIOx_AFRH;
} GPIO_t;

#endif //STM32_PROJECT_GPIO_REG_H
