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
void shoot(int y, int x, int v, int angle, int g,int Height[],int baseHeight);
int collision(int y, int x, int Height[], int baseHeight);
void destruction(int y, int x, int Height[], int baseHeight);

#endif /* SHOOT_H_ */
