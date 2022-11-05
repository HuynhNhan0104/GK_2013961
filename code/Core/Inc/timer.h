/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "global.h"


extern int timer_counter[NUMBER_OF_TIMER];
extern int timer_flag[NUMBER_OF_TIMER];

void set_timer(int index, int duration);
void clear_timer(int index);
int is_timer_timeout(int index);
void timer_run();



#endif /* INC_TIMER_H_ */
