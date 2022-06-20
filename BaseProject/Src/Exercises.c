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
#include "random.h"







//Exercise 4
typedef struct{
	int angle;
	int speed;
	int speedY;
	int speedX;
	int xLoc;
	int yLoc;
	int hit;
}Ball_t;
void move(Ball_t * Balls,int32_t x1,int x2, int y1, int y2){
	if((Balls->yLoc+Balls->speedY)>=y2){
		Balls->yLoc=y2-(Balls->yLoc+Balls->speedY-y2);
		Balls->speedY=-Balls->speedY;
		Balls->hit++;
	}
	if((Balls->yLoc+Balls->speedY)<=y1){
			Balls->yLoc=y1-Balls->speedY;
			Balls->hit++;
			Balls->speedY=-Balls->speedY;
	}
	if((Balls->xLoc+Balls->speedX)<x1){
				Balls->xLoc=x1-Balls->speedX;
				Balls->hit++;
				Balls->speedX=-Balls->speedX;
	}
	if((Balls->xLoc+Balls->speedX)>=x2){
		Balls->xLoc=x2-(Balls->xLoc+Balls->speedX-x2);
		Balls->speedX=-Balls->speedX;
		Balls->hit++;
	}else{
		Balls->yLoc=Balls->yLoc+Balls->speedY;
		Balls->xLoc=Balls->xLoc+Balls->speedX;
	}
}

void initBall(Ball_t * Balls,int yMax,int xMax){
	//Balls->angle=getRand(0,1);
	//getXYMove(Balls);
	Balls->hit = 0;
	Balls->yLoc=yMax/2;
	Balls->xLoc=xMax/2;
}


void ball(int y1, int x1, int y2, int x2){
	Ball_t Balls;
	resPos();
	window(y1, x1, y2, x2);
	resPos();
	initBall(&Balls,y2,x2);

	while((&Balls)->hit < 100){
		move((&Balls),x1,x2,y1,y2);
		moveToXY((int)(&Balls)->xLoc,(int)(&Balls)->yLoc);
		//printf("%c",248);
		printf("o");
		for(int i = 0 ; i < 100000 ; i++);
		clean((&Balls)->yLoc,(&Balls)->xLoc,y1,x1,y2,x2);
		savePos();
		moveToXY(x2/2,y2/2-4);
		printf("Hits%c %d",58,(&Balls)->hit);
		recallPos();

	}
}

void clean(int yLoc,int xLoc,int y1,int x1,int y2, int x2){
	moveBack(1);
	if(xLoc-1 <= x1 && yLoc-1 <= y1){
		printf("%c",201);
	} else if(xLoc-1 <= x1 && yLoc >= y2){
		printf("%c",187);
	} else if(xLoc >= x2 && yLoc >= y2){
		printf("%c",188);
	} else if(xLoc >= x2 && yLoc-1 <= y1){
		printf("%c",200);
	} else if(xLoc-1 <= x1 || xLoc >= x2){
		printf("%c",205);
	} else if(yLoc-1 <= y1 || yLoc >= y2){
		printf("%c",186);
	} else{
		printf(" ");
	}
}
