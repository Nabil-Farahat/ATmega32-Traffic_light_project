/*
 * main.c
 *
 *  Created on: Aug 10, 2026
 *      Author: DeLL
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include <util/delay.h>

#include "LED_interface.h"
#include "SEG_interface.h"
#include "DIO_interface.h"

/* Phase definitions for the State */
#define STATE_GREEN        0
#define STATE_YELLOW_1     1
#define STATE_RED          2
#define STATE_YELLOW_2     3

int main(void)
{
	/* Configure I/O Directions for LEDs */
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_OUTPUT);

	/* Configure 7-Segment Ports */
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_OUTPUT); // Tens Digit
	DIO_u8SetPortDirection(DIO_u8PORTC, DIO_u8PORT_OUTPUT); // Units Digit

	uint8 Local_u8Seconds = 0;
	uint8 LocalPhase_u8Counter = STATE_GREEN;

	while (1)
	{
		/* Calculate digits */
		uint8 LocalA_u8Counter = Local_u8Seconds / 10;
		uint8 LocalC_u8Counter = Local_u8Seconds % 10;

		/* Display numbers on 7-Segment Displays */
		SEG_u8DisplayNumber(DIO_u8PORTA, LocalA_u8Counter);
		SEG_u8DisplayNumber(DIO_u8PORTC, LocalC_u8Counter);

		/* Handle Traffic Light States */
		switch (LocalPhase_u8Counter)
		{
		case STATE_GREEN:
			LED_u8TurnOn(DIO_u8PORTB, DIO_u8PIN2, SOURCE_u8CONNECTION);
			LED_u8TurnOff(DIO_u8PORTB, DIO_u8PIN1, SOURCE_u8CONNECTION);
			if (Local_u8Seconds >= 15)
			{
				Local_u8Seconds = 0;
				LocalPhase_u8Counter = STATE_YELLOW_1;
			}
			break;
		case STATE_YELLOW_1:
			LED_u8TurnOff(DIO_u8PORTB, DIO_u8PIN2, SOURCE_u8CONNECTION);
			LED_u8TurnOn(DIO_u8PORTB, DIO_u8PIN1, SOURCE_u8CONNECTION);
			if (Local_u8Seconds >= 3)
			{
				Local_u8Seconds = 0;
				LocalPhase_u8Counter = STATE_RED;
			}
			break;
		case STATE_RED:
			LED_u8TurnOff(DIO_u8PORTB, DIO_u8PIN1, SOURCE_u8CONNECTION);
			LED_u8TurnOn(DIO_u8PORTB, DIO_u8PIN0, SOURCE_u8CONNECTION);
			if (Local_u8Seconds >= 15)
			{
				Local_u8Seconds = 0;
				LocalPhase_u8Counter = STATE_YELLOW_2;
			}
			break;
		case STATE_YELLOW_2:
			LED_u8TurnOn(DIO_u8PORTB, DIO_u8PIN1, SOURCE_u8CONNECTION);
			LED_u8TurnOff(DIO_u8PORTB, DIO_u8PIN0, SOURCE_u8CONNECTION);
			if (Local_u8Seconds >= 3)
			{
				Local_u8Seconds = 0;
				LocalPhase_u8Counter = STATE_GREEN;
			}
			break;
		default:
			LocalPhase_u8Counter = STATE_GREEN;
			break;
		}

		_delay_ms(300); // 1-second delay tick
		Local_u8Seconds++;
	}
}
