/*
 * button.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "button.h"

int buttonList[NUM_OF_BUTTON] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeForKeyPress =  200;
int button_flag[NUM_OF_BUTTON] = {0, 0, 0};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int i=0; i<NUM_OF_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
	    KeyReg1[i] = KeyReg0[i];
	    KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, buttonList[i]);
	    if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		   if (KeyReg2[i] != KeyReg3[i]){
		      KeyReg3[i] = KeyReg2[i];

		      if (KeyReg3[i] == PRESSED_STATE){
			     TimeForKeyPress = 200;
			     subKeyProcess(i);
		      }
		   } else {
			   	  TimeForKeyPress--;
			      if (TimeForKeyPress == 0){
			      KeyReg3[i] = NORMAL_STATE;
			      }
		     }
	    }
	}
}


