

#ifndef SYSTEM_INC_SYSCFG_H_
#define SYSTEM_INC_SYSCFG_H_

#include "types.h"
typedef struct
{
  __IO MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
  uint32      RESERVED1[2]; /*!< Reserved, 0x24-0x28                                                          */
  __IO CFGR;         /*!< SYSCFG Configuration register,                     Address offset: 0x2C      */
} SYSCFG_t;

#endif /* SYSTEM_INC_SYSCFG_H_ */
