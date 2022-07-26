#include "TM4C123GH6PM.h"
#include "int.h"
#include "int_config.h"


void static (*timerCall)(void);
void static (*systimerCall)(void);

void INT_timer_Call(void (*Call)(void))
{
	timerCall=Call;
}

void INT_sysTimer_Call(void (*Call)(void))
{
	systimerCall=Call;
}

void TIMER0A_Handler(void)
{
	(*timerCall)();
	TIMER0_ICR |=0x00000001;
}
void SysTick_Handler(void)
{
	(*systimerCall)();
}
