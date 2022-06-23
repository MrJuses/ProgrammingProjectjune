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
#include "structs.h"
#include "initialization.h"
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( ((a)*(b)) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )

uint16_t readButton(){
	uint16_t white = GPIOD->IDR & (0x0001 << 2); //Read from pin PA1
	uint16_t red = GPIOC->IDR & (0x0001 << 11); //Read from pin PC11

	uint16_t bit = 0;

	if (white){
		bit |= 0x004;
	}

	if (red){
		bit |= 0x800;
	}
	return bit;
}

int shootButton(uint16_t variabel){//This function return a shoot value depending on which button was pressed
	switch(variabel){
		case 4: {

			return 4;
			break;
		}
		case 2048: {

			return 2048;
			break;
		}

	}
}

int shoot(int Height[] ,int baseHeight, tank_t * tiger, tank_t * sherman, powerUp_t powerUp){
	//This function calculates the trajectory of the projectile fired from a tank
	int check=0;
	int t=1;
	int v=4;
	int g=1;
	int32_t xPos=0;
	int32_t yPos=0;
	int32_t fixX=convert(tiger->xLoc+1); //The coordinates are converted to fixed point notation
	int32_t fixY=convert(tiger->yLoc+2);
	int32_t fixG=convert(g)>>4; //Gravity is converted to fixed point and bitshifted to the value we want
	int32_t vX;
	int32_t vY;
	int32_t fixT;
	int32_t fixT2;
	int bulletX=tiger->xLoc+1;
	int bulletY=tiger->yLoc+2;
	vX=(FIX8_MULT(convert(v), fixRound(expand(SIN[tiger->angle]))));//The speed in both directions is defined by angle and speed
	vY=FIX8_MULT(convert(v), fixRound(expand(COS(tiger->angle))));
	while(check==0){
		fixT=convert(t);
		fixT2=FIX8_MULT(fixT, fixT);//We multiply time by time to get time squared
		xPos=fixX-FIX8_MULT(vX, fixT)+FIX8_MULT(fixG, fixT2);
		yPos=fixY+FIX8_MULT(vY, fixT);
		bulletX=fixRound(xPos);//Calculated coordinates are converted back to regular ints for coordinates
		bulletY=fixRound(yPos)-(fixRound(yPos)+1)%2;
		check=collision(bulletY, bulletX, Height, baseHeight, &*tiger, &*sherman, powerUp);
		t++;

	}
	tiger->ammo1=tiger->ammo1-1;
	return 1;
}
int collision(int y, int x, int Height[], int baseHeight, tank_t * tiger, tank_t * sherman, powerUp_t powerUp){
	//This function checks if the projectile collides with an object each time time steps
	int l;
	if((y<=0)||(y>=210)){
		return 1;
	}else if((x<powerUp.x+3)&&(x>=powerUp.x)&&(y>=powerUp.y)&&(y<(powerUp.y+6))){
		deleteBox(powerUp.y,powerUp.x);
		tiger->ammo2=tiger->ammo2+1;
		powerUp.x=1;
		powerUp.y=1;
		return 1;
	}if((x>=tiger->xLoc)&&(y>=tiger->yLoc)&&(y<(tiger->yLoc+6))){
		//If a tank is hit or the ground beneath the tank is hit the tank will respawn and lose a life
		deleteBox(tiger->yLoc,tiger->xLoc);
		for(l = 0; l < 70000; l++);
		if(x>=tiger->xLoc+3){
			int delX=(baseHeight-((Height[(y-1)/6])*3));
			int delY=y-y%6+1;
			deleteBox(delY,delX);
			Height[(y-1)/6]-=1;
			tiger->xLoc=baseHeight-(Height[(tiger->yLoc-1)/6]+1)*3;
		}
		tank(&*tiger);
		setLed(0,0,1);
		tiger->health=tiger->health-1;
		return 1;
	}else if((x>=sherman->xLoc)&&(y>=sherman->yLoc)&&(y<(sherman->yLoc+6))){
		deleteBox(sherman->yLoc,sherman->xLoc);
		if(x>=sherman->xLoc+3){
			int delX=(baseHeight-((Height[(y-1)/6])*3));
			int delY=y-y%6+1;
			deleteBox(delY,delX);
			Height[(y-1)/6]-=1;
			sherman->xLoc=baseHeight-(Height[(sherman->yLoc-1)/6]+1)*3;
			}
		for(l = 0; l < 70000; l++);
		tank(&*sherman);
		setLed(0,0,1);
		sherman->health=sherman->health-1;
		return 1;
	}else if(baseHeight-((Height[(y-1)/6])*3)<=x){
		destruction(y,x,Height, baseHeight);
		return 1;
	}else if(3>=x){
		return 0;
	}else{
		smallBox(y,x,11);
		for(l = 0; l < 70000; l++);
		deleteSmallBox(y,x);
		return 0;
	}

}
void destruction(int y, int x, int Height[], int baseHeight){
	//This function deletes a part of the map if its hit
	int delX=(baseHeight-((Height[(y-1)/6])*3));
	int delY=y-y%6+1;
	deleteBox(delY,delX);
	Height[(y-1)/6]-=1;

}
