/*
 * meteor.h
 *
 *  Created on: 21. jun. 2022
 *      Author: emilm
 */

#ifndef METEOR_H_
#define METEOR_H_

void meteorFall(int angle, int x, int y,int Height[] ,int baseHeight, tank_t * tiger, tank_t * sherman);
int meteorCollision(int y, int x, int Height[], int baseHeight, tank_t * tiger, tank_t * sherman);
void meteorDestruction(int y, int x, int Height[], int baseHeight);

#endif /* METEOR_H_ */
