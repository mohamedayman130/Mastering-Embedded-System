
#include "inc/lcd.h"
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
	_delay_ms(20);
	LCD_CTRL&=~(1<<EN);
}

void LCD_WRITE_COMMAND(char command)
{
	LCD_PORT=(LCD_PORT & 0x0f) | (command & 0xf0);
	LCD_CTRL&=~(1<<RW);
	LCD_CTRL&=~(1<<RS);
	LCD_ENABLE();
	
	LCD_PORT=(LCD_PORT & 0x0f) | (command <<4);
	LCD_CTRL&=~(1<<RW);
	LCD_CTRL&=~(1<<RS);
	LCD_ENABLE();
	
}
void LCD_WRITE_CHAR(char text)
{
	LCD_PORT=(LCD_PORT & 0x0f) | (text & 0xf0);
	LCD_CTRL&=~(1<<RW);
	LCD_CTRL|=(1<<RS);
	LCD_ENABLE();
	
	LCD_PORT=(LCD_PORT & 0x0f) | (text << 4);//0x0f
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

void lcd_clear_screen()
{
	LCD_WRITE_COMMAND(0x01);
}
void LCD_INIT()
{
	_delay_ms(100);
	GPIO_DDRA=0xff;
	LCD_CTRL &= ~(1<<RW | 1<<RS | 1<<EN );
	LCD_ENABLE();
	LCD_WRITE_COMMAND(0x02);//to turn on 4_bits mode
	LCD_WRITE_COMMAND(0x0e);//to turn on lcd and cursor
	LCD_WRITE_COMMAND(0x28);//2 lines and 5×7 matrix
	LCD_WRITE_COMMAND(0x80);//to start from first row
	
}


void lcd_write_num(uint32_t num)
{
	char num_arr[40]={0},counter=0;
		if(num==0) LCD_WRITE_CHAR('0');
		else{
	while(num!=0)
	{
		num_arr[counter++]=num%10;
		num/=10;
	}
	while(counter)
	{
		LCD_WRITE_CHAR(num_arr[--counter]+48);
	}
		}
	
}