/********************************************************************************************
 * File name : main.c
 * Date      : 25/7/2022
 * Auther    : Mohamed Faryed Ahmed 
 * Des       : Control blinking of an LED for a user-defined ON and OFF periods
 *
 *******************************************************************************************/

#include "main.h"
#include "../hal/led/led.h"
#include "../mcal/int/int.h"
#include "../mcal/int/int_config.h"
#include "../mcal/systick/systick.h"
#include "../mcal/pll/pll.h"
#include "../hal/push_button/button.h"

/*
#include "../mcal/timer/timer.h"
*/
void static PWM_led(uint8_t time_on,uint8_t time_off);


static uint8_t ticks=0;

int main()
{
  Sys_Init systime={9999999,SYSTEM};      /*use system cloc and count tick for 1 second*/
  PLL_Init();                             /*system clock 10MHZ*/
	led_Init(PORTF, PIN2);                  /*define len on pf2*/
  led_Init(PORTF, PIN3);                  /*define len on pf3*/
  SYS_TICK_init(&systime);                /*use system cloc and count tick for 1 second*/
  BUTTON_init(PORTF,PIN4,UP);             /*define switch on pf4*/
	INT_sysTimer_Call(callBack);            /*callback function*/
  INT_sysTimer_En(PRI_0);                 /*enable systim inerrupt and set priorty*/
	
	led_On(PORTF,PIN2);
	SYS_TICK_reset();                       /*reset timer*/
  led_Off(PORTF,PIN3);
  while(1)
  {
    if(BUTTON_read(PORTF,PIN4))
    {
      led_Off(PORTF,PIN3);
    }
    else 
    {
      led_On(PORTF,PIN3);
    }
		PWM_led(T_ON,T_OFF);
  }
}
/******************************************************************************************
*  Func name:  PWM_LED FUNC                                                                *
*  Discr    :  turn on /turn off led                                                       * 
*******************************************************************************************/
void static PWM_led(uint8_t time_on,uint8_t time_off)
{
	if((ticks >= time_on) && (ticks <(time_on + time_off)))
	{
		led_Off(PORTF,PIN2);
	}
	else if(ticks >= (time_on + time_off) )
	{
		led_On(PORTF,PIN2);
		ticks = 0;
	}
}

/******************************************************************************************
*  Func name:  Callback FUNC                                                              *
*  Discr    :  inceement  ticks                                                           * 
*******************************************************************************************/
void callBack (void)
{
	ticks++;
}

