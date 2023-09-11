/*
 * stm32f103x6_gpio_driver.h
 *
 *  Created on: 5 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_STM32F103X6_GPIO_DRIVER_H_
#define INC_STM32F103X6_GPIO_DRIVER_H_

#include "stm32f103x6.h"

typedef struct
{
	short int gpio_pin_number;//chose number of pins to configure
	//can you define them from gpio_config_define
	char gpio_mode;				//chose mode of pins to configure
	//can you define them from gpio_mode_define

	char gpio_speed;//chose speed of pins
	//can you define them from gpio_speed
}gpio_config;







/////////////////
//macros config ref
/////////////////

///gpio_config_define
#define GPIO_PIN_0   	(int )0x00000001
#define GPIO_PIN_1   	(int )0x00000002
#define GPIO_PIN_2   	(int )0x00000004
#define GPIO_PIN_3   	(int )0x00000008
#define GPIO_PIN_4   	(int )0x00000010
#define GPIO_PIN_5   	(int )0x00000020
#define GPIO_PIN_6   	(int )0x00000040
#define GPIO_PIN_7   	(int )0x00000080
#define GPIO_PIN_8   	(int )0x00000100
#define GPIO_PIN_9   	(int )0x00000200
#define GPIO_PIN_10   	(int )0x00000400
#define GPIO_PIN_11   	(int )0x00000800
#define GPIO_PIN_12   	(int )0x00001000
#define GPIO_PIN_13   	(int )0x00002000
#define GPIO_PIN_14  	(int )0x00004000
#define GPIO_PIN_15  	(int )0x00008000
#define GPIO_PIN_all   	(int )0xffff


///gpio_mode_define
#define GPIO_MODE_ANALOG  		(int )0x00000000//for analog input
#define GPIO_MODE_INPUT_FLO   	(int )0x00000001//for floating input
#define GPIO_MODE_INPUT_PU   	(int )0x00000002//for pull_up input
#define GPIO_MODE_INPUT_PD   	(int )0x00000003//for pull_down input
#define GPIO_MODE_OUTPUT_PP   	(int )0x00000004//for push_pull output
#define GPIO_MODE_OUTPUT_OD   	(int )0x00000005//for open drain output
#define GPIO_MODE_OUTPUT_AF_PP  (int )0x00000006//for altranative push_pull output
#define GPIO_MODE_OUTPUT_AF_OD  (int )0x00000007//for altranative open_drain output
#define GPIO_MODE_AF_INPUT   	(int )0x00000008//for altranative input

////gpio_speed
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz
#define  max_speed_10 		0x1
#define  max_speed_2 		0x2
#define  max_speed_50 		0x3





/////////////////////////////APIS///////////////////////////////
////////////////////////////////////////////////////////////////

void mcal_gpio_init(GPIO *gpiox,gpio_config *config);
void mcal_gpio_deinit(GPIO *gpiox);
char mcal_gpio_read_pin(GPIO *gpiox,unsigned short pin_number);
void mcal_gpio_write_pin(GPIO *gpiox,unsigned short pin_number,char val);
void mcal_gpio_write_port(GPIO *gpiox,unsigned short val);
void mcal_gpio_toggle_pin(GPIO *gpiox,unsigned short pin_number);
#endif /* INC_STM32F103X6_GPIO_DRIVER_H_ */
