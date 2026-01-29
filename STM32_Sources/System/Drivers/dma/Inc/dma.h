/**
 * @file    dma.h
 * @brief   DMA driver for USART2 TX
 */

#ifndef STM32_PROJECT_DMA_H
#define STM32_PROJECT_DMA_H

#include "STM32F446RE_Base.h"

/**
 * @brief  Initialize DMA for UART TX (one-time setup)
 *         Configures DMA1 Stream6 Channel4 for USART2 TX
 */
void dma_uart_init(void);

/**
 * @brief  Start DMA transfer for UART TX (non-blocking)
 * @param  data: Pointer to data buffer
 * @param  length: Number of bytes to transfer
 * @note   After calling this, CPU is free to do other work.
 *         Check transfer_done flag or use interrupt to know when complete.
 */
void dma_uart_send(uint8 *data, uint32 length);

/**
 * @brief  Check if DMA transfer is complete
 * @return 1 if complete, 0 if still running
 */
uint8 dma_uart_is_complete(void);

#endif //STM32_PROJECT_DMA_H
