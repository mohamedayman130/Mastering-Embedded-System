/*
 * keypad.c
 *
 *  Created on: 10 Sep 2023
 *      Author: Alfanan02
 */
#include"keypad.h"

 void delay_ms(int x)
{
	for(int i=0;i<=x;i++)
		for(int j=0;j<=1000;j++);
}
unsigned short keypad_col[]={k1,k2,k3,k4};
unsigned short keypad_row[]={kA,kB,kC,kD};

void keypad_init()
{
	gpio_config keypad_cnf;

	keypad_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	keypad_cnf.gpio_pin_number=kA;
	keypad_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	keypad_cnf.gpio_pin_number=kB;
	keypad_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	keypad_cnf.gpio_pin_number=kC;
	keypad_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_OUTPUT_PP;
	keypad_cnf.gpio_pin_number=kD;
	keypad_cnf.gpio_speed=max_speed_10;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_INPUT_FLO;
	keypad_cnf.gpio_pin_number=k1;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_INPUT_FLO;
	keypad_cnf.gpio_pin_number=k2;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_INPUT_FLO;
	keypad_cnf.gpio_pin_number=k3;
	mcal_gpio_init(keypad_port, &keypad_cnf);

	keypad_cnf.gpio_mode=GPIO_MODE_INPUT_FLO;
	keypad_cnf.gpio_pin_number=k4;
	mcal_gpio_init(keypad_port, &keypad_cnf);
}
char keypad_get_char()
{

	for(int i=0;i<4;i++)
	{
		delay_ms(20);
		mcal_gpio_write_pin(keypad_port, keypad_row[0], 0);
		mcal_gpio_write_pin(keypad_port, keypad_row[1], 0);
		mcal_gpio_write_pin(keypad_port, keypad_row[2], 0);
		mcal_gpio_write_pin(keypad_port, keypad_row[3], 0);

		mcal_gpio_write_pin(keypad_port, keypad_row[i], 1);
		for(int j=0;j<4;j++)
		{
			if(mcal_gpio_read_pin(keypad_port, keypad_col[j]))
			{
				while(mcal_gpio_read_pin(keypad_port, keypad_col[j]));
				switch(i){
				case (0):
										if (j == 0) return '7';
										else if (j == 1) return '8';
										else if (j == 2) return '9';
										else if (j == 3) return '/';
										break;
				case (1):
										if (j == 0) return '4';
										else if (j == 1) return '5';
										else if (j == 2) return '6';
										else if (j == 3) return '*';
										break;
				case (2):
										if (j == 0) return '1';
										else if (j == 1) return '2';
										else if (j == 2) return '3';
										else if (j == 3) return '-';
										break;
				case (3):
										if (j == 0) return '?';
										else if (j == 1) return '0';
										else if (j == 2) return '=';
										else if (j == 3) return '+';
										break;
				}
			}
		}

	}
	return 'N';
}
