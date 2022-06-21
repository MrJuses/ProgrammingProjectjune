/*
 * gameplay.c
 *
 *  Created on: 17. jun. 2022
 *      Author: Thomas
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "caller.h"
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
#include "random.h"
#include "structs.h"
#include "initialization.h"
#include "menu.h"

void runGame(){
	tank_t tank1;
	tank_t tank2;



	randConfig();
	uint16_t variabel;
	int Height[36];
	for(int i = 0 ; i < 36 ; i++){
		if(i == 0){
			Height[i] = getRand()/2;
		} else{
			int x = getRand()/2;
			int sameLevel = 0;
			while(!(Height[i-1]+1 == x || Height[i-1]-1 == x || Height[i-1] == x)){
				x = getRand()/2;

				/*if(Height[i-1] == x){
					sameLevel++;
					if(sameLevel >=2){
						x += 1;
					}
				}*/
			}
			Height[i] = x;
		}
	}
	int mapHeight=49;
	int mapWidth=35;
	tank1.angle=30;
	tank1.yLoc=31;
	tank1.color=2;
	tank1.xLoc=mapHeight-(Height[(tank1.yLoc-1)/6]+1)*3;
	tank2.angle=145;
	tank2.yLoc=151;
	tank2.xLoc=mapHeight-(Height[(tank2.yLoc-1)/6]+1)*3;
	tank2.color=4;

	clearScreenResCurser();
	drawTerrain(mapWidth,mapHeight,Height);
	tank(tank1);
	tank(tank2);

	randMeteor();


	//tank(69,mapHeight,2,Height,2);
	//tank(138,mapHeight,31,Height,4);
	while(1){
		if (variabel != readButton()){
			variabel = readButton();
			if(shootButton(variabel)==4){
				shoot(Height,mapHeight, tank1,tank2);
			} else if(shootButton(variabel)==2048){
				shoot(Height,mapHeight, tank2,tank1);
			}
		} else if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,210);
		}
	}

}

void randPower(int type){
	if(getRand() > 7){
		int x = getRand()*getRand(), y = getRand()*getRand()*getRand();
		while(x > 28 || x == 0 || y == 0 || y > 210){
			x = getRand()*getRand(),y = getRand()*getRand()*getRand();
		}
		powerUp(y,x,type);
	}
}

void randMeteor(){
	int angle = getRand();
	int x = 5, y = getRand()*getRand()*getRand();
	while(y == 0 || y > 210){
		y = getRand()*getRand()*getRand();
	}
	drawMeteor(y,x,angle);
	x++;
	for(int i = 0; i < 10000 ; i++);
}
