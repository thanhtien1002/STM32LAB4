/*
 * fsm_automatic.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "fsm_automatic.h"

int led_buffer[2] = {0, 0};

void fsm_automatic(void){
	if (mode == MODE1){
		// AUTO MODE 1
		switch (statusAUTO1){
			case INIT:
				statusAUTO1 = STATE_RED;
				setTimer1(100);
				break;
			case STATE_RED:
				if (timer1_flag == 1){
					enableRed1();
					led_buffer[0] = counterRed1;
					counterRed1--;
					if (counterRed1 == INIT){
						counterRed1 = AUTO_RED;
						statusAUTO1 = STATE_GREEN;
					}
					setTimer1(100);
				}
				break;
			case STATE_GREEN:
				if (timer1_flag == 1){
					enableGreen1();
					led_buffer[0] = counterGreen1;
					counterGreen1--;
					if (counterGreen1 == INIT){
						counterGreen1 = AUTO_GREEN;
						statusAUTO1 = STATE_YELLOW;
					}
					setTimer1(100);
				}
				break;
			case STATE_YELLOW:
				if (timer1_flag == 1){
					enableYellow1();
					led_buffer[0] = counterYellow1;
					counterYellow1--;
					if (counterYellow1 == INIT){
						counterYellow1 = AUTO_YELLOW;
						statusAUTO1 = STATE_RED;
					}
					setTimer1(100);
				}
				break;
			default:
				break;
		}

		// AUTO MODE 2
		switch (statusAUTO2){
			case INIT:
				statusAUTO2 = STATE_GREEN;
				setTimer2(100);
				break;
			case STATE_RED:
				if (timer2_flag == 1){
					enableRed2();
					led_buffer[1] = counterRed2;
					counterRed2--;
					if (counterRed2 == INIT){
						counterRed2 = AUTO_RED;
						statusAUTO2 = STATE_GREEN;
					}
					setTimer2(100);
				}
				break;
			case STATE_GREEN:
				if (timer2_flag == 1){
					enableGreen2();
					led_buffer[1] = counterGreen2;
					counterGreen2--;
					if (counterGreen2 == INIT){
						counterGreen2 = AUTO_GREEN;
						statusAUTO2 = STATE_YELLOW;
					}
					setTimer2(100);
				}
				break;
			case STATE_YELLOW:
				if (timer2_flag == 1){
					enableYellow2();
					led_buffer[1] = counterYellow2;
					counterYellow2--;
					if (counterYellow2 == INIT){
						counterYellow2 = AUTO_YELLOW;
						statusAUTO2 = STATE_RED;
					}
					setTimer2(100);
				}
				break;
			default:
				break;
		}

		// AUTO MODE 3 - DISPLAY WAITING TIME
		switch (statusAUTO3){
			case INIT:
				statusAUTO3 = HIGH_DIGIT;
				setTimer3(100);
				break;
			case HIGH_DIGIT:
				if (timer3_flag == 1){
					blinkDigit1(led_buffer[0], led_buffer[1]);
					statusAUTO3 = LOW_DIGIT;
					setTimer3(50);
				}
				break;
			case LOW_DIGIT:
				if (timer3_flag == 1){
					blinkDigit2(led_buffer[0], led_buffer[1]);
					statusAUTO3 = HIGH_DIGIT;
					setTimer3(50);
				}
				break;
			default:
				break;
		}

		// CHANGE MODE
		switch(statusAUTO4){
			case INIT:
				if (isButtonPressed(BUTTON1) == 1)
					mode = MODE2;
				break;
			case MODE2:
				if (isButtonPressed(BUTTON1) == 1)
					mode = MODE3;
				break;
			case MODE3:
				if (isButtonPressed(BUTTON1) == 1)
					mode = MODE1;
				initVar();
				break;
			default:
				break;
		}
	}
}

