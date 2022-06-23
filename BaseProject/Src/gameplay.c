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
#include "random.h"
#include "structs.h"
#include "initialization.h"
#include "menu.h"
#include "meteor.h"
#include "turn.h"
#include "lcd.h"
#include "Endgame.h"
#include "vinkel.h"

void runGame(){
	//creating structs
	game_t game;
	tank_t tank1;
	tank_t tank2;
	powerUp_t triple;

	//init elements
	lcd_init();
	randConfig();
	uint16_t variabel=0;

	//creates height-map
	int Height[36];
	for(int i = 0 ; i < 36 ; i++){
		if(i == 0){
			Height[i] = getRand()/2;
		} else{
			int x = getRand()/2;
			while(!(Height[i-1]+1 == x || Height[i-1]-1 == x || Height[i-1] == x)){
				x = getRand()/2;
			}
			Height[i] = x;
		}
	}

	//sets screensize
	int mapHeight=49;
	int mapWidth=35;

	//win condition
	int win=0;

	//values for structs created
	tank1.health=10;
	tank1.angle=30;
	tank1.fuel=10;
	tank1.ammo1=99;
	tank1.ammo2=0;
	tank1.yLoc=19;
	tank1.color=2;
	tank1.xLoc=mapHeight-(Height[(tank1.yLoc-1)/6]+1)*3;
	tank2.health=10;
	tank2.angle=150;
	tank2.fuel=10;
	tank2.ammo1=99;
	tank2.ammo2=0;
	tank2.yLoc=187;
	tank2.xLoc=mapHeight-(Height[(tank2.yLoc-1)/6]+1)*3;
	tank2.color=4;
	triple.x=1;
	triple.y=1;
	game.roundNum=1;

	//draws terrain and tanks
	clearScreenResCurser();
	drawTerrain(mapWidth,mapHeight,Height);
	tank(&tank1);
	tank(&tank2);

	//gameloop
	while(1){
		setLed(1,0,1);//purple

		//spawns meteor(s) depending on the round
		for(int i = 0; i < game.roundNum; i++){
			randMeteor(Height,mapHeight,&tank1,&tank2);
		}
		if(tank2.health<=0){win=1;} //check if green is dead
		else if(tank1.health<=0){win=2;} //check if blue is dead
		randPower(1,&triple);  //chance for power to spawn
		setLed(0,1,0); //green
		lcdDisplay(&tank1); //stats for green tank
		turn(Height,mapHeight,&tank1,&tank2,triple,variabel,win,1); // greens turn
		if(tank2.health<=0){win=1;}  //check if tank
		else if(tank1.health<=0){win=2;}  //check if blue is dead
		setLed(1,0,0); //blue
		lcdDisplay(&tank2);  //stats for blue tank
		turn(Height,mapHeight,&tank2,&tank1,triple,variabel,win,2); //blues turn
		//gives extra fuel
		tank1.fuel++;
		tank2.fuel++;

		//1 round has passed = more meteors
		game.roundNum++;
		if(tank2.health<=0){win=1;} //check if green is dead
		else if(tank1.health<=0){win=2;} //check if blue is dead
	}
}

//power-up
void randPower(int type, powerUp_t * triple){
	if(getRand() > 7){  //chance of spawning = 2/10
		int x = getRand()*getRand(), y = getRand()*getRand()*getRand();  //multiply random numbers together to allow spawning all across the screen
		while(x > 28 || x == 0 || y == 0 || y > 210){  //makes sure to spawn it within the screen boundaries
			x = getRand()*getRand(),y = getRand()*getRand()*getRand();
		}
		deleteBox(triple->y,triple->x);  //deletes old power-up
		triple->x=x;
		triple->y=y;
		powerUp(y,x,type);  // creates new power-up
	}
}

//meteor
void randMeteor(int Height[],int baseHeight,tank_t * tiger,tank_t * sherman){
	int angle = getRand()*10+225;  // shoots at different angles
	int x = 0, y = getRand()*getRand()*getRand();  //utilize full width to spawn
	while(y == 0 || y > 210){  //checks if within boundaries
		y = getRand()*getRand()*getRand();
	}
	x++;
	for(int i = 0; i < 10000 ; i++);  //small delay to visualize it better
	meteorFall(angle,x,y,Height,baseHeight, &*tiger, &*sherman);  //shoot meteor from sky mechanic
}
