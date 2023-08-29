
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include <stdio.h>

//GPIO
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define GPIOA_CRL *(volatile int *)(GPIOA_BASE + 0X00)
#define GPIOA_CRH *(volatile int *)(GPIOA_BASE + 0X04)
#define GPIOA_IDR *(volatile int *)(GPIOA_BASE + 0X08)
#define GPIOB_CRL *(volatile int *)(GPIOB_BASE + 0X00)
#define GPIOB_CRH *(volatile int *)(GPIOB_BASE + 0X04)
#define GPIOB_ODR *(volatile int *)(GPIOB_BASE + 0X0c)


//RCC
#define RCC_BASE  0x40021000
#define RCC_APB2ENR *(volatile int *)(RCC_BASE + 0x18)


void CLOCK_INIT()
{
	RCC_APB2ENR |=3<<2;
}

void GPIO_INIT()
{
	GPIOA_CRH=0;
	GPIOA_CRL=0;
	GPIOB_CRH=0;
	GPIOB_CRL=0;

	GPIOA_CRL|=4<<4;
	GPIOA_CRH|=4<<20;

	GPIOB_CRH|=1<<20;
	GPIOB_CRL|=1<<4;
}
void wait_ms(int time){
	 int i, j;
	for(i = 0; i< time ; i++)
		for(j = 0; j < 255 ; j++);
}


int main(void)
{
	CLOCK_INIT();
	GPIO_INIT();


	while(1){
		if( (GPIOA_IDR & 1<<1) !=0 )
			GPIOB_ODR^=1<<1;
			while((GPIOA_IDR & 1<<1));
		if((GPIOA_IDR & 1<<13) !=0)
			GPIOB_ODR^=1<<13;
		wait_ms(300);
	}

	return 0;
}






