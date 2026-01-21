

#ifndef SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_
#define SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_

#include "STM32F446RE_Base.h"

//the UIF from SR register indicate when ARR rich establish limit and set the flag to 1 manualy should be reseted
/*while(!(TIM_2->SR & SR_UIF)){}
TIM_2->SR &=~SR_UIF;*/
#define SR_UIF (1<<0)

#define SR_CC1IF (1<<1)


// Timer configuration macros for 16MHz system clock
// PSC divides clock, ARR sets period: Period = (PSC+1) * (ARR+1) / 16MHz

// Prescaler values (actual divider = value + 1)
#define PSC_1MHZ    (16 - 1)      // 16MHz / 16 = 1MHz (1us per tick)
#define PSC_1KHZ    (16000 - 1)   // 16MHz / 16000 = 1kHz (1ms per tick)

// ARR values for common periods (with 1kHz counter = 1ms ticks)
#define ARR_1SEC    (1000 - 1)    // 1000 ticks = 1 second
#define ARR_500MS   (500 - 1)     // 500 ticks = 0.5 second
#define ARR_100MS   (100 - 1)     // 100 ticks = 0.1 second

// Macros: TIMER_MS(period_ms) gives (ARR, PSC) for millisecond periods
#define TIMER_MS(ms)    ((ms) - 1), PSC_1KHZ
#define TIMER_SEC(sec)  ((sec) * 1000 - 1), PSC_1KHZ

/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1UL << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk



#define  TMR_GET_VALUE32(reg)                              (((reg) >> 0u) & 0xFFFFFFFFu)
#define  TMR_GET_VALUE16(reg)                              (((reg) >> 0u) & 0xFFFFu)

void StartTimer(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_OutputCompare(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_InputCapture(TIM_t * timerX,uint32 tick, uint32 prescaler);
void StartTimer_IRQ(TIM_t * timerX,uint32 tick, uint32 prescaler);


#endif /* SYSTEM_DRIVERS_TIMERS_INC_TIMER_H_ */
