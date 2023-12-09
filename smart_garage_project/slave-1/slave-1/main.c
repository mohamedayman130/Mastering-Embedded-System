
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include "hal/lcd.h"
#include "mcal/inc/spi.h"
#include "mcal/inc/uart.h"

int8_t uart_counter=0,temp=0,spi_receved_data=0,pir=0;

void pir_init()
{
	DDRC&=~(1<<1);
}
int main(void)
{
	DDRA=0xff;
	DDRC=0xff;
	uart_init();
	spi_init();
	LCD_INIT();
	pir_init();
	LCD_WRITE_STRING("enter id::");SET_CURSOR(1,0);
	while (1)
	{
		uint8_t uart_recevrd_data=uart_rec();
		if(uart_recevrd_data)
		{
			if(uart_counter==0)
			send_rec_data(16);
			send_rec_data(uart_recevrd_data);
			LCD_WRITE_CHAR(uart_recevrd_data);
			uart_counter++;
			//PORTA=uart_recevrd_data;
		}

					spi_receved_data=rec_data();
				if(spi_receved_data==10)
				{PORTC|=1<<0;lcd_clear_screen();LCD_WRITE_STRING("pass true");_delay_ms(1000);lcd_clear_screen();LCD_WRITE_STRING("enter id::");SET_CURSOR(1,0);PORTC&=~(1<<0);uart_counter=0;pir=1;}
				else if(spi_receved_data==11)
				{PORTC|=1<<1;lcd_clear_screen();LCD_WRITE_STRING("pass false");_delay_ms(1000);lcd_clear_screen();LCD_WRITE_STRING("enter id::");SET_CURSOR(1,0);PORTC&=~(1<<1);uart_counter=0;}
				else if(spi_receved_data==12)
				{PORTC|=1<<1;lcd_clear_screen();LCD_WRITE_STRING("garage is full");_delay_ms(1000);lcd_clear_screen();LCD_WRITE_STRING("enter id::");SET_CURSOR(1,0);PORTC&=~(1<<1);uart_counter=0;}
					
					///pir
					
				if(PINC & 1<<2 && pir==1)
				{
					PORTC|=1<<0;
				}
				else {PORTC&=~(1<<0);pir=0;}
	}
}
