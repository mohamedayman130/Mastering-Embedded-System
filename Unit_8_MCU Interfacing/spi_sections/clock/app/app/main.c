/*
 * app.c
 *
 * Created: 27/09/2023 02:26:06
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include <avr/delay.h>
void spi_send(char x)
{
	SPDR=x;
	while(!(SPSR&(1<<SPIF)));
}

void seven_Seg_send(char reg, char data)
{
	PORTB&=~(1<<4);
	spi_send(reg);
	spi_send(data);
	PORTB|=1<<4;
}

int main(void)
{
	DDRB=0xff;
	//set spi as master and enable it
	SPCR=(1<<SPE)|(1<<MSTR);
	//decode 0-7 digits
	seven_Seg_send(0x09,0xFF);
	//Display digits 0 1 2 3 4 5 6 7
	seven_Seg_send(0x0B,0x07);
	//normal operation
	seven_Seg_send(0x0C,0x01);
	//Intensity 
	seven_Seg_send(0x0A,0x03);

    while (1) 
    {
		
		for(char i=1;i<=24;i++)
		{
			for(int j=1;j<60;j++)
			{
				for(int k=0;k<60;k++)
				{
					seven_Seg_send(0x05,k/10);
					seven_Seg_send(0x06,k%10);
					_delay_ms(100);
				}
				seven_Seg_send(0x03,j/10);
				seven_Seg_send(0x04,j%10);
				_delay_ms(100);
			}			
			seven_Seg_send(0x01,i/10);
			seven_Seg_send(0x02,i%10);
			//_delay_ms(1);
		}
		
    }
}

