#include "pwm.h"

void fast_pwm_init()
{
	sei();//to enable global intrrupt
	TCCR1A|=1<<0;
	 TIMSK1|=1<<0 | 1<<1;
	TCCR1B|=1<<1 | 1<<3;
	
}

void set_pwm_val(char pwm_val)
{
	OCR1A=pwm_val;
}

ISR(TIMER1_COMPA_vect)
{
	call_back_overfolw();
}

ISR(TIMER1_OVF_vect)
{
	call_back_compare();
}