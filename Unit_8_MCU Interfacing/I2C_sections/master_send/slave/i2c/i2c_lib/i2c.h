/*
 * i2c.h
 *
 * Created: 05/10/2023 23:04:25
 *  Author: Alfanan02
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>
//void i2c_init();
//void i2c_start();
//void i2c_stop();
//void send(uint8_t data);

void set_address(uint8_t address);
uint8_t read();

#endif /* I2C_H_ */







