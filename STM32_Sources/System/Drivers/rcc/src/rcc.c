
#include "rcc.h"

/*========================== static function declarations*/


/*========================== static global variable*/

/*========================== function definitions*/

/*void vDoRCC_Init(RCC_t *RCC_reg) {
    RCC_reg->AHB1ENR = 0;
    //....
}*/

void vDo_AHB1ENR_EnableClockAccessToPort(gpio_port_t port) {

    if ((RCC->AHB1ENR & port) != SET) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIO_X_EN_Msk(port);
    }
}

void vDo_AHB1ENR_DisableClockAccessToPort(gpio_port_t port) {

    if ((RCC->AHB1ENR & port) == SET) {
        RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIO_X_EN_Msk(port);
    }
}

//RCC_t u32GetRCC_AHB1ENR_Status(RCC_t *RCC_reg) {
 //   return RCC_reg->AHB1ENR;
//}

