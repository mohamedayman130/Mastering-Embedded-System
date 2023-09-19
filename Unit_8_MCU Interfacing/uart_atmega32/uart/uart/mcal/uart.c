#include "uart.h"
void uart_init()
{
	UBRRL=51;
	UCSRB|=1<<3;
	UCSRB|=1<<4;
}
void uart_Send(char x)
{
	while(!(UCSRA & (1<<5) ));
	UDR = x;
}

char uart_rec()
{
	while(!(UCSRA & (1<<7)));
	return UDR;
}

void uart_rec_string()
{
	char i=0;
	while(i<150)
	{
		string[i]=uart_rec();
		if(string[i]==13) break;//if press enter string will send
		i++;
	}
	string[i]=0;
	LCD_WRITE_STRING(string);
	
}


void uart_send_string(char * text)
{
	while(*text!=0)
	uart_Send(*text++);
}
