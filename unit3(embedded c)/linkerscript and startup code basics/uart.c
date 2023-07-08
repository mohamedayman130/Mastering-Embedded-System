#include"uart.h"
#define uartd0 *((volatile int *)(0x101f1000))
void uart0(char *text)
{
	while(*text!='\0')
	{
		uartd0=*text;
		text++;
	}

}