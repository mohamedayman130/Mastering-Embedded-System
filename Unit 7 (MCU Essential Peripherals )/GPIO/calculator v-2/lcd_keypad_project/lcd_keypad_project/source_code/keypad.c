#include "keypad.h"
void KEYBAD_INIT(){
	GPIO_DDRD |=(1<<0 | 1<<1 |1<<2 |1<<3);//first 4 bits as output
	GPIO_DDRD&=~(1<<4 | 1<<5   | 1<<6  |1<<7);//last 4 bits as input
	GPIO_PORTD=0;

}
char GET_KEY()
{
	
	for(int i=0;i<4;i++)
	{
		_delay_ms(50);
		GPIO_PORTD=0;
		GPIO_PORTD|=(1<<i);
		for(int j=0;j<4;j++)
		{
			if( (GPIO_PIND & (1<<j<<4) ) )
			{
				while( (GPIO_PIND & (1<<j<<4) ) );
				switch(i){
					case (0):
					if (j == 0) return '7';
					else if (j == 1) return '8';
					else if (j == 2) return '9';
					else if (j == 3) return '/';
					break;
					case (1):
					if (j == 0) return '4';
					else if (j == 1) return '5';
					else if (j == 2) return '6';
					else if (j == 3) return '*';
					break;
					case (2):
					if (j == 0) return '1';
					else if (j == 1) return '2';
					else if (j == 2) return '3';
					else if (j == 3) return '-';
					break;
					case (3):
					if (j == 0) return '?';
					else if (j == 1) return '0';
					else if (j == 2) return '=';
					else if (j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'n';
}




