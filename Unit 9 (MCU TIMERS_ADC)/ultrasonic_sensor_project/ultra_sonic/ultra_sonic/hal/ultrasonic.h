
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

uint32_t ultra_read();
void ultra_init();



#endif /* ULTRASONIC_H_ */