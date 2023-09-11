/*
 * lcd_keypad_driver.h
 *
 *  Created on: 10 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include"stm32f103x6.h"
#include"stm32f103x6_gpio_driver.h"
//////////////////////////////////////////////////////
/*
  to use this driver ::
  change EN,RW,RS and LCD_PORT

 /////////// you can find them in lcd pins section////////////

 change lcd_port from d0 to d7
  //////////you can find them in lcd pins section also///////////
*/
//////////////////////////////////////////////////////
//lcd pins
#define LCD_PORT GPIOA
#define LCD_CTR  GPIOB
#define EN GPIO_PIN_10 //portB
#define RW GPIO_PIN_11 //portB
#define RS GPIO_PIN_12 //portB

#define D0 GPIO_PIN_0
#define D1 GPIO_PIN_1
#define D2 GPIO_PIN_2
#define D3 GPIO_PIN_3
#define D4 GPIO_PIN_4
#define D5 GPIO_PIN_5
#define D6 GPIO_PIN_6
#define D7 GPIO_PIN_7
//lcd command
#define lcd_on_cursor_on 0x0f
#define lcd_set_16_2 0x38
#define lcd_clear_display 0x01
#define lcd_return_home 0x02
#define lcd_first_line 0x80
#define lcd_second_line 0xc0
#define lcd_cursor_off 0x0c
//lcd functions
void delay(char x);
void kick();
void lcd_write_char(char text);
void lcd_write_string(char* text);
void lcd_write_command(char command);
void LCD_INIT();

#endif /* INC_LCD_H_ */
