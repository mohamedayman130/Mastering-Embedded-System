
#include "lcd.h"
void SET_CURSOR(char row,char col)
{
	if(row==0)
	{
		if(col>=0 && col<16)
		LCD_WRITE_COMMAND(0x80+col);
	}
	else if(row==1)
	{
		if(col>=0 && col<16)
		LCD_WRITE_COMMAND(0xC0+col);
	}
	else
	{
		LCD_WRITE_COMMAND(0x80);
	}
}

void LCD_ENABLE()//turn on and turn off enable
{
	LCD_CTRL |=1<<EN;
	_delay_ms(50);
	LCD_CTRL&=~(1<<EN);
}

void LCD_WRITE_COMMAND(char command)
{
	LCD_PORT=command;
	LCD_CTRL&=~(1<<RW);
	LCD_CTRL&=~(1<<RS);
	LCD_ENABLE();
	
}
void LCD_WRITE_CHAR(char text)
{
	LCD_PORT=text;
	LCD_CTRL^=1<<5;
	LCD_CTRL&=~(1<<RW);
	LCD_CTRL|=(1<<RS);
	LCD_ENABLE();
}
void LCD_WRITE_STRING(char * text)
{
	while(*text !='\0')
	{
		LCD_WRITE_CHAR(*text++);
	}
}

void LCD_INIT()
{
	_delay_ms(100);
	GPIO_DDRA=0xff;
	GPIO_DDRB=0XFF;
	LCD_CTRL &= ~(1<<RW | 1<<RS | 1<<EN );
	LCD_ENABLE();
	LCD_WRITE_COMMAND(0x0f);//to turn on lcd and cursor
	LCD_WRITE_COMMAND(0x38);//2 lines and 5×7 matrix
	LCD_WRITE_COMMAND(0x80);//to start from first row
	
}