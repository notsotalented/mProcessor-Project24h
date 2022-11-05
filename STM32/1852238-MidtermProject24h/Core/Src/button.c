/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#include "button.h"

int button_inc_flag = 0;
int button_dec_flag = 0;
int button_reset_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;

int TimerForKeyPress = 200;

int isButtonINCPressed() {
	if(button_inc_flag == 1) {
		button_inc_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonDECPressed() {
	if(button_dec_flag == 1) {
		button_dec_flag = 0;
		return 1;
	}
	return 0;
}

int isButtonRESETPressed() {
	if(button_reset_flag == 1) {
		button_reset_flag = 0;
		return 1;
	}
	return 0;
}

//This func do work
void subKeyProcess(int which) {
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button_inc_flag = 1;
	button_dec_flag = 1;
	button_reset_flag = 1;
}

void getKeyInput(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = KeyReg2;


	  KeyReg2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);



	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
		  if (KeyReg3 != KeyReg2) {
			  KeyReg3 = KeyReg2;
			  if (KeyReg2 == PRESSED_STATE) {
				  //TODO
				  subKeyProcess();
				  TimerForKeyPress = 200;
			  }
		  }
		  else {
			  TimerForKeyPress--;
			  if (TimerForKeyPress == 0) {
				  //TODO
				  KeyReg3 = NORMAL_STATE;
			  }
		  }
	  }


}