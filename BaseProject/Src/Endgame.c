/*
 * Endgame.c
 *
 *  Created on: 22. jun. 2022
 *      Author: emilm
 */


/*
 * Endgame.c
 *
 *  Created on: Jun 21, 2022
 *      Author: Mars
 */

#include "stdio.h"
#include "ansi.h"
#include "menu.h"
#include "Timer.h"

int scoreCalculator(int hours, int minutes, int seconds){

	int Score = hours*10800 + minutes*180 + seconds*3;
	int Endscore = 10000 - Score;

	return Endscore;
}

void printEndGameScreen(){

	alphabet("space-thanks",40,10);
	moveToXY(20,40);
	printf("Thanks for playing our game, we hoped you enjoyed playing it just as much as we enjoyed creating it!");
	moveToXY(25,40);
	printf("Down below you will find your final score, along with the amount of time the game lasted for");
	moveToXY(30,40);
	printf("To play again simply flick the joystick on the Microcontroller up once");

}

void EndGame(int hours, int minutes, int seconds){
	clearScreenResCurser();
	stopTimer();
	printEndGameScreen();
	int Finalscore = scoreCalculator(hours, minutes, seconds);
	moveToXY(35,40);
	fgcolor(6);
	printf("The game lasted for : %d hours, %d minutes and  %d seconds", hours, minutes, seconds);
	fgcolor(1);
	moveToXY(40,40);
	printf("Your final score is: %d", Finalscore);
}

