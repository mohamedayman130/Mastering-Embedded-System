/*
 * uart.h
 *
 *  Created on: 22 Sep 2023
 *      Author: Alfanan02
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f103x6.h"
#include "stm32f103x6_gpio_driver.h"


////config struct

typedef struct
{
	uint8_t   mode;//rx,tx en or dis @ref mode_define
	uint32_t baud_rate; //baud rate @ref baudrate_define
	uint8_t payload_lenght; //select payload @ref payload_define
	uint8_t parity_bits; //select parity @ref parity_define
	uint8_t sop_bits; //number of wtop bits @ref stop bits num

}usart_user_config;



/////ref macros////

////@ref mode_define
#define rx			1<<2
#define tx   		1<<3
#define tx_rx 		(1<<2)|(1<<3)

//@ref baudrate_define

#define baud_rate_7400 	7400
#define baud_rate_9600 	9600
#define baud_rate_19200 19200
#define baud_rate_57600 57600

//@ref payload_define
#define payload_8 0
#define payload_9 1<<12

//@ref parity_define
#define odd_parity (1<<10 | 1<<9)
#define even_parity 1<<10
#define none_parity 0

//@ref stop bits num

#define stop_bits_half 			1<<12
#define stop_bits_1  			0
#define stop_bits_1_half		3<<12
#define stop_bits_2				2<<12



//baud rate calc

#define USARTDIV(CLK, baudRate)             ((uint32_t)(CLK / (16 * baudRate)))
#define USARTDIV_MUL100(CLK, baudRate)      ((uint32_t)((25 * CLK) / (4 * baudRate)))
#define DIV_Mantissa(CLK, baudRate)         ((uint32_t)USARTDIV(CLK, baudRate))
#define DIV_Man
#define DIV_Fraction(CLK, baudRate)         ((uint32_t)((USARTDIV_MUL100(CLK, baudRate) - \
												USARTDIV_MUL100(CLK, baudRate)) * 16 )/ 100)

#define UART_BRR_VALUE(CLK, baudRate)       ((DIV_Mantissa(CLK, baudRate) << 4) | (DIV_Fraction(CLK,baudRate) & 0xF))


/////////////APIS//////////////

void mcal_usart_init(usart_t * usart_reg,usart_user_config *usart_config);
void mcal_usart_deinit(usart_t * usart_reg);
void mcal_gpio_set_bins_uart(usart_t * usart_reg);
void mcal_send_data(usart_t * usart_reg,uint16_t* data,uint8_t polling_mech);
void mcal_rec_data(usart_t * usart_reg,uint16_t *data,uint8_t polling_mech);
#endif /* INC_UART_H_ */
