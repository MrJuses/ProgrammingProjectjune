/*
 * gameplay.h
 *
 *  Created on: 17. jun. 2022
 *      Author: Tnopn
 */
#include "structs.h"
#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
void runGame();
void randPower(int type, powerUp_t * triple);
void randMeteor(int Height[],int baseHeight,tank_t * tiger,tank_t * sherman);


#endif /* GAMEPLAY_H_ */
