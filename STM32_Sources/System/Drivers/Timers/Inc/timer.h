

#ifndef SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_
#define SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_

#include "STM32F446RE_Base.h"

//the UIF from SR register indicate when ARR rich establish limit and set the flag to 1 manualy should be reseted
/*while(!(TIM_2->SR & SR_UIF)){}
TIM_2->SR &=~SR_UIF;*/
#define SR_UIF (1<<0)

#define SR_CC1IF (1<<1)


//1sec = 1000ms
#define DIVIDER_16MHZ    0UL
#define DIVIDER_1HZ   (16000 - 1)
#define DIVIDER_0_5HZ   (800 - 1)

#define TICK_16MHZ(X)   (uint32)((((X)*(16000000UL))/1000000UL)-1)
#define TICK_1HZ(X)   (uint32)((((X)*(1UL))/1000000UL)-1)

#define TIMER_TICK_US_16MHZ(x)		TICK_16MHZ(x), DIVIDER_16MHZ
#define TIMER_TICK_US_1HZ(x)		TICK_16MHZ(x), DIVIDER_1HZ
#define TIMER_TICK_US_0_5HZ(x)		TICK_16MHZ(x), DIVIDER_0_5HZ

/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1UL << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk



#define  TMR_GET_VALUE32(reg)                              (((reg) >> 0u) & 0xFFFFFFFFu)
#define  TMR_GET_VALUE16(reg)                              (((reg) >> 0u) & 0xFFFFu)


#define ONE_SECOND 1000000UL
void StartTimer(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_OutputCompare(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_InputCapture(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_IRQ(TIM_t * timerX,uint32 tick, uint32 prescaler);


#endif /* SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_ */
