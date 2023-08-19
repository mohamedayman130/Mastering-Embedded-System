
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>
#include <stdint.h>

#define PORTA_BASE 	0x40010800
#define GPIOA_CRH		*(volatile int*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile int*)(PORTA_BASE + 0x0c)
#define RCC_Base 	0x40021000
#define RCC_APB2ENR *(volatile int *)( RCC_Base +0x18)
#define RCC_CFGR *(volatile int *)( RCC_Base +0x04)

int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	RCC_CFGR |=0b101<<11;
	RCC_CFGR |=0b100<<8;
	while(1){
		GPIOA_ODR |= 1<<13;
		for(int i =0 ; i<3000 ; i++);
		GPIOA_ODR &= ~(1<<13);
		for(int i =0 ; i<3000 ; i++);
	}
	return 0;
}
