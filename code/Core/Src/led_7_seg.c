/*
 * led_7_seg.c
 *
 *  Created on: Nov 4, 2022
 *      Author: NHAN
 */

/*
void turn_on_led_7seg(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, RESET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin( GPIOB, EN0_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN1_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN2_Pin, SET);
		HAL_GPIO_WritePin( GPIOB, EN3_Pin, SET);
		break;
	}
}
/////////////////////////////////////////////S
void display_led_7seg(int number){
	switch(number){
	case 0:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_A_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_B_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_C_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_D_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_E_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_F_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_G_Pin, RESET);
		break;
	default:
		break;
	}
}

*/
