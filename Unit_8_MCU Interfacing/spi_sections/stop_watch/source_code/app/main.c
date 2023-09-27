/*
 * app.c
 *
 * Created: 27/09/2023 02:26:06
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include <avr/delay.h>
void spi_send(char x)
{
	SPDR=x;
	while(!(SPSR&(1<<SPIF)));
}

void seven_Seg_send(char reg, char data)
{
	PORTB&=~(1<<4);
	spi_send(reg);
	spi_send(data);
	PORTB|=1<<4;
}

void uart_init()
{
	UCSRB|= 1<<4 | 1<<3 ;
	UBRRL=51;
}

char clk[2];
//char m_clk[2];
//char h_clk[2];
void uart_rec()
{
	char j=0;
	while(j<6){
	char i=0;
	while(i<2){
	while(! (UCSRA & 1<<7) );
	char text=UDR;
	if(text != 13)
	{
		clk[j++]=text-48;
		i++;
	}
	}
	}
}
int main(void)
{
	DDRB=0xff;
	DDRD=0xff;
	uart_init();
	//set spi as master and enable it
	SPCR=(1<<SPE)|(1<<MSTR);
	//decode 0-7 digits
	seven_Seg_send(0x09,0xFF);
	//Display digits 0 1 2 3 4 5 
	seven_Seg_send(0x0B,0x05);
	//normal operation
	seven_Seg_send(0x0C,0x01);
	//Intensity 
	seven_Seg_send(0x0A,0x03);
    char h=0,m=0,s=0; 
	
    while (1) 
    {
		char flag=0,alarm=0;
		uart_rec();
		s= (clk[4])*10 +clk[5] ;
		m= (clk[2])*10 +clk[3] ;
		h= (clk[0])*10 +clk[1] ;
		if( s>59 )s=59;
		if( m>59 )m=59;
		if(h>23) h=23;
		for(char i=0;i<24;)
		{
			for(char j=0;j<60;)
			{
				for(char k=0;k<60;k++)
				{
					
					seven_Seg_send(0x05,k/10);
					seven_Seg_send(0x06,k%10);
					_delay_ms(1000);///////////////////only change this delay
					if(k==s && j==m && i==h){flag=1;alarm=1;PORTB|=1<<1; break;}
				}
				if(flag == 1) break;
				if(j==59) 
				{
				seven_Seg_send(0x03,0);
				seven_Seg_send(0x04,0);break;
				}
				j++;
				seven_Seg_send(0x03,j/10);
				seven_Seg_send(0x04,j%10);
			}
			if(flag == 1) break;
			i++;
			seven_Seg_send(0x01,i/10);
			seven_Seg_send(0x02,i%10);
			
		}
		if(alarm == 1)
		{
			while(1)
			{
				if( (PINB & (1<<0)) !=0)
				{
					PORTB&=~(1<<1);
					seven_Seg_send(0x01,0);
					seven_Seg_send(0x02,0);
					seven_Seg_send(0x03,0);
					seven_Seg_send(0x04,0);
					seven_Seg_send(0x05,0);
					seven_Seg_send(0x06,0);
					break;
				}
			}

		}
		
    }
}

