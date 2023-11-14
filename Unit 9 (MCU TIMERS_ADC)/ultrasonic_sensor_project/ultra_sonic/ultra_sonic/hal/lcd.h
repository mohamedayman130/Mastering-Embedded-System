
#ifndef LCD_H_
#define LCD_H_
#include <util/delay.h>
//GPIO
#define GPIO_BASE 0x20
#define GPIO_PORTD *(volatile char *)(GPIO_BASE + 0X0B)
#define GPIO_DDRD *(volatile char *)(GPIO_BASE + 0X0A)
#define GPIO_PORTB *(volatile char *)(GPIO_BASE + 0X05)
#define GPIO_DDRB *(volatile char *)(GPIO_BASE + 0X04)

//ctrl
#define RS 2
#define RW 1
#define EN 0

//PORT
#define LCD_CTRL GPIO_PORTB
#define LCD_PORT GPIO_PORTD

//functions
void SET_CURSOR(char row,char col);
void LCD_WRITE_COMMAND(char command);
void LCD_WRITE_CHAR(char text);
void LCD_WRITE_STRING(char * text);
void LCD_ENABLE();
void LCD_INIT();
void lcd_clear_screen();
void lcd_write_num(uint32_t num);



#endif