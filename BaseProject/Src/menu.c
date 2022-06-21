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
#include "movement.h"
#include "Initialization.h"

void drawLetter(int yPos, int xPos,int color){
	fgcolor(color);
	moveToXY(xPos,yPos);
	printf("%c",219);
	printf("%c",219);
}
void menu(int width){
	int yPos = 10,xPos = 10;
	uint8_t variabel;
	variabel = readJoystick();

	clearScreenResCurser();
	int y = yPos;
	alphabet("space-tanks",(width/4),xPos);
	//print border
	moveToXY(yPos+10,0);
	fgcolor(15);
	for(int i = 0; i < width; i++){
		printf("%c",205);
	}
	fgcolor(15);
	moveToXY(xPos+15,width/2-3);
	printf("Start");
	moveToXY(xPos+17,width/2-6);
	printf("Difficulty");
	moveToXY(xPos+19,width/2-3);
	printf("Help");

	moveToXY(xPos+45,width/2-12);
	printf("(Joystick Up -> Start)");
	moveToXY(xPos+46,width/2-16);
	printf("(Joystick Center -> bossKey)");
	moveToXY(xPos+47,width/2-12);
	printf("(Joystick Right -> Help)");
	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,width);
		}
	}

}
void helpMenu(int width){
	uint8_t variabel;
	variabel = readJoystick();
	int yPos = 10,xPos = 10;

	clearScreenResCurser();
	alphabet("help",(width/2)-20,xPos);
	//print border
	moveToXY(yPos+10,0);
	fgcolor(15);
	for(int i = 0; i < width; i++){
		printf("%c",205);
	}

	fgcolor(15);
	moveToXY(xPos+15,width/2-3);
	printf("Back");



	moveToXY(xPos+47,width/2-11);
	printf("(Joystick Left -> Back)");

	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,width);
		}
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
