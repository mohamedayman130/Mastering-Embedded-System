
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "hal/inc/keypad.h"
#include "hal/inc/lcd.h"

uint32_t power(uint8_t exponent) {
	uint32_t result = 1;
	
	if (exponent >= 0) {
		for (int i = 0; i < exponent; i++) 
		{
			result *= 2;
		}
		} 
	
	return result;
}

void dec_to_bin(uint32_t data)
{
	uint8_t bin_array[32]={0},offset=0,bin_counter=0,flag=0,cpy_bin_counter=0;
		
		lcd_clear_screen();
		for(int8_t i=31;i>=0;i--)
		{
			//lcd_clear_screen();
			if(data==0){LCD_WRITE_CHAR('0');break;}
			if(  ( (1<<i)&data)!=0 ) flag=1;
			if(flag==1)
			{
				if( ((1<<i)&data)==0) {bin_array[bin_counter++]=0;}
				else {bin_array[bin_counter++]=1;}
			}
		}
	/////////////////////
	uint8_t array[32]={0};
		cpy_bin_counter=bin_counter;
		while((cpy_bin_counter % 4)) cpy_bin_counter++;
		offset=cpy_bin_counter-bin_counter;
		for(uint8_t i=0;i<offset;i++)
		{
			array[i]=0;
		}
		for(int8_t i=offset;i<cpy_bin_counter;i++)
		{
			array[i]=bin_array[i-offset];
		}
		
		
		///for binary
		for (uint8_t i=1;i<=cpy_bin_counter;i++)
		{
			LCD_WRITE_CHAR(array[i-1]+48);
			if(i%4==0) LCD_WRITE_CHAR(' ');
		}
		SET_CURSOR(1,0);
		LCD_WRITE_STRING("BIN");
		_delay_ms(4000);
		lcd_clear_screen();
		
		
		
		//////////////////for hex
		for(int8_t i=0;i<cpy_bin_counter;i+=4)
		{
			uint8_t temp2=array[i]*8+array[i+1]*4+array[i+2]*2+array[i+3]*1;
			switch(temp2)
			{
				case  10 : LCD_WRITE_CHAR('A');break;
				case  11 : LCD_WRITE_CHAR('B');break;
				case  12 : LCD_WRITE_CHAR('C');break;
				case  13 : LCD_WRITE_CHAR('D');break;
				case  14 : LCD_WRITE_CHAR('E');break;
				case  15 : LCD_WRITE_CHAR('F');break;
				default:LCD_WRITE_CHAR(temp2+48);break;
			}
			
		}
		SET_CURSOR(1,0);LCD_WRITE_STRING("HEX");
		_delay_ms(4000);
		lcd_clear_screen();
	
		
		//////////////////for octal
		uint8_t oct_offset=0,cpy_2_bin_counter=bin_counter,oct_array[30];
		
		while((cpy_2_bin_counter % 3)) cpy_2_bin_counter++;
		
		oct_offset=cpy_2_bin_counter-bin_counter;
		for(uint8_t i=0;i<oct_offset;i++)
		{
			oct_array[i]=0;
		}
		for(int8_t i=oct_offset;i<cpy_2_bin_counter;i++)
		{
			oct_array[i]=bin_array[i-oct_offset];
		}
		for(int8_t i=0;i<cpy_2_bin_counter;i+=3)
		{
			uint8_t temp2=oct_array[i]*4+oct_array[i+1]*2+oct_array[i+2]*1;
			LCD_WRITE_CHAR(temp2+48);
			
		}
		SET_CURSOR(1,0);LCD_WRITE_STRING("oct");
		_delay_ms(4000);
		lcd_clear_screen();
}



int main(void)
{
    
	LCD_INIT();
	KEYBAD_INIT();
		
	
    while (1) 
    {
		lcd_clear_screen();
		uint32_t dec_number=0;
			uint8_t flag=1,choice=0;
			LCD_WRITE_COMMAND(0x0e);
		LCD_WRITE_STRING("1:DEC     ");LCD_WRITE_STRING("2:BIN");SET_CURSOR(1,0);LCD_WRITE_STRING("3:HEX     ");LCD_WRITE_STRING("4:OCT");LCD_WRITE_COMMAND(0x0c);
		while(flag){
		uint8_t n_sys=get_key();
		switch(n_sys)
		{
			case 'N' : break;
			case '1' :{choice=1;flag=0;break;}
			case '2' : {choice=2;flag=0;break;}
			case '3' : {choice=3;flag=0;break;}
			case '4' : {choice=4;flag=0;break;}
		}
		}
		if(choice==1){
			uint8_t exit=1;
			lcd_clear_screen();LCD_WRITE_STRING("enter dec number:");SET_CURSOR(1,0);
			while(exit){
		uint8_t read=get_key();
		switch(read)
		{
			case 'N' : break;
			case '=' :{dec_to_bin(dec_number);exit=0;break;}
			default : {LCD_WRITE_CHAR(read);dec_number=dec_number*10+read-48;break;}
		}
			}
			
    }
	
		else if(choice==2){
			uint8_t exit=1,i=0,j=0,array[32]={0};
			lcd_clear_screen();LCD_WRITE_STRING("enter bin number:");SET_CURSOR(1,0);
			while(exit){
				uint8_t read=get_key();
				switch(read)
				{
					case 'N' : break;
					case '=' :{exit=0;break;}
					case '0':
					case '1' :{LCD_WRITE_CHAR(read);array[i++]=read-48;j++;break;}
				}
			}
			
			for(int8_t c=0;c<i;c++)
			{
				dec_number=dec_number + (array[c])* power(--j);	
			}
			lcd_clear_screen();
			lcd_write_num(dec_number);
			SET_CURSOR(1,0);
			LCD_WRITE_STRING("dec");
			_delay_ms(4000);
			lcd_clear_screen();
			dec_to_bin(dec_number);
		}
			
			else if(choice==3){
				uint8_t exit=1,i=0,j=0,array[32]={0};
				lcd_clear_screen();LCD_WRITE_STRING("enter hex number:");SET_CURSOR(1,0);
				while(exit){
					uint8_t read=get_key();
					switch(read)
					{
						case 'N' : break;
						case '=' :{exit=0;break;}
						default : {
							switch(read)
							{
								case '0':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=0;array[i+3]=0;i+=4;j+=4;break;
								case '1':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=0;array[i+3]=1;i+=4;j+=4;break;
								case '2':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=1;array[i+3]=0;i+=4;j+=4;break;
								case '3':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=1;array[i+3]=1;i+=4;j+=4;break;
								case '4':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=0;array[i+3]=0;i+=4;j+=4;break;
								case '5':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=0;array[i+3]=1;i+=4;j+=4;break;
								case '6':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=1;array[i+3]=0;i+=4;j+=4;break;
								case '7':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=1;array[i+3]=1;i+=4;j+=4;break;
								case '8':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=0;array[i+3]=0;i+=4;j+=4;break;
								case '9':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=0;array[i+3]=1;i+=4;j+=4;break;
								case 'A':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=1;array[i+3]=0;i+=4;j+=4;break;
								case 'B':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=1;array[i+3]=1;i+=4;j+=4;break;
								case 'C':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=0;array[i+3]=0;i+=4;j+=4;break;
								case 'D':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=0;array[i+3]=1;i+=4;j+=4;break;
								case 'E':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=1;array[i+3]=0;i+=4;j+=4;break;
								case 'F':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=1;array[i+3]=1;i+=4;j+=4;break;
								
							}
							
							
							}
					}
				}
				
				for(int8_t c=0;c<i;c++)
				{
					dec_number=dec_number + (array[c])* power(--j);
				}
				lcd_clear_screen();
				lcd_write_num(dec_number);
				SET_CURSOR(1,0);
				LCD_WRITE_STRING("dec");
				_delay_ms(4000);
				lcd_clear_screen();
				dec_to_bin(dec_number);
			}
			
	else if(choice==4){
		uint8_t exit=1,i=0,j=0,array[32]={0};
		lcd_clear_screen();LCD_WRITE_STRING("enter oct number:");SET_CURSOR(1,0);
		while(exit){
			uint8_t read=get_key();
			switch(read)
			{
				case 'N' : break;
				case '=' :{exit=0;break;}
				default : {
					switch(read)
					{
						case '0':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=0;i+=3;j+=3;break;
						case '1':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=0;array[i+2]=1;i+=3;j+=3;break;
						case '2':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=0;i+=3;j+=3;break;
						case '3':LCD_WRITE_CHAR(read);array[i]=0;array[i+1]=1;array[i+2]=1;i+=3;j+=3;break;
						case '4':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=0;i+=3;j+=3;break;
						case '5':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=0;array[i+2]=1;i+=3;j+=3;break;
						case '6':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=0;i+=3;j+=3;break;
						case '7':LCD_WRITE_CHAR(read);array[i]=1;array[i+1]=1;array[i+2]=1;i+=3;j+=3;break;
					}
					
					
				}
			}
		}
		
		for(int8_t c=0;c<i;c++)
		{
			dec_number=dec_number + (array[c])* power(--j);
		}
		lcd_clear_screen();
		lcd_write_num(dec_number);
		SET_CURSOR(1,0);
		LCD_WRITE_STRING("dec");
		_delay_ms(4000);
		lcd_clear_screen();
		dec_to_bin(dec_number);
	}
	}
}

