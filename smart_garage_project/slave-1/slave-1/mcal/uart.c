
#include "inc/uart.h"
void uart_init()
{
	DDRD&=~(1<<0);
	UBRRL=103;
	UCSRB|=1<<4;
}

uint8_t uart_rec()
{
	if((UCSRA & 1<<7))
	return UDR;
	return 0;
}
