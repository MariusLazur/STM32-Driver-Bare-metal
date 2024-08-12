

#ifndef STM32_PROJECT_GPIO_H
#define STM32_PROJECT_GPIO_H



#include "STM32F446RE_Base.h"

typedef enum {
    GPIO_PORT_A = 0, /*!< Port A */
    GPIO_PORT_B = 1, /*!< Port B */
    GPIO_PORT_C = 2, /*!< Port C */
    GPIO_PORT_D = 3,  /*!< Port D */
    GPIO_PORT_E = 4,  /*!< Port E */
    GPIO_PORT_F = 5,  /*!< Port F */
    GPIO_PORT_G = 6,  /*!< Port G */
    GPIO_PORT_H = 7   /*!< Port H */
} gpio_port_t;

typedef enum
{
	PIN_0 = 0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
}gpio_pins_t;



typedef enum{
    INPUT = 0,          /*Input (reset state)*/
    OUTPUT,         /*General purpose output mode*/
    ALTERNATE_FUNC, /*Alternate function mode*/
    ANALOG          /*Analog mode*/
}gpio_mode_reg_t;

typedef enum {
    OUTPUT_PUSH_EN,
    OUTPUT_OPEN_DRAIN
}gpio_otype_reg_t;

typedef enum {
    LOW_SPEED,
    MEDIUM_SPEED,
    FAST_SPEED,
    HIGH_SPEED
}gpio_ospeed_reg_t;

typedef enum {
    NO_PULLS,
    PULL_UP,
    PULL_DOWN,
    RESERVED
}gpio_pupd_reg_t;

/*GPIO port input data register */
typedef enum {
    NO_ACTION,
    SET_BIT
}gpio_bsr_reg_t;

typedef enum {
    LOCK_KEY_NO_ACTIVE,
    LOCK_KEY_ACTIVE
}gpio_lck_reg_t;


typedef enum {
    AF_0 = 0,
	AF_1,
	AF_2,
	AF_3,
	AF_4,
	AF_5,
	AF_6,
	AF_7,
	AF_8,
	AF_9,
	AF_10,
	AF_11,
	AF_12,
	AF_13,
	AF_14,
	AF_15,

}gpio_AFR_select_t;

typedef enum{
	AF_LOW,
	AF_HIGH
}gpio_AFR_HI_LO_t;



typedef struct {
    gpio_mode_reg_t direction;
    gpio_otype_reg_t output_type;
    gpio_ospeed_reg_t output_speed;
    gpio_pupd_reg_t pull_up_pull_down;
    gpio_bsr_reg_t set_pin_level;
    gpio_lck_reg_t lock;
}gpio_config_t;

void vDoConfigDirection(gpio_port_t port,gpio_pins_t pin,gpio_config_t config);
void vDoSetPin(gpio_port_t port, gpio_pins_t pin, uint8 pin_lvl);
void vDoSetGPIOAltFunc(gpio_port_t port,gpio_pins_t pin, gpio_AFR_select_t af_select,gpio_AFR_HI_LO_t af_type);


#endif //STM32_PROJECT_GPIO_H


