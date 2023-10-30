#include "timer.h"

void conf_timer(configrations_t * conf)
{
	sei();
	if(conf->mode == normal_mode)
	{
		TCCR1B&=~(1<<3);
	}
	else if(conf->mode == crc_mode)
	{
		TCCR1B|=1<<3;
	}
	if(conf->pre_scaller == pre_scaller_no)
	{
		TCCR1B|=pre_scaller_no;
	}
	else if(conf->pre_scaller == pre_scaller_1)
	{
		TCCR1B|=pre_scaller_1;
	}
	else if(conf->pre_scaller == pre_scaller_8)
	{
		TCCR1B|=pre_scaller_8;
	}
	else if(conf->pre_scaller == pre_scaller_64)
	{
		TCCR1B|=pre_scaller_64;
	}
	else if(conf->pre_scaller == pre_scaller_256)
	{
		TCCR1B|=pre_scaller_256;
	}
	else if(conf->pre_scaller == pre_scaller_1024)
	{
		TCCR1B|=pre_scaller_1024;
	}
	if(conf->over_flow_intr == enable_overflow_intr)
	{
		TIMSK1 |=1<<0;
	}
	else
	TIMSK1 &=~(1<<0);
	
	if (conf->compare_output_intr == enable_compare_intr)
	TIMSK1 |=1<<1;
	else
	TIMSK1&=~(1<<1);
}

void set_num_of_ticks_normal(int val)
{
	g_read_ticks=65535-val;
	TCNT1=g_read_ticks;
}

void set_num_of_ticks_crc(int val)
{
	OCR1A=val;
}
ISR(TIMER1_COMPA_vect)
{
	call_back_compare();
}

ISR(TIMER1_OVF_vect)
{
	call_back_overfolw();
	TCNT1=g_read_ticks;
}