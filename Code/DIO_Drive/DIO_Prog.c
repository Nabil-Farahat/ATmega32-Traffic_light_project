/*
 * DIO_Prog.c
 *
 *  Created on: Aug 8, 2026
 *      Author: DeLL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Reg.h"
#include "DIO_Cfg.h"
#include "DIO_interface.h"
#include "DIO_Prv.h"
#include "defines.h"

uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Direction)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8Pin >= DIO_u8PIN0 && Copy_u8Pin <= DIO_u8PIN7 )
	{
		if(Copy_u8Direction == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;
			}
		}else if (Copy_u8Direction == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;
			}

		}else
		{
			Local_u8ErrorState = NOK;
		}
	}else
	{
		Local_u8ErrorState =NOK;
	}

	return Local_u8ErrorState;
}

uint8 DIO_u8SetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Value)

{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8Pin >= DIO_u8PIN0 && Copy_u8Pin <= DIO_u8PIN7 )
	{
		if(Copy_u8Value == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;
			}
		}else if (Copy_u8Value == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
			default:Local_u8ErrorState = NOK;break;
			}

		}else
		{
			Local_u8ErrorState = NOK;
		}
	}else
	{
		Local_u8ErrorState =NOK;
	}

	return Local_u8ErrorState;
}

uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port,uint8 Copy_u8Direction)
{
	uint8 Local_u8ErrorState = OK;

	if((Copy_u8Direction == DIO_u8PORT_OUTPUT) || (Copy_u8Direction == DIO_u8PORT_INPUT))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : DDRA = Copy_u8Direction ;break;
		case DIO_u8PORTB : DDRB = Copy_u8Direction ;break;
		case DIO_u8PORTC : DDRC = Copy_u8Direction ;break;
		case DIO_u8PORTD : DDRD = Copy_u8Direction ;break;
		default:Local_u8ErrorState = NOK;break;
		}
	}else
	{
		Local_u8ErrorState = NOK;
	}


	return Local_u8ErrorState;
}

uint8 DIO_u8SetPortValue(uint8 Copy_u8Port,uint8 Copy_u8Value)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : PORTA = Copy_u8Value ;break;
	case DIO_u8PORTB : PORTB = Copy_u8Value ;break;
	case DIO_u8PORTC : PORTC = Copy_u8Value ;break;
	case DIO_u8PORTD : PORTD = Copy_u8Value ;break;
	default:Local_u8ErrorState = NOK;break;
	}


	return Local_u8ErrorState;
}


uint8 DIO_u8GetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8* Pu8_State)
{
	uint8 Local_u8ErrorState = OK;

	if(Pu8_State != NULL)
	{
		if(Copy_u8Pin >= DIO_u8PIN0 && Copy_u8Pin <= DIO_u8PIN7 )
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA :  *(Pu8_State) = PINA;break ;
			case DIO_u8PORTB :  *(Pu8_State) = PINB;break ;
			case DIO_u8PORTC :  *(Pu8_State) = PINC;break ;
			case DIO_u8PORTD :  *(Pu8_State) = PIND;break ;
			default:Local_u8ErrorState = NOK;break;
			}

		}else
		{
			Local_u8ErrorState = NOK;
		}
	}else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;

}

uint8 DIO_u8TogglePin(uint8 Copy_u8Port,uint8 Copy_u8Pin)
{
	uint8 Local_u8ErrorState = OK;


	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : TOGGLE_BIT(PORTA,Copy_u8Pin) ;break;
	case DIO_u8PORTB : TOGGLE_BIT(PORTB,Copy_u8Pin);break;
	case DIO_u8PORTC : TOGGLE_BIT(PORTC,Copy_u8Pin);break;
	case DIO_u8PORTD : TOGGLE_BIT(PORTD,Copy_u8Pin);break;
	default:Local_u8ErrorState = NOK;break;
	}

return Local_u8ErrorState;
}
