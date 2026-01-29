#include "rcc.h"
#include "spi.h"

/*========================== static function declarations*/


/*========================== static global variable*/

/*========================== function definitions*/
void vDO_SpiEnable() {
    SPI1->CR1 &= ~SPI_CR1_SPEn;
    SPI1->CR1 |= SPI_CR1_SPEn;
}
void vDO_SpiDisable() {
    while(SPI1->SR & (1 << 7));  // Wait BSY=0
    SPI1->CR1 &= ~SPI_CR1_SPEn;
}
void vDo_Spi1Config() {

    vDoSetGPIOAltFunc(GPIO_PORT_A,(PIN_5|PIN_6|PIN_7),AF_5,AF_LOW);
    vDo_APB2ENR_EnableClockAccessToSPI1(RCC_APB2ENR_SPI_1_EN_Msk);
    SPI1->CR1 |= (
        SPI_CR1_MSTR(1) | SPI_CR1_CPOL(1) | SPI_CR1_CPHA(1) |
        SPI_CR1_BR(2) | SPI_CR1_LSBFIRST(1) | SPI_CR1_SSM(0) |
        SPI_CR1_SSI(0) | SPI_CR1_RXONLY(0) | SPI_CR1_DFF(0) | SPI_CR1_BIDIMODE(0));

    vDO_SpiEnable();
}

uint8 vDo_SpiTransferByte(SPI_t *SPIx, uint8 tx_data) {
    while(!(SPIx->SR & (1 << 1)));
    SPIx->DR = tx_data;
    while(!(SPIx->SR & (1 << 0)));
    return SPIx->DR;
}

void vDo_Spi1Receive(uint8 *data) {
    while (!(SPI1->SR & (1<<0)));
        *data = SPI1->DR;
}


