/*
 * GccApplication1.c
 *
 * Created: 29/08/2023 23:27:56
 * Author : Alfanan02
 */ 

#include<stdio.h>
///GPIO
#define GPIO_BASE 0x20
#define GPIOA_DDR *(volatile int *)(GPIO_BASE + 0X1A)
#define GPIOA_PORT *(volatile int *)(GPIO_BASE + 0X1B)


void GPIO_INIT()
{
	GPIOA_DDR|=0xff;;//set porta as an output
}

void wait(int x)
{
	
	for(int i=0;i<=x;i++)
	for(int y=0;y<=500;y++);
}
int main(void)
{
   GPIO_INIT();
   int i=1;
    while(1)
    {
		while(i<(1<<7))
		{
			GPIOA_PORT|=i;
		wait(30);i<<=1;}
		wait(70);
		while(i>=1)
		{
			GPIOA_PORT&=~i;
			wait(30);i>>=1;}
			i=1;
		
}
}