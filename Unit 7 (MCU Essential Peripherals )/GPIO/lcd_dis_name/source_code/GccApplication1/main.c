#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
# define F_CPU 1000000UL

#define GPIO_BASE 0X20
#define GPIO_PORTA *(volatile int *)(GPIO_BASE + 0x1B)
#define GPIO_DDRA *(volatile int *)(GPIO_BASE + 0x1A)

#define GPIO_PORTB *(volatile int *)(GPIO_BASE + 0x18)
#define GPIO_DDRB *(volatile int *)(GPIO_BASE + 0x17)

//#define GPIO_BINA *(volatile int *)(GPIO_BASE+ 0x19)
//#define GPIO_BINB *(volatile int *)(GPIO_BASE+ 0x16)

#define LCD_CTR PORTB///////////again
#define LCD_PORT GPIO_PORTA

#define RS_SWITCH 1
#define RW_SWITCH 2
#define EN_SWITCH 3

void kick()
{
	LCD_CTR|=1<<EN_SWITCH;
	_delay_ms(50);
	LCD_CTR&=~(1<<EN_SWITCH);
}
void lcd_write_command(char command)
{
	LCD_PORT =command;
	LCD_CTR &=~(1<<RS_SWITCH);
	LCD_CTR &=~(1<<RW_SWITCH);
	_delay_ms(1);
	kick();
}
void LCD_clear_screen(){
	lcd_write_command(0x01);
}
void lcd_write_char(char text)
{
	LCD_PORT =text;
	LCD_CTR |=(1<<RS_SWITCH);
	LCD_CTR &=~(1<<RW_SWITCH);
	//_delay_ms(1);
	kick();
	
}
void set_pos(char row,char col)
{
	if(row==0)
	lcd_write_command(0x80 +col);
	else if(row==1)
	lcd_write_command(0xc0 +col);
}
void LCD_WRITE_STRING(char * text,char row,char col)
{
	set_pos(row,col);
	while(*text !='\0')
	{
		lcd_write_char(*text);
		text++;
	}
}
void lcd_init()
{
     GPIO_DDRB=0xff;
	 GPIO_DDRA=0XFF;
	LCD_CTR &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	_delay_ms(20);
	LCD_clear_screen();
	lcd_write_command(0x38);
	lcd_write_command(0x80);
	lcd_write_command(0x0e);

	
}

int main(void)
{
	lcd_init();
	LCD_WRITE_STRING("mohamed",0,5);
	LCD_WRITE_STRING("ayman",1,6);
	lcd_write_command(0x0c);
	int count=1;
	while (1)
	{
		if(count<=5)
		{count++;
		lcd_write_command(0x18);
		_delay_ms(50);
		}
		else if(count<=14)
		{
			count++;
			lcd_write_command(0x1c);
			_delay_ms(50);
		}
		else if(count<=19)
		{count++;
			lcd_write_command(0x18);
			_delay_ms(50);
			if(count>=19) count=1;
		}
	}
}

