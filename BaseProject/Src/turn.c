/*
 * turn.c
 *
 *  Created on: 21. jun. 2022
 *      Author: Tnopn
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include <time.h>
#include <stdlib.h>
#include <sin.h>
#include "charset.h"
#include "visuals.h"
#include "random.h"
#include "fixed.h"
#include "shoot.h"
#include "gameplay.h"
#include "structs.h"
#include "initialization.h"
#include "menu.h"
#include "meteor.h"
#include "lcd.h"
#include "Endgame.h"
#include "Vinkel.h"
#include "Timer.h"
#include "Movement.h"

typedef struct{
		int hours;
		int minutes;
		int seconds;
		int hundreds;
	}timer;

static timer timer2;


void TIM2_IRQHandler(void) {

	timer2.hundreds++;

	if (timer2.hundreds == 100){
		timer2.seconds++;
		timer2.hundreds = 0;
	}
	if (timer2.seconds == 60){
		timer2.minutes++;
		timer2.seconds = 0;

		if (timer2.minutes == 60){
			timer2.hours++;
			timer2.minutes = 0;
		}
	}
	TIM2->SR &= ~0x0001; // Clear interrupt bit
}

void turn(int Height[] ,int baseHeight, tank_t * tiger, tank_t * sherman, powerUp_t powerUp, uint16_t variabel,int win, int t){
	int fire=0;
	if (win==1){
		EndGame(timer2.hours, timer2.minutes, timer2.seconds,*tiger,*sherman);
		setLed(0,1,1);
	} else if (win==2){
		EndGame(timer2.hours, timer2.minutes, timer2.seconds,*sherman,*tiger);
		setLed(0,1,1);
	}
	while(fire==0){
		moveToXY(0,0);
		TimerWindow();
		moveToXY(0,0);
		printf("GAMETIME : %d:%d:%d ",timer2.hours, timer2.minutes, timer2.seconds);
		readAntenna8();
		uint16_t Joystickposition = ADC_GetConversionValue(ADC1);
		int adclocationone = readAntenna1();
		int adclocationtwo = readAntenna2();
		int AnglePlayer1 = GetAngleplayer1(adclocationone);
		int AnglePlayer2 = GetAngleplayer2(adclocationtwo);
		fgcolor(2);
		moveToXY(0,175);
		printf("Angle for player 1's shot: %d ", AnglePlayer1);
		fgcolor(6);
		moveToXY(3,175);
		printf("Angle for player 2's shot: %d ", AnglePlayer2);

		if(t==1){
			if((tiger->angle!=AnglePlayer1)||(sherman->angle!=AnglePlayer2)){
		tiger->angle=AnglePlayer1;
		sherman->angle=AnglePlayer2;
		deleteBox(tiger->yLoc,tiger->xLoc);
		deleteBox(sherman->yLoc,sherman->xLoc);
		tank(&*tiger);
		tank(&*sherman);
		}
		}else if(t==2){
			if((tiger->angle!=AnglePlayer2)||(sherman->angle!=AnglePlayer1)){
			tiger->angle=AnglePlayer2;
			sherman->angle=AnglePlayer1;
			deleteBox(tiger->yLoc,tiger->xLoc);
			deleteBox(sherman->yLoc,sherman->xLoc);
			tank(&*tiger);
			tank(&*sherman);
		}}

		if (variabel != readButton()){
			variabel = readButton();
			if((shootButton(variabel)==4)&&(tiger->ammo1>0)){
				fire=shoot(Height,baseHeight, &*tiger,&*sherman,powerUp);
			} else if((shootButton(variabel)==2048)&&(tiger->ammo2>0)){
				shoot(Height,baseHeight, &*tiger, &*sherman,powerUp);
				shoot(Height,baseHeight, &*tiger, &*sherman,powerUp);
				fire=shoot(Height,baseHeight, &*tiger, &*sherman,powerUp);
				tiger->ammo2=tiger->ammo2-1;
			}
		} else if (variabel != readJoystick()){
				variabel = readJoystick();
				moveMenu(variabel,210);
		}else if(Joystickposition < 50){ //move left
			if(tiger->fuel > 0){
				deleteBox(tiger->yLoc,tiger->xLoc);
				tiger->yLoc-=6;
				tiger->xLoc=baseHeight-(Height[(tiger->yLoc-1)/6]+1)*3;
				tiger->fuel--;
				tank(&*tiger);
				for(int q = 0 ; q < 1000000 ; q++);
			}
		} else if(Joystickposition > 4000){ //move right
			if(tiger->fuel > 0){
				deleteBox(tiger->yLoc,tiger->xLoc);
				tiger->yLoc+=6;
				tiger->xLoc=baseHeight-(Height[(tiger->yLoc-1)/6]+1)*3;
				tiger->fuel--;
				tank(&*tiger);
				for(int q = 0 ; q < 1000000 ; q++);
			}
		}
	}
}

