/********************************************************************************************
 * File name : main.c
 * Date      : 25/7/2022
 * Auther    : Mohamed Faryed Ahmed 
 * Des       : Control blinking of an LED for a user-defined ON and OFF periods
 *
 *******************************************************************************************/

#include "main.h"
#include "../hal/led/led.h"
#include "../mcal/timer/timer.h"
#include "../mcal/int/int.h"
#include "../mcal/int/int_config.h"


static uint8_t ticks=0;

int main()
{
	
	Timer_Init tm={T0,TA,P};
	TIMER_init(&tm);
	int_timer_call(callBack);
	
	led_Init(PORTF, PIN2);
	
	INT_timer0A_En();
	TIMER_start(T0,TA);
	
	led_On(PORTF,PIN2);
	while(1)
	{

	}
	
	return 0;
}

void callBack (void)
{
	ticks++;
	if(ticks >= T_ON && ticks <(T_ON + T_OFF))
	{
		led_Off(PORTF,PIN2);
	}
	else if(ticks >= (T_ON + T_OFF) )
	{
		led_On(PORTF,PIN2);
		ticks = 0;
	}
}
