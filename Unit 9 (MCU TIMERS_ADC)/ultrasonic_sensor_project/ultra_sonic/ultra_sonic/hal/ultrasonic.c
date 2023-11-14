
#include "ultrasonic.h"

void ultra_init()
{
	DDRD|=1<<3;//trig
	DDRD&=~(1<<2);//echo
}

uint32_t ultra_read()
{
	PORTD|=1<<3;
	_delay_ms(0.01);
	PORTD&=~(1<<3);
	while( !((1<<2) & PIND));
	TCNT1=0;
	while( (1<<2) & PIND);
	uint32_t dis=TCNT1;
	dis/=932.95;
	return dis;
}