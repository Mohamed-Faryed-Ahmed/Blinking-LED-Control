#ifndef  MAIN_H
#define  MAIN_H
#include  "../common/std_type.h"


#define T_ON  (2U) /* led on for 2S */
#define T_OFF (4U) /* led off for 4S */

extern volatile uint32_t ticks; /* number of second elapsed */

void callBack (void);

#endif 
