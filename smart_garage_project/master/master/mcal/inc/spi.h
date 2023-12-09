/*
 * spi.h
 *
 * Created: 02/12/2023 00:26:08
 *  Author: Alfanan02
 */ 


#ifndef SPI_H_
#define SPI_H_
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>

void spi_init();
uint8_t send_rec_data(char data);
void spi_send_data(uint8_t data);
#endif /* SPI_H_ */