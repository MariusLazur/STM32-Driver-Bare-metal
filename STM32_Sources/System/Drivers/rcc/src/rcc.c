
#include "rcc.h"

/*========================== static function declarations*/

static void vDoEnable_RCC_AHB1ENR(uint8 position);

static void vDoEnable_RCC_AHB2ENR(uint8 position);

static void vDoEnable_RCC_AHB3ENR(uint8 position);

static void vDoDisable_RCC_AHB1ENR(uint8 position);

static void vDoDisable_RCC_AHB2ENR(uint8 position);

static void vDoDisable_RCC_AHB3ENR(uint8 position);

static void vDoEnable_RCC_APB1ENR(uint8 position);

static void vDoEnable_RCC_APB2ENR(uint8 position);

static void vDoDisable_RCC_APB1ENR(uint8 position);

static void vDoDisable_RCC_APB2ENR(uint8 position);

/*========================== static global variable*/

/*========================== function definitions*/

static void vDoEnable_RCC_AHB1ENR(uint8 position) {

    if ((position <= 7) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIO_X_EN_Msk(position);
    } else if ((position == 12) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_CRC_EN_Msk(position);
    } else if ((position == 18) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAM_EN_Msk(position);
    } else if ((position == 21) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_DMA1_EN_Msk(position);
    } else if ((position == 22) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_DMA2_EN_Msk(position);
    } else if ((position == 29) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_OTGHS_EN_Msk(position);
    } else if ((position == 30) && (RCC->AHB1ENR & position) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPI_EN_Msk(position);
    } else {/*do nothing*/}
}

static void vDoEnable_RCC_AHB2ENR(uint8 position) {

    if ((position == 0) && (RCC->AHB2ENR & position) != SET) {
        RCC->AHB2ENR |= RCC_AHB3ENR_FMC_EN_Msk(position);
    } else if ((position == 7) && (RCC->AHB2ENR & position) != SET) {
        RCC->AHB2ENR |= RCC_AHB3ENR_QSPI_EN_Msk(position);
    } else {/*do nothing*/}
}

static void vDoEnable_RCC_AHB3ENR(uint8 position) {

    if ((position == 0) && (RCC->AHB3ENR & position) != SET) {
        RCC->AHB3ENR |= RCC_AHB2ENR_OTGFSE_EN_Msk(position);
    } else if ((position == 1) && (RCC->AHB3ENR & position) != SET) {
        RCC->AHB3ENR |= RCC_AHB2ENR_OTGFSE_EN_Msk(position);
    } else {/*do nothing*/}
}

void vDoEnablePeriph_Clock_AHB(rcc_config periph_clock, uint8 position) {

    switch (periph_clock.rcc_AHB_clock_EN_r) {
        case (AHB_1_PERIPH):
            vDoEnable_RCC_AHB1ENR(position);
            break;
        case (AHB_2_PERIPH):
            vDoEnable_RCC_AHB2ENR(position);
            break;
        case (AHB_3_PERIPH):
            vDoEnable_RCC_AHB3ENR(position);
            break;
        default:
            break;
    }
}

static void vDoDisable_RCC_AHB1ENR(uint8 position) {
    if ((position <= 7) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIO_X_EN_Msk(position));
    } else if ((position == 12) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_CRC_EN_Msk(position));
    } else if ((position == 18) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_BKPSRAM_EN_Msk(position));
    } else if ((position == 21) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA1_EN_Msk(position));
    } else if ((position == 22) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2_EN_Msk(position));
    } else if ((position == 29) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_OTGHS_EN_Msk(position));
    } else if ((position == 30) && (RCC->AHB1ENR & position) == SET) {
        RCC->AHB1ENR &= ~(RCC_AHB1ENR_OTGHSULPI_EN_Msk(position));
    } else {/*do nothing*/}
}

static void vDoDisable_RCC_AHB2ENR(uint8 position) {
    if ((position == 0) && (RCC->AHB2ENR & position) == SET) {
        RCC->AHB2ENR &= ~(RCC_AHB3ENR_FMC_EN_Msk(position));
    } else if ((position == 7) && (RCC->AHB2ENR & position) == SET) {
        RCC->AHB2ENR &= ~(RCC_AHB3ENR_QSPI_EN_Msk(position));
    } else {/*do nothing*/}
}

static void vDoDisable_RCC_AHB3ENR(uint8 position) {
    if ((position == 0) && (RCC->AHB3ENR & position) == SET) {
        RCC->AHB3ENR &= ~(RCC_AHB2ENR_OTGFSE_EN_Msk(position));
    } else if ((position == 1) && (RCC->AHB3ENR & position) == SET) {
        RCC->AHB3ENR &= ~(RCC_AHB2ENR_OTGFSE_EN_Msk(position));
    } else {/*do nothing*/}
}

void vDoDisablePeriph_Clock_AHB(rcc_config periph_clock, uint8 position) {

    switch (periph_clock.rcc_AHB_clock_EN_r) {
        case (AHB_1_PERIPH):
            vDoDisable_RCC_AHB1ENR(position);
            break;
        case (AHB_2_PERIPH):
            vDoDisable_RCC_AHB2ENR(position);
            break;
        case (AHB_3_PERIPH):
            vDoDisable_RCC_AHB3ENR(position);
            break;
        default:
            break;
    }
}

static void vDoEnable_RCC_APB1ENR(uint8 position) {
    if ((position <= 8) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM_X_EN_Msk(position);
    } else if ((position == 11) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_WWDG_EN_Msk(position);
    } else if (((position == 14) || (position == 15)) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB1ENR_SPI_X_EN_Msk(position);
    } else if ((position == 16) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_SPDIFRX_EN_Msk(position);
    } else if (((position == 17) || (position == 18)) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_USART_X_EN_Msk(position);
    } else if (((position == 19) || (position == 20)) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_UART_X_EN_Msk(position);
    } else if (((position >= 21) && (position <= 23)) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_I2C_X_EN_Msk(position);
    } else if ((position == 24) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_FMPI2C1_EN_Msk(position);
    } else if (((position == 25) || (position == 26)) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_CAN_X_EN_Msk(position);
    } else if ((position == 27) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_CEC_EN_Msk(position);
    } else if ((position == 28) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_PWR_EN_Msk(position);
    } else if ((position == 29) && (RCC->APB1ENR & position) != SET) {
        RCC->APB1ENR |= RCC_APB1ENR_DAC_EN_Msk(position);
    } else {
    }
}

static void vDoEnable_RCC_APB2ENR(uint8 position) {
    if (((position <= 1) || ((position >= 16) && (position <= 18))) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_TIM_X_EN_Msk(position);
    } else if (((position == 4) || (position == 5)) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_USART_X_EN_Msk(position);
    } else if (((position >= 8) && (position <= 10)) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_ADC_X_EN_Msk(position);
    } else if ((position == 11) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_SDIO_EN_Msk(position);
    } else if (((position == 12) || (position == 13)) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_SPI_X_EN_Msk(position);
    } else if ((position == 14) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_SYSCFG_EN_Msk(position);
    } else if (((position == 22) || (position == 23)) && ((RCC->APB1ENR & position) != SET)) {
        RCC->APB1ENR |= RCC_APB2ENR_SAI_X_EN_Msk(position);
    }
}

void vDoEnablePeriphClock_APB(rcc_config periph_clock, uint8 position) {

    switch (periph_clock.rcc_APB_clock_EN_r) {
        case (APB_1_PERIPH):
            vDoEnable_RCC_APB1ENR(position);
            break;
        case (APB_2_PERIPH):
            vDoEnable_RCC_APB2ENR(position);
            break;
        default:
            break;
    }
}

static void vDoDisable_RCC_APB1ENR(uint8 position) {
    if ((position <= 8) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_TIM_X_EN_Msk(position));
    } else if ((position == 11) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_WWDG_EN_Msk(position));
    } else if ((position == 14) || (position == 15) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_SPI_X_EN_Msk(position));
    } else if ((position == 16) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_SPDIFRX_EN_Msk(position));
    } else if (((position == 17) || (position == 18)) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_USART_X_EN_Msk(position));
    } else if (((position == 19) || (position == 20)) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_UART_X_EN_Msk(position));
    } else if (((position >= 21) && (position <= 23)) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_I2C_X_EN_Msk(position));
    } else if ((position == 24) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_FMPI2C1_EN_Msk(position));
    } else if (((position == 25) || (position == 26)) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_CAN_X_EN_Msk(position));
    } else if ((position == 27) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_CEC_EN_Msk(position));
    } else if ((position == 28) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_PWR_EN_Msk(position));
    } else if ((position == 29) && (RCC->APB1ENR & position) == SET) {
        RCC->APB1ENR &= ~(RCC_APB1ENR_DAC_EN_Msk(position));
    } else {/*do nothing*/}
}

static void vDoDisable_RCC_APB2ENR(uint8 position) {
    if (((position <= 1) || ((position >= 16) && (position <= 18))) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_TIM_X_EN_Msk(position));
    } else if (((position == 4) || (position == 5)) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_USART_X_EN_Msk(position));
    } else if (((position >= 8) && (position <= 10)) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_ADC_X_EN_Msk(position));
    } else if ((position == 11) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_SDIO_EN_Msk(position));
    } else if (((position == 12) || (position == 13)) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_SPI_X_EN_Msk(position));
    } else if ((position == 14) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_SYSCFG_EN_Msk(position));
    } else if (((position == 22) || (position == 23)) && ((RCC->APB1ENR & position) == SET)) {
        RCC->APB1ENR &= ~(RCC_APB2ENR_SAI_X_EN_Msk(position));
    } else {/*do nothing*/}
}

void vDoDisablePeriphClock_APB(rcc_config periph_clock, uint8 position) {

    switch (periph_clock.rcc_APB_clock_EN_r) {
        case (APB_1_PERIPH):
            vDoDisable_RCC_APB1ENR(position);
            break;
        case (APB_2_PERIPH):
            vDoDisable_RCC_APB2ENR(position);
            break;
        default:
            break;
    }
}
