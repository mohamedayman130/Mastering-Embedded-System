
#ifndef LCD_H_
#define LCD_H_
#include <util/delay.h>
//GPIO
#define GPIO_BASE 0x20
#define GPIO_PORTA *(volatile int *)(GPIO_BASE + 0X1B)
#define GPIO_DDRA *(volatile int *)(GPIO_BASE + 0X1A)
#define GPIO_PORTB *(volatile int *)(GPIO_BASE + 0X18)
#define GPIO_DDRB *(volatile int *)(GPIO_BASE + 0X17)

//ctrl
#define RS 0
#define RW 1
#define EN 2

//PORT
#define LCD_CTRL GPIO_PORTA
#define LCD_PORT GPIO_PORTB

//functions
void SET_CURSOR(char row,char col);
void LCD_WRITE_COMMAND(char command);
void LCD_WRITE_CHAR(char text);
void LCD_WRITE_STRING(char * text);
void LCD_ENABLE();
void LCD_INIT();




#endif