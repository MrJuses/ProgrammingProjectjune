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
#include "movement.h"
#include "Initialization.h"

//draws a square with a specific color at a position
void drawLetter(int yPos, int xPos,int color){
	fgcolor(color);
	moveToXY(xPos,yPos);
	printf("%c",219);
	printf("%c",219);
}
//displays main menu
void menu(int width){
	int yPos = 10,xPos = 10;  //title position
	uint8_t variabel;
	variabel = readJoystick();

	clearScreenResCurser();
	int y = yPos;
	alphabet("space-tanks",(width/4),xPos); //title
	//print border
	moveToXY(yPos+10,0);
	fgcolor(15);

	//draws line across screen
	for(int i = 0; i < width; i++){
		printf("%c",205);
	}

	//selection display
	fgcolor(15);
	moveToXY(xPos+15,width/2-3);
	printf("Start");
	moveToXY(xPos+17,width/2-3);
	printf("Help");
	moveToXY(xPos+19,width/2-3);
	printf("Exit");

	moveToXY(xPos+45,width/2-13);
	printf("(Joystick  Up -> Start)");
	moveToXY(xPos+46,width/2-13);
	printf("(Joystick Right -> Help)");
	moveToXY(xPos+47,width/2-13);
	printf("(Joystick Down -> Exit)");

	//nav inputs
	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,width);
		}
	}

}
//help screen
void helpMenu(int width){
	uint8_t variabel;
	variabel = readJoystick();
	int yPos = 10,xPos = 10;

	//title and line
	clearScreenResCurser();
	alphabet("help",(width/2)-20,xPos);
	//print border
	moveToXY(yPos+10,0);
	fgcolor(15);
	for(int i = 0; i < width; i++){
		printf("%c",205);
	}

	//menu options
	fgcolor(15);
	moveToXY(xPos+15,width/2-3);
	printf("Back");

	//game description
	moveToXY(xPos+22,width/2-65);
	printf("Space-Tanks is a two-player competitive turn based game, on the moon, where you must find the correct angle to shoot each other,");
	moveToXY(xPos+23,width/2-65);
	printf("     whilst avoiding the meteors raining from above. power-ups can be aquired in game by shooting them when they appear.\n ");
	moveToXY(xPos+24,width/2-65);
	printf("     Scoring is highly dependend on time, when one of the players die the end screen will show the stats of the winner\n");
	moveToXY(xPos+25,width/2-65);
	printf("              A few Easter-Eggs have been implemented in the game E.g: A special level. - Can you find it?!");
	moveToXY(xPos+26,width/2-65);
	printf("        For additional help visit our User manual, here all the functions and descriptions can be read in full detail!");

	//game controls
	moveToXY(xPos+33,width/2-20);
	printf("(Potentiometer 1 -> Green Tank Angle)");

	moveToXY(xPos+34,width/2-20);
	printf("(Potentiometer 2 -> Blue  Tank Angle)");

	moveToXY(xPos+35,width/2-22);
	printf("(2-axis Joystick Left  -> Move Tank Left)");

	moveToXY(xPos+36,width/2-22);
	printf("(2-axis Joystick Right -> Move Tank Right)");

	moveToXY(xPos+37,width/2-16);
	printf("(Red  Button  -> Normal shot)");

	moveToXY(xPos+38,width/2-16);
	printf("(White Button -> Special Shot)");

	moveToXY(xPos+39,width/2-15);
	printf("(Joystick Center -> BossKey)");


	//menu nav
	moveToXY(xPos+47,width/2-11);
	printf("(Joystick Left -> Back)");

	//input
	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,width);
		}
	}
}

//draws different blockwords
void alphabet(char string[20],int yPos,int xPos){
	int color = 1,y = yPos;
	int stringLength = strlen(string);  //takes string and iterates through it
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
