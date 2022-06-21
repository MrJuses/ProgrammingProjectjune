/*
 * shoot.c
 *
 *  Created on: 15. jun. 2022
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
#include "structs.h"
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( ((a)*(b)) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )
/*int32_t FIX16_MULT(int32_t a, int32_t b){
	return(((a)*(b))>>16);}*/

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
}

int shootButton(uint16_t variabel){
	switch(variabel){
		case 4: {
			return 4;
		}
		case 2048: {
			return 2048;
		}
	}
}

void shoot(int Height[] ,int baseHeight, tank_t tiger, tank_t sherman){
	int check=0;
	int t=1;
	//int l;
	int v=4;
	int g=1;
	int32_t xPos=0;
	int32_t yPos=0;
	int32_t fixX=convert(tiger.xLoc+1);
	int32_t fixY=convert(tiger.yLoc+2);
	int32_t fixG=convert(g)>>4;
	int32_t vX;
	int32_t vY;
	int32_t fixT;
	int32_t fixT2;
	int bulletX=tiger.xLoc+1;
	int bulletY=tiger.yLoc+2;
	vX=(FIX8_MULT(convert(v), fixRound(expand(SIN[tiger.angle]))));
	vY=FIX8_MULT(convert(v), fixRound(expand(COS(tiger.angle))));
	while(check==0){
		fixT=convert(t);
		fixT2=FIX8_MULT(fixT, fixT);

		xPos=fixX-FIX8_MULT(vX, fixT)+FIX8_MULT(fixG, fixT2);
		yPos=fixY+FIX8_MULT(vY, fixT);
		bulletX=fixRound(xPos);
		bulletY=fixRound(yPos)-(fixRound(yPos)+1)%2;
		//smallBox(bulletY,bulletX,11);
		//for(l = 0; l < 70000; l++);
		check=collision(bulletY, bulletX, Height, baseHeight, tiger, sherman);
		t++;

	}

}
int collision(int y, int x, int Height[], int baseHeight, tank_t tiger, tank_t sherman){

	int l;
	if((x>=tiger.xLoc)&&(y>=tiger.yLoc)&&(y<(tiger.yLoc+6))){
		deleteBox(tiger.yLoc,tiger.xLoc);
		for(l = 0; l < 7000000; l++);
		if(x>=tiger.xLoc+3){
			int delX=(baseHeight-((Height[(y-1)/6])*3));
			int delY=y-y%6+1;
			deleteBox(delY,delX);
			Height[(y-1)/6]-=1;
			tiger.xLoc=baseHeight-(Height[(tiger.yLoc-1)/6]+1)*3;
		}
		tank(tiger);

		return 1;
	}else if((x>=sherman.xLoc)&&(y>=sherman.yLoc)&&(y<(sherman.yLoc+6))){
		deleteBox(sherman.yLoc,sherman.xLoc);
		if(x>=sherman.xLoc+3){
			int delX=(baseHeight-((Height[(y-1)/6])*3));
			int delY=y-y%6+1;
			deleteBox(delY,delX);
			Height[(y-1)/6]-=1;
			sherman.xLoc=baseHeight-(Height[(sherman.yLoc-1)/6]+1)*3;
			};
		for(l = 0; l < 7000000; l++);
		tank(sherman);

		return 1;
	}else if(baseHeight-((Height[(y-1)/6])*3)<=x){
		destruction(y,x,Height, baseHeight);
		return 1;
	}else{
		smallBox(y,x,11);
		for(l = 0; l < 70000; l++);
		deleteSmallBox(y,x);
		return 0;
	}

}
void destruction(int y, int x, int Height[], int baseHeight){
	int delX=(baseHeight-((Height[(y-1)/6])*3));
	int delY=y-y%6+1;
	deleteBox(delY,delX);
	Height[(y-1)/6]-=1;

}
