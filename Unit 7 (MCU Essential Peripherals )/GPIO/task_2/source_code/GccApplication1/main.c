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
#define GPIOA_PIN *(volatile int *)(GPIO_BASE + 0X19)

void GPIO_INIT()
{
	GPIOA_DDR|=0x7f;;//set porta as an output
}

void wait(int x)
{
	
	for(int i=0;i<=x;i++)
	for(int y=0;y<=500;y++);
}
int main(void)
{
   GPIO_INIT();
   int i=-1,k=-1;
    while(1)
    {
		if( (GPIOA_PIN & 1<<7) !=0 )
		{
			while(GPIOA_PIN & 1<<7);
		if(k<6)
		     {
				    k++;i++;
			 GPIOA_PORT|=1<<i;
			 }
		else if(k>=6 && k<13)
		     {
			GPIOA_PORT&=~(1<<i);
			k++;i--;
			if(k==13) k=-1;
		     }
		 
			
		}
		
	}

}