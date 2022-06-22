
 /*
 * Timer.c
 *
 *  Created on: Jun 21, 2022
 *      Author: Mars
 */


#include "ansi.h"
#include "stdio.h"
#include "stdint.h"
#include "Initialization.h"
#include "stm32f30x.h"
#include "string.h"

void TimerWindow(){
	fgcolor(2);
	moveToXY(2,0);
	for (int i = 0; i < 19; i++){
		printf("%c",205);
	}
	printf("%c", 188);
	moveUp(1);moveBack(1);
	printf("%c", 186);

	}

void startTimer(){
	TIM2->CR1 |= 0x0001; // Starting timer
}
void stopTimer(){
	TIM2->CR1 &= 0x0000; // Stopping timer
}
