/*
 * spi.c
 *
 * Created: 27/09/2023 01:10:16
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include <avr/delay.h>

void spi_slave_init()
{
	DDRB|=1<<6;
	SPCR|=1<<6;
}

char slave_receive(char data)
{
	SPDR= data;
	while(!(SPSR & 1<<7));
	return SPDR;
}
int main(void)
{
	DDRA=0xff;
   spi_slave_init();
   
   for(unsigned char i=9;i>=0;i--)
   {PORTA=slave_receive(i);
	   _delay_ms(1000);}
    while (1) 
    {
    }
}

