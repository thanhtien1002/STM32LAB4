/*
 * fsm_manual.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "fsm_manual.h"

void fsm_manual(void) { // START IN MANUAL MODE

    // CONFIG RED (MODE2)
    if (mode == MODE2) {
        // Blink LED RED
        switch (statusMODE2_1) {
            case INIT:
                statusMODE2_1 = TOGGLE;
                setTimer4(1);
                break;
            case TOGGLE:
                if (timer4_flag == 1) {
                    toggleREDs();
                    setTimer4(25);
                }
                break;
            default:
                break;
        }

        // Display Digit Red and Value
        switch (statusMODE2_2) {
            case INIT:
                statusMODE2_2 = HIGH_DIGIT;
                setTimer5(1);
                break;
            case HIGH_DIGIT:
                if (timer5_flag == 1) {
                    blinkDigit1(mode, AUTO_RED);
                    statusMODE2_2 = LOW_DIGIT;
                    setTimer5(25);
                }
                break;
            case LOW_DIGIT:
                if (timer5_flag == 1) {
                    blinkDigit2(mode, AUTO_RED);
                    statusMODE2_2 = HIGH_DIGIT;
                    setTimer5(25);
                }
                break;
            default:
                break;
        }

        // Change time for mode
        switch (statusMODE2_3) {
            case INIT:
                if (isButtonPressed(BUTTON2) == 1) {
                    statusMODE2_3 = INCREASE;
                    AUTO_RED++;
                }
                break;
            case INCREASE:
                if (isButtonPressed(BUTTON2) == 1) {
                    AUTO_RED += 1;
                    if (AUTO_RED > UPPER_BOUND) AUTO_RED = UPPER_BOUND;
                }
                if (isButtonPressed(BUTTON3) == 1) {
                    statusMODE2_3 = SAVE;
                }
                break;
            case SAVE:
                mode = MODE1;
                initVar();
                break;
            default:
                break;
        }

        // Continue to MODE3
        if (isButtonPressed(BUTTON1) == 1) {
            mode = MODE3;
        }
    }

    // CONFIG GREEN (MODE3)
    if (mode == MODE3) {
        // Blink LED GREEN
        switch (statusMODE3_1) {
            case INIT:
                statusMODE3_1 = TOGGLE;
                setTimer6(1);
                break;
            case TOGGLE:
                if (timer6_flag == 1) {
                    toggleGREENs();
                    setTimer6(25);
                }
                break;
            default:
                break;
        }

        // Display Digit Green and Value
        switch (statusMODE3_2) {
            case INIT:
                statusMODE3_2 = HIGH_DIGIT;
                setTimer7(1);
                break;
            case HIGH_DIGIT:
                if (timer7_flag == 1) {
                    blinkDigit1(mode, AUTO_GREEN);
                    statusMODE3_2 = LOW_DIGIT;
                    setTimer7(25);
                }
                break;
            case LOW_DIGIT:
                if (timer7_flag == 1) {
                    blinkDigit2(mode, AUTO_GREEN);
                    statusMODE3_2 = HIGH_DIGIT;
                    setTimer7(25);
                }
                break;
            default:
                break;
        }

        // Change time for mode
        switch (statusMODE3_3) {
            case INIT:
                if (isButtonPressed(BUTTON2) == 1) {
                    statusMODE3_3 = INCREASE;
                    AUTO_GREEN++;
                }
                break;
            case INCREASE:
                if (isButtonPressed(BUTTON2) == 1) {
                    AUTO_GREEN += 1;
                    if (AUTO_GREEN > UPPER_BOUND) AUTO_GREEN = UPPER_BOUND;
                }
                if (isButtonPressed(BUTTON3) == 1) {
                    statusMODE3_3 = SAVE;
                }
                break;
            case SAVE:
                mode = MODE1;
                initVar();
                break;
            default:
                break;
        }

        // Continue to MODE4
        if (isButtonPressed(BUTTON1) == 1) {
            mode = MODE4;
        }
    }

    // CONFIG YELLOW (MODE4)
    if (mode == MODE4) {
        // Blink LED YELLOW
        switch (statusMODE4_1) {
            case INIT:
                statusMODE4_1 = TOGGLE;
                setTimer8(1);
                break;
            case TOGGLE:
                if (timer8_flag == 1) {
                    toggleYELLOWs();
                    setTimer8(25);
                }
                break;
            default:
                break;
        }

        // Display Digit Yellow and Value
        switch (statusMODE4_2) {
            case INIT:
                statusMODE4_2 = HIGH_DIGIT;
                setTimer9(1);
                break;
            case HIGH_DIGIT:
                if (timer9_flag == 1) {
                    blinkDigit1(mode, AUTO_YELLOW);
                    statusMODE4_2 = LOW_DIGIT;
                    setTimer9(25);
                }
                break;
            case LOW_DIGIT:
                if (timer9_flag == 1) {
                    blinkDigit2(mode, AUTO_YELLOW);
                    statusMODE4_2 = HIGH_DIGIT;
                    setTimer9(25);
                }
                break;
            default:
                break;
        }

        // Change time for mode
        switch (statusMODE4_3) {
            case INIT:
                if (isButtonPressed(BUTTON2) == 1) {
                    statusMODE4_3 = INCREASE;
                    AUTO_YELLOW++;
                }
                break;
            case INCREASE:
                if (isButtonPressed(BUTTON2) == 1) {
                    AUTO_YELLOW += 1;
                    if (AUTO_YELLOW > UPPER_BOUND) AUTO_YELLOW = UPPER_BOUND;
                }
                if (isButtonPressed(BUTTON3) == 1) {
                    statusMODE4_3 = SAVE;
                }
                break;
            case SAVE:
                mode = MODE1;
                initVar();
                break;
            default:
                break;
        }

        // Return to MODE1
        if (isButtonPressed(BUTTON1) == 1) {
            mode = MODE1;
        }
    }
}
