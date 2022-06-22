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
#include "meteor.h"
#include "turn.h"
#include "lcd.h"
void runGame(){
	game_t game;
	tank_t tank1;
	tank_t tank2;



	randConfig();
	uint16_t variabel=0;
	int Height[36];
	for(int i = 0 ; i < 36 ; i++){
		if(i == 0){
			Height[i] = getRand()/2;
		} else{
			int x = getRand()/2;
			//int sameLevel = 0;
			while(!(Height[i-1]+1 == x || Height[i-1]-1 == x || Height[i-1] == x)){
				x = getRand()/2;
			}
			Height[i] = x;
		}
	}
	int mapHeight=49;
	int mapWidth=35;
	int win=0;
	powerUp_t triple;

	tank1.health=10;
	tank1.angle=30;
	tank1.fuel=10;
	tank1.ammo1=99;
	tank1.ammo2=0;
	tank1.yLoc=31;
	tank1.color=2;
	tank1.xLoc=mapHeight-(Height[(tank1.yLoc-1)/6]+1)*3;
	tank2.health=10;
	tank2.angle=150;
	tank2.fuel=10;
	tank2.ammo1=99;
	tank2.ammo2=0;
	tank2.yLoc=151;
	tank2.xLoc=mapHeight-(Height[(tank2.yLoc-1)/6]+1)*3;
	tank2.color=4;

	triple.x=1;
	triple.y=1;
	game.roundNum=1;
	clearScreenResCurser();
	drawTerrain(mapWidth,mapHeight,Height);
	tank(&tank1);
	tank(&tank2);

	shoot(Height,mapHeight, &tank1, &tank2,triple);
	shoot(Height,mapHeight, &tank1, &tank2,triple);
	shoot(Height,mapHeight, &tank1, &tank2,triple);
	shoot(Height,mapHeight, &tank1, &tank2,triple);
	shoot(Height,mapHeight, &tank1, &tank2,triple);
	shoot(Height,mapHeight, &tank1, &tank2,triple);

	while(win==0){
		for(int i = 0; i < game.roundNum; i++){
			randMeteor(Height,mapHeight,&tank1,&tank2);
		}
	setLed(0,1,1);
	//lcdDisplay(&tank2);
	turn(Height,mapHeight,&tank1,&tank2,triple,variabel);

	setLed(1,0,1);
	//lcdDisplay(&tank2);
	turn(Height,mapHeight,&tank2,&tank1,triple,variabel);

	game.roundNum++;
	if(tank2.health<=0){win=1;}
	else if(tank1.health<=0){win=2;}

	if(win == 1){
		printf("Player 1 has won");
	} else if(win == 2){
		printf("Player 2 has won");
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

void randMeteor(int Height[],int baseHeight,tank_t * tiger,tank_t * sherman){
	int angle = getRand()*10+225;
	int x = 0, y = getRand()*getRand()*getRand();
	while(y == 0 || y > 210){
		y = getRand()*getRand()*getRand();
	}
	x++;
	for(int i = 0; i < 10000 ; i++);
	meteorFall(angle,x,y,Height,baseHeight, &*tiger, &*sherman);
}
