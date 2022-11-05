/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_inc_flag;
extern int button_dec_flag;
extern int button_reset_flag;

extern int isButtonINCPressed();
extern int isButtonDECPressed();
extern int isButtonRESPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
