

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
////////////////////////////////////////////////////////////
/////////////////// generic variables ////////////////////////
//
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

////////////////////////////////////////////////////////////
/////////////////// apis ///////////////////////////////////
void fast_pwm_init();
void set_pwm_val(char pwm_val);//pwm_val can take from 0 to 255


#endif /* PWM_H_ */