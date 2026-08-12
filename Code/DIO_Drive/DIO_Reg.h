/*
 * DIO_Reg.h
 *
 *  Created on: Aug 8, 2026
 *      Author: DeLL
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/* register addresses for group A */
#define DDRA    *((volatile uint8*)0x3A)
#define PORTA    *((volatile uint8*)0x3B)
#define PINA    *((volatile uint8*)0x39)

/* register addresses for group B */
#define DDRB  	*((volatile uint8*)0x37)
#define PORTB  	 *((volatile uint8*)0x38)
#define PINB  	*((volatile uint8*)0x36)

/* register addresses for group C */
#define DDRC 	*((volatile uint8*)0x34)
#define PORTC 	 *((volatile uint8*)0x35)
#define PINC 	*((volatile uint8*)0x33)

/* register addresses for group D */
#define DDRD    *((volatile uint8*)0x31)
#define PORTD    *((volatile uint8*)0x32)
#define PIND    *((volatile uint8*)0x30)

#endif /* DIO_REG_H_ */
