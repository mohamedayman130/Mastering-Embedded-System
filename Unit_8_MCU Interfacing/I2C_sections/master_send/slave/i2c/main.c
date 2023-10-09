/*
 * i2c.c
 *
 * Created: 05/10/2023 23:04:01
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include "i2c_lib/i2c.h"
#include "avr/delay.h"
int main(void)
{
	DDRB=0xff;
	set_address(0b11010000);
    while (1) 
    {
		
		PORTB = read();
    }
}

