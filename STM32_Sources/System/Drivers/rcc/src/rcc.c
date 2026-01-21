
#include "rcc.h"

/*========================== static function declarations*/


/*========================== static global variable*/

/*========================== function definitions*/

/*void vDoRCC_Init(RCC_t *RCC_reg) {
    RCC_reg->AHB1ENR = 0;
    //....
}*/

void vDo_AHB1ENR_EnableClockAccessToGPIO(gpio_port_t port) {

    if ((RCC->AHB1ENR & port) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIO_X_EN_Msk(port);
    }
}

void vDo_AHB1ENR_DisableClockAccessToGPIO(gpio_port_t port) {

    if ((RCC->AHB1ENR & port) == SET) {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIO_X_EN_Msk(port);
    }
}

void vDo_APB1ENR_EnableClockAccessToUSART(uint32 usart_select) {

    if ((RCC->APB1ENR & usart_select) != SET) {
        RCC->APB1ENR |= usart_select;
    }
}

void vDo_APB1ENR_DisableClockAccessToUSART(uint32 usart_select) {

    if ((RCC->APB1ENR & usart_select) == SET) {
        RCC->APB1ENR &= ~usart_select;
    }
}

void vDo_APB1ENR_EnableClockAccessToDMA(uint32 DMA_select) {

    if ((RCC->AHB1ENR & DMA_select) != SET) {
        RCC->AHB1ENR |= DMA_select;
    }
}

void vDo_APB1ENR_DisableClockAccessToDMA(uint32 DMA_select) {

    if ((RCC->AHB1ENR & DMA_select) == SET) {
        RCC->AHB1ENR &= ~DMA_select;
    }
}

void vDo_APB2ENR_DisableClockAccessToSYSCFG(uint32 enClockSYScfg) {

    if ((RCC->APB2ENR & enClockSYScfg) == SET) {
        RCC->APB2ENR &= ~enClockSYScfg;
    }
}

void vDo_APB2ENR_EnableClockAccessToSYSCFG(uint32 enClockSYScfg) {
    RCC->APB2ENR |= enClockSYScfg;
}
