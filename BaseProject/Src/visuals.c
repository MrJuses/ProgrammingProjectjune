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
#include "structs.h"

/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/


void drawTerrain(int yPos,int xPos,int arr[]){
	int i;
	for(i = 0; i < yPos; i++){
		int j;
		for(j = 0 ; j <= arr[i]+4; j++){
			drawBox(1+6*i,(xPos-(j*3)+3*4),7);
		}
	}
}

void drawBox(int yPos,int xPos,int color){
	int i,j;
	fgcolor(color);
	for( i = xPos; i < xPos + 3; i++){
		for( j = yPos; j < yPos + 6; j++){
			moveToXY(i,j);
			printf("%c",219);
		}
	}
}
void deleteBox(int yPos, int xPos){
	int i,j;
	for( i = xPos; i < xPos + 3; i++){
		for( j = yPos; j < yPos + 6; j++){
			moveToXY(i,j);
			printf(" ");
		}
	}
}
void smallBox(int yPos, int xPos, int color){
	int i;
	fgcolor(color);
	for( i = yPos; i < yPos + 2; i++){
		moveToXY(xPos,i);
		printf("%c",219);
	}
}
void deleteSmallBox(int yPos, int xPos){
	int i;
	for( i = yPos; i < yPos + 2; i++){
		moveToXY(xPos,i);
		printf(" ");
	}
}
void tank(tank_t tiger){
	int i=tiger.xLoc;//(xSize-((arr[(yPos)]+1)*3));
	int j=tiger.yLoc;//(6*yPos)+1;
	if(tiger.angle >= 0 && tiger.angle <=180){
		if(tiger.angle > 154){
			smallBox(j,i+2,tiger.color);
			smallBox(j+2,i+1,tiger.color);
			smallBox(j+4,i+2,tiger.color);
			smallBox(j+2,i+2,tiger.color);
			smallBox(j,i+1,1);
		} else if(tiger.angle > 110){
			smallBox(j,i+2,tiger.color);
			smallBox(j+2,i+1,tiger.color);
			smallBox(j+4,i+2,tiger.color);
			smallBox(j+2,i+2,tiger.color);
			smallBox(j,i,1);
		} else if(tiger.angle > 70){
			smallBox(j,i+2,tiger.color);
			smallBox(j+2,i+1,tiger.color);
			smallBox(j+4,i+2,tiger.color);
			smallBox(j+2,i+2,tiger.color);
			smallBox(j+2,i,1);
		} else if(tiger.angle > 25){
			smallBox(j,i+2,tiger.color);
			smallBox(j+2,i+1,tiger.color);
			smallBox(j+4,i+2,tiger.color);
			smallBox(j+2,i+2,tiger.color);
			smallBox(j+4,i,1);
		} else{
			smallBox(j,i+2,tiger.color);
			smallBox(j+2,i+1,tiger.color);
			smallBox(j+4,i+2,tiger.color);
			smallBox(j+2,i+2,tiger.color);
			smallBox(j+4,i+1,1);
		}
	} else if(tiger.angle > 180){
		tiger.angle = 180;
	} else{
		tiger.angle = 0;
	}
}

void powerUp(){
	printf("");
}





