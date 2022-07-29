#include "int.h"

void INT_timer0A_En(void)
{
	TIMER0_IM =0x01;                 /*setGPTM Interrupt Mask (GPTMIMR).*/
	TIMER0_ICR |=0x00000001;         /*clear flage */
	NVIC_EN0_REG |=(1<<19);          /*enable IRQ 19 */
}
