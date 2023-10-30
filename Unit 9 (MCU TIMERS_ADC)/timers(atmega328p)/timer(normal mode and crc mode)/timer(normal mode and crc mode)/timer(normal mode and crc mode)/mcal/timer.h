//this driver for ctc and normal mode only
#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>


////////////////////////////////////////////////////////////
/////////////////// generic variables ////////////////////////

int g_read_ticks;
//ref modes
typedef enum
{
	normal_mode,
	crc_mode
}modes_t;

typedef struct
{
	modes_t  mode;				//@ ref mode
	char pre_scaller;			//@ ref prescaller
	char over_flow_intr;		//@ref overflow_intr
	char compare_output_intr;	//@ref compare_intr
}configrations_t;



void (* call_back_overfolw)(void);//set it by overflow function
void (* call_back_compare)(void);//set it by comparing function

////////////////////////////////////////////////////////////
/////////////////// generic macros ////////////////////////

//ref prescaller
#define pre_scaller_no	0
#define pre_scaller_1	1
#define pre_scaller_8	2
#define pre_scaller_64	3
#define pre_scaller_256	4
#define pre_scaller_1024 5

//ref overflow intr
#define enable_overflow_intr 1
#define disable_overflow_intr 0

//ref compare_intr
#define enable_compare_intr 1
#define disable_compare_intr 0

////////////////////////////////////////////////////////////
/////////////////// apis ///////////////////////////////////
void conf_timer(configrations_t * conf);
void set_num_of_ticks_normal(int val);
void set_num_of_ticks_crc(int val);
#endif /* TIMER_H_ */