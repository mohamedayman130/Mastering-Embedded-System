/*
 * 15963.c
 *
 * Created: 01/10/2023 23:18:25
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <avr/delay.h>
#include "hal/lcd.h"
void spi_init()
{
	DDRB |= 1<<4 | 1<<5 |1<<7;
	SPCR|=1<<6 | 1<<4 ;
}

uint8_t send_rec_data(uint8_t data)
{
	SPDR = data;
	while (! (SPSR & 1<<7));
	return SPDR;
}

int main(void)
{	
	spi_init();
	LCD_INIT();
	uint8_t x='z';
	LCD_WRITE_STRING("master");
	
	while (1) 
    {
	LCD_WRITE_COMMAND(0xc0);
	LCD_WRITE_CHAR(send_rec_data(x--));
	if(x=='a'-1) x='z';
	_delay_ms(7000);
    }
}

