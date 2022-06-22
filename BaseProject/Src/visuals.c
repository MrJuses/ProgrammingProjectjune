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
void tank(tank_t * tiger){
	int i=tiger->xLoc;//(xSize-((arr[(yPos)]+1)*3));
	int j=tiger->yLoc;//(6*yPos)+1;
	int k=tiger->color;
	if(tiger->angle >= 0 && tiger->angle <=180){
		if(tiger->angle > 154){
			smallBox(j,i+2,k);
			smallBox(j+2,i+1,k);
			smallBox(j+4,i+2,k);
			smallBox(j+2,i+2,k);
			smallBox(j,i+1,1);
		} else if(tiger->angle > 110){
			smallBox(j,i+2,k);
			smallBox(j+2,i+1,k);
			smallBox(j+4,i+2,k);
			smallBox(j+2,i+2,k);
			smallBox(j,i,1);
		} else if(tiger->angle > 70){
			smallBox(j,i+2,k);
			smallBox(j+2,i+1,k);
			smallBox(j+4,i+2,k);
			smallBox(j+2,i+2,k);
			smallBox(j+2,i,1);
		} else if(tiger->angle > 25){
			smallBox(j,i+2,k);
			smallBox(j+2,i+1,k);
			smallBox(j+4,i+2,k);
			smallBox(j+2,i+2,k);
			smallBox(j+4,i,1);
		} else{
			smallBox(j,i+2,k);
			smallBox(j+2,i+1,k);
			smallBox(j+4,i+2,k);
			smallBox(j+2,i+2,k);
			smallBox(j+4,i+1,1);
		}
	} else if(tiger->angle > 180){
		tiger->angle = 180;
	} else{
		tiger->angle = 0;
	}
}

void powerUp(int y, int x, int type){
	moveToXY(x,y);
	fgcolor(11);
	for(int i = x; i < x + 3; i++){
		for(int j = y; j < y + 5; j++){
			moveToXY(i,j);
			if(i == x){
				if(j == y){
					printf("%c",201);
				} else if(j == y+4){
					printf("%c",187);
				} else{
					printf("%c",205);
				}
			} else if(i == x+2){
				if(j == y){
					printf("%c",200);
				} else if(j == y+4){
					printf("%c",188);
				} else{
					printf("%c",205);
				}
			} else{
				if (j == y || j == y+4){
					printf("%c",186);
				} else if(j == y+1){
					printf("P-U");
				}
			}
		}
	}
}

/*void drawMeteor(int y,int x,int angle){

	if(angle < 3){
		smallBox(y+2,x,8);
		smallBox(y,x+1,8);
		smallBox(y+2,x+1,1);
		smallBox(y+4,x+1,1);
		smallBox(y+2,x+2,9);
		smallBox(y+4,x+2,9);
	} else if(angle > 6){
		smallBox(y+2,x,8);
		smallBox(y+4,x+1,8);
		smallBox(y,x+1,1);
		smallBox(y+2,x+1,1);
		smallBox(y,x+2,9);
		smallBox(y+2,x+2,9);
	} else{
		smallBox(y+2,x,8);
		smallBox(y,x+1,1);
		smallBox(y+4,x+1,1);
		smallBox(y+2,x+2,1);
		smallBox(y+2,x+1,9);
	}

}*/



