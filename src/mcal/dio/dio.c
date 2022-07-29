#include "../../common/std_type.h"
#include "dio.h"

void DIO_portSetting(Port_Num port_num ,DIO_Status status ,DIO_Dir dir)
{
	volatile uint32_t delay =5 ;
	if(port_num == PORTF)
	{
		GPIO_HBCTL |= 0x00000020;
	  CLOCK_PORT |= 0x00000020;
	  delay = delay +5;
	  PORTF_DIR   &= dir;
	  PORTF_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTF_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTF_PDR   |= 0xff;
		}
	  PORTF_EN    |= 0xff;
	  PORTF_PCTL  &= 0x00000000;
	  PORTF_AMSEL &= 0x00;
	  PORTF_LOCK   = 0x4C4F434B ;
	  PORTF_CR    |= 0xff;
	}
	else if(port_num == PORTE )
	{
		GPIO_HBCTL |= 0x00000010;
	  CLOCK_PORT |= 0x00000010;
	  delay = delay +5;
	  PORTE_DIR   &= dir;
	  PORTE_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTE_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTE_PDR   |= 0xff;
		}
	  PORTE_EN    |= 0xff;
	  PORTE_PCTL  &= 0x00000000;
	  PORTE_AMSEL &= 0x00;
	  PORTE_LOCK   = 0x4C4F434B ;
	  PORTE_CR    |= 0xff;
	}
	else if(port_num == PORTD )
	{
		GPIO_HBCTL |= 0x00000008;
	  CLOCK_PORT |= 0x00000008;
	  delay = delay +5;
	  PORTD_DIR   &= dir;
	  PORTD_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTD_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTD_PDR   |= 0xff;
		}
	  PORTD_EN    |= 0xff;
	  PORTD_PCTL  &= 0x00000000;
	  PORTD_AMSEL &= 0x00;
	  PORTD_LOCK   = 0x4C4F434B ;
	  PORTD_CR    |= 0xff;
	}
	else if(port_num == PORTC )
	{
		GPIO_HBCTL |= 0x00000004;
	  CLOCK_PORT |= 0x00000004;
	  delay = delay +5;
	  PORTC_DIR   &= dir;
	  PORTC_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTC_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTC_PDR   |= 0xff;
		}
	  PORTC_EN    |= 0xff;
	  PORTC_PCTL  &= 0x00000000;
	  PORTC_AMSEL &= 0x00;
	  PORTC_LOCK   = 0x4C4F434B ;
	  PORTC_CR    |= 0xff;
	}
	else if(port_num == PORTB )
	{
		GPIO_HBCTL |= 0x00000002;
	  CLOCK_PORT |= 0x00000002;
	  delay = delay +5;
	  PORTB_DIR   &= dir;
	  PORTB_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTB_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTB_PDR   |= 0xff;
		}
	  PORTB_EN    |= 0xff;
	  PORTB_PCTL  &= 0x00000000;
	  PORTB_AMSEL &= 0x00;
	  PORTB_LOCK   = 0x4C4F434B ;
	  PORTB_CR    |= 0xff;
	}
	else if(port_num == PORTA )
	{
		GPIO_HBCTL |= 0x00000001;
	  CLOCK_PORT |= 0x00000001;
	  delay = delay +5;
	  PORTA_DIR   &= dir;
	  PORTA_AFSEL &= 0x00;
		if(status == UP)
		{
			PORTA_PUR   |= 0xff;
		}
	  if(status == DOWN)
		{
			PORTA_PDR   |= 0xff;
		}
	  PORTA_EN    |= 0xff;
	  PORTA_PCTL  &= 0x00000000;
	  PORTA_AMSEL &= 0x00;
	  PORTA_LOCK   = 0x4C4F434B ;
	  PORTA_CR    |= 0xff;
	}
}

void DIO_pinSetting(Port_Num port_num ,Pin_Num pin_num ,DIO_Status status ,DIO_Dir dir)
{
	volatile uint32_t delay =5;
	if(port_num == PORTF)
	{
		GPIO_HBCTL |= 0x00000020;
	  CLOCK_PORT |= 0x00000020;
	  delay = delay+5;
		PORTF_LOCK   = 0x4C4F434B ;
	  PORTF_CR    |= (1<<pin_num);
			if(dir == OUTPUT)
			{
				PORTF_DIR   |= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTF_DIR   &= ~(1<<pin_num);
			}
			
	  PORTF_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTF_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTF_PDR   |= (1<<pin_num);
		}
	  PORTF_EN    |= (1<<pin_num);
	  PORTF_PCTL  &= ~(1<<(4*pin_num));
	  PORTF_AMSEL &= ~(1<<pin_num);
	}
	else if(port_num == PORTE )
	{
		GPIO_HBCTL |= 0x00000010;
		CLOCK_PORT |= 0x00000010;
	  delay = delay+5;
			if(dir == OUTPUT)
			{
				PORTE_DIR   &= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTE_DIR   &= ~(1<<pin_num);
			}
			
	  PORTF_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTE_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTE_PDR   |= (1<<pin_num);
		}
	  PORTE_EN    |=  (1<<4*pin_num);
	  PORTE_PCTL  &= ~(1<<pin_num);
	  PORTE_AMSEL &= ~(1<<pin_num);
	  PORTE_LOCK   = 0x4C4F434B ;
	  PORTE_CR    |= (1<<pin_num);
	}
	else if(port_num == PORTD )
	{
		GPIO_HBCTL |= 0x00000008;
		CLOCK_PORT |= 0x00000008;
	  delay = delay+5;
			if(dir == OUTPUT)
			{
				PORTD_DIR   &= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTD_DIR   &= ~(1<<pin_num);
			}
			
	  PORTD_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTD_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTD_PDR   |= (1<<pin_num);
		}
	  PORTD_EN    |= (1<<pin_num);
	  PORTD_PCTL  &= (1<<pin_num);
	  PORTD_AMSEL &= ~(1<<pin_num);
	  PORTD_LOCK   = 0x4C4F434B ;
	  PORTD_CR    |= (1<<pin_num);
	}
	else if(port_num == PORTC )
	{
		GPIO_HBCTL |= 0x00000004;
		CLOCK_PORT |= 0x00000004;
	  delay = delay+5;
			if(dir == OUTPUT)
			{
				PORTC_DIR   &= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTC_DIR   &= ~(1<<pin_num);
			}
			
	  PORTC_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTC_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTC_PDR   |= (1<<pin_num);
		}
	  PORTC_EN    |= (1<<pin_num);
	  PORTC_PCTL  &= (1<<pin_num);
	  PORTC_AMSEL &= ~(1<<pin_num);
	  PORTC_LOCK   = 0x4C4F434B ;
	  PORTC_CR    |= (1<<pin_num);
	}
	else if(port_num == PORTB )
	{
		GPIO_HBCTL |= 0x00000002;
		CLOCK_PORT |= 0x00000002;
	  delay = delay+5;
			if(dir == OUTPUT)
			{
				PORTB_DIR   &= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTB_DIR   &= ~(1<<pin_num);
			}
			
	  PORTB_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTB_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTB_PDR   |= (1<<pin_num);
		}
	  PORTB_EN    |= (1<<pin_num);
	  PORTB_PCTL  &= (1<<pin_num);
	  PORTB_AMSEL &= ~(1<<pin_num);
	  PORTB_LOCK   = 0x4C4F434B ;
	  PORTB_CR    |= (1<<pin_num);
	}
	else if(port_num == PORTA )
	{
		GPIO_HBCTL |= 0x00000001;
		CLOCK_PORT |= 0x00000001;
	  delay = delay+5;
			if(dir == OUTPUT)
			{
				PORTA_DIR   &= (1<<pin_num);
			}
			else if(dir == INPUT)
			{
				PORTA_DIR   &= ~(1<<pin_num);
			}
			
	  PORTA_AFSEL &= ~(1<<pin_num);
		if(status == UP)
		{
			PORTA_PUR   |= (1<<pin_num);
		}
	  if(status == DOWN)
		{
			PORTA_PDR   |= (1<<pin_num);
		}
	  PORTA_EN    |= (1<<pin_num);
	  PORTA_PCTL  &= (1<<pin_num);
	  PORTA_AMSEL &= ~(1<<pin_num);
	  PORTA_LOCK   = 0x4C4F434B ;
	  PORTA_CR    |= (1<<pin_num);
	}
}
void DIO_portWrite(Port_Num port_num,uint8_t data)
{
	switch(port_num)
	{
		case PORTA: PORTA_DATA =data;
		            break;
	  case PORTB: PORTB_DATA =data;
		            break;
	  case PORTC: PORTC_DATA =data;
		            break;
		case PORTD: PORTD_DATA =data;
		            break;
		case PORTE: PORTE_DATA =data;
		            break;
		case PORTF: PORTF_DATA =data;
		            break;
	}
}

uint8_t DIO_portRead(Port_Num port_num)
{
		switch(port_num)
	{
		case PORTA: return (uint8_t)PORTA_DATA;
		            
	  case PORTB: return (uint8_t)PORTA_DATA;
		            
	  case PORTC: return (uint8_t)PORTA_DATA;
		            
		case PORTD: return (uint8_t)PORTA_DATA;
		            
		case PORTE: return (uint8_t)PORTA_DATA;
		           
		case PORTF: return (uint8_t)PORTA_DATA;
	}
}

void DIO_pinWrite(Port_Num port_num,Pin_Num pin_num,Status state)
{
		switch(port_num)
	{
		case PORTA: if(state == ON)
			{
				PORTA_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTA_DATA &=~(1<<pin_num);
			}
		            break;
	  case PORTB: if(state == ON)
			{
				PORTB_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTB_DATA &=~(1<<pin_num);
			}
		            break;
	  case PORTC: if(state == ON)
			{
				PORTC_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTC_DATA &=~(1<<pin_num);
			}
		            break;
		case PORTD: if(state == ON)
			{
				PORTD_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTD_DATA &=~(1<<pin_num);
			}
		            break;
		case PORTE: if(state == ON)
			{
				PORTE_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTE_DATA &=~(1<<pin_num);
			}
		            break;
		case PORTF: if(state == ON)
			{
				PORTF_DATA |=(1<<pin_num);
			}
			else 
			{
				PORTF_DATA &=~(1<<pin_num);
			}
		            break;
	}
}

uint8_t DIO_pinRead(Port_Num port_num,Pin_Num pin_num)
{
	switch(port_num)
	{
		case PORTA: return (uint8_t)(((1<<pin_num)&PORTA_DATA)>>pin_num);
		            
	  case PORTB: return (uint8_t)(((1<<pin_num)&PORTB_DATA)>>pin_num);
		            
	  case PORTC: return (uint8_t)(((1<<pin_num)&PORTC_DATA)>>pin_num);
		            
		case PORTD: return (uint8_t)(((1<<pin_num)&PORTD_DATA)>>pin_num);
		            
		case PORTE: return (uint8_t)(((1<<pin_num)&PORTE_DATA)>>pin_num);
		           
		case PORTF: return (uint8_t)(((1<<pin_num)&PORTF_DATA)>>pin_num);
	}
}
