/********************************************************************************************
 * File name : main.c
 * Date      : 25/7/2022
 * Auther    : Mohamed Faryed Ahmed 
 * Des       : Control blinking of an LED for a user-defined ON and OFF periods
 *
 *******************************************************************************************/

#include "main.h"
#include  "../hal/led/led.h"
#include  "../mcal/timer/timer.h"

int main()
{
	Timer_Init tm={T0,TA,P};
	TIMER_init(&tm,callBack);
	led_Init(PORTF, PIN2);
	TIMER_start(T0,TA);
	
	led_On(PORTF,PIN0);
	while(1)
	{
		
	}
	
	return 0;
}

void callBack (void)
{
	if(ticks >= T_ON && ticks <=(T_ON + T_OFF))
	{
		led_Off(PORTF,PIN0);
	}
	else if(ticks >= (T_ON + T_OFF) )
	{
		led_On(PORTF,PIN0);
		ticks = 0;
	}
}
