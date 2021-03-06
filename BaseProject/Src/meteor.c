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
#include "structs.h"
#include "gameplay.h"
#include "meteor.h"
#include "turn.h"
#include "initialization.h"
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( ((a)*(b)) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )




void meteorFall(int angle, int x, int y,int Height[] ,int baseHeight, tank_t * tiger, tank_t * sherman){
	//This is the function that calculates the trajectory of a meteor
	//It uses many of the same principles as shoot but the math is simpler
	int check=0;
	int t=4;
	int v=1;
	int32_t xPos=0;
	int32_t yPos=0;
	int32_t fixX=convert(x);
	int32_t fixY=convert(y);
	int32_t vX;
	int32_t vY;
	int32_t fixT;
	int bulletX=x;
	int bulletY=y;
	vX=(FIX8_MULT(convert(v), fixRound(expand(SIN[angle]))));
	vY=FIX8_MULT(convert(v), fixRound(expand(COS(angle))));
	while(check==0){
		fixT=convert(t);
		xPos=fixX-FIX8_MULT(vX, fixT);
		yPos=fixY+FIX8_MULT(vY, fixT);
		bulletX=fixRound(xPos);
		bulletY=fixRound(yPos)-(fixRound(yPos)+1)%2;
		check=meteorCollision(bulletY, bulletX, Height, baseHeight, &*tiger, &*sherman);
		t++;

	}

}
int meteorCollision(int y, int x, int Height[], int baseHeight, tank_t * tiger, tank_t * sherman){
	//This is basically the same function as collision from shoot with minor alterations
	int l;
	if((y<=0)||(y>=210)){
		return 1;
	}else if((x>=tiger->xLoc)&&(y>=tiger->yLoc)&&(y<(tiger->yLoc+6))){
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
			};
		for(l = 0; l < 70000; l++);
		tank(&*sherman);
		setLed(0,0,1);
		sherman->health=sherman->health-1;
		return 1;
	}else if(baseHeight-((Height[(y-1)/6])*3)<=x){
		destruction(y,x,Height, baseHeight);
		return 1;
	}else{
		smallBox(y,x,13);
		for(l = 0; l < 70000; l++);
		deleteSmallBox(y,x);
		return 0;
	}

}

