/*
 * shoot.h
 *
 *  Created on: 15. jun. 2022
 *      Author: Tnopn
 */

#ifndef SHOOT_H_
#define SHOOT_H_
//#define FIX16_SHIFT 16
//#define FIX16_MULT(a, b) ( (a)*(b) >> FIX16_SHIFT )
//#define FIX16_DIV(a, b) ( ((a) << FIX16_SHIFT) / b )
#include "structs.h"
void shoot(int Height[] ,int baseHeight, tank_t tiger, tank_t sherman,powerUp_t powerUp);
int collision(int y, int x, int Height[], int baseHeight, tank_t tiger, tank_t sherman,powerUp_t powerUp);
void destruction(int y, int x, int Height[], int baseHeight);
int shootButton(uint16_t variabel);
uint16_t readButton();

#endif /* SHOOT_H_ */
