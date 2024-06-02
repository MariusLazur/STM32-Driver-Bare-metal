
#include "rcc.h"

void vDoEnablePeriphClock_AHB(rcc_config periph_clock, rcc_select_port_en_clock position){

	switch(periph_clock.rcc_AHB_clock_EN_r)
	{
	case (AHB_1_PERIPH):
		RCC->AHB1ENR = RCC_AHB_X_ENR_GPIO_Y_EN_Msk(position);
			break;
	case (AHB_2_PERIPH):
		RCC->AHB2ENR = RCC_AHB_X_ENR_GPIO_Y_EN_Msk(position);
			break;
	case (AHB_3_PERIPH):
		RCC->AHB3ENR = RCC_AHB_X_ENR_GPIO_Y_EN_Msk(position);
				break;
	default:
		break;
	}

}

void vDoEnablePeriphClock_APB(rcc_config periph_clock, rcc_select_timer_en_clock position){

	switch(periph_clock.rcc_APB_clock_EN_r)
	{
	case (APB_1_PERIPH):
		RCC->APB1ENR = RCC_APB_X_ENR_TIM_Y_EN_Msk(position);
			break;
	case (APB_2_PERIPH):
		RCC->APB2ENR = RCC_APB_X_ENR_TIM_Y_EN_Msk(position);
			break;
	default:
		break;
	}

}
