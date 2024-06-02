
#include "gpio.h"

void vDoConfigDirection(gpio_port_t port,gpio_pins_t pin,gpio_config_t config){

    uint32 position = pin * 2;
    switch(port)
    {
        case GPIO_PORT_A:{
            GPIO_A_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_A_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_B:{
            GPIO_B_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_B_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_C:{
            GPIO_C_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_C_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_D:{
            GPIO_D_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_D_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_E:{
            GPIO_E_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_E_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_F:{
            GPIO_F_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_F_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_G:{
            GPIO_G_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_G_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        case GPIO_PORT_H:{
            GPIO_H_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_H_REG->GPIOx_MODER |= config.direction << position;
            break;
        }
        default:
            break;
    }
}


void vDoSetPin(gpio_port_t port, gpio_pins_t pin, uint8 pin_lvl){

    uint32 position = pin;

    switch(port)
    {
        case GPIO_PORT_A:{
            GPIO_A_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_A_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_B:{
            GPIO_B_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_B_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_C:{
            GPIO_C_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_C_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_D:{
            GPIO_D_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_D_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_E:{
            GPIO_E_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_E_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_F:{
            GPIO_F_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_F_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_G:{
            GPIO_G_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_G_REG->GPIOx_ODR |= pin_lvl << position;
            break;
        }
        case GPIO_PORT_H:{
            GPIO_H_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_H_REG->GPIOx_MODER |= pin_lvl << position;
            break;
        }
        default:
            break;
    }
}


/*
 * Pin Speed Configuration:
 *
 * Low Speed:
 *   Used for pins controlling LEDs or buttons where response times are not critical and energy consumption needs to be minimized.
 *
 * Medium Speed:
 *   Suitable for slow communications and control interfaces that do not require high speeds.
 *
 * High Speed:
 *   Used for fast communication interfaces such as SPI, I2C, or UART.
 *
 * Very High Speed:
 *   Used for high-performance applications such as display drivers or high-speed communications.
 */
void vDoSetSpeed(gpio_port_t port, gpio_pins_t pin, gpio_config_t config){

    uint32 position = pin * 2;

    switch(port)
    {
        case GPIO_PORT_A:{
            GPIO_A_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_A_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_B:{
            GPIO_B_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_B_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_C:{
            GPIO_C_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_C_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_D:{
            GPIO_D_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_D_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_E:{
            GPIO_E_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_E_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_F:{
            GPIO_F_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_F_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_G:{
            GPIO_G_REG->GPIOx_ODR &= ~(0x3u << position);
            GPIO_G_REG->GPIOx_ODR |= config.output_speed << position;
            break;
        }
        case GPIO_PORT_H:{
            GPIO_H_REG->GPIOx_MODER &= ~(0x3u << position);
            GPIO_H_REG->GPIOx_MODER |= config.output_speed << position;
            break;
        }
        default:
            break;
    }
}
