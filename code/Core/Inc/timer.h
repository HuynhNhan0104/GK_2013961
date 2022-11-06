/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "global.h"

//timer 0 for button 0 ( index = 0)
//timer 1 for button 1 ( index = 1)
//timer 2 for button 2 ( index = 2)
//timer 3 for system count down ( index = 3)
// timer 4 for linking led red ( index = 4)


extern int timer_counter[NUMBER_OF_TIMER];
extern int timer_flag[NUMBER_OF_TIMER];

void set_timer(int index, int duration);
void clear_timer(int index);
int is_timer_timeout(int index);
void timer_run();



#endif /* INC_TIMER_H_ */
