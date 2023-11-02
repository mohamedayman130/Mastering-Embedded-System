/*
 * adc.c
 *
 * Created: 01/11/2023 23:34:12
 * Author : Alfanan02
 */ 
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "hal/lcd.h"
void adc_init()
{
	ADMUX |=1<<6;
	ADCSRA|=1<<7;
}

uint16_t adc_read()
{
	ADCSRA|=1<<6;	
	while( (ADCSRA & 1<<6) == 1<<6);
	return  ADC;
}

void lcd_dis_data(uint32_t val)
{
	lcd_clear_screen();
	LCD_WRITE_STRING("per:>> ");
			lcd_write_num(val*100/1023);LCD_WRITE_CHAR('%');
			_delay_ms(10);
			SET_CURSOR(1,0);
			for(uint16_t i= 0;i<=val;i+=64)
			{
				
				LCD_WRITE_CHAR(255);
			}
			_delay_ms(10);
}


int main(void)
{
	adc_init();
	LCD_INIT();
    /* Replace with your application code */
	SET_CURSOR(0,0);
	uint32_t ref=0,mesure=0;
    while (1) 
    {
		mesure=adc_read();
		if(ref != mesure)
		{
			lcd_dis_data(mesure);
			ref=mesure;
		}
		_delay_ms(100);
		
	
    }
}

