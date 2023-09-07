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
	char x,flag=0,op=0,count=0,num_of_op=0;
	int first_num=0,second_num=0,res=0;
	while (1) 
    { 
		x=GET_KEY();
		//if(i==16) SET_CURSOR(1,0);
		//else if(i==32) {LCD_WRITE_COMMAND(0x01);i=1;}
				
				
		switch(x)
		{
			case 'n' :break;
			case '?' :{LCD_WRITE_COMMAND(0x01);flag=0;first_num=0,second_num=0;num_of_op=0;count=0;break;}
			case '+':{
				if(num_of_op==0){
				op=x;flag=1;
				if(count==0){LCD_WRITE_CHAR(x);}
				else if(count==1)
				{
					second_num=0;
					LCD_WRITE_COMMAND(0x01);LCD_WRITE_NUMBER(res);
					LCD_WRITE_CHAR(op);
				}
				 }num_of_op=1;break; }
			case '-':{
				if(num_of_op==0){op=x;flag=1;
				if(count==0){LCD_WRITE_CHAR(x);}
				else if(count==1)
				{
					second_num=0;
					LCD_WRITE_COMMAND(0x01);LCD_WRITE_NUMBER(res);
					LCD_WRITE_CHAR(op);
				}
			}num_of_op=1;break; }
			case '*':{if(num_of_op==0){
				op=x;flag=1;
				if(count==0){LCD_WRITE_CHAR(x);}
				else if(count==1)
				{
					second_num=0;
					LCD_WRITE_COMMAND(0x01);LCD_WRITE_NUMBER(res);
					LCD_WRITE_CHAR(op);
				}
			 }num_of_op=1;break; }
			case '/':{if(num_of_op==0){
				op=x;flag=1;
				if(count==0){LCD_WRITE_CHAR(x);}
				else if(count==1)
				{
					second_num=0;
					LCD_WRITE_COMMAND(0x01);LCD_WRITE_NUMBER(res);
					LCD_WRITE_CHAR(op);
				}
			}num_of_op=1;break; }
			case '=':{
				SET_CURSOR(1,0);LCD_WRITE_CHAR(x);
				switch(op)
				{
					case '+' :{if(count==0){res=first_num + second_num;count=1;}
						else if(count==1)
						{
							LCD_WRITE_COMMAND(0x01);
							LCD_WRITE_NUMBER(res);LCD_WRITE_CHAR('+');LCD_WRITE_NUMBER(second_num);SET_CURSOR(1,0);LCD_WRITE_CHAR('=');
							res+=second_num;
						}
						break;}
					case '-' :{if(count==0){res=first_num - second_num;count=1;}
					else if(count==1)
					{
						LCD_WRITE_COMMAND(0x01);
						LCD_WRITE_NUMBER(res);LCD_WRITE_CHAR('-');LCD_WRITE_NUMBER(second_num);SET_CURSOR(1,0);LCD_WRITE_CHAR('=');
						res-=second_num;
					}
				break;}
					case '*' :{if(count==0){res=first_num  * second_num;count=1;}
					else if(count==1)
					{
						LCD_WRITE_COMMAND(0x01);
						LCD_WRITE_NUMBER(res);LCD_WRITE_CHAR('*');LCD_WRITE_NUMBER(second_num);SET_CURSOR(1,0);LCD_WRITE_CHAR('=');
						res*=second_num;
					}
				break;}
					case '/' :{if(count==0){res=first_num / second_num;count=1;}
					else if(count==1)
					{
						LCD_WRITE_COMMAND(0x01);
						LCD_WRITE_NUMBER(res);LCD_WRITE_CHAR('/');LCD_WRITE_NUMBER(second_num);SET_CURSOR(1,0);LCD_WRITE_CHAR('=');
						res/=second_num;
					}
				break;}			
				}
				LCD_WRITE_NUMBER(res);num_of_op=0;
				LCD_WRITE_COMMAND(0x0c);
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