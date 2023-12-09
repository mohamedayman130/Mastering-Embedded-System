#include "inc/EEPROM.h"
void eeprom_init()
{
	DDRB|=1<<3;
}
void eeprom_write(uint8_t address, uint8_t data)
{
	PORTB|=1<<3;
	PORTB&=~(1<<3);
	send_rec_data(0x06);
	PORTB|=1<<3;
	PORTB&=~(1<<3);
	send_rec_data(0x02);
	send_rec_data(address);
	send_rec_data(data);
	PORTB|=1<<3;
	_delay_ms(5);
}
uint8_t eeprom_read(uint8_t add)
{
	PORTB|=1<<3;
	PORTB&=~(1<<3);
	send_rec_data(0x03);
	send_rec_data(add);
	uint8_t data=send_rec_data(0xff);
	PORTB|=1<<3;
	return data;
}
void eeprom_send_7_bytes(uint32_t id)
{
	uint32_t temp=id;
	uint8_t id_array[7],counter=0;
	while(temp)
	{
		id_array[counter++]=temp%10;
		temp/=10;
	}
	uint8_t temp2=eeprom_read(0x00)*7+20;
	for(uint8_t i=temp2;i<=6+temp2;i++)
	eeprom_write(i,id_array[--counter]);
}

uint32_t eeprom_read_7_bytes(uint8_t add )
{
	uint8_t temp=add,read=0;
	uint32_t id=0;
	for(uint8_t i=add;i<=6+temp;i++)
	{
		read=eeprom_read(i);
		id=id*10+read;
	}
	return id;
	
}
