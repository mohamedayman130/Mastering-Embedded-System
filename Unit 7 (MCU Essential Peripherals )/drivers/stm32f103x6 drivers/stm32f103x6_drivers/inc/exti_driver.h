/*
 * EXTI.h
 *
 *  Created on: 13 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_EXTI_DRIVER_H_
#define INC_EXTI_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103x6_gpio_driver.h"
#include <stdint.h>
typedef struct
{
	uint16_t 	 exti_line_number;
	GPIO 		 * gpio_port;
	uint16_t  	 gpio_pin;
	uint8_t 	 ivt_irq_number;

}exti_gpio_mapping;

typedef struct
{
	exti_gpio_mapping exti_pin;//this parameter must be set on @ref exti_define
	uint8_t trigger_case;//this parameter must be set on @ref exti_trigger_define
	uint8_t irq_state;//this parameter must be set on @ref exti_irq_define
	void (* irq_call_back )(void);
}exti_pin_conf;













/////////////reference macros////

#define exti0 		0
#define exti1		1
#define exti2 		2
#define exti3 		3
#define exti4 		4
#define exti5 		5
#define exti6 		6
#define exti7 		7
#define exti8 		8
#define exti9 		9
#define exti10 		10
#define exti11 		11
#define exti12 		12
#define exti13 		13
#define exti14 		14
#define exti15 		15

//@ref exti_Define
#define EXTI0A0  (exti_gpio_mapping){exti0,GPIOA,GPIO_PIN_0,exti0_irq};
#define EXTI0B0  (exti_gpio_mapping){exti0,GPIOB,GPIO_PIN_0,exti0_irq};
#define EXTI0C0  (exti_gpio_mapping){exti0,GPIOC,GPIO_PIN_0,exti0_irq};
#define EXTI0D0  (exti_gpio_mapping){exti0,GPIOD,GPIO_PIN_0,exti0_irq};

#define EXTI1A1  (exti_gpio_mapping){exti1,GPIOA,GPIO_PIN_1,exti1_irq};
#define EXTI1B1  (exti_gpio_mapping){exti1,GPIOB,GPIO_PIN_1,exti1_irq};
#define EXTI1C1  (exti_gpio_mapping){exti1,GPIOC,GPIO_PIN_1,exti1_irq};
#define EXTI1D1  (exti_gpio_mapping){exti1,GPIOD,GPIO_PIN_1,exti1_irq};

#define EXTI2A2  (exti_gpio_mapping){exti2,GPIOA,GPIO_PIN_2,exti2_irq};
#define EXTI2B2  (exti_gpio_mapping){exti2,GPIOB,GPIO_PIN_2,exti2_irq};
#define EXTI2C2  (exti_gpio_mapping){exti2,GPIOC,GPIO_PIN_2,exti2_irq};
#define EXTI2D2  (exti_gpio_mapping){exti2,GPIOD,GPIO_PIN_2,exti2_irq};

#define EXTI3A3  (exti_gpio_mapping){exti3,GPIOA,GPIO_PIN_3,exti3_irq};
#define EXTI3B3  (exti_gpio_mapping){exti3,GPIOB,GPIO_PIN_3,exti3_irq};
#define EXTI3C3  (exti_gpio_mapping){exti3,GPIOC,GPIO_PIN_3,exti3_irq};
#define EXTI3D3  (exti_gpio_mapping){exti3,GPIOD,GPIO_PIN_3,exti3_irq};

#define EXTI4A4  (exti_gpio_mapping){exti4,GPIOA,GPIO_PIN_4,exti4_irq};
#define EXTI4B4  (exti_gpio_mapping){exti4,GPIOB,GPIO_PIN_4,exti4_irq};
#define EXTI4C4  (exti_gpio_mapping){exti4,GPIOC,GPIO_PIN_4,exti4_irq};
#define EXTI4D4  (exti_gpio_mapping){exti4,GPIOD,GPIO_PIN_4,exti4_irq};

#define EXTI5A5  (exti_gpio_mapping){exti5,GPIOA,GPIO_PIN_5,exti5_irq};
#define EXTI5B5  (exti_gpio_mapping){exti5,GPIOB,GPIO_PIN_5,exti5_irq};
#define EXTI5C5  (exti_gpio_mapping){exti5,GPIOC,GPIO_PIN_5,exti5_irq};
#define EXTI5D5  (exti_gpio_mapping){exti5,GPIOD,GPIO_PIN_5,exti5_irq};

#define EXTI6A6  (exti_gpio_mapping){exti6,GPIOA,GPIO_PIN_6,exti6_irq};
#define EXTI6B6  (exti_gpio_mapping){exti6,GPIOB,GPIO_PIN_6,exti6_irq};
#define EXTI6C6  (exti_gpio_mapping){exti6,GPIOC,GPIO_PIN_6,exti6_irq};
#define EXTI6D6  (exti_gpio_mapping){exti6,GPIOD,GPIO_PIN_6,exti6_irq};

#define EXTI7A7  (exti_gpio_mapping){exti7,GPIOA,GPIO_PIN_7,exti7_irq};
#define EXTI7B7  (exti_gpio_mapping){exti7,GPIOB,GPIO_PIN_7,exti7_irq};
#define EXTI7C7  (exti_gpio_mapping){exti7,GPIOC,GPIO_PIN_7,exti7_irq};
#define EXTI7D7  (exti_gpio_mapping){exti7,GPIOD,GPIO_PIN_7,exti7_irq};

#define EXTI8A8  (exti_gpio_mapping){exti8,GPIOA,GPIO_PIN_8,exti8_irq};
#define EXTI8B8  (exti_gpio_mapping){exti8,GPIOB,GPIO_PIN_8,exti8_irq};
#define EXTI8C8  (exti_gpio_mapping){exti8,GPIOC,GPIO_PIN_8,exti8_irq};
#define EXTI8D8  (exti_gpio_mapping){exti8,GPIOD,GPIO_PIN_8,exti8_irq};

#define EXTI9A9  (exti_gpio_mapping){exti9,GPIOA,GPIO_PIN_9,exti9_irq};
#define EXTI9B9  (exti_gpio_mapping){exti9,GPIOB,GPIO_PIN_9,exti9_irq};
#define EXTI9C9  (exti_gpio_mapping){exti9,GPIOC,GPIO_PIN_9,exti9_irq};
#define EXTI9D9  (exti_gpio_mapping){exti9,GPIOD,GPIO_PIN_9,exti9_irq};

#define EXTI10A10  (exti_gpio_mapping){exti10,GPIOA,GPIO_PIN_10,exti10_irq};
#define EXTI10B10  (exti_gpio_mapping){exti10,GPIOB,GPIO_PIN_10,exti10_irq};
#define EXTI10C10  (exti_gpio_mapping){exti10,GPIOC,GPIO_PIN_10,exti10_irq};
#define EXTI10D10  (exti_gpio_mapping){exti10,GPIOD,GPIO_PIN_10,exti10_irq};

#define EXTI11A11  (exti_gpio_mapping){exti11,GPIOA,GPIO_PIN_11,exti11_irq};
#define EXTI11B11  (exti_gpio_mapping){exti11,GPIOB,GPIO_PIN_11,exti11_irq};
#define EXTI11C11  (exti_gpio_mapping){exti11,GPIOC,GPIO_PIN_11,exti11_irq};
#define EXTI11D11  (exti_gpio_mapping){exti11,GPIOD,GPIO_PIN_11,exti11_irq};

#define EXTI12A12  (exti_gpio_mapping){exti12,GPIOA,GPIO_PIN_12,exti12_irq};
#define EXTI12B12  (exti_gpio_mapping){exti12,GPIOB,GPIO_PIN_12,exti12_irq};
#define EXTI12C12  (exti_gpio_mapping){exti12,GPIOC,GPIO_PIN_12,exti12_irq};
#define EXTI12D12  (exti_gpio_mapping){exti12,GPIOD,GPIO_PIN_12,exti12_irq};

#define EXTI13A13  (exti_gpio_mapping){exti13,GPIOA,GPIO_PIN_13,exti13_irq};
#define EXTI13B13  (exti_gpio_mapping){exti13,GPIOB,GPIO_PIN_13,exti13_irq};
#define EXTI13C13  (exti_gpio_mapping){exti13,GPIOC,GPIO_PIN_13,exti13_irq};
#define EXTI13D13  (exti_gpio_mapping){exti13,GPIOD,GPIO_PIN_13,exti13_irq};

#define EXTI14A14  (exti_gpio_mapping){exti14,GPIOA,GPIO_PIN_14,exti14_irq};
#define EXTI14B14  (exti_gpio_mapping){exti14,GPIOB,GPIO_PIN_14,exti14_irq};
#define EXTI14C14  (exti_gpio_mapping){exti14,GPIOC,GPIO_PIN_14,exti14_irq};
#define EXTI14D14  (exti_gpio_mapping){exti14,GPIOD,GPIO_PIN_14,exti14_irq};

#define EXTI15A15  (exti_gpio_mapping){exti15,GPIOA,GPIO_PIN_15,exti15_irq};
#define EXTI15B15  (exti_gpio_mapping){exti15,GPIOB,GPIO_PIN_15,exti15_irq};
#define EXTI15C15  (exti_gpio_mapping){exti15,GPIOC,GPIO_PIN_15,exti15_irq};
#define EXTI15D15  (exti_gpio_mapping){exti15,GPIOD,GPIO_PIN_15,exti15_irq};


/////////////@ref exti_trigger_define

#define trigger_rising 				0
#define trigger_falling 			1
#define trigger_rising_falling 		2




///////////@ref exti_irq_define
#define irq_en 	1
#define irq_dn 	0







///////////////////APIS///////////////////

void mcal_gpio_exti_init(exti_pin_conf * exti_conf);
void mcal_gpio_exti_deinit(void);
void mcal_gpio_exti_update(exti_pin_conf * exti_conf);


#endif /* INC_EXTI_DRIVER_H_ */
