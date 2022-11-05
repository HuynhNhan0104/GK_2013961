/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
//System

extern int counter;
extern int state_of_system;
//timer
#define TIME_CYCLE																							10 				//10ms
#define NUMBER_OF_TIMER 																			5

//Button
#define NUMBER_OF_BUTTON																			3

#define BUTTON_IS_PRESSED																			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED																			GPIO_PIN_SET

#define BUTTON_RELEASED																				10
#define BUTTON_PRESSED																				11
#define BUTTON_PRESSED_3S																			12


//finite state machine for single buttons


#define NORMAL																								20
#define RESET																									21
#define INCREASE																							22
#define DECREASE																							23

//finite state machine for long pressed buttons
#define LONG_INCREASE																					32
#define LONG_DECREASE																					33
#define TIME_OUT_10S																						34




#endif /* INC_GLOBAL_H_ */
