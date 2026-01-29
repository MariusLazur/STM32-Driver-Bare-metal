

#ifndef STM32_PROJECT_SPI_REG_H
#define STM32_PROJECT_SPI_REG_H

#include "types.h"

#define SPI_CR1_CPHA(x)      (x<<0U)
#define SPI_CR1_CPOL(x)      (x<<1U)
#define SPI_CR1_MSTR(x)      (x<<2U)
#define SPI_CR1_BR(n)        (n<<3U)
#define SPI_CR1_SPEn         (1<<6U)
#define SPI_CR1_LSBFIRST(x)  (x<<7U)
#define SPI_CR1_SSI(x)       (x<<8U)
#define SPI_CR1_SSM(x)       (x<<9U)
#define SPI_CR1_RXONLY(x)    (x<<10U)
#define SPI_CR1_DFF(x)       (x<<11U)
#define SPI_CR1_CRCNEXT(x)   (x<<12U)
#define SPI_CR1_CRCEN(x)     (x<<13U)
#define SPI_CR1_BIDIOE(x)    (x<<14U)
#define SPI_CR1_BIDIMODE(x)  (x<<15U)

#define SPI_GET_DATA_OUT(reg)      (((reg) >> 0u) & 0xFFFFFFFFu)

#define GET_SPI_SR_RXNE(reg)   ((reg) >> 0U)
#define GET_SPI_SR_TXE(reg)    (((reg) >> 1U) & 1U)
#define GET_SPI_SR_CHSIDE(reg) ((reg) >> 2U)
#define GET_SPI_SR_UDR(reg)    ((reg) >> 3U)
#define GET_SPI_SR_CRCERR(reg) ((reg) >> 4U)
#define GET_SPI_SR_MODF(reg)   ((reg) >> 5U)
#define GET_SPI_SR_OVR(reg)    ((reg) >> 6U)
#define GET_SPI_SR_BSY(reg)    ((reg) >> 7U)
#define GET_SPI_SR_FRE(reg)    ((reg) >> 8U)

typedef struct {
	__IO CR1;
	__IO CR2;
	__IO SR;
	__IO DR;
	__IO CRCPR;
	__IO RXCRCR;//read only
	__IO TXCRCR;// read only
	__IO I2SCFGR;
	__IO I2SPR;
} SPI_t;



#endif //STM32_PROJECT_SPI_REG_H
