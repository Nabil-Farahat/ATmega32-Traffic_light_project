/*
 * SEG_pro.c
 *
 *  Created on: Aug 10, 2026
 *      Author: DeLL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"
#include "SEG_interface.h"
#include "SEG_prv.h"
#include "DIO_interface.h"

/*
 * @brief: our function is used to display a digit (0-9) on the 7-segment
 * @param: Copy_u8Port  : the port that the 7-segment is connected on it
 * @param: Copy_u8Number: the digit to display, valid range 0->9
 * return: Local_u8ErrorState : carry return error state
 */
uint8 SEG_u8DisplayNumber(uint8 Copy_u8Port, uint8 Copy_u8Number)
{
	uint8 Local_u8ErrorState = OK;

	if((Copy_u8Port >= DIO_u8PORTA && Copy_u8Port <= DIO_u8PORTD) && (Copy_u8Number <= 9u))
	{
		/* write the whole pattern in one shot on the port */
		DIO_u8SetPortValue(Copy_u8Port, SEG_au8Numbers[Copy_u8Number]);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/*
 * @brief: our function is used to turn off all the segments (including dp)
 * @param: Copy_u8Port  : the port that the 7-segment is connected on it
 * return: Local_u8ErrorState : carry return error state
 */
uint8 SEG_u8TurnOff(uint8 Copy_u8Port)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8Port >= DIO_u8PORTA && Copy_u8Port <= DIO_u8PORTD)
	{
		DIO_u8SetPortValue(Copy_u8Port, SEG_u8ALL_OFF);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
