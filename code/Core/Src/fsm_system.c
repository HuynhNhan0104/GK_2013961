/*
 * fms_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: NHAN
 */


#include <fsm_system.h>



void blinking_led_red(){
	if(is_timer_timeout(4)){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		set_timer(4, 500);
	}
}



void fsm_simple_buttons_run(){


	switch(state_of_system){
	case INIT:
		// trang thai ban dau cua he thong
		counter = 5;
		display_led_7seg(counter);
		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_SET);
		set_timer(3, 10000);
		set_timer(4, 500);
		state_of_system = NORMAL;

	break;

	case NORMAL:
		// O Trang thai NORMAL he thong luc nay se ko lam gi
		//Button RESET(index = 0) duoc nhan se chuyen sang trang thai RESET
		if( is_pressed(0) ){
			clear_timer(3);
			state_of_system = RESET;
		}
		//Button INC (index = 1) duoc nhan se chuyen sang trang thai INCREASE
		if( is_pressed(1) ){
			clear_timer(3);
			++counter;
			if(counter > 9) counter = 0;
			state_of_system = INCREASE;
		}
		//Button DEC (index = 2) duoc nhan se chuyen sang trang thai  DECREASE
		if( is_pressed(2) ){
			clear_timer(3);
			if(counter >0) --counter;
			else  counter = 9;
			state_of_system = DECREASE;
		}

		//Khi het 10s khong lam gi he thong se chuyen sang trang thai TIME_OUT_10S
		if(is_timer_timeout(3)){

			if(counter > 0) --counter;
			display_led_7seg(counter);
			set_timer(3, 1000);
			state_of_system = TIME_OUT_10S;
		}
	break;

	case RESET:
		//dua counter ve 0;
		counter = 0;
		// BUTTON RESET(index = 0) duoc tha se tro lai trang thai NORMAL
		if( is_button_released(0)){
			//set timer bang 10s(10000ms) de dem thoi gian ko lam gi cua he thong
			set_timer(3,10000);
			state_of_system = NORMAL;
		}

	break;

	case INCREASE:
		// BUTTON INC(index = 1) duoc tha se tro lai trang thai NORMAL
		if( is_button_released(1)){
			set_timer(3,10000);
			state_of_system = NORMAL;
		}

		//Button INC(index = 1) duoc nhan de 3s giay se chuyen sang trang thai LONG_INCREASE;
		if( is_pressed_3s(1) ){
			// tang counter len 1 moi 1 giay khi nut con duoc nhan de
			++counter;
			if(counter > 9) counter = 0;
			set_timer(3, 1000);
			state_of_system = LONG_INCREASE;
		}

		break;

	case DECREASE:
		//todo
		if( is_button_released(2)){
			set_timer(3,10000);
			state_of_system = NORMAL;
		}

		//BUTTON DEC (index = 2) đuoc tha se tro lai trang thai NORMAL
		if( is_pressed_3s(2) ){
			// giam counter len 1 moi 1 giay khi nut con duoc nhan de
			if(counter >0) --counter;
			else  counter = 9;
			set_timer(3, 1000);
			state_of_system = LONG_DECREASE;
		}


	break;
	default:
	break;
	}
}




void fsm_long_buttons_run(){
	switch(state_of_system){
	case LONG_INCREASE:
		 // truoc khi chuyen qua trang thai LONG_INCREASE, ta se set thoi gian cho timer3 la 1 giay va tang counter len 1
		// neu BUTTON INC(index = 1) khong duoc tha thi ta se lap lai moi giay de tang counter len 1

		//timer(3) het gio se tang counter len 1.
		if( is_timer_timeout(3) ){
			//lap lai moi 1 giay cho den khi
			++counter;
			if(counter > 9) counter = 0;
			set_timer(3,1000);
		}
        //BUTTON INC(index = 1) duoc tha se tro ve trang thai NORMAL.
		if( is_button_released(1)){
    		//ta se clear timer de timer ko tiep tuc chay dan den ket qua sai khi sang trang thai khac.
			//Deu nay la rat quan trong de trang cac loi phien toai va ra kho debug.
			clear_timer(3);
			set_timer(3,10000);
			state_of_system = NORMAL;
		}
		break;
	case LONG_DECREASE:
    	//tuong tu nhu voi trang thai LONG_INCREASE chi khac thay vi tang thi ta se giam
		if( is_timer_timeout(3) ){
			if(counter >0) --counter;
			else  counter = 9;
			set_timer(3,1000);
		}
		if( is_button_released(2)){
			clear_timer(3);
			set_timer(3,10000);
			state_of_system = NORMAL;
		}
		break;
	default:
	break;
	}
}
void fsm_timeout_10s_run(){
	switch(state_of_system){

	case TIME_OUT_10S:
		// cac trang thai khac khi 3 BUTTON ko duoc nhan se deu tro ve trang thai NORMAL
		// O trang thai nay ta se giam counter di 1 moi 1 giay
		//cho den khi counter = 0 thi ta se khong giam nua
		if(counter > 0) {
			if( is_timer_timeout(3)){
				 --counter;
				 set_timer(3,1000);
			}
		}
		// khi counter = 0 ta se ko can set timer nua
		else clear_timer(3);

		//Button RESET(index = 0) duoc nhan
		if( is_pressed(0) ){
		    // clear timer truoc khi chuyen sang trang thai khac
			clear_timer(3);
			state_of_system = RESET;
		}

		//Button INC (index = 1) duoc nhan
		if( is_pressed(1) ){
			clear_timer(3);
			 ++counter;
			if(counter >9) counter = 0;
			state_of_system = INCREASE;
		}

		//Button DEC (index = 2) duoc nhan
		if( is_pressed(2) ){
			clear_timer(3);
			if(counter >0) --counter;
			else  counter = 9;
			state_of_system = DECREASE;
		}
	break;

	default:
	break;
	}
}



