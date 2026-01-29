/**
 * @file    dma.c
 * @brief   DMA driver for USART2 TX (DMA1 Stream6 Channel4)
 */

#include "dma.h"
#include "dma_reg.h"
#include "rcc.h"
#include "irq.h"

/* ============== External flag for transfer complete ============== */
extern volatile uint8 transfer_done;

/* ============== DMA1 Stream6 for USART2 TX ============== */
// USART2_TX = DMA1, Stream 6, Channel 4

/**
 * @brief  Initialize DMA for UART TX (one-time setup)
 */
void dma_uart_init(void)
{
    // 1. Enable DMA1 clock
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;

    // 2. Make sure stream is disabled before configuration
    DMA1_STREAM6->CR &= ~DMA_SxCR_EN;

    // 3. Wait until stream is disabled (EN bit reads 0)
    while(DMA1_STREAM6->CR & DMA_SxCR_EN);

    // 4. Clear all interrupt flags for stream 6 (write to HIFCR)
    DMA1->HIFCR = DMA_HIFCR_STREAM6_ALL;

    // 5. Set peripheral address (USART2 Data Register)
    DMA1_STREAM6->PAR = (uint32)&USART_2->DR;

    // 6. Configure DMA stream:
    //    - Channel 4 (USART2_TX)
    //    - Memory to Peripheral direction
    //    - Memory increment mode (citește bytes consecutivi din memorie)
    //    - Peripheral size 8-bit (UART trimite byte cu byte)
    //    - Memory size 8-bit
    //    - Priority high
    //    - Transfer complete interrupt enable
    DMA1_STREAM6->CR = DMA_SxCR_CHSEL(4)      |  // Channel 4 = USART2_TX
                       DMA_SxCR_DIR_M2P       |  // Memory to Peripheral
                       DMA_SxCR_MINC          |  // Memory increment
                       DMA_SxCR_PSIZE_8BIT    |  // Peripheral size 8-bit
                       DMA_SxCR_MSIZE_8BIT    |  // Memory size 8-bit
                       DMA_SxCR_PL_HIGH       |  // Priority high
                       DMA_SxCR_TCIE;            // Transfer complete interrupt

    // 7. Disable FIFO (use direct mode)
    DMA1_STREAM6->FCR = 0;

    // 8. Enable USART2 DMA transmitter
    USART_2->CR3 |= USART_CR3_DMAT;

    // 9. Enable DMA interrupt in NVIC
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

/**
 * @brief  Start DMA transfer for UART TX
 * @param  data: Pointer to data buffer
 * @param  length: Number of bytes to transfer
 */
void dma_uart_send(uint8 *data, uint32 length)
{
    // 1. Disable stream before reconfiguration
    DMA1_STREAM6->CR &= ~DMA_SxCR_EN;

    // 2. Wait until disabled
    while(DMA1_STREAM6->CR & DMA_SxCR_EN);

    // 3. Clear interrupt flags
    DMA1->HIFCR = DMA_HIFCR_STREAM6_ALL;

    // 4. Set memory address (source buffer)
    DMA1_STREAM6->M0AR = (uint32)data;

    // 5. Set number of data items(bytes) to transfer
    DMA1_STREAM6->NDTR = length;

    // 6. Enable stream (start transfer)
    DMA1_STREAM6->CR |= DMA_SxCR_EN;

    // Transfer is now running in background!
    // CPU can do other work...
    // When complete, DMA1_Stream6_IRQHandler will be called
}

/**
 * @brief  Check if DMA transfer is complete
 * @return 1 if complete, 0 if still running
 */
uint8 dma_uart_is_complete(void)
{
    return (DMA1->HISR & DMA_HISR_TCIF6) ? 1 : 0;
}

/**
 * @brief  DMA1 Stream6 Interrupt Handler (Transfer Complete)
 */
void DMA1_Stream6_IRQHandler(void)
{
    // Check if transfer complete flag is set
    if(DMA1->HISR & DMA_HISR_TCIF6)
    {
        // Clear the transfer complete flag
        DMA1->HIFCR = DMA_HIFCR_CTCIF6;

        // Set the global flag to notify main code
        transfer_done = 1;
    }

    // Clear any other flags (error flags)
    DMA1->HIFCR = DMA_HIFCR_STREAM6_ALL;
}
