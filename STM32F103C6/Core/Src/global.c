/*
 * global.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#include "global.h"

/*------------------------------- Global Variables Initialization -------------------------------*/

// Current Mode Tracking
int mode = 0;

// Status Variables for MODE 1 (Automatic)
int statusAUTO1 = 0;
int statusAUTO2 = 0;
int statusAUTO3 = 0;
int statusAUTO4 = 0;

// Status Variables for MODE 2 (Manual)
int statusMODE2_1 = 0;
int statusMODE2_2 = 0;
int statusMODE2_3 = 0;

// Status Variables for MODE 3 (Manual)
int statusMODE3_1 = 0;
int statusMODE3_2 = 0;
int statusMODE3_3 = 0;

// Status Variables for MODE 4 (Manual)
int statusMODE4_1 = 0;
int statusMODE4_2 = 0;
int statusMODE4_3 = 0;

// Waiting Times for Each State
int AUTO_RED = 0;
int AUTO_GREEN = 0;
int AUTO_YELLOW = 0;

// Counters for Each Traffic Light Side
int counterRed1 = 0;
int counterGreen1 = 0;
int counterYellow1 = 0;

int counterRed2 = 0;
int counterGreen2 = 0;
int counterYellow2 = 0;

/*------------------------------- Function Implementations -------------------------------*/

void initWaitingTime(void) {
    AUTO_GREEN = 2;
    AUTO_YELLOW = 1;
    AUTO_RED = AUTO_GREEN + AUTO_YELLOW;
}

void initVar(void) {
    mode = MODE1;

    // Initialize status variables for Automatic Mode (MODE 1)
    statusAUTO1 = INIT;
    statusAUTO2 = INIT;
    statusAUTO3 = INIT;
    statusAUTO4 = INIT;

    // Initialize status variables for Manual Mode (MODE 2)
    statusMODE2_1 = INIT;
    statusMODE2_2 = INIT;
    statusMODE2_3 = INIT;

    // Initialize status variables for Manual Mode (MODE 3)
    statusMODE3_1 = INIT;
    statusMODE3_2 = INIT;
    statusMODE3_3 = INIT;

    // Initialize status variables for Manual Mode (MODE 4)
    statusMODE4_1 = INIT;
    statusMODE4_2 = INIT;
    statusMODE4_3 = INIT;

    // Initialize counters for each traffic light side
    counterRed1 = AUTO_RED;
    counterGreen1 = AUTO_GREEN;
    counterYellow1 = AUTO_YELLOW;

    counterRed2 = AUTO_RED;
    counterGreen2 = AUTO_GREEN;
    counterYellow2 = AUTO_YELLOW;
}
