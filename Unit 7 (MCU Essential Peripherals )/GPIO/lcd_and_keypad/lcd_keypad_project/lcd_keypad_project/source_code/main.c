#include <stdio.h>
#include "lcd.h"
#include "keypad.h"
int main(void)
{
	LCD_INIT();
	KEYBAD_INIT();
	SET_CURSOR(0,5);
	LCD_WRITE_STRING("hello");
	for(int i=9;i>=0;i--) //to turn on counter befor display 
	{
		SET_CURSOR(1,7);
		LCD_WRITE_CHAR(i+48);
		_delay_ms(1000);
	}
	LCD_WRITE_COMMAND(0x01);
	char x,i=1;
	while (1) 
    { 
		x=GET_KEY();
		if(i==16) SET_CURSOR(1,0);
		else if(i==32) {LCD_WRITE_COMMAND(0x01);i=1;}
		switch(x)
		{
			case 'n' :break;
			case '?' :LCD_WRITE_COMMAND(0x01);i=1;break;
			default: LCD_WRITE_CHAR(x);i++;
		}
		
		
	}
}