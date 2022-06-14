/*
 * visuals.h
 *
 *  Created on: 13. jun. 2022
 *      Author: emilm
 */

#ifndef VISUALS_H_
#define VISUALS_H_

void initHeight(int arr[],int size);
void drawBox(int yPos, int xPos,int color);
void drawTerrain(int yPos, int xPos,int arr[]);
void playerBox(int yPos,int xPos,int color);
void tank(int angle, int groundheight, int yPos);

#endif /* VISUALS_H_ */
