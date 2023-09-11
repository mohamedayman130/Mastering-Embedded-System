/*
 * keypad.h
 *
 *  Created on: 10 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
///////////////////////////
//4*4 keypad driver///
///////////////////////////
#include"stm32f103x6.h"
#include"stm32f103x6_gpio_driver.h"
//keypad ports
#define keypad_port GPIOB
#define k1 GPIO_PIN_0
#define k2 GPIO_PIN_1
#define k3 GPIO_PIN_3
#define k4 GPIO_PIN_4
#define kA GPIO_PIN_5
#define kB GPIO_PIN_6
#define kC GPIO_PIN_7
#define kD GPIO_PIN_8


//keypad functions
char keypad_get_char();
void keypad_init();
void delay_ms(int x);


#endif /* INC_KEYPAD_H_ */
