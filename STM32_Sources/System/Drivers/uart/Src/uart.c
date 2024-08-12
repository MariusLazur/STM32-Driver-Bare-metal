
#include "uart.h"


//init usart
void vDoUSARTx_cfg(){

	//enable clock to gpio
	vDo_AHB1ENR_EnableClockAccessToGPIO(GPIO_PORT_A);

	//set gpio as alternate function
	gpio_config_t cfg_reg;
	cfg_reg.direction = ALTERNATE_FUNC;

    //for Tx
	vDoConfigDirection(GPIO_PORT_A, PIN_2, cfg_reg);

    //for RX
    vDoConfigDirection(GPIO_PORT_A, PIN_3, cfg_reg);

	//set usart type rx or tx
    vDoSetGPIOAltFunc(GPIO_PORT_A, PIN_2,AF_7,AF_LOW);
    //set usart type rx or tx
    vDoSetGPIOAltFunc(GPIO_PORT_A, PIN_3,AF_7,AF_LOW);

	//enable clock for usart
	vDo_APB1ENR_EnableClockAccessToUSART(RCC_APB1ENR_USART_2_EN_Msk);

	//configure baudrte
	vSetUSART_bd(USART_2,APB1_CLK,USART_BAUDRATE);

	//configure transfer direction
    USART_2->CR1 = (USART_CR1_TE |USART_CR1_RE);
	//enable usart
    USART_2->CR1 |= USART_CR1_UE;
}

void vSetUSART_bd(USART_t *USARTX, uint32 Periphclk, uint32 BaudRate){

	USARTX->BRR |= (( Periphclk + (BaudRate/2U) ) / BaudRate);

}

uint8 vDoReadUSART_data(){
    while(!(USART_2->SR & USART_SR_RNXE)){}

    return USART_2->DR;
}

void vDoWriteUSART_data(uint8 data){
    while(!(USART_2->SR & USART_SR_TXE)){}

    USART_2->DR = (data & 0xFF);
}

