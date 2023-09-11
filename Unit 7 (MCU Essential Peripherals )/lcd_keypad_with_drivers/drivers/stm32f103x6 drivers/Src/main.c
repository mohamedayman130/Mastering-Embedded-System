#include<stdio.h>
#include"stm32f103x6.h"
#include"stm32f103x6_gpio_driver.h"
#include"lcd.h"
#include"keypad.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void clk_init()
{
	RCC_GPIOA_CLK_EN;
	RCC_GPIOB_CLK_EN;
}


void segment_init()
{
	gpio_config segment_cnf;

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_8;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_9;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_10;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_11;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_12;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_13;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

	segment_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	segment_cnf.gpio_pin_number=GPIO_PIN_14;
	segment_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(GPIOA, &segment_cnf);

}
int main(void)
{

	clk_init();
	segment_init();
	LCD_INIT();
	lcd_write_string("      hello");
	delay_ms(500);
	lcd_write_command(lcd_clear_display);
	unsigned short segment[]={0x01,0x4f,0x12,0x06,0x4c,0x24,0x20,0x0f,0x00,0x04};
	for(int i=0;i<10;i++)
	{
		lcd_write_char(i+48);
		mcal_gpio_write_port(GPIOA, segment[i]<<8);
		delay(200);
		delay(200);
	}
	mcal_gpio_write_port(GPIOA,segment[8]<<8);
	lcd_write_command(lcd_clear_display);
	lcd_write_string("keypad is ready!! ");
	delay_ms(500);
	lcd_write_command(lcd_clear_display);
	keypad_init();
	char x;

	while(1)
	{

		x=keypad_get_char();
		switch(x)
		{
		case 'N': break;
		default :lcd_write_char(x);
		}
		delay(20);


	}
}
