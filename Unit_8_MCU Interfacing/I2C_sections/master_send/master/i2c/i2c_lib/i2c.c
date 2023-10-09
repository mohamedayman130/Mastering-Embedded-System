/*
 * i2c.c
 *
 * Created: 05/10/2023 23:04:34
 *  Author: Alfanan02
 */ 
#include "i2c.h"
#include <avr/delay.h>
void i2c_init()
{
	TWBR = (((8000000 /0x48)-16)/2);
	TWSR = 0;
}
void i2c_start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( (TWCR & 1<<7)==0  );
	//while (TWSR != 0x08);
}
void i2c_stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
void send(uint8_t data)
{
	TWDR =data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	//while( TWCR & 0x80 ==0);
}






