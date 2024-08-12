

#ifndef SYSTEM_DRIVERS_TIMERS_INC_TIMER_REG_H_
#define SYSTEM_DRIVERS_TIMERS_INC_TIMER_REG_H_

#include "types.h"

/**
  * @brief TIM
  */

typedef struct
{
  __IO CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_t;


#endif /* SYSTEM_DRIVERS_TIMERS_INC_TIMER_REG_H_ */
