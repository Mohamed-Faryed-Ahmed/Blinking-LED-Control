#include "int.h"
#include "int_config.h"


void static (*timerCall)(void);

void int_timer_call(void (*Call)(void))
{
	timerCall=Call;
}

TIMER0A_Handler()
{
	(*timerCall)();
	TIMER0_ICR |=0x00000001;
}
