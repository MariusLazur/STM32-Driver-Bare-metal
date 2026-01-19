
#ifndef STM32_PROJECT_DMA_REG_H
#define STM32_PROJECT_DMA_REG_H

#include "types.h"

typedef struct {
	__IO SxCR;
	__IO SxNDTR;
	__IO SxPAR;
	__IO SxM0AR;
	__IO SxM1AR;
	__IO SxFCR;
} DMA_STREAMx_t;


typedef struct {
	__IO LISR; 
	__IO HISR;
	__IO LIFCR;
	__IO HIFCR;
} DMA_t;



#endif //STM32_PROJECT_DMA_REG_H
