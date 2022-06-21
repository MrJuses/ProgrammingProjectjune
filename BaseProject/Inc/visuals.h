/*
 * visuals.h
 *
 *  Created on: 13. jun. 2022
 *      Author: emilm
 */

#ifndef VISUALS_H_
#define VISUALS_H_
#include "structs.h"
void initHeight(int arr[],int size);
void drawBox(int yPos, int xPos,int color);
void drawTerrain(int yPos, int xPos,int arr[]);
void playerBox(int yPos,int xPos,int color);
void tank(tank_t tiger);
void smallBox(int yPos, int xPos, int color);
void deleteBox(int yPos, int xPos);
void deleteSmallBox(int yPos, int xPos);
void powerUp();
void meteor();

#endif /* VISUALS_H_ */
