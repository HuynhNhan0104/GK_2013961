/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"


//timer
#define TIME_CYCLE																							10 				//10ms
#define NUMBER_OF_TIMER 																			3

//Button
#define NUMBER_OF_BUTTON																			3

#define BUTTON_IS_PRESSED																			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED																			GPIO_PIN_SET

#define BUTTON_RELEASED																				10
#define BUTTON_PRESSED																				11
#define BUTTON_PRESSED_1S																			12
#define BUTTON_SINGLE_CLICK																		13
#define BUTTON_DOUBLE_CLICK																		14


#endif /* INC_GLOBAL_H_ */
