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

int control_reg_val,ipsr_val;

void irq_fun()
{
	mcal_gpio_toggle_pin(GPIOB, GPIO_PIN_0);
	__asm("mrs %0,ipsr"
			  :"=r" (ipsr_val) );
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

	__asm("mrs %0,control"
		  :"=r" (control_reg_val) );
	for(;;);
}
