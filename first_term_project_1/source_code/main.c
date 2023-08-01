#include <stdio.h>
#include "pressure_sensor.h"
#include "alarm.h"

int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
       if(getPressureVal()>20)
       {
          Set_Alarm_actuator(0);
          Delay(1000000);
       }
       else{
       	Set_Alarm_actuator(1);
       }


	}

}
