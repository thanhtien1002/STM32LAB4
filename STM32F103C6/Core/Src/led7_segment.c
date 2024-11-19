/*
 * led7_segment.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ASUS
 */
#include "led7_segment.h"
#include "main.h"

const uint8_t sevenSegTable[10] = {
		  0x40 //0
		, 0x79 //1
		, 0x24 //2
		, 0x30 //3
		, 0x19 //4
		, 0x12 //5
		, 0x02 //6
		, 0x78 //7
		, 0x00 //8
		, 0x10 /*9*/};

void display7SEG1(int num){
	HAL_GPIO_WritePin(A0_GPIO_Port, A0_Pin, ((sevenSegTable[num]>>0)&0x01));
	HAL_GPIO_WritePin(B0_GPIO_Port, B0_Pin, ((sevenSegTable[num]>>1)&0x01));
	HAL_GPIO_WritePin(C0_GPIO_Port, C0_Pin, ((sevenSegTable[num]>>2)&0x01));
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, ((sevenSegTable[num]>>3)&0x01));
	HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, ((sevenSegTable[num]>>4)&0x01));
	HAL_GPIO_WritePin(F0_GPIO_Port, F0_Pin, ((sevenSegTable[num]>>5)&0x01));
	HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, ((sevenSegTable[num]>>6)&0x01));
}

void display7SEG2(int num){
	HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, ((sevenSegTable[num]>>0)&0x01));
	HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, ((sevenSegTable[num]>>1)&0x01));
	HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, ((sevenSegTable[num]>>2)&0x01));
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, ((sevenSegTable[num]>>3)&0x01));
	HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, ((sevenSegTable[num]>>4)&0x01));
	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, ((sevenSegTable[num]>>5)&0x01));
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, ((sevenSegTable[num]>>6)&0x01));
}

void blinkDigit1(int num1, int num2){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	display7SEG1(num1/10);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	display7SEG2(num2/10);
}

void blinkDigit2(int num1, int num2){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	display7SEG1(num1%10);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	display7SEG2(num2%10);
}
