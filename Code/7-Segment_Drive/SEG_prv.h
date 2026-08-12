/*
 * SEG_prv.h
 *
 *  Created on: Aug 10, 2026
 *      Author: DeLL
 *
 *  Private lookup table for the 7-segment driver.
 *  Common Anode ==> segment ON = 0 , segment OFF = 1
 *  Bit order on the port : bit0=a bit1=b bit2=c bit3=d bit4=e bit5=f bit6=g bit7=dp
 *  (dp is always kept OFF "1" in this table, we don't use it)
 */

#ifndef SEG_PRV_H_
#define SEG_PRV_H_

#define SEG_u8ALL_OFF   0xFFu

static const uint8 SEG_au8Numbers[10] =
{
	0b11000000, /* 0 */
	0b11111001, /* 1 */
	0b10100100, /* 2 */
	0b10110000, /* 3 */
	0b10011001, /* 4 */
	0b10010010, /* 5 */
	0b10000010, /* 6 */
	0b11111000, /* 7 */
	0b10000000, /* 8 */
	0b10010000  /* 9 */
};

#endif /* SEG_PRV_H_ */
