/*
 * rcc.h
 *
 *  Created on: 22 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f103x6.h"
#include "stm32f103x6_gpio_driver.h"

uint32_t mcal_rcc_get_sysclk1(void);
uint32_t mcal_rcc_get_hclk1(void);
uint32_t mcal_rcc_get_pclk1(void);
uint32_t mcal_rcc_get_pclk2(void);

#endif /* INC_RCC_H_ */
