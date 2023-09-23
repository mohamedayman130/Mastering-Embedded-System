/*
 * uart.c
 *
 * Created: 23/09/2023 21:51:08
 * Author : Alfanan02
 */ 
#include <avr/delay.h>
#define udr *(volatile char *)0x2c
#define UCSRA *(volatile char *)0x2b 
#define UCSRB *(volatile char *)0x2a
//#define UCSRC
#define UBRRL *(volatile char *)0x29

#define PORTB *(volatile char *) 0x38
#define DDRB *(volatile char *) 0x37
#define PINB *(volatile char *) 0x36
#define PORTD *(volatile char *) 0x35
#define DDRD *(volatile char *) 0x34
char get_key()
{
	for(int i=0;i<=3;i++)
	{
		_delay_ms(10);
		PORTB=0;
		PORTB |=1<<i;
	
		for(int j=0;j<=3;j++)
		{	
			if(PINB & (1<<j<<4)){
			while(PINB & (1<<j<<4));
			switch(i){
			case 0 :
			if(j==0 ) return '7';
			else if(j==1 ) return '8';
			else if(j==2 ) return '9';
			else if(j==3 ) return '/';
			break;
			
			case 1 :
			if(j==0 ) return '4';
			else if(j==1 ) return '5';
			else if(j==2 ) return '6';
			else if(j==3 ) return '*';
			break;
			
			case 2 :
			if(j==0 ) return '1';
			else if(j==1 ) return '2';
			else if(j==2 ) return '3';
			else if(j==3 ) return '-';
			break;
			
			case 3 :
			if(j==0 ) return 'c';
			else if(j==1 ) return '0';
			else if(j==2 ) return '=';
			else if(j==3 ) return '+';
			break;
			}
		}
		}
	}
	return 'N';
	
}



void init()
{
	UBRRL=51;
	UCSRB|=1<<3 | 1<<4;
}
void send (char text)
{
	while(! (UCSRA & 1<<5));
	udr = text;
}

char rec ()
{
	while(! (UCSRA & 1<<7));
	return udr;
}

int main(void)
{
	DDRB=0x0f;
	DDRD=0XFF;
   init();
   char x;
    while (1) 
    {
		x=get_key();
		switch(x)
		{
			case 'N': break;
			case  'c' :x=rec();PORTD=x-48;break;
			default: send(x);break;
		}
		
		
    }
}

