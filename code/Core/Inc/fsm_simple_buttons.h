/*
 * fms_simple_buttons.h
 *
 *  Created on: Nov 5, 2022
 *      Author: NHAN
 */

#ifndef INC_FSM_SIMPLE_BUTTONS_H_
#define INC_FSM_SIMPLE_BUTTONS_H_
#include "global.h"
#include "timer.h"
#include "button.h"
#include "led_7_seg.h"

void blinking_led_red();
void fsm_simple_buttons_run();
void fsm_long_buttons_run();
void fsm_timeout_10s_run();

#endif /* INC_FSM_SIMPLE_BUTTONS_H_ */
