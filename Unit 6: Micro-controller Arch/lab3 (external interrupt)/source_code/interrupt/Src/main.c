
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>
//GPIO
#define PORTA_BASE 0x40010800
#define GPIOA_CRH *(volatile int *)(PORTA_BASE+0x04)
#define GPIOA_ODR *(volatile int *)(PORTA_BASE+0x0C)
//RCC
#define RCC_Base 	0x40021000
#define RCC_APB2ENR *(volatile int*)( RCC_Base +0x18)
//#define RCC_CFGR *(volatile int *)(RCC_Base + 0X04)

//EXTI
#define EXTI 0x40010400
#define EXTI_IMR *(volatile int *)(EXTI + 0X00)
#define EXTI_RTSR *(volatile int *)(EXTI + 0X08)
#define EXTI_PR *(volatile int *)(EXTI + 0X14)
//AFIO
#define AFIO_BASE 0x40010000
#define  AFIO_EXTICR4 *(volatile int *)(AFIO_BASE + 0X14)

#define NVIC_EXTI *(volatile int *)(0xE000E100)

int main(void)
{
	RCC_APB2ENR |= 1<<2;//PORTA SET CLOCK
	RCC_APB2ENR |= 1<<0;//AFIO set clock
	GPIOA_CRH |=0x20200004;//GPIO a15,a3  AS OUTPUT a0 as input

	//SET GPIO0 AS EXTERNAL INTERRUPT
	EXTI_IMR |=1<<0;//SET INTERRUPT MASK REGISTER
	EXTI_RTSR |=1<<0;//SET RISING EDGE
	AFIO_EXTICR4 &=~(0B0000<<8);//MAPPING GPIO PORT A
	NVIC_EXTI |=1<<6;

	while(1)
	{
    //toggle bit 13
		GPIOA_ODR |=(1<<13);
		for(int i=0;i<=3000000;i++);
		GPIOA_ODR &=~(1<<13);
			for(int i=0;i<=3000000;i++);
	}
	return 0;
}

void EXTI0_IRQHandler ()
{
	GPIOA_ODR ^=(1<<15);
	EXTI_PR |=1<<0;
}





