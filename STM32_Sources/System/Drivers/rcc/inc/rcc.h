

#include "STM32F446RE_Base.h"

#define RCC_AHB_X_ENR_GPIO_Y_EN_Msk(RCC_AHB_X_ENR_GPIO_Y_EN_Pos)          (0x1UL << RCC_AHB_X_ENR_GPIO_Y_EN_Pos)

#define RCC_APB_X_ENR_TIM_Y_EN_Msk(RCC_APBX_X_ENR_TIM_Y_EN_Pos)           (0x1UL << RCC_APBX_X_ENR_TIM_Y_EN_Pos)


typedef enum{
	AHB_1_PERIPH = 1,
	AHB_2_PERIPH = 2,
	AHB_3_PERIPH = 3
}rcc_enable_periph_AHB_clock_t;

typedef enum{
	APB_1_PERIPH = 1,
	APB_2_PERIPH = 2
}rcc_enable_periph_APB_clock_t;

typedef enum{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}rcc_select_port_en_clock;

typedef enum{
	TIM_A = 0,
	TIM_B,
	TIM_C,
	TIM_D,
	TIM_E,
	TIM_F,
	TIM_G,
	TIM_H
}rcc_select_timer_en_clock;

typedef struct{
	rcc_enable_periph_AHB_clock_t rcc_AHB_clock_EN_r;
	rcc_enable_periph_APB_clock_t rcc_APB_clock_EN_r;
}rcc_config;



void vDoEnablePeriphClock_AHB(rcc_config periph_clock, rcc_select_port_en_clock position);
void vDoEnablePeriphClock_APB(rcc_config periph_clock, rcc_select_timer_en_clock position);
