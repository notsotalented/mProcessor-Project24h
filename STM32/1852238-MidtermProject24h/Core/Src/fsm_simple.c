/*
 * fsm_simple.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "fsm_simple.h"

//Simple state
void fsm_simple_buttons_run() {
	switch(state) {
	case 0:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 1;
		break;
	case 1:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 2;
		break;
	case 2:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 3;
		break;
	case 3:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 4;
		break;
	case 4:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 5;
		break;
	case 5:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 6;
		break;
	case 6:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 7;
		break;
	case 7:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 8;
		break;
	case 8:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 9;
		break;
	case 9:
		display7SEG0(state);
		setTimer1(1000);
		if (isButtonINCPressed() == 1) state = 0;
		break;
	default:
		break;
	}
}
