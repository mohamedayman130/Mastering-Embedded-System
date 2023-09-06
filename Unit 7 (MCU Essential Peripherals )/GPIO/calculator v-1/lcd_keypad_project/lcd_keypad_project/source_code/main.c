#include <stdio.h>
#include "lcd.h"
#include "keypad.h"
int main(void)
{
	LCD_INIT();
	KEYBAD_INIT();
	SET_CURSOR(0,5);
	LCD_WRITE_STRING("hello");
	//for(int i=9;i>=0;i--) //to turn on counter befor display 
	//{
		//SET_CURSOR(1,7);
		//LCD_WRITE_CHAR(i+48);
		//_delay_ms(1000);
	//}
	LCD_WRITE_COMMAND(0x01);
	char x,i=1,flag=0,op=0;
	int first_num=0,second_num=0,res=0;
	while (1) 
    { 
		x=GET_KEY();
		//if(i==16) SET_CURSOR(1,0);
		//else if(i==32) {LCD_WRITE_COMMAND(0x01);i=1;}
		switch(x)
		{
			case 'n' :break;
			case '?' :{LCD_WRITE_COMMAND(0x01);i=1;flag=0;first_num=0,second_num=0;break;}
			case '+':{LCD_WRITE_CHAR(x);op=x;flag=1; break;}
			case '-':{LCD_WRITE_CHAR(x);op=x;flag=1; break;}
			case '*':{LCD_WRITE_CHAR(x);op=x;flag=1; break;}
			case '/':{LCD_WRITE_CHAR(x);op=x;flag=1; break;}		
			case '=':{SET_CURSOR(1,0);LCD_WRITE_CHAR(x);
				switch(op)
				{
					case '+' :{res=first_num + second_num;break;}
					case '-' :{res=first_num - second_num;break;}
					case '*' :{res=first_num * second_num;break;}
					case '/' :{res=first_num / second_num;break;}			
				}
				LCD_WRITE_NUMBER(res);
				break;}	
			default: {LCD_WRITE_CHAR(x);
				if(flag == 0)
				{
					first_num =first_num*10 +x-48;
				}
				else if(flag == 1)
				{
					second_num =second_num *10 +x-48;
				}
		}
		
		
	}
}
			}