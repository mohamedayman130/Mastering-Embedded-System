

#ifndef KEYBAD_H_
#define KEYBAD_H_
#include "lcd.h"

//GPIO
#define GPIO_PORTD *(volatile int *)(GPIO_BASE + 0X12)
#define GPIO_DDRD *(volatile int *)(GPIO_BASE + 0X11)
#define GPIO_PIND *(volatile int *)(GPIO_BASE + 0X10)
//functions
char GET_KEY();
void KEYBAD_INIT();


#endif /* KEYBAD_H_ */

