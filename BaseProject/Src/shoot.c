/*
 * shoot.c
 *
 *  Created on: 15. jun. 2022
 *      Author: Tnopn
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

#define FIX16_SHIFT 16
#define FIX16_MULT(a, b) ( (a)*(b) >> FIX16_SHIFT )
#define FIX16_DIV(a, b) ( ((a) << FIX16_SHIFT) / b )

void shoot(int y, int x, int v, int angle, int g,int Height[],int baseHeight){
	int check=0;
	int t;
	int l;
	int32_t xPos;
	int32_t yPos;
	int32_t fixX=convert(x);
	int32_t fixY=convert(y);
	int32_t fixG=convert(g);
	int32_t vX;
	int32_t vY;
	int32_t fixT;
	int bulletX;
	int bulletY;
	vX=convert(v)*(expand(SIN[angle]));
	vY=convert(v)*expand(COS(angle));
	while(check==0){
		fixT=convert(t);
		//for(l=0;l<100000;l++)
		xPos=fixX-FIX16_MULT(vX, fixT)+FIX16_MULT(fixG, FIX16_MULT(fixT, fixT));
		yPos=fixY+FIX16_MULT(vY, fixT);
		bulletX=(int)fixRound(xPos);
		bulletY=(int)fixRound(yPos);
		smallBox(bulletY,bulletX,4);
		collision(bulletY, bulletX, Height, baseHeight);
		t++;

	}

}
int collision(int y, int x, int Height[], int baseHeight){
	int tankX=0;
	int tankY=0;
	if(baseHeight-Height[y/6]>=x/3){return 1;}
	else if((x<=tankX)&&(y>=tankY)&&(y<=(tankY+2))){return 1;}
	else{return 0;}

}
