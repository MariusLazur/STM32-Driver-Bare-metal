

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
    PIN_1 = 0,
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


typedef struct {
    gpio_mode_reg_t direction;
    gpio_otype_reg_t output_type;
    gpio_ospeed_reg_t output_speed;
    gpio_pupd_reg_t pull_up_pull_down;
    gpio_bsr_reg_t set_pin_level;
    gpio_lck_reg_t lock;
}gpio_config_t;

#endif //STM32_PROJECT_GPIO_H


