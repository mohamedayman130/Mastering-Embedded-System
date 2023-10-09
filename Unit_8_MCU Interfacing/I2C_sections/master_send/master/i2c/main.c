/*
 * i2c.c
 *
 * Created: 05/10/2023 23:04:01
 * Author : Alfanan02
 */ 

#include <avr/io.h>
#include "i2c_lib/i2c.h"
#include "avr/delay.h"
int main(void)
{
	i2c_init(0X48);
    /* Replace with your application code */
	char ch=0;
	
    while (1) 
    {
		
		
		i2c_start();    //transmit start condition
		
		send(0b11010000+0);   //transmit slave address + W(0)
		
		while(TWSR != 0x18);      //slave address + W(0) has been transmitted and ACK has been received
		
		send(ch++);   //transmit data
		while(TWSR != 0x28);   //data has been transmitted and ACK has been received
		
		i2c_stop();
		_delay_ms(5000);
    }
}

