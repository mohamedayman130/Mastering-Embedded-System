/*
 * lcd_keypad_driver.c
 *
 *  Created on: 10 Sep 2023
 *      Author: Alfanan02
 */

#include"lcd.h"
void delay(char x)
{
	for(int i=0;i<=x;i++)
		for(int j=0;j<=1000;j++);
}
void kick()
{
	mcal_gpio_write_pin(LCD_CTR, EN, 1);
	delay(10);
	mcal_gpio_write_pin(LCD_CTR, EN, 0);
}
void lcd_write_char(char text)
{
	mcal_gpio_write_port(LCD_PORT, text<<(get_pos_odr(D0)));
	mcal_gpio_write_pin(LCD_CTR, RS,1);
	mcal_gpio_write_pin(LCD_CTR,RW,0);
	kick();
}
void lcd_write_string(char *text)
{
	while(*text!='\0')
		lcd_write_char(*text++);
}
void lcd_write_command(char command)
{
	mcal_gpio_write_port(LCD_PORT, command<<get_pos_odr(D0));
	mcal_gpio_write_pin(LCD_CTR, RS,0);
	mcal_gpio_write_pin(LCD_CTR,RW,0);
	kick();
}
void LCD_INIT()
{
	delay(5);
	gpio_config gpio_cnf;

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D0;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D1;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D2;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D3;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D4;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D5;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D6;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=D7;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_PORT, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=EN;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_CTR, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=RS;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_CTR, &gpio_cnf);

	gpio_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_cnf.gpio_pin_number=RW;
	gpio_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(LCD_CTR, &gpio_cnf);


	mcal_gpio_write_pin(LCD_CTR, EN, 0);
	mcal_gpio_write_pin(LCD_CTR, RW, 0);
	mcal_gpio_write_pin(LCD_CTR, RS, 0);

	lcd_write_command(lcd_set_16_2);
	lcd_write_command(lcd_on_cursor_on);
	lcd_write_command(lcd_first_line);
}
