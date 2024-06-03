

#include "STM32F446RE_Base.h"

/*AHB1ENR register*/
#define RCC_AHB1ENR_GPIO_X_EN_Msk(RCC_AHB1ENR_GPIO_X_Pos)                (0x1UL << RCC_AHB1ENR_GPIO_X_Pos)
#define RCC_AHB1ENR_CRC_EN_Msk(RCC_AHB1ENR_CRC_Pos)                      (0x1UL << RCC_AHB1ENR_CRC_Pos)
#define RCC_AHB1ENR_BKPSRAM_EN_Msk(RCC_AHB1ENR_BKPSRAM_Pos)              (0x1UL << RCC_AHB1ENR_BKPSRAM_Pos)
#define RCC_AHB1ENR_DMA1_EN_Msk(RCC_AHB1ENR_DMA1_Pos)                    (0x1UL << RCC_AHB1ENR_DMA1_Pos)
#define RCC_AHB1ENR_DMA2_EN_Msk(RCC_AHB1ENR_DMA2_Pos)                    (0x1UL << RCC_AHB1ENR_DMA2_Pos)
#define RCC_AHB1ENR_OTGHS_EN_Msk(RCC_AHB1ENR_OTGHS_Pos)                  (0x1UL << RCC_AHB1ENR_OTGHS_Pos)
#define RCC_AHB1ENR_OTGHSULPI_EN_Msk(RCC_AHB1ENR_OTGHSULPI_Pos)          (0x1UL << RCC_AHB1ENR_OTGHSULPI_Pos)

/*AHB2ENR register*/
#define RCC_AHB2ENR_DCMI_EN_Msk(RCC_AHB2ENR_DCMI_Pos)                    (0x1UL << RCC_AHB2ENR_DCMI_Pos)
#define RCC_AHB2ENR_OTGFSE_EN_Msk(RCC_AHB2ENR_OTGFSE_Pos)                (0x1UL << RCC_AHB2ENR_OTGFSE_Pos)

/*AHB3ENR register*/
/**
* RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
 *
 * Address offset: 0x38
 * Reset value: 0x0000 0000
 * Access: no wait state, word, half-word and byte access.
 *
 * Bit definition:
* +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
* | 31   | 30   | 29   | 28   | 27   | 26   | 25   | 24   | 23   | 22   | 21   | 20   | 19   | 18   | 17   | 16   |
* | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  |
* +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
* +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
* | 15   | 14   | 13   | 12   | 11   | 10   | 9    | 8    | 7    | 6    | 5    | 4    | 3    | 2      | 1     | 0    |
* | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | Res  | QSPIEN | FMCEN |
* |      |      |      |      |      |      |      |      |      |      |      |      |      |   rw   |  rw   |
* +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
*/
#define RCC_AHB3ENR_FMC_EN_Msk(RCC_AHB3ENR_FMC_Pos)                      (0x1UL << RCC_AHB3ENR_FMC_Pos)
#define RCC_AHB3ENR_QSPI_EN_Msk(RCC_AHB3ENR_QSPI_Pos)                    (0x1UL << RCC_AHB3ENR_QSPI_Pos)


/*APB1ENR register*/
/**
 * Address offset: 0x40
 *  Reset value: 0x0000 0000
 * Access: no wait state, word, half-word and byte access

 * RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 *
 * Bit definition:
 * +------+------+------+------+------+------+------+-------------+------+-------+-------+--------+--------+--------+--------+------+------+
 * | 31   | 30   | 29   | 28   | 27   | 26    | 25    | 24        | 23   | 22    | 21    | 20     | 19     | 18     | 17     | 16    |
 * | Res  | Res  | DACEN| PWREN| CECEN| CAN2EN| CAN1EN| FMPI2C1EN| I2C3EN| I2C2EN| I2C1EN| UART5EN| UART4EN| UART3EN| UART2EN| SPIFRXEN |
 * |      |      |  rw  |  rw  |  rw  |  rw   |  rw   |  rw      |  rw   |  rw   |  rw   |   rw   |  rw    |  rw    |  rw    |  rw  |
 * +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
 * | 15    | 14    | 13   | 12   | 11    | 10     | 9      | 8     | 7     | 6     | 5    | 4     | 3     | 2     | 1    | 0    |
 * | SPI3EN| SPI2EN| Res  | Res  | WWDGEN| Res    |Res     |TIM14EN|TIM13EN|TIM12EN|TIM7EN| TIM6EN| TIM5EN| TIM4EN|TIM3EN|TIM2EN|
 * |  rw   |  rw   |      |      |  rw   |  rw    |   rw   |  rw   |  rw   |  rw   |  rw  |  rw   |  rw   |  rw   |      |      |
 * +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
 */


#define RCC_APB1ENR_TIM_X_EN_Msk(RCC_APB1ENR_TIM_X_EN_Pos)               (0x1UL << RCC_APB1ENR_TIM_X_EN_Pos)
#define RCC_APB1ENR_WWDG_EN_Msk(RCC_APB1ENR_WWDG_EN_Pos)                 (0x1UL << RCC_APB1ENR_WWDG_EN_Pos)
#define RCC_APB1ENR_SPI_X_EN_Msk(RCC_APB1ENR_SPI_X_EN_Pos)                 (0x1UL << RCC_APB1ENR_SPI_X_EN_Pos)
//#define RCC_APB1ENR_SPI3_EN_Msk(RCC_APB1ENR_SPI3_EN_Pos)                 (0x1UL << RCC_APB1ENR_SPI3_EN_Pos)
#define RCC_APB1ENR_SPDIFRX_EN_Msk(RCC_APB1ENR_SPDIFRX_EN_Pos)           (0x1UL << RCC_APB1ENR_SPDIFRX_EN_Pos)
#define RCC_APB1ENR_USART_X_EN_Msk(RCC_APB1ENR_USART_X_EN_Pos)             (0x1UL << RCC_APB1ENR_USART_X_EN_Pos)
//#define RCC_APB1ENR_USART3_EN_Msk(RCC_APB1ENR_USART3_EN_Pos)             (0x1UL << RCC_APB1ENR_USART3_EN_Pos)
#define RCC_APB1ENR_UART_X_EN_Msk(RCC_APB1ENR_UART_X_EN_Pos)               (0x1UL << RCC_APB1ENR_UART_X_EN_Pos)
//#define RCC_APB1ENR_UART4_EN_Msk(RCC_APB1ENR_UART4_EN_Pos)               (0x1UL << RCC_APB1ENR_UART4_EN_Pos)
//#define RCC_APB1ENR_UART5_EN_Msk(RCC_APB1ENR_UART5_EN_Pos)               (0x1UL << RCC_APB1ENR_UART5_EN_Pos)
#define RCC_APB1ENR_I2C_X_EN_Msk(RCC_APB1ENR_I2C_X_EN_Pos)                 (0x1UL << RCC_APB1ENR_I2C_X_EN_Pos)
//#define RCC_APB1ENR_I2C2_EN_Msk(RCC_APB1ENR_I2C2_EN_Pos)                 (0x1UL << RCC_APB1ENR_I2C2_EN_Pos)
//#define RCC_APB1ENR_I2C3_EN_Msk(RCC_APB1ENR_I2C3_EN_Pos)                 (0x1UL << RCC_APB1ENR_I2C3_EN_Pos)
#define RCC_APB1ENR_FMPI2C1_EN_Msk(RCC_APB1ENR_FMPI2C1_EN_Pos)           (0x1UL << RCC_APB1ENR_FMPI2C1_EN_Pos)
#define RCC_APB1ENR_CAN_X_EN_Msk(RCC_APB1ENR_CAN_X_EN_Pos)                 (0x1UL << RCC_APB1ENR_CAN_X_EN_Pos)
//#define RCC_APB1ENR_CAN2_EN_Msk(RCC_APB1ENR_CAN2_EN_Pos)                 (0x1UL << RCC_APB1ENR_CAN2_EN_Pos)
#define RCC_APB1ENR_CEC_EN_Msk(RCC_APB1ENR_CEC_EN_Pos)                   (0x1UL << RCC_APB1ENR_CEC_EN_Pos)
#define RCC_APB1ENR_PWR_EN_Msk(RCC_APB1ENR_PWR_EN_Pos)                   (0x1UL << RCC_APB1ENR_PWR_EN_Pos)
#define RCC_APB1ENR_DAC_EN_Msk(RCC_APB1ENR_DAC_EN_Pos)                   (0x1UL << RCC_APB1ENR_DAC_EN_Pos)

/*APB2ENR register*/
#define RCC_APB2ENR_TIM_X_EN_Msk(RCC_APB2ENR_TIM_X_EN_Pos)               (0x1UL << RCC_APB2ENR_TIM_X_EN_Pos)
#define RCC_APB2ENR_USART_X_EN_Msk(RCC_APB2ENR_USART_X_EN_Pos)           (0x1UL << RCC_APB2ENR_USART_X_EN_Pos)
#define RCC_APB2ENR_ADC_X_EN_Msk(RCC_APB2ENR_ADC_X_EN_Pos)               (0x1UL << RCC_APB2ENR_ADC_X_EN_Pos)
#define RCC_APB2ENR_SDIO_EN_Msk(RCC_APB2ENR_SDIO_EN_Pos)                 (0x1UL << RCC_APB2ENR_SDIO_EN_Pos)
#define RCC_APB2ENR_SPI_X_EN_Msk(RCC_APB2ENR_SPI_X_EN_Pos)               (0x1UL << RCC_APB2ENR_SPI_X_EN_Pos)
#define RCC_APB2ENR_SYSCFG_EN_Msk(RCC_APB2ENR_SYSCFG_EN_Pos)             (0x1UL << RCC_APB2ENR_SYSCFG_EN_Pos)
#define RCC_APB2ENR_SAI_X_EN_Msk(RCC_APB2ENR_SAI_X_EN_Pos)               (0x1UL << RCC_APB2ENR_SAI_X_EN_Pos)

/*RCC_AHB1LPENR registers*/




typedef enum {
    AHB_1_PERIPH = 1,
    AHB_2_PERIPH = 2,
    AHB_3_PERIPH = 3
} rcc_enable_periph_AHB_clock_t;

typedef enum {
    APB_1_PERIPH = 1,
    APB_2_PERIPH = 2
} rcc_enable_periph_APB_clock_t;

typedef struct {
    rcc_enable_periph_AHB_clock_t rcc_AHB_clock_EN_r;
    rcc_enable_periph_APB_clock_t rcc_APB_clock_EN_r;
} rcc_config;


void vDoEnablePeriph_Clock_AHB(rcc_config periph_clock, uint8 position);
void vDoDisablePeriph_Clock_AHB(rcc_config periph_clock, uint8 position);
void vDoEnablePeriphClock_APB(rcc_config periph_clock, uint8 position);
void vDoEnablePeriphClock_APB(rcc_config periph_clock, uint8 position);
