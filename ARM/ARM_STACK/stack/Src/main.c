/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Ayman
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include"inc/rcc.h"
#include"inc/exti_driver.h"
#include"inc/stm32f103x6.h"
#include"inc/stm32f103x6_gpio_driver.h"

#define os_set_psp(add) __asm("mov r0,%0 \n\r msr psp,r0" : : "r" (add))
#define os_switch_sp_to_psp __asm("mrs r0,control \n\t mov r1,#0x02 \n\t orr r0,r1 \n\t msr control,r0")
#define os_switch_sp_to_msp __asm("mrs r0,control \n\t mov r1,#0x05 \n\t and r0,r1 \n\t msr control,r0")

#define os_generate_exception __asm("svc #0x03")


extern unsigned int _estack;
#define taska_stack_size 100
#define taskb_stack_size 100
//msp
unsigned int _s_msp=&_estack;
unsigned int _e_msp;

//psp task a
unsigned int _s_pspa;
unsigned int _e_pspa;
//psp task b
unsigned int _s_pspb;
unsigned int _e_pspb;
//flags
uint8_t taska_flag,taskb_flag,irq_flag;

void SVC_Handler()
{
	//enable privilige mode
	__asm("mrs r3,CONTROL   \n\t"
			"lsr r3,r3,#0x1 \n\t"
			"lsl r3,r3,#0x1 \n\t"
			"msr CONTROL,r3");
}

int taska (int a,int b,int c)
{
	return a+b+c;
}

int taskb (int a,int b,int c,int d )
{
	return a+b+c+d;
}
void main_os()
{
	//main stack
	_e_msp=_s_msp - 512;
	//task a
	_s_pspa = _e_msp - 8;
	_e_pspa = _s_pspa - taska_stack_size ;
	//task b
	_s_pspb = _e_pspa - 8;
	_e_pspb = _s_pspb - taskb_stack_size ;


	while(1)
	{
		__asm("nop");
		if(taska_flag == 1)
		{
			//set psp reg = _s_psp_A
			os_set_psp(_s_pspa);
			//sp-> psp
			os_switch_sp_to_psp;
			//switch from privilege to unprivilege
			__asm("mrs r0,control \n\t"
					"orr r0,#0x01 \n\t"
					"msr control,r0"
			);
			taska_flag=taska(2, 3, 5);
			//switch from unprivilege to privilege
			os_generate_exception;
			////sp-> msp
			os_switch_sp_to_msp;
		}
		else if(taskb_flag == 1)
		{
			//set psp reg = _s_psp_b
			os_set_psp(_s_pspb);
			//sp-> psp
			os_switch_sp_to_psp;
			//switch from privilege to unprivilege
			__asm("mrs r0,control \n\t"
					"orr r0,#0x01 \n\t"
					"msr control,r0"
			);
			taskb_flag=taskb(1, 2, 3, 5);
			//switch from unprivilege to privilege
			os_generate_exception;
			////sp-> msp
			os_switch_sp_to_msp;
		}

	}
}
void irq_fun()
{
	if(irq_flag == 0)
	{
		taska_flag = 1;
		irq_flag = 1 ;
	}
	else if(irq_flag == 1 )
	{
		taskb_flag = 1 ;
		irq_flag = 0;
	}

}

void clk_init()
{

	RCC_GPIOA_CLK_EN;
	RCC_GPIOB_CLK_EN;
	//AFIO_CLK_EN;

}

int main(void)
{
	clk_init();
	//gpio conf
	gpio_config gpio_conf;
	gpio_conf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	gpio_conf.gpio_pin_number=GPIO_PIN_0;
	gpio_conf.gpio_speed=max_speed_2;
	mcal_gpio_init(GPIOB, &gpio_conf);
	//exti config
	exti_pin_conf config;
	config.exti_pin=EXTI0A0;
	config.irq_state=irq_en;
	config.trigger_case=trigger_rising;
	config.irq_call_back=irq_fun;
	mcal_gpio_exti_init(&config);
	mcal_gpio_write_pin(GPIOB, GPIO_PIN_0, 1);

	main_os();

	for(;;);
}
