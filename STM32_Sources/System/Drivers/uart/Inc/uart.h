#include "STM32F446RE_Base.h"
#include "gpio.h"
#include "rcc.h"

#define USART_BAUDRATE 115200

#define USART_CR1_UE 1<<13

#define USART_CR1_TE 1<<3
#define USART_CR1_RE 1<<2

#define USART_SR_TXE 1<<7
#define USART_SR_RNXE 1<<5



void vDoUSARTx_cfg();
void vSetUSART_bd(USART_t *USARTX,uint32 Periphclk, uint32 BaudRate);

uint8 vDoReadUSART_data();
void vDoWriteUSART_data(uint8 data);
