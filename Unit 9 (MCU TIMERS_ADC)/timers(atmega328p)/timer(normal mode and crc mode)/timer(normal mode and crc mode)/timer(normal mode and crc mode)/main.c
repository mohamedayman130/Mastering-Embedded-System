
#include "mcal/timer.h"

void over(void)
{
	PORTB^=1<<0;
}

void timer_init()
{
	configrations_t timer1_conf={normal_mode,pre_scaller_1024,enable_overflow_intr,disable_compare_intr};
	set_num_of_ticks_normal(15625);
	call_back_overfolw=over;
	conf_timer(&timer1_conf);
}

int main(void)
{
	DDRB=0xff;
	timer_init();
	while (1)
	{
	}
}

