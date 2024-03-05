/*
 * stm32f103x6_gpio_driver.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Alfanan02
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//////////////////
//includes
/////////////////
#include<stdlib.h>
#include<stdio.h>

/////////////////
//BASE ADDRESSES FOR MEMORY
/////////////////
#define flash_memory 	0x08000000
#define system_memory	0x1ffff000
#define s_ram			0x20000000
#define periphrals_base 0x40000000

/////////////////
//BASE ADDRESSES AHB PERIOHRALES
/////////////////
//RCC
#define RCC_BASE 		0x40021000



/////////////////
//BASE ADDRESSES FOR APB1 PERIPHRALS
/////////////////

////uart
#define usart2_base 0x40004400
#define usart3_base 0x40004800

//spi2

#define SPI2_BASE 0x40003800

/////////////////
//BASE ADDRESSES FOR APB2 PERIPHRALS
/////////////////

//GPIO
 //port a,b fully included
#define GPIO_PORTA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
 //port c,d partially includede
#define GPIOC_BASE 0x40011000
#define GPID_BASE 0x40011400
 //port e not included
#define GPIOE_BASE 0x40011800

//EXTI
#define EXTI_BASE 		0x40010400
//AFIO
#define AFIO_BASE 		0x40010000
//NVIC
#define NVIC_BASE 0xe000e100
#define NVIC_ISER0 *(volatile int *)(NVIC_BASE+0X00)
#define NVIC_ISER1 *(volatile int *)(NVIC_BASE+0X04)
#define NVIC_ISER2 *(volatile int *)(NVIC_BASE+0X08)

#define NVIC_ICER0 *(volatile int *)(NVIC_BASE+0X80)
#define NVIC_ICER1 *(volatile int *)(NVIC_BASE+0X84)
#define NVIC_ICER2 *(volatile int *)(NVIC_BASE+0X88)



////uart
#define usart1_base 0x40013800


//spi
#define SPI1_BASE  0x40013000

//=========================================================

/////////////////
// GPIO REGISTERS
/////////////////
typedef struct
{
	volatile unsigned int CRL;
	volatile unsigned int CRH;
	volatile unsigned int IDR;
	volatile unsigned int ODR;
	volatile unsigned int PSRR;
	volatile unsigned int PRR;
	volatile unsigned int LOCK;

}GPIO;


/////////////////
// RCC REGISTERS
/////////////////
typedef struct
{
	volatile unsigned int CR;
	volatile unsigned int CFGR;
	volatile unsigned int CIR;
	volatile unsigned int APB2RSTR;
	volatile unsigned int APB1RSTR;
	volatile unsigned int AHBENR;
	volatile unsigned int APB2NENR;
	volatile unsigned int APB1NENR;
	volatile unsigned int BDCR;
	volatile unsigned int CSR;

}RCC;


/////////////////
// EXTI REGISTERS
/////////////////
typedef struct
{
	volatile unsigned int IMR;
	volatile unsigned int EMR;
	volatile unsigned int RTSR;
	volatile unsigned int FTSR;
	volatile unsigned int SWEIR;
	volatile unsigned int PR;

}EXTI_t;



////////////////////
//SPI REGISTERS
///////////////////
typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI;


/////////////////
// AFIO REGISTERS
/////////////////
typedef struct
{
	volatile unsigned int EVCR;
	volatile unsigned int MAPR;
	volatile unsigned int EXTICR[4];
	volatile unsigned int RESRVED0;
	volatile unsigned int MAPR2;

}AFIO;


/////////////////
// USART REGISTERS
/////////////////

typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}usart_t;
//=========================================================


/////////////////
// PERIPHRALS INSTANS
/////////////////

///SPI
#define SPI1  ( (SPI *) SPI1_BASE)
#define SPI2  ( (SPI *) SPI2_BASE)


#define GPIOA 			 (GPIO *)GPIO_PORTA_BASE
#define GPIOB 			 (GPIO *)GPIOB_BASE
#define GPIOC 			 (GPIO *)GPIOC_BASE
#define GPIOD 			 (GPIO *)GPIOD_BASE
#define GPIOE  		     (GPIO *)GPIOE_BASE
#define EXTI_macros 	 ((EXTI_t *)EXTI_BASE)
#define AFIO_CONFIG 	 ((AFIO *)AFIO_BASE)
#define RCC_config  	 ((RCC *) RCC_BASE)

///clk
#define RCC_GPIOA_CLK_EN (RCC_config->APB2NENR|=1<<2)
#define RCC_GPIOB_CLK_EN (RCC_config->APB2NENR|=1<<3)
#define RCC_GPIOC_CLK_EN (RCC_config->APB2NENR|=1<<4)
#define RCC_GPIOD_CLK_EN (RCC_config->APB2NENR|=1<<5)
#define RCC_GPIOE_CLK_EN (RCC_config->APB2NENR|=1<<6)
#define AFIO_CLK_EN 	 (RCC_config->APB2NENR|=1<<0)

/////usart
#define USART_1 (usart_t *)usart1_base
#define USART_2 (usart_t *)usart2_base
#define USART_3 (usart_t *)usart3_base
//usart clk
#define USART_1_CLK_EN 	 (RCC_config->APB2NENR|=1<<14)
#define USART_2_CLK_EN 	 (RCC_config->APB1NENR|=1<<17)
#define USART_3_CLK_EN 	 (RCC_config->APB1NENR|=1<<18)
//reset
#define USART_1_CLK_reset 	 (RCC_config->APB2RSTR|=1<<14)
#define USART_2_CLK_reset 	 (RCC_config->APB1RSTR|=1<<17)
#define USART_3_CLK_reset 	 (RCC_config->APB1RSTR|=1<<18)
//SPI CLK
#define SPI1_CLK (RCC_config->APB2RSTR|=1<<12)
#define SPI2_CLK (RCC_config->APB1RSTR|=1<<14)

///EXTI

#define exti0_irq 6
#define exti1_irq 7
#define exti2_irq 8
#define exti3_irq 9
#define exti4_irq 10
#define exti5_irq 23
#define exti6_irq 23
#define exti7_irq 23
#define exti8_irq 23
#define exti9_irq 23
#define exti10_irq 40
#define exti11_irq 40
#define exti12_irq 40
#define exti13_irq 40
#define exti14_irq 40
#define exti15_irq 40
//USART IRQ
#define usart_1_iqr 37
#define usart_2_iqr 38
#define usart_3_iqr 39
//SPI IRQ
#define SPI1_IRQ 35
#define SPI2_IRQ 36

//ENABLE@DISABLE NVIC
//exti
#define NVIC_IRQ6_EXTI0_EN 			(NVIC_ISER0|=1<<6)
#define NVIC_IRQ7_EXTI1_EN 			(NVIC_ISER0|=1<<7)
#define NVIC_IRQ8_EXTI2_EN 			(NVIC_ISER0|=1<<8)
#define NVIC_IRQ9_EXTI3_EN 			(NVIC_ISER0|=1<<9)
#define NVIC_IRQ10_EXTI4_EN			(NVIC_ISER0|=1<<10)
#define NVIC_IRQ23_EXTI5_9_EN 		(NVIC_ISER0|=1<<23)
#define NVIC_IRQ40_EXTI_10_15_EN	(NVIC_ISER1|=1<<8)

#define NVIC_IRQ6_EXTI0_dis			 (NVIC_ICER0|=1<<6)
#define NVIC_IRQ7_EXTI1_dis			 (NVIC_ICER0|=1<<7)
#define NVIC_IRQ8_EXTI2_dis			 (NVIC_ICER0|=1<<8)
#define NVIC_IRQ9_EXTI3_dis			 (NVIC_ICER0|=1<<9)
#define NVIC_IRQ10_EXTI4_dis		 (NVIC_ICER0|=1<<10)
#define NVIC_IRQ23_EXTI5_9_dis 		 (NVIC_ICER0|=1<<23)
#define NVIC_IRQ40_EXTI_10_15_dis 	 (NVIC_ICER1 |=1<<8)
//usart
#define NVIC_IRQ37_USART1_DIS		(NVIC_ICER1|=1<<5)
#define NVIC_IRQ38_USART2_DIS		(NVIC_ICER1|=1<<6)
#define NVIC_IRQ39_USART3_DIS		(NVIC_ICER1|=1<<7)
#define NVIC_IRQ37_USART1_EN		(NVIC_ISER1|=1<<5)
#define NVIC_IRQ38_USART2_EN		(NVIC_ISER1|=1<<6)
#define NVIC_IRQ39_USART3_EN		(NVIC_ISER1|=1<<7)
//SPI
#define NVIC_IRQ35_SPI1_DIS		(NVIC_ICER1|=1<<3)
#define NVIC_IRQ36_SPI2_DIS		(NVIC_ICER1|=1<<4)
#define NVIC_IRQ35_SPI1_EN		(NVIC_ISER1|=1<<3)
#define NVIC_IRQ36_SPI2_EN		(NVIC_ISER1|=1<<4)

#endif /* INC_STM32F103X6_H_ */
