#include<stdio.h>
#include"stm32f103x6.h"
#include"stm32f103x6_gpio_driver.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void clk_init()
{

		RCC_GPIOA_CLK_EN;
		RCC_GPIOB_CLK_EN;
}
void gpio_init()
{
	gpio_config pin_config;
	//set pin_1 port_a as a pull up input
	pin_config.gpio_pin_number=GPIO_PIN_1;
	pin_config.gpio_mode=GPIO_MODE_INPUT_PU;
	mcal_gpio_init(GPIOA, &pin_config);
	//set pin_13 port_a as a pull down input
	pin_config.gpio_pin_number=GPIO_PIN_13;
	pin_config.gpio_mode=GPIO_MODE_INPUT_PD;
	mcal_gpio_init(GPIOA, &pin_config);
	//set pin_13 port_b as a push_pull output
	pin_config.gpio_pin_number=GPIO_PIN_13;
	pin_config.gpio_mode=GPIO_MODE_OUTPUT_PP;
	pin_config.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOB, &pin_config);
	//set pin_1 port_b as a push_pull output
	pin_config.gpio_pin_number=GPIO_PIN_1;
	pin_config.gpio_mode=GPIO_MODE_OUTPUT_PP;
	pin_config.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOB, &pin_config);



}
int main(void)
{

	clk_init();
	gpio_init();
	for(;;)
	{
		if(mcal_gpio_read_pin(GPIOA, GPIO_PIN_1)==0)
			{
			while(!mcal_gpio_read_pin(GPIOA, GPIO_PIN_1));
			mcal_gpio_toggle_pin(GPIOB, GPIO_PIN_1);
			}
		if(mcal_gpio_read_pin(GPIOA, GPIO_PIN_13)==1)
					{
					mcal_gpio_toggle_pin(GPIOB, GPIO_PIN_13);
					}
for(int i=0;i<=50000;i++);
	}
}
