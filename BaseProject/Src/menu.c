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

void drawLetter(int yPos, int xPos,int color){
	fgcolor(color);
	moveToXY(xPos,yPos);
	printf("%c",219);
	printf("%c",219);
}

void menu(int width,int yPos,int xPos,int up,int down,int center){
	int color = 1,y = yPos;
	alphabet("space-tanks",(width/4)-5,xPos);
	//print border
	moveToXY(yPos+10,0);
	fgcolor(15);
	for(int i = 0; i < width; i++){
		printf("%c",205);
	}

	//print start
	while(center != 1){
		moveToXY(xPos+15,width/2-3);
		fgcolor(15);
		printf("start");
		moveToXY(xPos+12,yPos+20);
		printf("Help");
	}

}
void alphabet(char string[20],int yPos,int xPos){
	int color = 1,y = yPos;
	int stringLength = strlen(string);
	for(int i = 0; i < stringLength; i++){
		//S
		if(string[i] == 's'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+3,color);
			drawLetter(y+6,xPos+4,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+2,xPos+6,color);
			drawLetter(y+4,xPos+6,color);
			drawLetter(y,xPos+5,color);
			y +=10,color +=1;
		}
		//p
		if(string[i] == 'p'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y,xPos+6,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+6,xPos+2,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+3,color);
			y +=10,color +=1;
		}
		//a
		if(string[i] == 'a'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y,xPos+6,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+6,xPos+2,color);
			drawLetter(y+6,xPos+3,color);
			drawLetter(y+6,xPos+4,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+6,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+3,color);
			y +=10,color +=1;
		}
		//c
		if(string[i] == 'c'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y+2,xPos+6,color);
			drawLetter(y+4,xPos+6,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+1,color);
			y +=10,color +=1;
		}
		//e
		if(string[i] == 'e'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y+6,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y+2,xPos+6,color);
			drawLetter(y+4,xPos+6,color);
			drawLetter(y+6,xPos+6,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+3,color);
			y +=10,color +=1;
		}

		//-
		if(string[i]== '-'){
			drawLetter(y,xPos+3,color);
			drawLetter(y+2,xPos+3,color);
			y +=5,color +=1;
		}

		//t
		if(string[i] == 't'){
			drawLetter(y,xPos,color);
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y+6,xPos,color);
			drawLetter(y+8,xPos,color);
			drawLetter(y+4,xPos+1,color);
			drawLetter(y+4,xPos+2,color);
			drawLetter(y+4,xPos+3,color);
			drawLetter(y+4,xPos+4,color);
			drawLetter(y+4,xPos+5,color);
			drawLetter(y+4,xPos+6,color);
			y +=12,color +=1;
		}
		//n
		if(string[i] == 'n'){
			drawLetter(y+2,xPos,color);
			drawLetter(y+4,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y,xPos+6,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+6,xPos+2,color);
			drawLetter(y+6,xPos+3,color);
			drawLetter(y+6,xPos+4,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+6,color);
			y +=10,color +=1;
		}
		//k
		if(string[i] == 'k'){
			drawLetter(y,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y,xPos+6,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+2,color);
			drawLetter(y+4,xPos+4,color);
			drawLetter(y+6,xPos,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+6,color);
			y +=10,color +=1;
		}
		//H
		if(string[i] == 'h'){
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+4,xPos+3,color);
			drawLetter(y,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y,xPos+6,color);
			drawLetter(y+6,xPos,color);
			drawLetter(y+6,xPos+1,color);
			drawLetter(y+6,xPos+2,color);
			drawLetter(y+6,xPos+3,color);
			drawLetter(y+6,xPos+4,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+6,color);
			y +=10,color +=1;
		}
		//L
		if(string[i] == 'l'){
			drawLetter(y,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y,xPos+3,color);
			drawLetter(y,xPos+4,color);
			drawLetter(y,xPos+5,color);
			drawLetter(y+2,xPos+6,color);
			drawLetter(y+4,xPos+6,color);
			drawLetter(y+6,xPos+6,color);
			y +=10,color +=1;
		}
		//v
		if(string[i] == 'v'){
			drawLetter(y,xPos,color);
			drawLetter(y,xPos+1,color);
			drawLetter(y,xPos+2,color);
			drawLetter(y+2,xPos+3,color);
			drawLetter(y+2,xPos+4,color);
			drawLetter(y+2,xPos+5,color);
			drawLetter(y+4,xPos+6,color);
			drawLetter(y+6,xPos+5,color);
			drawLetter(y+6,xPos+4,color);
			drawLetter(y+6,xPos+3,color);
			drawLetter(y+8,xPos+2,color);
			drawLetter(y+8,xPos+1,color);
			drawLetter(y+8,xPos,color);
			y +=12,color +=1;
		}

	}
}
