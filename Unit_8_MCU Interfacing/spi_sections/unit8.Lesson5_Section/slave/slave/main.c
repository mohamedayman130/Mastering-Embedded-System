
#include <avr/io.h>
#include <stdint.h>
#include "hal/lcd.h"
void spi_init()
{
	DDRB|=1<<6;
	SPCR|=1<<6;
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
	uint8_t x='a';
	LCD_WRITE_STRING("slave:");
	
    while (1) 
    {
		LCD_WRITE_COMMAND(0xc0);
		LCD_WRITE_CHAR(send_rec_data(x++));
		if(x=='z'+1) x='a';
		_delay_ms(7000);
    }
}

