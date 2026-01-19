#include "STM32F446RE_Base.h"
#include "gpio.h"
/*RCC_CR*/
#define RCC_CtrlReg_HSI_ON_Pos                          0UL
#define RCC_CtrlReg_HSI_ON_Msk(VALUE)                (VALUE << RCC_CtrlReg_HSI_ON_Pos)

#define RCC_CtrlReg_HSI_RDY_Pos                         1UL
#define RCC_CtrlReg_HSI_RDY_Msk(VALUE)               (VALUE << RCC_CtrlReg_HSI_RDY_Pos)

#define RCC_CtrlReg_HSITRIM_Pos                         3UL
#define RCC_CtrlReg_HSITRIM_Msk(VALUE)               (VALUE << RCC_CtrlReg_HSITRIM_Pos)

#define RCC_CtrlReg_HSICAL_Pos                          8UL
#define RCC_CtrlReg_HSICAL_Msk(VALUE)                (VALUE << RCC_CtrlReg_HSICAL_Pos)

#define RCC_CtrlReg_HSE_ON_Pos                          16UL
#define RCC_CtrlReg_HSE_ON_Msk(VALUE)                (VALUE << RCC_CtrlReg_HSE_ON_Pos)

#define RCC_CtrlReg_HSE_RDY_Pos                         17UL
#define RCC_CtrlReg_HSE_RDY_Msk(VALUE)               (VALUE << RCC_CtrlReg_HSE_RDY_Pos)

#define RCC_CtrlReg_HSE_BYP_Pos                         18UL
#define RCC_CtrlReg_HSE_BYP_Msk(VALUE)               (VALUE << RCC_CtrlReg_HSE_BYP_Pos)

#define RCC_CtrlReg_CSS_ON_Pos                          19UL
#define RCC_CtrlReg_CSS_ON_Msk(VALUE)                (VALUE << RCC_CtrlReg_CSS_ON_Pos)

#define RCC_CtrlReg_PLL_ON_Pos                          24UL
#define RCC_CtrlReg_PLL_ON_Msk(VALUE)                (VALUE << RCC_CtrlReg_PLL_ON_Pos)

#define RCC_CtrlReg_PLL_RDY_Pos                         25UL
#define RCC_CtrlReg_PLL_RDY_Msk(VALUE)               (VALUE << RCC_CtrlReg_PLL_RDY_Pos)

#define RCC_CtrlReg_PLLI2S_ON_Pos                       26UL
#define RCC_CtrlReg_PLLI2S_ON_Msk(VALUE)             (VALUE << RCC_CtrlReg_PLLI2S_ON_Pos)

#define RCC_CtrlReg_PLLI2S_RDY_Pos                      27UL
#define RCC_CtrlReg_PLLI2S_RDY_Msk(VALUE)            (VALUE << RCC_CtrlReg_PLLI2S_RDY_Pos)

#define RCC_CtrlReg_PLLSAI_ON_Pos                       28UL
#define RCC_CtrlReg_PLLSAI_ON_Msk(VALUE)             (VALUE << RCC_CtrlReg_PLLSAI_ON_Pos)

#define RCC_CtrlReg_PLLSAI_RDY_Pos                      29UL
#define RCC_CtrlReg_PLLSAI_RDY_Msk(VALUE)            (VALUE << RCC_CtrlReg_PLLSAI_RDY_Pos)


/*RCC PLL configuration register (RCC_PLLCFGR)*/
#define RCC_PLLCFG_reg_PLLM_Pos                         0UL
#define RCC_PLLCFG_reg_PLLM_Msk(VALUE)                (VALUE << RCC_PLLCFG_reg_PLLM_Pos)

#define RCC_PLLCFG_reg_PLLN_Pos                         6UL
#define RCC_PLLCFG_reg_PLLN_Msk(VALUE)                (VALUE << RCC_PLLCFG_reg_PLLN_Pos)

#define RCC_PLLCFG_reg_PLLP_Pos                         16UL
#define RCC_PLLCFG_reg_PLLP_Msk(VALUE)                (VALUE << RCC_PLLCFG_reg_PLLP_Pos)

#define RCC_PLLCFG_reg_PLLSRC_Pos                       22UL
#define RCC_PLLCFG_reg_PLLSRC_Msk(VALUE)              (VALUE << RCC_PLLCFG_reg_PLLSRC_Pos)

#define RCC_PLLCFG_reg_PLLQ_Pos                         24UL
#define RCC_PLLCFG_reg_PLLQ_Msk(VALUE)                (VALUE << RCC_PLLCFG_reg_PLLQ_Pos)

#define RCC_PLLCFG_reg_PLLR_Pos                         28UL
#define RCC_PLLCFG_reg_PLLR_Msk(VALUE)                (VALUE << RCC_PLLCFG_reg_PLLR_Pos)

/*RCC clock configuration register (RCC_CFGR)*/
#define RCC_CFGR_reg_SW_Pos                                 0UL
#define RCC_CFGR_reg_SW_Msk(VALUE)                        (VALUE << RCC_CFGR_reg_SW_Pos)

#define RCC_CFGR_reg_SWS_Pos                                2UL
#define RCC_CFGR_reg_SWS_Msk(VALUE)                       (VALUE << RCC_CFGR_reg_SWS_Pos)

#define RCC_CFGR_reg_HPRE_Pos                               4UL
#define RCC_CFGR_reg_HPRE_Msk(VALUE)                      (VALUE << RCC_CFGR_reg_HPRE_Pos)

#define RCC_CFGR_reg_PPRE1_Pos                                           10UL
#define RCC_CFGR_reg_PPRE1_Msk(VALUE)                                    (VALUE << RCC_CFGR_reg_PPRE1_Pos)
#define RCC_CFGR_reg_PPRE2_Pos                                           13UL
#define RCC_CFGR_reg_PPRE2_Msk(VALUE)                                    (VALUE << RCC_CFGR_reg_PPRE2_Pos)
#define RCC_CFGR_reg_RTCPRE_Pos                                          16UL
#define RCC_CFGR_reg_RTCPRE_Msk(VALUE)                                   (VALUE << RCC_CFGR_reg_RTCPRE_Pos)
#define RCC_CFGR_reg_MCO1_Pos                                            21UL
#define RCC_CFGR_reg_MCO1_Msk(VALUE)                                     (VALUE << RCC_CFGR_reg_MCO1_Pos)
#define RCC_CFGR_reg_MCO1_PRE_Pos                                        24UL
#define RCC_CFGR_reg_MCO1_PRE_Msk(VALUE)                                 (VALUE << RCC_CFGR_reg_MCO1_PRE_Pos)
#define RCC_CFGR_reg_MCO2_PRE_Pos                                        27UL
#define RCC_CFGR_reg_MCO2_PRE_Msk(VALUE)                                 (VALUE << RCC_CFGR_reg_MCO2_PRE_Pos)
#define RCC_CFGR_reg_MCO2_Pos                                            30UL
#define RCC_CFGR_reg_MCO2_Msk(VALUE)                                     (VALUE << RCC_CFGR_reg_MCO2_Pos)




/*RCC clock interrupt register (RCC_CIR)*/
#define RCC_CIR_reg_LSI_RDYF_Pos                        0UL
#define RCC_CIR_reg_LSI_RDYF_Msk(VALUE)               (VALUE << RCC_CIR_reg_LSI_RDYF_Pos)
#define RCC_CIR_reg_LSE_RDYF_Pos                        1UL
#define RCC_CIR_reg_LSE_RDYF_Msk(VALUE)               (VALUE << RCC_CIR_reg_LSE_RDYF_Pos)
#define RCC_CIR_reg_HSI_RDYF_Pos                        2UL
#define RCC_CIR_reg_HSI_RDYF_Msk(VALUE)               (VALUE << RCC_CIR_reg_HSI_RDYF_Pos)
#define RCC_CIR_reg_HSE_RDYF_Pos                        3UL
#define RCC_CIR_reg_HSE_RDYF_Msk(VALUE)               (VALUE << RCC_CIR_reg_HSE_RDYF_Pos)
#define RCC_CIR_reg_PLL_RDYF_Pos                        4UL
#define RCC_CIR_reg_PLL_RDYF_Msk(VALUE)               (VALUE << RCC_CIR_reg_PLL_RDYF_Pos)
#define RCC_CIR_reg_PLLI2S_RDYF_Pos                     5UL
#define RCC_CIR_reg_PLLI2S_RDYF_Msk(VALUE)            (VALUE << RCC_CIR_reg_PLLI2S_RDYF_Pos)
#define RCC_CIR_reg_PLLSAI_RDYF_Pos                     6UL
#define RCC_CIR_reg_PLLSAI_RDYF_Msk(VALUE)            (VALUE << RCC_CIR_reg_PLLSAI_RDYF_Pos)
#define RCC_CIR_reg_CSSF_Pos                            7UL
#define RCC_CIR_reg_CSSF_Msk(VALUE)                   (VALUE << RCC_CIR_reg_CSSF_Pos)
#define RCC_CIR_reg_LSI_RDYIE_Pos                       8UL
#define RCC_CIR_reg_LSI_RDYIE_Msk(VALUE)              (VALUE << RCC_CIR_reg_LSI_RDYIE_Pos)
#define RCC_CIR_reg_LSE_RDYIE_Pos                       9UL
#define RCC_CIR_reg_LSE_RDYIE_Msk(VALUE)              (VALUE << RCC_CIR_reg_LSE_RDYIE_Pos)
#define RCC_CIR_reg_HSI_RDYIE_Pos                       10UL
#define RCC_CIR_reg_HSI_RDYIE_Msk(VALUE)              (VALUE << RCC_CIR_reg_HSI_RDYIE_Pos)
#define RCC_CIR_reg_HSE_RDYIE_Pos                       11UL
#define RCC_CIR_reg_HSE_RDYIE_Msk(VALUE)              (VALUE << RCC_CIR_reg_HSE_RDYIE_Pos)
#define RCC_CIR_reg_PLL_RDYIE_Pos                       12UL
#define RCC_CIR_reg_PLL_RDYIE_Msk(VALUE)              (VALUE << RCC_CIR_reg_PLL_RDYIE_Pos)
#define RCC_CIR_reg_PLLI2S_RDYIE_Pos                    13UL
#define RCC_CIR_reg_PLLI2S_RDYIE_Msk(VALUE)           (VALUE << RCC_CIR_reg_PLLI2S_RDYIE_Pos)
#define RCC_CIR_reg_PLLSAI_RDYIE_Pos                    14UL
#define RCC_CIR_reg_PLLSAI_RDYIE_Msk(VALUE)           (VALUE << RCC_CIR_reg_PLLSAI_RDYIE_Pos)
#define RCC_CIR_reg_LSI_RDYC_Pos                        16UL
#define RCC_CIR_reg_LSI_RDYC_Msk(VALUE)                (VALUE << RCC_CIR_reg_LSI_RDYC_Pos)
#define RCC_CIR_reg_LSE_RDYC_Pos                        17UL
#define RCC_CIR_reg_LSE_RDYC_Msk(VALUE)                (VALUE << RCC_CIR_reg_LSE_RDYC_Pos)
#define RCC_CIR_reg_HSI_RDYC_Pos                        18UL
#define RCC_CIR_reg_HSI_RDYC_Msk(VALUE)                (VALUE << RCC_CIR_reg_HSI_RDYC_Pos)
#define RCC_CIR_reg_HSE_RDYC_Pos                        19UL
#define RCC_CIR_reg_HSE_RDYC_Msk(VALUE)                (VALUE << RCC_CIR_reg_HSE_RDYC_Pos)
#define RCC_CIR_reg_PLL_RDYC_Pos                        20UL
#define RCC_CIR_reg_PLL_RDYC_Msk(VALUE)                (VALUE << RCC_CIR_reg_PLL_RDYC_Pos)
#define RCC_CIR_reg_PLLI2S_RDYC_Pos                     21UL
#define RCC_CIR_reg_PLLI2S_RDYC_Msk(VALUE)             (VALUE << RCC_CIR_reg_PLLI2S_RDYC_Pos)
#define RCC_CIR_reg_PLLSAI_RDYC_Pos                     22UL
#define RCC_CIR_reg_PLLSAI_RDYC_Msk(VALUE)             (VALUE << RCC_CIR_reg_PLLSAI_RDYC_Pos)
#define RCC_CIR_reg_CSSC_RDYC_Pos                       23UL
#define RCC_CIR_reg_CSSC_RDYC_Msk(VALUE)               (VALUE << RCC_CIR_reg_CSSC_RDYC_Pos)


/*AHB1ENR register*/
#define RCC_AHB1ENR_GPIO_X_EN_Msk(RCC_AHB1ENR_GPIO_X_Pos)        (1UL << RCC_AHB1ENR_GPIO_X_Pos)

#define RCC_AHB1ENR_CRC_Pos                                 12UL
#define RCC_AHB1ENR_CRC_EN_Msk                             (1UL << RCC_AHB1ENR_CRC_Pos)

#define RCC_AHB1ENR_BKPSRAM_Pos                             18UL
#define RCC_AHB1ENR_BKPSRAM_EN_Msk(VALUE)                  (VALUE << RCC_AHB1ENR_BKPSRAM_Pos)
#define RCC_AHB1ENR_DMA_X_Pos                               21UL
#define RCC_AHB1ENR_DMA_X_EN_Msk(VALUE)                    (VALUE << RCC_AHB1ENR_DMA_X_Pos)
//#define RCC_AHB1ENR_DMA2_EN_Msk(VALUE)                    (0x1UL << RCC_AHB1ENR_DMA2_Pos)
#define RCC_AHB1ENR_OTGHS_Pos                               29UL
#define RCC_AHB1ENR_OTGHS_EN_Msk(VALUE)                    (VALUE << RCC_AHB1ENR_OTGHS_Pos)
#define RCC_AHB1ENR_OTGHSULPI_Pos                           30UL
#define RCC_AHB1ENR_OTGHSULPI_EN_Msk(VALUE)                (VALUE << RCC_AHB1ENR_OTGHSULPI_Pos)

/*AHB2ENR register*/
#define RCC_AHB2ENR_DCMI_Pos                            0UL
#define RCC_AHB2ENR_DCMI_EN_Msk(VALUE)                  (VALUE << RCC_AHB2ENR_DCMI_Pos)

#define RCC_AHB2ENR_OTGFSE_Pos                          7UL
#define RCC_AHB2ENR_OTGFSE_EN_Msk(VALUE)                (VALUE << RCC_AHB2ENR_OTGFSE_Pos)

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
#define RCC_AHB3ENR_FMC_Pos                             0UL
#define RCC_AHB3ENR_FMC_EN_Msk                     (1UL << RCC_AHB3ENR_FMC_Pos)
#define RCC_AHB3ENR_QSPI_Pos                            1UL
#define RCC_AHB3ENR_QSPI_EN_Msk                    (1UL << RCC_AHB3ENR_QSPI_Pos)


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

#define RCC_APB1ENR_TIM_2_EN_Pos                  0UL
#define RCC_APB1ENR_TIM_2_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_2_EN_Pos)

#define RCC_APB1ENR_TIM_3_EN_Pos                  1UL
#define RCC_APB1ENR_TIM_3_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_3_EN_Pos)

#define RCC_APB1ENR_TIM_4_EN_Pos                  2UL
#define RCC_APB1ENR_TIM_4_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_4_EN_Pos)

#define RCC_APB1ENR_TIM_5_EN_Pos                  3UL
#define RCC_APB1ENR_TIM_5_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_5_EN_Pos)

#define RCC_APB1ENR_TIM_6_EN_Pos                  4UL
#define RCC_APB1ENR_TIM_6_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_6_EN_Pos)

#define RCC_APB1ENR_TIM_7_EN_Pos                  5UL
#define RCC_APB1ENR_TIM_7_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_7_EN_Pos)

#define RCC_APB1ENR_TIM_12_EN_Pos                  5UL
#define RCC_APB1ENR_TIM_12_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_12_EN_Pos)

#define RCC_APB1ENR_TIM_13_EN_Pos                  5UL
#define RCC_APB1ENR_TIM_13_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_13_EN_Pos)

#define RCC_APB1ENR_TIM_14_EN_Pos                  5UL
#define RCC_APB1ENR_TIM_14_EN_Msk               (0x1UL << RCC_APB1ENR_TIM_14_EN_Pos)


#define RCC_APB1ENR_WWDG_EN_Pos                 11UL
#define RCC_APB1ENR_WWDG_EN_Msk                (0x1UL << RCC_APB1ENR_WWDG_EN_Pos)

#define RCC_APB1ENR_SPI_2_EN_Pos                14UL
#define RCC_APB1ENR_SPI_2_EN_Msk               (0x1UL << RCC_APB1ENR_SPI_2_EN_Pos)

#define RCC_APB1ENR_SPI_3_EN_Pos                15UL
#define RCC_APB1ENR_SPI_3_EN_Msk               (0x1UL << RCC_APB1ENR_SPI_3_EN_Pos)

#define RCC_APB1ENR_SPDIFRX_EN_Pos              16UL
#define RCC_APB1ENR_SPDIFRX_EN_Msk             (0x1UL << RCC_APB1ENR_SPDIFRX_EN_Pos)

#define RCC_APB1ENR_USART_EN_Pos                17UL
#define RCC_APB1ENR_USART_2_EN_Msk             (uint32)(0x1UL << RCC_APB1ENR_USART_EN_Pos)
#define RCC_APB1ENR_USART_3_EN_Msk             (uint32)(0x2UL << RCC_APB1ENR_USART_EN_Pos)

#define RCC_APB1ENR_UART_EN_Pos                 18UL
#define RCC_APB1ENR_UART_3_EN_Msk              (0x1UL << RCC_APB1ENR_UART_EN_Pos)
#define RCC_APB1ENR_UART_4_EN_Msk              (0x2UL << RCC_APB1ENR_UART_EN_Pos)
#define RCC_APB1ENR_UART_5_EN_Pos               20UL
#define RCC_APB1ENR_UART_5_EN_Msk              (0x3UL << RCC_APB1ENR_UART_5_EN_Pos)

#define RCC_APB1ENR_I2C_EN_Pos                  21UL
#define RCC_APB1ENR_I2C_1_EN_Msk               (0x1UL << RCC_APB1ENR_I2C_EN_Pos)
#define RCC_APB1ENR_I2C_2_EN_Msk               (0x2UL << RCC_APB1ENR_I2C_EN_Pos)
#define RCC_APB1ENR_I2C_3_EN_Pos                23UL
#define RCC_APB1ENR_I2C_3_EN_Msk               (0x1UL << RCC_APB1ENR_I2C_3_EN_Pos)

#define RCC_APB1ENR_FMPI2C1_EN_Pos              24UL
#define RCC_APB1ENR_FMPI2C1_EN_Msk             (0x1UL << RCC_APB1ENR_FMPI2C1_EN_Pos)

#define RCC_APB1ENR_CAN_EN_Pos                  25UL
#define RCC_APB1ENR_CAN_1_EN_Msk               (0x1UL << RCC_APB1ENR_CAN_EN_Pos)
#define RCC_APB1ENR_CAN_2_EN_Msk               (0x2UL << RCC_APB1ENR_CAN_EN_Pos)

#define RCC_APB1ENR_CEC_EN_Pos                  27UL
#define RCC_APB1ENR_CEC_EN_Msk                 (0x1UL << RCC_APB1ENR_CEC_EN_Pos)

#define RCC_APB1ENR_PWR_EN_Pos                  28UL
#define RCC_APB1ENR_PWR_EN_Msk                 (0x1UL << RCC_APB1ENR_PWR_EN_Pos)

#define RCC_APB1ENR_DAC_EN_Pos                  29UL
#define RCC_APB1ENR_DAC_EN_Msk                 (0x1UL << RCC_APB1ENR_DAC_EN_Pos)

/*APB2ENR register*/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)
#define RCC_APB1ENR_TIM2EN_Msk             (0x1UL << RCC_APB1ENR_TIM2EN_Pos)    /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk

#define RCC_APB1ENR_TIM3EN_Pos             (1U)
#define RCC_APB1ENR_TIM3EN_Msk             (0x1UL << RCC_APB1ENR_TIM3EN_Pos)    /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk

#define RCC_APB1ENR_TIM4EN_Pos             (2U)
#define RCC_APB1ENR_TIM4EN_Msk             (0x1UL << RCC_APB1ENR_TIM4EN_Pos)    /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk

#define RCC_APB1ENR_TIM5EN_Pos             (3U)
#define RCC_APB1ENR_TIM5EN_Msk             (0x1UL << RCC_APB1ENR_TIM5EN_Pos)    /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk

#define RCC_APB1ENR_TIM6EN_Pos             (4U)
#define RCC_APB1ENR_TIM6EN_Msk             (0x1UL << RCC_APB1ENR_TIM6EN_Pos)    /*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN                 RCC_APB1ENR_TIM6EN_Msk
#define RCC_APB1ENR_TIM7EN_Pos             (5U)
#define RCC_APB1ENR_TIM7EN_Msk             (0x1UL << RCC_APB1ENR_TIM7EN_Pos)    /*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN                 RCC_APB1ENR_TIM7EN_Msk
#define RCC_APB1ENR_TIM12EN_Pos            (6U)
#define RCC_APB1ENR_TIM12EN_Msk            (0x1UL << RCC_APB1ENR_TIM12EN_Pos)   /*!< 0x00000040 */
#define RCC_APB1ENR_TIM12EN                RCC_APB1ENR_TIM12EN_Msk
#define RCC_APB1ENR_TIM13EN_Pos            (7U)
#define RCC_APB1ENR_TIM13EN_Msk            (0x1UL << RCC_APB1ENR_TIM13EN_Pos)   /*!< 0x00000080 */
#define RCC_APB1ENR_TIM13EN                RCC_APB1ENR_TIM13EN_Msk
#define RCC_APB1ENR_TIM14EN_Pos            (8U)
#define RCC_APB1ENR_TIM14EN_Msk            (0x1UL << RCC_APB1ENR_TIM14EN_Pos)   /*!< 0x00000100 */
#define RCC_APB1ENR_TIM14EN                RCC_APB1ENR_TIM14EN_Msk

#define RCC_APB2ENR_USART_1_EN_Pos 4UL
#define RCC_APB2ENR_USART_1_EN_Msk           (0x1UL << RCC_APB2ENR_USART_1_EN_Pos)
#define RCC_APB2ENR_USART_6_EN_Pos 5UL
#define RCC_APB2ENR_USART_6_EN_Msk           (0x1UL << RCC_APB2ENR_USART_6_EN_Pos)

#define RCC_APB2ENR_ADC_1_EN_Pos 8UL
#define RCC_APB2ENR_ADC_1_EN_Msk               (0x1UL << RCC_APB2ENR_ADC_1_EN_Pos)
#define RCC_APB2ENR_ADC_2_EN_Pos 9UL
#define RCC_APB2ENR_ADC_2_EN_Msk               (0x1UL << RCC_APB2ENR_ADC_2_EN_Pos)
#define RCC_APB2ENR_ADC_3_EN_Pos 10UL
#define RCC_APB2ENR_ADC_3_EN_Msk               (0x1UL << RCC_APB2ENR_ADC_3_EN_Pos)

#define RCC_APB2ENR_SDIO_EN_Pos 11UL
#define RCC_APB2ENR_SDIO_EN_Msk                 (0x1UL << RCC_APB2ENR_SDIO_EN_Pos)
#define RCC_APB2ENR_SPI_1_EN_Pos 12UL
#define RCC_APB2ENR_SPI_1_EN_Msk               (0x1UL << RCC_APB2ENR_SPI_1_EN_Pos)
#define RCC_APB2ENR_SPI_4_EN_Pos 13UL
#define RCC_APB2ENR_SPI_4_EN_Msk               (0x1UL << RCC_APB2ENR_SPI_4_EN_Pos)

#define RCC_APB2ENR_SYSCFG_EN_Pos 14UL
#define RCC_APB2ENR_SYSCFG_EN_Msk             (0x1UL << RCC_APB2ENR_SYSCFG_EN_Pos)

#define RCC_APB2ENR_SAI_1_EN_Pos 22UL
#define RCC_APB2ENR_SAI_1_EN_Msk               (0x1UL << RCC_APB2ENR_SAI_1_EN_Pos)
#define RCC_APB2ENR_SAI_2_EN_Pos 23UL
#define RCC_APB2ENR_SAI_2_EN_Msk               (0x1UL << RCC_APB2ENR_SAI_2_EN_Pos)

/*RCC_AHB1LPENR registers*/


typedef enum{
    HSI_OSCI = 0,
    HSE_OSCI,
    PLL_P,
    PLL_R
}eSysClk_Source_t;

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


void vDo_AHB1ENR_EnableClockAccessToGPIO(gpio_port_t port);
void vDo_AHB1ENR_DisableClockAccessToGPIO(gpio_port_t port);

void vDo_APB1ENR_EnableClockAccessToUSART(uint32 usart_select);
void vDo_APB1ENR_DisableClockAccessToUSART(uint32 usart_select);

void vDo_APB2ENR_DisableClockAccessToSYSCFG(uint32 enClockSYScfg);

void vDo_APB1ENR_EnableClockAccessToDMA(uint32 DMA_select);
void vDo_APB1ENR_DisableClockAccessToDMA(uint32 DMA_select);