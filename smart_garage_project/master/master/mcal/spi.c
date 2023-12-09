#include "inc/spi.h"

void spi_init()
{
	DDRB=0xff;
	DDRB&=~(1<<6);
	SPCR|=1<<6 | 1<<4 | 1<<7;
}

uint8_t send_rec_data(char data)
{
	//PORTB&=~(1<<2);
	SPDR = data;
	while(!(1<<7 & SPSR));
	return SPDR;
}

void spi_send_data(uint8_t data)
{
	SPDR = data;
	while(!(1<<7 & SPSR));
}