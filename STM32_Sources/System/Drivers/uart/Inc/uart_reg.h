/*
 * uart_reg.h
 *
 *  Created on: Jun 24, 2024
 */

#ifndef SYSTEM_DRIVERS_UART_INC_UART_REG_H_
#define SYSTEM_DRIVERS_UART_INC_UART_REG_H_

#include "types.h"

typedef struct
{
  __IO SR;         /*!< USART Status register,                   Address offset: 0x00 */
  __IO DR;         /*!< USART Data register,                     Address offset: 0x04 */
  __IO BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  __IO CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  __IO CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  __IO GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_t;

#endif /* SYSTEM_DRIVERS_UART_INC_UART_REG_H_ */
