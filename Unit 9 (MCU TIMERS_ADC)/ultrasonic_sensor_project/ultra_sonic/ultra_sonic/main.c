
#define F_CPU 16000000
#include "hal/lcd.h"
#include "hal/ultrasonic.h"


void timer_init()
{
	 TCCR1B|=1<<0;
	 TCNT1=0;
}

int main(void)
{
	LCD_INIT();
	ultra_init();
	timer_init();
	lcd_clear_screen();
	LCD_WRITE_STRING("distance:(cm)");
    while (1) 
    {
	
	    SET_CURSOR(1,0);
	    lcd_write_num(ultra_read());
		LCD_WRITE_CHAR(' ');
		_delay_ms(100);
    }
}
