

#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
void spi_init();
uint8_t send_rec_data(char data);
uint8_t rec_data();




#endif /* SPI_H_ */