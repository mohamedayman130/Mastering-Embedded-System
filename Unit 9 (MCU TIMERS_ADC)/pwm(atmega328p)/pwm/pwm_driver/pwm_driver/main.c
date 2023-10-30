
#define  F_CPU 16000000ul
#include "mcal/pwm.h"

void turn_on_led()
{
	PORTB|=1<<3;
}
void turn_off_led()
{
	PORTB&=~(1<<3);
}
void pwm_init()
{
	fast_pwm_init();
	call_back_compare=turn_on_led;
	call_back_overfolw=turn_off_led;
}
int main(void)
{
	DDRB=0xff;
	pwm_init();
    while (1) 
    {
		for(int i=0;i<=250;i+=15)
		{set_pwm_val(i);
		_delay_ms(70);}
		
		for(int i=250;i>=0;i-=15)
		{set_pwm_val(i);
		_delay_ms(70);}
		
    }
}

