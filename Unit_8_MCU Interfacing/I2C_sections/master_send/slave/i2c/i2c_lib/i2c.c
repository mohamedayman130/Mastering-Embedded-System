
#include "i2c.h"

void set_address(uint8_t address)
{
	TWAR =address;
}
uint8_t read()
{
	uint8_t x=0;
	TWCR = (1<<TWINT)|(1<<TWEN) | (1<<TWEA);
	while( (TWCR & 1<<7)==0  );
	while(TWSR != 0x60) x=TWSR;
	TWCR = (1<<TWINT)|(1<<TWEN) | (1<<TWEA);
	while( (TWCR & 1<<7)==0  );
	while(TWSR != 0x80) x=TWSR;
	return TWDR;
}
