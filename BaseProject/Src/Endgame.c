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

//calculates the winners score
int scoreCalculator(int hours, int minutes, int seconds,tank_t * winner){

	int timeScore = hours*10000 + minutes*500 + seconds*50;
	int Endscore =  1000000+winner->ammo1*10+winner->ammo2*1000+winner->health*500-timeScore;

	return Endscore;
}

void printEndGameScreen(){

	alphabet("space-thanks",210/4-5,10);
	moveToXY(20,47);
	printf("Thanks for playing our game, we hoped you enjoyed playing it just as much as we enjoyed creating it!");
	moveToXY(25,47);
	printf("Down below you will find your final score, along with the amount of time the game lasted for");
	moveToXY(30,47);
	printf("To play again simply click the reset button on the Micro-controller");

}

void EndGame(int hours, int minutes, int seconds, tank_t player1, tank_t player2){
	int winner=0;
	clearScreenResCurser();
	stopTimer();
	if(player1.health > player2.health){
		winner = 1;
	} else if(player1.health < player2.health){
		winner = 2;
	}
	printEndGameScreen();

	int Finalscore;
	if(winner == 1){
		Finalscore = scoreCalculator(hours, minutes, seconds,&player1);
	} else if(winner == 2){
		Finalscore = scoreCalculator(hours, minutes, seconds,&player2);
	}
	moveToXY(35,47);
	fgcolor(6);
	printf("The game lasted for : %d hours, %d minutes and  %d seconds", hours, minutes, seconds);

	fgcolor(15);
	if(winner==1){
		moveToXY(40,47);
		printf("Green Player has won");

		moveToXY(45,47);
		printf("Final Health: %d", player1.health);

		moveToXY(50,47);
		printf("You moved this many blocks: %d", 10-player1.fuel);

		moveToXY(55,47);
		printf("You used this much ammo: %d", 99-player1.ammo1);

		moveToXY(60,47);
		printf("Your final score is: %d", Finalscore);

	} else if(winner==2){
		moveToXY(40,47);
		printf("Blue Player has won");

		moveToXY(45,47);
		printf("Final Health: %d", player2.health);

		moveToXY(50,47);
		printf("You moved this many blocks: %d", 10-player2.fuel);

		moveToXY(55,47);
		printf("You used this much ammo: %d", 99-player2.ammo1);

		moveToXY(60,47);
		printf("Your final score is: %d", Finalscore);
		}
}

