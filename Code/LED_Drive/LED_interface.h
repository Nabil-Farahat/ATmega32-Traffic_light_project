/*
 * LED_interface.h
 *
 *  Created on: Aug 10, 2026
 *      Author: DeLL
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define SINK_u8CONNECTION      0u
#define SOURCE_u8CONNECTION    1u

/*
 * @brief:our function is used to turn on the led based on connection type
 * @param: Copy_u8Port: is used to define which port that the led is connected on it
 * @param: Copy_u8Pin: is used to define which pin that the led is connected on it
 * @param: Copy_u8Connection: is used to define the connection of the led is sink or source
 * return: Local_u8ErrorState : carry return error state
 */
uint8 LED_u8TurnOn(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Connection);

/*
 * @brief:our function is used to turn off the led based on connection type
 * @param: Copy_u8Port: is used to define which port that the led is connected on it
 * @param: Copy_u8Pin: is used to define which pin that the led is connected on it
 * @param: Copy_u8Connection: is used to define the connection of the led is sink or source
 * return: Local_u8ErrorState : carry return error state
 */
uint8 LED_u8TurnOff(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Connection);

/*
 * @brief:our function is used to  toggle the led based on connection type
 * @param: Copy_u8Port: is used to define which port that the led is connected on it
 * @param: Copy_u8Pin: is used to define which pin that the led is connected on it
 * @param: Copy_u8Connection: is used to define the connection of the led is sink or source
 * return: Local_u8ErrorState : carry return error state
 */
uint8 LED_u8Toggle(uint8 Copy_u8Port,uint8 Copy_u8Pin);

#endif /* LED_INTERFACE_H_ */
