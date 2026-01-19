#include "timer.h"
#include "rcc.h"
#include "gpio.h"
#include "irq.h"




//tim 2 and 5 general purpose timer

void StartTimer(TIM_t * timerX,uint32 tick, uint32 prescaler)
{
	//enable clock for TIM reg
	 RCC->APB1ENR |= RCC_APB1ENR_TIM_2_EN_Msk;

	 //set prescaler
	 timerX->PSC = prescaler - 1u;

	 //set auto-reloadH
	 timerX->ARR = tick;

	 //clear counter
	 timerX->CNT = 0;

	 //enable TIMER
	 timerX->CR1 = TIM_CR1_CEN;
}

void StartTimer_IRQ(TIM_t * timerX,uint32 tick, uint32 prescaler)
{
	//enable clock for TIM reg
	 RCC->APB1ENR |= RCC_APB1ENR_TIM_2_EN_Msk;

	 //set prescaler
	 timerX->PSC = prescaler - 1u;

	 //set auto-reloadH
	 timerX->ARR = tick;

	 //clear counter
	 timerX->CNT = 0;

	 //enable TIMER
	 timerX->CR1 = TIM_CR1_CEN;

	 //en irq
	 timerX->DIER = 1<<0;

	 NVIC_EnableIRQ(TIM2_IRQn);
}


void StartTimer_OutputCompare(TIM_t * timerX,uint32 tick, uint32 prescaler)
{
	gpio_config_t x;
	x.direction = ALTERNATE_FUNC;

	vDo_AHB1ENR_EnableClockAccessToGPIO(GPIO_PORT_A);

	vDoConfigDirection(GPIO_PORT_A,PIN_5,x);

	vDoSetGPIOAltFunc(GPIO_PORT_A,PIN_5,AF_1,AF_LOW);


	 RCC->APB1ENR |= RCC_APB1ENR_TIM_2_EN_Msk;

	 //set prescaler
	 timerX->PSC = prescaler - 1u;

	 //set auto-reloadH
	 timerX->ARR = tick;

	 //set ouput compare toggle mode
	 timerX->CCMR1 = (1<<4) | (1<<5);

	 //enable tim in  compare mode
	 timerX->CCER = 1<<0;

	 //clear counter
	 timerX->CNT = 0;

	 timerX->CR1 = TIM_CR1_CEN;
}

void StartTimer_InputCapture(TIM_t * timerX,uint32 tick, uint32 prescaler)
{
	gpio_config_t x;
	x.direction = ALTERNATE_FUNC;

	vDo_AHB1ENR_EnableClockAccessToGPIO(GPIO_PORT_A);

	vDoConfigDirection(GPIO_PORT_A,PIN_6,x);

	vDoSetGPIOAltFunc(GPIO_PORT_A,PIN_6,AF_2,AF_LOW);


	 RCC->APB1ENR |= RCC_APB1ENR_TIM_3_EN_Msk;

	 //set prescaler
	 timerX->PSC = prescaler - 1u;

	 //set auto-reloadH
	 //timerX->ARR = tick;

	 //set input capture
	 timerX->CCMR1 = (1<<0);

	 //enable tim in  capture mode
	 timerX->CCER = 1<<0;

	 //clear counter
	 timerX->CNT = 0;

	 timerX->CR1 = TIM_CR1_CEN;
}
