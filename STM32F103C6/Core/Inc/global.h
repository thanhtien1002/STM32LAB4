/*
 * global.h
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"

/*-------------------------------- State Definitions -------------------------------*/
#define INIT 0

// Automatic Mode (MODE 1)
#define STATE_RED 1
#define STATE_GREEN 2
#define STATE_YELLOW 3

// Manual Modes (MODE 2, 3, 4)
#define TOGGLE 1
#define INCREASE 2
#define DECREASE 3
#define SAVE 4

// 7-Segment LED Digits
#define HIGH_DIGIT 1
#define LOW_DIGIT 2

// Threshold for waiting time
#define UPPER_BOUND 99
#define LOWER_BOUND 1

/*----------------------------- Available Modes --------------------------------*/
#define MODE1  1
#define MODE2  2
#define MODE3  3
#define MODE4  4

/*----------------------------- Available Buttons ------------------------------*/
#define NUM_OF_BUTTON 4
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2

/*------------------------------- Global Variables ------------------------------*/
// Current Mode Tracking
extern int mode;

// Waiting Times for Each State
extern int AUTO_RED;
extern int AUTO_GREEN;
extern int AUTO_YELLOW;

// Counters for Each Traffic Light Side
extern int counterRed1;
extern int counterGreen1;
extern int counterYellow1;

extern int counterRed2;
extern int counterGreen2;
extern int counterYellow2;

// Status Variables for MODE 1 (Automatic)
extern int statusAUTO1; // Traffic light display
extern int statusAUTO2;
extern int statusAUTO3; // Countdown number display
extern int statusAUTO4; // Mode switching

// Status Variables for MODE 2 (Manual)
extern int statusMODE2_1; // LED blinking
extern int statusMODE2_2; // Mode and value display
extern int statusMODE2_3; // Adjust waiting time

// Status Variables for MODE 3 (Manual)
extern int statusMODE3_1; // LED blinking
extern int statusMODE3_2; // Mode and value display
extern int statusMODE3_3; // Adjust waiting time

// Status Variables for MODE 4 (Manual)
extern int statusMODE4_1; // LED blinking
extern int statusMODE4_2; // Mode and value display
extern int statusMODE4_3; // Adjust waiting time

/*------------------------------- Function Prototypes ------------------------------*/
void initWaitingTime(void);
void initVar(void);

#endif /* INC_GLOBAL_H_ */
