/*
 * fsm_led.c
 *
 *  Created on: Nov 6, 2022
 *      Author: ASUS
 */

#include "fsm_led.h"

void fsm_led_run() {
	if (timer1_flag == 1) {
		setTimer1(100);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}
}
