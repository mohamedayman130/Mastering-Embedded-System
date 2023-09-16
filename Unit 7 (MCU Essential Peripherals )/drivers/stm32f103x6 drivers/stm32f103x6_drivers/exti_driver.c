/*
 * EXTI.C
 *
 *  Created on: 13 Sep 2023
 *      Author: Alfanan02
 */
#include "EXTI_dRIVER.h"


///////////generic variables

void (* g_irq_call_back[15] )(void);

///////////generic mcaros

#define afio_gpio_exti_mapping(x)(  (x==GPIOA)?0:\
									(x==GPIOB)?1:\
									(x==GPIOC)?2:\
									(x==GPIOC)?3:0)




///////////////generic functions


void en_nvic(uint16_t irq)
{
	switch(irq)
	{
	case 0:NVIC_IRQ6_EXTI0_EN;break;
	case 1:NVIC_IRQ7_EXTI1_EN;break;
	case 2:NVIC_IRQ8_EXTI2_EN;break;
	case 3:NVIC_IRQ9_EXTI3_EN;break;
	case 4:NVIC_IRQ10_EXTI4_EN;break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:NVIC_IRQ23_EXTI5_9_EN;break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:NVIC_IRQ40_EXTI_10_15_EN;break;

	}
}

void dis_nvic(uint16_t irq)
{
	switch(irq)
		{
		case 0:NVIC_IRQ6_EXTI0_dis;break;
		case 1:NVIC_IRQ7_EXTI1_dis;break;
		case 2:NVIC_IRQ8_EXTI2_dis;break;
		case 3:NVIC_IRQ9_EXTI3_dis;break;
		case 4:NVIC_IRQ10_EXTI4_dis;break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:NVIC_IRQ23_EXTI5_9_dis;break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:NVIC_IRQ40_EXTI_10_15_dis;break;

		}
}



//name:mcal_gpio_exti_init
//brief:intialize exti pins
//param[in]:exti_pin conf to confige pin
//


//name:mcal_gpio_exti_deinit
//brief:reset pins
//

void mcal_gpio_exti_deinit(void)
{
	EXTI_macros->EMR=0;
	EXTI_macros->FTSR=0;
	EXTI_macros->IMR=0;
	EXTI_macros->PR=0xffffffff;
	EXTI_macros->RTSR=0;
	EXTI_macros->SWEIR=0;
	//disable exi irq from nvic

	NVIC_IRQ6_EXTI0_dis;
	NVIC_IRQ7_EXTI1_dis;
	NVIC_IRQ8_EXTI2_dis ;
	NVIC_IRQ9_EXTI3_dis ;
	NVIC_IRQ10_EXTI4_dis ;
	NVIC_IRQ23_EXTI5_9_dis;
	NVIC_IRQ40_EXTI_10_15_dis;
}

//name:mcal_gpio_exti_update
//brief:update exti pins
//param[in]:exti_pin_conf * exti_conf

void update(exti_pin_conf * pin_config)
{
	//config gpio to be floting input
	gpio_config pin;
	pin.gpio_mode=GPIO_MODE_INPUT_FLO;
	pin.gpio_pin_number=pin_config->exti_pin.gpio_pin;
	mcal_gpio_init(pin_config->exti_pin.gpio_port, &pin);

	//update afio to match pin
	////afio index
	uint8_t EXTICR_index=pin_config->exti_pin.exti_line_number/4;
	////afio position
	uint8_t EXTICR_pos=(pin_config->exti_pin.exti_line_number %4)*4;
	//clear 4 bits
	AFIO_CONFIG->EXTICR[EXTICR_index]&=~(0xf<<EXTICR_pos);
	AFIO_CONFIG->EXTICR[EXTICR_index]|= (afio_gpio_exti_mapping(pin_config->exti_pin.gpio_port)<<EXTICR_pos);
	//update rising and falling edge
	EXTI_macros->RTSR&=~(0xf<<pin_config->exti_pin.exti_line_number);
	EXTI_macros->FTSR&=~(0xf<<pin_config->exti_pin.exti_line_number);

	if(pin_config->trigger_case==trigger_rising)
	{
		EXTI_macros->RTSR|=(1<<pin_config->exti_pin.exti_line_number);
	}
	else if(pin_config->trigger_case==trigger_falling)
	{
		EXTI_macros->FTSR|=(1<<pin_config->exti_pin.exti_line_number);
	}
	else if(pin_config->trigger_case==trigger_rising_falling)
	{
		EXTI_macros->RTSR|=(1<<pin_config->exti_pin.exti_line_number);
		EXTI_macros->FTSR|=(1<<pin_config->exti_pin.exti_line_number);
	}

	//update irq
	g_irq_call_back[pin_config->exti_pin.exti_line_number]=pin_config->irq_call_back;
	//enable and disable irq
	if(pin_config->irq_state == irq_en){
	EXTI_macros->IMR|=(1<< pin_config->exti_pin.exti_line_number);
	en_nvic(pin_config->exti_pin.exti_line_number);}
	else{
		EXTI_macros->IMR&=~(1<<pin_config->exti_pin.exti_line_number);
		dis_nvic(pin_config->exti_pin.exti_line_number);}
}


void mcal_gpio_exti_update(exti_pin_conf * exti_conf)
{
	update(exti_conf);
}

void mcal_gpio_exti_init(exti_pin_conf * exti_conf)
{
	update(exti_conf);

}


void EXTI0_IRQHandler (void)
{
	//clear pr reg
	EXTI_macros->PR|=1<<0;
	g_irq_call_back[0]();
}

void EXTI1_IRQHandler (void)
{
	//clear pr reg
	EXTI_macros->PR|=1<<1;
	g_irq_call_back[1]();
}

void EXTI2_IRQHandler (void)
{
	//clear pr reg
	EXTI_macros->PR|=1<<2;
	g_irq_call_back[2]();
}

void EXTI3_IRQHandler (void)
{
	//clear pr reg
	EXTI_macros->PR|=1<<3;
	g_irq_call_back[3]();
}

void EXTI4_IRQHandler (void)
{
	//clear pr reg
	EXTI_macros->PR|=1<<4;
	g_irq_call_back[4]();
}

void EXTI9_5_IRQHandler (void)
{
	if(EXTI_macros->PR & 1<<5){EXTI_macros->PR|=1<<5;g_irq_call_back[5]();}
	if(EXTI_macros->PR & 1<<6){EXTI_macros->PR|=1<<6;g_irq_call_back[6]();}
	if(EXTI_macros->PR & 1<<7){EXTI_macros->PR|=1<<7;g_irq_call_back[7]();}
	if(EXTI_macros->PR & 1<<8){EXTI_macros->PR|=1<<8;g_irq_call_back[7]();}
	if(EXTI_macros->PR & 1<<9){EXTI_macros->PR|=1<<9;g_irq_call_back[9]();}
}

void EXTI15_10_IRQHandler (void)
{
	if(EXTI_macros->PR & 1<<10){EXTI_macros->PR|=1<<10;g_irq_call_back[10]();}
	if(EXTI_macros->PR & 1<<11){EXTI_macros->PR|=1<<11;g_irq_call_back[11]();}
	if(EXTI_macros->PR & 1<<12){EXTI_macros->PR|=1<<12;g_irq_call_back[12]();}
	if(EXTI_macros->PR & 1<<13){EXTI_macros->PR|=1<<13;g_irq_call_back[13]();}
	if(EXTI_macros->PR & 1<<14){EXTI_macros->PR|=1<<14;g_irq_call_back[14]();}
	if(EXTI_macros->PR & 1<<15){EXTI_macros->PR|=1<<15;g_irq_call_back[15]();}
}

