/*
 * SEG_interface.h
 *
 *  Created on: Aug 10, 2026
 *      Author: DeLL
 *
 *  Driver for a single Common-Anode 7-Segment display
 *  connected directly (8 pins) to ONE full port:
 *  Pin0=a  Pin1=b  Pin2=c  Pin3=d  Pin4=e  Pin5=f  Pin6=g  Pin7=dp
 */

#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

/*
 * @brief: our function is used to display a digit (0-9) on the 7-segment
 * @param: Copy_u8Port  : the port that the 7-segment is connected on it
 * @param: Copy_u8Number: the digit to display, valid range 0->9
 * return: Local_u8ErrorState : carry return error state
 */
uint8 SEG_u8DisplayNumber(uint8 Copy_u8Port, uint8 Copy_u8Number);

/*
 * @brief: our function is used to turn off all the segments (including dp)
 * @param: Copy_u8Port  : the port that the 7-segment is connected on it
 * return: Local_u8ErrorState : carry return error state
 */
uint8 SEG_u8TurnOff(uint8 Copy_u8Port);

#endif /* SEG_INTERFACE_H_ */
