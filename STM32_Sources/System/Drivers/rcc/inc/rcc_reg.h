#include "types.h"

typedef struct
{
  __IO CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32 RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO  APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO  APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32 RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO  AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO  AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO  AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32 RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO  APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO  APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32 RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO  AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO  AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO  AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32 RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO  APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO  APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32 RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO  BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO  CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32 RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO  SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO  PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  __IO  PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  __IO  DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
  __IO  CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
  __IO  DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_t;
