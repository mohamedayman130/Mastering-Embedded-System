
#include "mcal/uart.h"
#include "hal/lcd.h"




int main(void)
{
	LCD_INIT();
    uart_init();
	char y,count=0;
		uart_Send(300);
    while (1) 
    {
	//y=uart_rec();
	//if(y==13) //not to print enter and start again
	//{LCD_WRITE_COMMAND(0x01);count=0;}
	//else LCD_WRITE_CHAR(y);
	//
	//if(count==16) SET_CURSOR(1,0);
	//else if(count ==32) {LCD_WRITE_COMMAND(0x01);count=0;}
	//count++;

    }
}

