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

#define GPIOB_DDR *(volatile int *)(GPIO_BASE + 0X17)
#define GPIOB_PIN *(volatile int *)(GPIO_BASE + 0X16)

void GPIO_INIT()
{
	GPIOA_DDR|=3<<0;//set pin A0 and A1 as an output
	GPIOB_DDR&=~(3<<0);//set pin B0 and B1 as an input
	
}

void wait(int x)
{
	
	for(int i=0;i<=x;i++)
	for(int y=0;y<=500;y++);
}
int main(void)
{
   GPIO_INIT();
    while (1) 
    {
		if( (GPIOB_PIN & 1<<0) !=0 )
		GPIOA_PORT^=1<<0;
		while(GPIOB_PIN & (1<<0));
		
		if( (GPIOB_PIN & 1<<1) !=0 )
		GPIOA_PORT^=1<<1;
		wait(10);
    }
}

