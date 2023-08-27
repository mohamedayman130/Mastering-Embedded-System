//#include <avr/io.h>
#include<stdio.h>
#include<avr/interrupt.h>
#define IO_BASE 0x20
#define IO_PORTA *(volatile int *)(IO_BASE + 0x1B)
#define IO_DDRA *(volatile int *)(IO_BASE + 0x1A)
#define IO_PINA *(volatile int *)(IO_BASE + 0x19)
int main(void)
{
	//intialize pins as output
    IO_DDRA|=1<<0;
	IO_DDRA|=1<<1;
	IO_DDRA|=1<<2;
	IO_DDRA|=1<<3;
	//select rising or falling edge of interrupt
	//for INT0 AND INT1
	MCUCR |=0b1001<<0;
	//FOR INT2
	MCUCSR |=1<<6;
	//enable external pin interrupt
	GICR|=7<<5;
	//enable global interrupt
	SREG |=1<<7;
	
	
    while (1)
    {
		
	    //toggle PORTA3 led
		IO_PORTA |=1<<3;
		for(int i=0;i<=30000;i++);
		IO_PORTA &=~1<<3;
		for(int i=0;i<=30000;i++);
	   	   

    }
}

void __vector_1(void) __attribute__((signal, used));
void __vector_1(void)
{
	
	IO_PORTA |=1<<0;
	for(int i=0;i<=30000;i++);
	IO_PORTA &=~1<<0;
}
void __vector_2(void) __attribute__((signal, used));
void __vector_2(void)
{
	
	IO_PORTA |=1<<1;
	for(int i=0;i<=30000;i++);
	IO_PORTA &=~1<<1;
}
void __vector_3(void) __attribute__((signal, used));
void __vector_3(void)
{
	
	IO_PORTA |=1<<2;
	for(int i=0;i<=30000;i++);
	IO_PORTA &=~1<<2;
}