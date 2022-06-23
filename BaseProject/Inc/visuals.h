#ifndef VISUALS_H_
#define VISUALS_H_
#include "structs.h"
void initHeight(int arr[],int size);
void drawBox(int yPos, int xPos,int color);
void drawTerrain(int yPos, int xPos,int arr[]);
void playerBox(int yPos,int xPos,int color);
void tank(tank_t * tiger);
void smallBox(int yPos, int xPos, int color);
void deleteBox(int yPos, int xPos);
void deleteSmallBox(int yPos, int xPos);
void powerUp(int y, int x, int type);
#endif /* VISUALS_H_ */
