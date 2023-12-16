#include "uart.h"

//generic variables
usart_user_config * g_usart_config=NULL;


////functions
void mcal_usart_init(usart_t * usart_reg,usart_user_config *usart_config)
{
	g_usart_config=usart_config;
	//enable clocks
	if(usart_reg == USART_1) 			USART_1_CLK_EN;
	else if(usart_reg == USART_2) 	USART_2_CLK_EN;
	else if(usart_reg == USART_3) 	USART_3_CLK_EN;
	//enable uart module
	usart_reg->USART_CR1|=1<<13;
	//enable tx or rx
	usart_reg->USART_CR1|=usart_config->mode;
	//payload wedth
	usart_reg->USART_CR1|=usart_config->payload_lenght;
	//parity bits
	usart_reg->USART_CR1|=usart_config->parity_bits;
	//stop bits
	usart_reg->USART_CR2|=usart_config->sop_bits;
	//baud rate
	uint32_t p_clk,brr;
	if(usart_reg == USART_1) 			p_clk=mcal_rcc_get_pclk2();
	else p_clk=mcal_rcc_get_pclk1();

	brr=UART_BRR_VALUE(p_clk,usart_config->baud_rate);
	usart_reg->USART_BRR=brr;

}
//void mcal_usart_deinit(usart_t * usart_reg)
//{
//
//}
void mcal_gpio_set_bins_uart(usart_t * usart_reg)
{
	gpio_config pin_conf;
	if(usart_reg == USART_1)
	{
		pin_conf.gpio_pin_number=GPIO_PIN_9;
		pin_conf.gpio_mode=GPIO_MODE_OUTPUT_AF_PP;
		pin_conf.gpio_speed=max_speed_10;
		mcal_gpio_init(GPIOA,&pin_conf );

		pin_conf.gpio_pin_number=GPIO_PIN_10;
		pin_conf.gpio_mode=GPIO_MODE_AF_INPUT;

		mcal_gpio_init(GPIOA,&pin_conf );
	}

	if(usart_reg == USART_2)
		{
			pin_conf.gpio_pin_number=GPIO_PIN_2;
			pin_conf.gpio_mode=GPIO_MODE_OUTPUT_AF_PP;
			pin_conf.gpio_speed=max_speed_10;
			mcal_gpio_init(GPIOA,&pin_conf );

			pin_conf.gpio_pin_number=GPIO_PIN_3;
			pin_conf.gpio_mode=GPIO_MODE_AF_INPUT;

			mcal_gpio_init(GPIOA,&pin_conf );
		}

	if(usart_reg == USART_3)
		{
			pin_conf.gpio_pin_number=GPIO_PIN_10;
			pin_conf.gpio_mode=GPIO_MODE_OUTPUT_AF_PP;
			pin_conf.gpio_speed=max_speed_10;
			mcal_gpio_init(GPIOB,&pin_conf );

			pin_conf.gpio_pin_number=GPIO_PIN_11;
			pin_conf.gpio_mode=GPIO_MODE_AF_INPUT;

			mcal_gpio_init(GPIOB,&pin_conf );
		}
}
void mcal_send_data(usart_t * usart_reg,uint16_t *data,uint8_t polling_mech)
{
	if(polling_mech==1)
		while(!(usart_reg->USART_SR & 1<<7));
	if(g_usart_config->parity_bits == payload_9)
		usart_reg->USART_DR=(*data & 0x01ff);
	else
		usart_reg->USART_DR=(*data & 0xff);
}
void mcal_rec_data(usart_t * usart_reg,uint16_t *data,uint8_t polling_mech)
{
	if(polling_mech == 1)
		while(!(usart_reg->USART_DR & 1<<5));
	if(g_usart_config->payload_lenght ==  payload_9)
	{
		if(g_usart_config->parity_bits == none_parity)
			*data=usart_reg->USART_DR;
		else
			*data=usart_reg->USART_DR & 0xff;

	}
	else
	{
		if(g_usart_config->payload_lenght ==  payload_9)
		{
			if(g_usart_config->parity_bits == none_parity)
				*data=usart_reg->USART_DR;
			else
				*data=usart_reg->USART_DR & 0x7f;
		}
	}
}
