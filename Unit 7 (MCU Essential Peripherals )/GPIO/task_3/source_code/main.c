/*
 * GccApplication1.c
 *
 * Created: 30/08/2023 23:32:15
 * Author : Alfanan02
 */ 

#include <stdio.h>
#define GPIO_BASE 0x20
#define GPIO_PORTC *(volatile int *)(GPIO_BASE +0X15 )
//#define GPIOC_PIN *(volatile int *)(GPIO_BASE +0X19 )
#define GPIO_DDRC *(volatile int *)(GPIO_BASE +0X14 )

//PORTD
#define GPIO_PORTD *(volatile int *)(GPIO_BASE +0X12)
#define GPIO_PIND *(volatile int *)(GPIO_BASE +0X10 )
#define GPIO_DDRD *(volatile int *)(GPIO_BASE +0X11 )
// int sev_seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	 
	 void wait(int x)
	 {
		 
		 for (int i=0;i<=x;i++)
		 {
			 for(int j=0;j<=500;j++);
		 }
	 }
int main(void)
{
    GPIO_DDRD|=0b1111 <<4;
	GPIO_DDRD&=~(0B111<<0);
	int i=4,k=0;
    while (1) 
    {
		if( (GPIO_PIND & 1<<0) !=0 )
		{
			while(GPIO_PIND & 1<<0);
			if(k<3)
			{
				k++;i++;
				GPIO_PORTD|=1<<i;
			}
			else if(k>=3)
			{
				GPIO_PORTD&=~(1<<i);
				k++;i--;
				if(k==6) k=0;
			}
		
	}
	}
}

