#ifndef INT_H
#define INT_H
#include "../../common/std_type.h"


#define TIMER0A_VECT (*((volatile uint32_t *const)0x0000008C))
#define TIMER0B_VECT (*((volatile uint32_t *const)0x00000090))
#define TIMER1A_VECT (*((volatile uint32_t *const)0x00000094))
#define TIMER1B_VECT (*((volatile uint32_t *const)0x00000098))
#define TIMER2A_VECT (*((volatile uint32_t *const)0x0000009C))
#define TIMER2B_VECT (*((volatile uint32_t *const)0x000000A0))


#endif
