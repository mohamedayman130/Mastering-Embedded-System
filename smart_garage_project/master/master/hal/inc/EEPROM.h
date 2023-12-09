/*
 * EEPROM.h
 *
 * Created: 04/12/2023 22:19:06
 *  Author: Alfanan02
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../mcal/inc/spi.h"

void eeprom_init();
void eeprom_write(uint8_t address, uint8_t data);
uint8_t eeprom_read(uint8_t add);
void eeprom_send_7_bytes(uint32_t id);
uint32_t eeprom_read_7_bytes(uint8_t add );


#endif /* EEPROM_H_ */