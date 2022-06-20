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
#define FIX8_SHIFT 8
#define FIX8_MULT(a, b) ( ((a)*(b)) >> FIX8_SHIFT )
#define FIX8_DIV(a, b) ( ((a) << FIX8_SHIFT) / b )
/*int32_t FIX16_MULT(int32_t a, int32_t b){
	return(((a)*(b))>>16);}*/

void shoot(int y, int x, int v, int angle, int g,int Height[],int baseHeight){
	int check=0;
	int t=0;
	//int l;
	int32_t xPos=0;
	int32_t yPos=0;
	int32_t fixX=convert(x);
	int32_t fixY=convert(y);
	int32_t fixG=convert(g)>>4;
	int32_t vX;
	int32_t vY;
	int32_t fixT;
	int32_t fixT2;
	int bulletX=12;
	int bulletY=12;
	vX=(FIX8_MULT(convert(v), fixRound(expand(SIN[angle]))));
	vY=FIX8_MULT(convert(v), fixRound(expand(COS(angle))));
	while(check==0){
		fixT=convert(t);
		fixT2=FIX8_MULT(fixT, fixT);

		xPos=fixX-FIX8_MULT(vX, fixT)+FIX8_MULT(fixG, fixT2);
		yPos=fixY+FIX8_MULT(vY, fixT);
		bulletX=fixRound(xPos);
		bulletY=fixRound(yPos)-(fixRound(yPos)+1)%2;
		//smallBox(bulletY,bulletX,11);
		//for(l = 0; l < 70000; l++);
		check=collision(bulletY, bulletX, Height, baseHeight);
		t++;

	}

}
int collision(int y, int x, int Height[], int baseHeight){
	int tankX=0;
	int tankY=0;
	int l;
	if(baseHeight-((Height[(y-1)/6])*3)<=x){
		destruction(y,x,Height, baseHeight);
		return 1;
	}else if((x<=tankX)&&(y>=tankY)&&(y<=(tankY+2))){
		deleteSmallBox(y,x);

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
