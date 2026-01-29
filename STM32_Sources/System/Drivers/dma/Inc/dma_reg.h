
#ifndef STM32_PROJECT_DMA_REG_H
#define STM32_PROJECT_DMA_REG_H

#include "types.h"

/* ============== DMA Stream Register Structure ============== */
typedef struct {
    __IO CR;      // Configuration register
    __IO NDTR;    // Number of data register
    __IO PAR;     // Peripheral address register
    __IO M0AR;    // Memory 0 address register
    __IO M1AR;    // Memory 1 address register
    __IO FCR;     // FIFO control register
} DMA_Stream_t;

// Alias pentru compatibilitate cu definițiile existente
typedef DMA_Stream_t DMA_STREAMx_t;

/* ============== DMA Controller Register Structure ============== */
typedef struct {
    __IO LISR;    // Low interrupt status register
    __IO HISR;    // High interrupt status register
    __IO LIFCR;   // Low interrupt flag clear register
    __IO HIFCR;   // High interrupt flag clear register
} DMA_t;

/* ============== DMA_SxCR - Stream Configuration Register ============== */
#define DMA_SxCR_EN_Pos         0U
#define DMA_SxCR_EN             (1UL << DMA_SxCR_EN_Pos)      // Stream enable

#define DMA_SxCR_DMEIE_Pos      1U
#define DMA_SxCR_DMEIE          (1UL << DMA_SxCR_DMEIE_Pos)   // Direct mode error interrupt enable

#define DMA_SxCR_TEIE_Pos       2U
#define DMA_SxCR_TEIE           (1UL << DMA_SxCR_TEIE_Pos)    // Transfer error interrupt enable

#define DMA_SxCR_HTIE_Pos       3U
#define DMA_SxCR_HTIE           (1UL << DMA_SxCR_HTIE_Pos)    // Half transfer interrupt enable

#define DMA_SxCR_TCIE_Pos       4U
#define DMA_SxCR_TCIE           (1UL << DMA_SxCR_TCIE_Pos)    // Transfer complete interrupt enable

#define DMA_SxCR_PFCTRL_Pos     5U
#define DMA_SxCR_PFCTRL         (1UL << DMA_SxCR_PFCTRL_Pos)  // Peripheral flow controller

#define DMA_SxCR_DIR_Pos        6U
#define DMA_SxCR_DIR_P2M        (0UL << DMA_SxCR_DIR_Pos)     // Peripheral to memory
#define DMA_SxCR_DIR_M2P        (1UL << DMA_SxCR_DIR_Pos)     // Memory to peripheral
#define DMA_SxCR_DIR_M2M        (2UL << DMA_SxCR_DIR_Pos)     // Memory to memory

#define DMA_SxCR_CIRC_Pos       8U
#define DMA_SxCR_CIRC           (1UL << DMA_SxCR_CIRC_Pos)    // Circular mode

#define DMA_SxCR_PINC_Pos       9U
#define DMA_SxCR_PINC           (1UL << DMA_SxCR_PINC_Pos)    // Peripheral increment mode

#define DMA_SxCR_MINC_Pos       10U
#define DMA_SxCR_MINC           (1UL << DMA_SxCR_MINC_Pos)    // Memory increment mode

#define DMA_SxCR_PSIZE_Pos      11U
#define DMA_SxCR_PSIZE_8BIT     (0UL << DMA_SxCR_PSIZE_Pos)   // Peripheral size 8-bit
#define DMA_SxCR_PSIZE_16BIT    (1UL << DMA_SxCR_PSIZE_Pos)   // Peripheral size 16-bit
#define DMA_SxCR_PSIZE_32BIT    (2UL << DMA_SxCR_PSIZE_Pos)   // Peripheral size 32-bit

#define DMA_SxCR_MSIZE_Pos      13U
#define DMA_SxCR_MSIZE_8BIT     (0UL << DMA_SxCR_MSIZE_Pos)   // Memory size 8-bit
#define DMA_SxCR_MSIZE_16BIT    (1UL << DMA_SxCR_MSIZE_Pos)   // Memory size 16-bit
#define DMA_SxCR_MSIZE_32BIT    (2UL << DMA_SxCR_MSIZE_Pos)   // Memory size 32-bit

#define DMA_SxCR_PINCOS_Pos     15U
#define DMA_SxCR_PINCOS         (1UL << DMA_SxCR_PINCOS_Pos)  // Peripheral increment offset size

#define DMA_SxCR_PL_Pos         16U
#define DMA_SxCR_PL_LOW         (0UL << DMA_SxCR_PL_Pos)      // Priority low
#define DMA_SxCR_PL_MEDIUM      (1UL << DMA_SxCR_PL_Pos)      // Priority medium
#define DMA_SxCR_PL_HIGH        (2UL << DMA_SxCR_PL_Pos)      // Priority high
#define DMA_SxCR_PL_VERY_HIGH   (3UL << DMA_SxCR_PL_Pos)      // Priority very high

#define DMA_SxCR_DBM_Pos        18U
#define DMA_SxCR_DBM            (1UL << DMA_SxCR_DBM_Pos)     // Double buffer mode

#define DMA_SxCR_CT_Pos         19U
#define DMA_SxCR_CT             (1UL << DMA_SxCR_CT_Pos)      // Current target

#define DMA_SxCR_CHSEL_Pos      25U
#define DMA_SxCR_CHSEL(ch)      ((ch) << DMA_SxCR_CHSEL_Pos)  // Channel selection

/* ============== DMA_HISR/HIFCR - Stream 6 Flag Positions ============== */
// Stream 6 flags are in HISR/HIFCR (streams 4-7 are in High registers)
#define DMA_HISR_FEIF6_Pos      16U
#define DMA_HISR_FEIF6          (1UL << DMA_HISR_FEIF6_Pos)   // FIFO error flag

#define DMA_HISR_DMEIF6_Pos     18U
#define DMA_HISR_DMEIF6         (1UL << DMA_HISR_DMEIF6_Pos)  // Direct mode error flag

#define DMA_HISR_TEIF6_Pos      19U
#define DMA_HISR_TEIF6          (1UL << DMA_HISR_TEIF6_Pos)   // Transfer error flag

#define DMA_HISR_HTIF6_Pos      20U
#define DMA_HISR_HTIF6          (1UL << DMA_HISR_HTIF6_Pos)   // Half transfer flag

#define DMA_HISR_TCIF6_Pos      21U
#define DMA_HISR_TCIF6          (1UL << DMA_HISR_TCIF6_Pos)   // Transfer complete flag

// Clear flags (same positions, write to HIFCR)
#define DMA_HIFCR_CFEIF6        DMA_HISR_FEIF6
#define DMA_HIFCR_CDMEIF6       DMA_HISR_DMEIF6
#define DMA_HIFCR_CTEIF6        DMA_HISR_TEIF6
#define DMA_HIFCR_CHTIF6        DMA_HISR_HTIF6
#define DMA_HIFCR_CTCIF6        DMA_HISR_TCIF6

// All Stream 6 flags combined
#define DMA_HIFCR_STREAM6_ALL   (DMA_HIFCR_CFEIF6 | DMA_HIFCR_CDMEIF6 | \
                                 DMA_HIFCR_CTEIF6 | DMA_HIFCR_CHTIF6 | \
                                 DMA_HIFCR_CTCIF6)

/* ============== USART DMA Enable ============== */
#define USART_CR3_DMAT_Pos      7U
#define USART_CR3_DMAT          (1UL << USART_CR3_DMAT_Pos)   // DMA enable transmitter

/* ============== RCC DMA Clock Enable ============== */
#define RCC_AHB1ENR_DMA1EN_Pos  21U
#define RCC_AHB1ENR_DMA1EN      (1UL << RCC_AHB1ENR_DMA1EN_Pos)

#define RCC_AHB1ENR_DMA2EN_Pos  22U
#define RCC_AHB1ENR_DMA2EN      (1UL << RCC_AHB1ENR_DMA2EN_Pos)

#endif //STM32_PROJECT_DMA_REG_H
