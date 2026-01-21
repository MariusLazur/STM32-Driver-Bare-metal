#include "irq.h"
#include "rcc.h"
#include "gpio.h"

#define SET_EXTI13  (2<<4)


void PC13_exti_init(){

	gpio_config_t cfgGPIO;

	cfgGPIO.direction = INPUT;

	//disable global inrq (good practice)
	//__disable_irq();

	// enable clock access dor gpio pc13
	vDo_AHB1ENR_EnableClockAccessToGPIO(GPIO_PORT_C);

	//set PC13 as input
	vDoConfigDirection(GPIO_PORT_C,PIN_13,cfgGPIO);

	//enable clock access for syscfg
	vDo_APB2ENR_EnableClockAccessToSYSCFG(RCC_APB2ENR_SYSCFG_EN_Msk);

	//select PORTC as EXTI
	SYSCFG->EXTICR[3] = SET_EXTI13;

	//unmask EXTI
	EXTI->IMR = (1U<<13);

	//select falling edge trigger
	EXTI->FTSR = (1U<<13);

	//enable EXTI13 line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);


	//__enable_irq();
}


