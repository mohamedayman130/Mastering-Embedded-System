#include "inc/spi.h"
uint8_t rec_data()
{
	if((1<<7 & SPSR))
	return SPDR;
	return 0;
}

uint8_t send_rec_data(char data)
{
	SPDR = data;
	while(!(1<<7 & SPSR));
	return SPDR;
}

void spi_init()
{
	DDRB=0xff;
	DDRB&=~(1<<5 |1<<4 |1<<7);
	SPCR|=1<<6;
}

