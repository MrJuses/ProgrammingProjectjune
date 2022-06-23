/*
 * Endgame.h
 *
 *  Created on: Jun 21, 2022
 *      Author: Mars
 */
#ifndef ENDGAME_H_
#define ENDGAME_H_

#include "structs.h"

int scoreCalculator(int hours, int minutes, int seconds,tank_t * winner);
void printEndGameScreen();
void EndGame(int hours, int minutes, int seconds, tank_t player1, tank_t player2);

#endif /* TIMER_H_ */

