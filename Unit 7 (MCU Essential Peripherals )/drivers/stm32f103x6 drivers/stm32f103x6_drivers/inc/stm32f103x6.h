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
	volatile unsigned int EMR;
	volatile unsigned int IMR;
	volatile unsigned int RTSR;
	volatile unsigned int FTSR;
	volatile unsigned int SWEIR;
	volatile unsigned int PR;

}EXTI;

/////////////////
// AFIO REGISTERS
/////////////////
typedef struct
{
	volatile unsigned int EVCR;
	volatile unsigned int MAPR;
	volatile unsigned int EXTICR1;
	volatile unsigned int EXTICR2;
	volatile unsigned int EXTICR3;
	volatile unsigned int EXTICR4;
	volatile unsigned int RESRVED0;
	volatile unsigned int MAPR2;

}AFIO;
//=========================================================


/////////////////
// PERIPHRALS INSTANS
/////////////////

#define GPIOA 			 (GPIO *)GPIO_PORTA_BASE
#define GPIOB 			 (GPIO *)GPIOB_BASE
#define GPIOC 			 (GPIO *)GPIOC_BASE
#define GPIOD 			 (GPIO *)GPIOD_BASE
#define GPIOE  		     (GPIO *)GPIOE_BASE
#define EXTI_config  	 (EXTI *)EXTI_BASE
#define AFIO_CONFIG 	 (AFIO *)AFIO_BASE
#define RCC_config  	 ((RCC *) RCC_BASE)


#define RCC_GPIOA_CLK_EN (RCC_config->APB2NENR|=1<<2)
#define RCC_GPIOB_CLK_EN (RCC_config->APB2NENR|=1<<3)
#define RCC_GPIOC_CLK_EN (RCC_config->APB2NENR|=1<<4)
#define RCC_GPIOD_CLK_EN (RCC_config->APB2NENR|=1<<5)
#define RCC_GPIOE_CLK_EN (RCC_config->APB2NENR|=1<<6)
#define AFIO_CLK_EN 	 (RCC_config->APB2NENR|=1<<0)
#endif /* INC_STM32F103X6_H_ */
