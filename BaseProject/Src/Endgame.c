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
#include "gameplay.h"
#include "random.h"
#include "structs.h"
#include "initialization.h"
#include "menu.h"
#include "meteor.h"
#include "turn.h"
#include "lcd.h"
#include "Endgame.h"
#include "vinkel.h"
#include "timer.h"
#include "structs.h"

int scoreCalculator(int hours, int minutes, int seconds){

	int Score = hours*10800 + minutes*180 + seconds*3;
	int Endscore = 10000 - Score;

	return Endscore;
}

void printEndGameScreen(){

	alphabet("space-thanks",210/4-5,10);
	moveToXY(20,47);
	printf("Thanks for playing our game, we hoped you enjoyed playing it just as much as we enjoyed creating it!");
	moveToXY(25,47);
	printf("Down below you will find your final score, along with the amount of time the game lasted for");
	moveToXY(30,47);
	printf("To play again simply click the reset button on the Microcontroller");

}

void EndGame(int hours, int minutes, int seconds, tank_t player1, tank_t player2){
	clearScreenResCurser();
	stopTimer();
	printEndGameScreen();
	int Finalscore = scoreCalculator(hours, minutes, seconds);
	int winner=0;
	moveToXY(35,47);
	fgcolor(6);
	printf("The game lasted for : %d hours, %d minutes and  %d seconds", hours, minutes, seconds);
	fgcolor(1);
	moveToXY(47,47);
	if(player1.health > player2.health){
		winner = 1;
		printf("Green Player has won");
	} else if(player1.health < player2.health){
		winner = 2;
		printf("Blue Player has won");
	}

	fgcolor(1);
	moveToXY(45,47);
	if(winner==1){
	printf("Final Health: %d", player1.health);

	fgcolor(1);
	moveToXY(50,47);
	printf("You moved this many blocks: %d", 10-player1.fuel);

	fgcolor(1);
	moveToXY(55,47);
	printf("You used this much ammo: %d", 99-player1.ammo1);

	fgcolor(1);
	moveToXY(60,47);
	printf("Your final score is: %d", Finalscore);
	}else if(winner==2){
		printf("Final Health: %d", player2.health);

		fgcolor(1);
		moveToXY(50,47);
		printf("You moved this many blocks: %d", 10-player2.fuel);

		fgcolor(1);
		moveToXY(55,47);
		printf("You used this much ammo: %d", 99-player2.ammo1);

		fgcolor(1);
		moveToXY(60,47);
		printf("Your final score is: %d", Finalscore);
		}
}

