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

void initHeight(int arr[],int size){
	arr[0] = getRand(1,3);
	for(int i = 0; i < size; i++){
		arr[i] = arr[i-1] + getRand(-1,1);
	}
}

void drawTerrain(int yPos,int xPos,int arr[]){
	int i,j;
	for(i = 0; i < xPos; i = i + 3){
		for(j = yPos - 2; j > (yPos - arr[i]); j = j - 3){
			drawBox(i,j,7);
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
void smallBox(int yPos, int xPos, int color){
	int i;
	fgcolor(color);
	for( i = yPos; i < yPos + 2; i++){
		moveToXY(xPos,i);
		printf("%c",219);
	}
}
void tank(int angle, int groundHeight, int xPos){
	if(angle >= 0 && angle <=180){
		if(angle > 154){
			smallBox(xPos,groundHeight,2);
			smallBox(xPos+2,groundHeight-1,2);
			smallBox(xPos+4,groundHeight,2);
			smallBox(xPos+2,groundHeight,2);
			smallBox(xPos,groundHeight-1,1);
		} else if(angle > 110){
			smallBox(xPos,groundHeight,2);
			smallBox(xPos+2,groundHeight-1,2);
			smallBox(xPos+4,groundHeight,2);
			smallBox(xPos+2,groundHeight,2);
			smallBox(xPos,groundHeight-2,1);
		} else if(angle > 70){
			smallBox(xPos,groundHeight,2);
			smallBox(xPos+2,groundHeight-1,2);
			smallBox(xPos+4,groundHeight,2);
			smallBox(xPos+2,groundHeight,2);
			smallBox(xPos+2,groundHeight-2,1);
		} else if(angle > 25){
			smallBox(xPos,groundHeight,2);
			smallBox(xPos+2,groundHeight-1,2);
			smallBox(xPos+4,groundHeight,2);
			smallBox(xPos+2,groundHeight,2);
			smallBox(xPos+4,groundHeight-2,1);
		} else{
			smallBox(xPos,groundHeight,2);
			smallBox(xPos+2,groundHeight-1,2);
			smallBox(xPos+4,groundHeight,2);
			smallBox(xPos+2,groundHeight,2);
			smallBox(xPos+4,groundHeight-1,1);
		}
	} else if(angle > 180){
		angle = 180;
	} else{
		angle = 0;
	}
}






