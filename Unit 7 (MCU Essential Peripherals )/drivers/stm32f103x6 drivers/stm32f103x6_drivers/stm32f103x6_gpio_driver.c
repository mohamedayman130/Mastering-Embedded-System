/*
 * stm32f103x6_gpio_driver.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Alfanan02
 */
#include "stm32f103x6_gpio_driver.h"
short get_pos(short pin_number)
{
	switch(pin_number)
	{
	case GPIO_PIN_0 : return 0;break;
	case GPIO_PIN_1 : return 1;break;
	case GPIO_PIN_2 : return 2;break;
	case GPIO_PIN_3 : return 3;break;
	case GPIO_PIN_4 : return 4;break;
	case GPIO_PIN_5 : return 5;break;
	case GPIO_PIN_6 : return 6;break;
	case GPIO_PIN_7 : return 7;break;
	case GPIO_PIN_8 : return 0;break;
	case GPIO_PIN_9 : return 1;break;
	case GPIO_PIN_10 : return 2;break;
	case GPIO_PIN_11 : return 3;break;
	case GPIO_PIN_12 : return 4;break;
	case GPIO_PIN_13: return 5;break;
	case GPIO_PIN_14 : return 6;break;
	case GPIO_PIN_15 : return 7;break;


	}
return 0;
}

//name:mcal_gpio_init
//brief:intialize pins
//param[in]:gpiox: to select port and pin
//param[in]:config:to config pin
//
void mcal_gpio_init(GPIO *gpiox,gpio_config *config)
{
	short PIN_config;
	volatile unsigned int *config_reg=NULL;
	config_reg=(config->gpio_pin_number<GPIO_PIN_8)?&gpiox->CRL:&gpiox->CRH;
	(*config_reg)&=~(0xf<<(get_pos(config->gpio_pin_number)*4));

	if( config->gpio_mode==GPIO_MODE_OUTPUT_AF_OD ||config->gpio_mode==GPIO_MODE_OUTPUT_AF_PP||config->gpio_mode== GPIO_MODE_OUTPUT_OD||config->gpio_mode==GPIO_MODE_OUTPUT_PP)
		{PIN_config = ((config->gpio_mode - 4)<<2 ) | ((config->gpio_speed) & (0X0F));}


	else
	{
		if(config->gpio_mode==GPIO_MODE_ANALOG ||config->gpio_mode==GPIO_MODE_INPUT_FLO)
		{
			PIN_config=config->gpio_mode<<2;

		}
		else if(config->gpio_mode== GPIO_MODE_AF_INPUT)
		{
			PIN_config=GPIO_MODE_INPUT_FLO<<2;
		}
		else
		{

			PIN_config=GPIO_MODE_INPUT_PU<<2;
			if(config->gpio_mode == GPIO_MODE_INPUT_PU)
			{
				gpiox->ODR|=(config->gpio_pin_number);

			}
			else if(config->gpio_mode == GPIO_MODE_INPUT_PD)
			{
				gpiox->ODR&=~(config->gpio_pin_number);
			}

		}


	}


	*config_reg|=(PIN_config<<(get_pos(config->gpio_pin_number)*4));
}






//name:mcal_gpio_deinit
//brief:deintialize pins(reset pins)
//param[in]:gpiox: to select port and pin
//
void mcal_gpio_deinit(GPIO *gpiox)
{
gpiox->CRH= 0x44444444;
gpiox->CRL=0x44444444;
//gpiox->IDR=; read only
gpiox->LOCK=0x0000000;
gpiox->ODR=0x00000000;
gpiox->PRR=0x00000000;
gpiox->PSRR=0x00000000;
}


//name:mcal_gpio_read
//brief:read pins data
//param[in]:gpiox: to select port and pin
//param[in]:pin_number
//param[out]:pin status
char mcal_gpio_read_pin(GPIO *gpiox,unsigned short pin_number)
{
	short bit_status;
	if( (gpiox->IDR & pin_number) !=0)
	{
		bit_status=1;
	}
	else
		bit_status=0;
	return bit_status;
}



//name:mcal_gpio_read
//brief:read port data
//param[in]:gpiox: to select port and pin
//param[out]:port status
short mcal_gpio_read_port(GPIO *gpiox)
{
	int port_status;
	port_status=gpiox->IDR;
	return port_status;
}


void mcal_gpio_write_pin(GPIO *gpiox,unsigned short pin_number,char val)
{
		if(val!=0)
			gpiox->ODR|=pin_number;
		else
			gpiox->ODR&=~pin_number;
}
void mcal_gpio_write_port(GPIO *gpiox,unsigned short val)
{
	gpiox->ODR=val;
}


void mcal_gpio_toggle_pin(GPIO *gpiox,unsigned short pin_number)
{
	gpiox->ODR^=pin_number;
}

