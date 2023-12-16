

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <inttypes.h>
#define GPIO_BASE 0x20
#define GPIO_PORTC *(volatile char *)(GPIO_BASE + 0X15)
#define GPIO_PINC *(volatile char *)(GPIO_BASE + 0X13)
#define GPIO_DDRC *(volatile char *)(GPIO_BASE + 0X14)
uint8_t get_key();
void KEYBAD_INIT();

#endif /* KEYPAD_H_ */