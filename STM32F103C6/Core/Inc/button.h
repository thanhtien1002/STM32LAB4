/*
 * button.h
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed();

void getKeyInput();
#endif /* INC_BUTTON_H_ */


