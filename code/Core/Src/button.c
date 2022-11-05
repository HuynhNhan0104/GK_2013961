
/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */
#include "button.h"

int state_of_button[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON - 1] = BUTTON_RELEASED};

int flag_for_pressed[NUMBER_OF_BUTTON] = {0};
int flag_for_pressed_1s[NUMBER_OF_BUTTON] = {0};
int flag_for_double_click[NUMBER_OF_BUTTON] = {0};


int is_pressed(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_for_pressed[index]){
		flag_for_pressed[index] = 0;
		return 1;
	}
	return 0;
}
int is_pressed_1s(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_for_pressed_1s[index]){
		flag_for_pressed_1s[index] = 0;
		return 1;
	}
	return 0;
}

int is_double_click(int index){
	if(index > NUMBER_OF_BUTTON) return 0;
	if(flag_for_double_click[index]){
		flag_for_double_click[index] = 0;
		return 1;
	}
	return 0;
}




int register0_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register1_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int register2_key[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};
int button_buffer[NUMBER_OF_BUTTON] = {[0 ... NUMBER_OF_BUTTON-1] = BUTTON_IS_RELEASED};



void read_input(){
	for(int i = 0 ; i < NUMBER_OF_BUTTON; ++i){
		register0_key[i] = register1_key[i];
		register1_key[i] = register2_key[i];
		switch(i){
		case 0 :
			 register2_key[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON0_Pin);
			break;
		case 1:
			register2_key[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON1_Pin);
			break;
		case 2:
			register2_key[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON2_Pin);
			break;
		default:
			break;
		}

		if(register0_key[i] == register1_key[i] && register1_key[i] == register2_key[i]){
			button_buffer[i] = register2_key[i];
		}
	}
}

void fms_for_button(){
	for(int i = 0; i < NUMBER_OF_BUTTON; ++i){
		switch(state_of_button[i]){
		case BUTTON_RELEASED:
			if(button_buffer[i] == BUTTON_IS_PRESSED){
				flag_for_pressed[i] = 1;
				set_timer(i, 1000);
				state_of_button[i] = BUTTON_PRESSED;
			}

			break;
		case BUTTON_PRESSED:


			if(is_timer_timeout(i)){
				flag_for_pressed_1s[i] = 1;
				state_of_button[i] = BUTTON_PRESSED_1S;
			}

			if(button_buffer[i] == BUTTON_IS_RELEASED){
				set_timer(i, 200);
				state_of_button[i] = BUTTON_SINGLE_CLICK;
			}
			break;
		case BUTTON_PRESSED_1S:
			if(button_buffer[i] == BUTTON_IS_RELEASED){
				state_of_button[i] = BUTTON_RELEASED;
			}

			break;
		case BUTTON_SINGLE_CLICK:

			if(button_buffer[i] == BUTTON_IS_PRESSED){
				flag_for_double_click[i] = 1;
			}

			if(is_timer_timeout(i)){
				state_of_button[i] = BUTTON_RELEASED;
			}

			break;
		case BUTTON_DOUBLE_CLICK:
			if(button_buffer[i] == BUTTON_IS_RELEASED){
				state_of_button[i] = BUTTON_RELEASED;
			}


			break;
		default:
			break;



		}
	}
}





