
#include <avr/delay.h>
#include "lcd.h"

//uart 
#define udr *(volatile char *)0x2c
#define UCSRA *(volatile char *)0x2b 
#define UCSRB *(volatile char *)0x2a
#define UBRRL *(volatile char *)0x29
//gpio
#define PORTB *(volatile char *) 0x38
#define DDRB *(volatile char *) 0x37
#define PINB *(volatile char *) 0x36
#define PORTC *(volatile char *) 0x35
#define DDRC *(volatile char *) 0x34
#define PORTA *(volatile char *) 0x3b
#define DDRA *(volatile char *) 0x3a
#define DDRD *(volatile char *) 0x31


//interrupt
#define MCUCR *(volatile char *)(0x55)
#define GICR *(volatile char *)(0x5b)
#define GIFR *(volatile char *)(0x5a)
#define SREG *(volatile char *)(0x5f)


void uart_init()
{
	UBRRL=51;
	UCSRB|=1<<3 | 1<<4 | 1<<7 ;
}

char str[100];

void rec_str(char x)
{
	static char i=0;
	if(x==13) {LCD_WRITE_COMMAND(0x01);str[i]=0;i=0;LCD_WRITE_STRING(str);send_str(str);}
	else {str[i++]=x;PORTC=x;}
}


void send_str(char* text)
{
	while(*text!=0)
	{
	if((UCSRA & 1<<5))
	udr = *text++;
	}
}
	
void intr_init()
{
	SREG|=1<<7;
}
int main(void)
{
	
	intr_init();
	DDRB=0x0f;
	DDRC=0XFF;
   uart_init();
   LCD_INIT();
   send_str("mohamed ayman");
char i=0;
    while (1) 
    {
		
		PORTA=i++;
		if(i==10) i=0;
		_delay_ms(500);  
    }
}



void __vector_13(void)__attribute__((signal,used));
void __vector_13(void)
{
	rec_str(udr);
}