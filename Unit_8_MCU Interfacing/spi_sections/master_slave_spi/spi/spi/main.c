/*
 * spi.c
 *
 * Created: 27/09/2023 01:10:16
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include <avr/delay.h>

void spi_init()
{
	DDRB |= 1<<4 | 1<<5 |1<<7;
	SPCR|=1<<6 | 1<<4 ;
}

char send_char(char data)
{
	SPDR= data;
	while(!(SPSR & 1<<7));
	return SPDR;
}
int main(void)
{DDRA=0xff;
   spi_init();
   
   for(unsigned char i=0;i<10;i++)
   {PORTA=send_char(i);_delay_ms(1000);}
    while (1) 
    {
    }
}

