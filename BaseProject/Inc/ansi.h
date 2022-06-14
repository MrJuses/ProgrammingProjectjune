/*
 * ansi.h
 *
 *  Created on: 7. jun. 2022
 *      Author: emilm
 */
#include "stdio.h"
#include "stdint.h"

#ifndef ANSI_H_
#define ANSI_H_

void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void resetbgcolor();

void moveToXY(int x, int y);
void moveUp(int i);
void moveDown(int i);
void moveForward(int i);
void moveBack(int i);
void savePos();
void recallPos();
void resPos();

void clearCursorToEnd();
void clearScreenResCurser();
void clearCursorToEndLine();
void clearLineResCurser();

#endif /* ANSI_H_ */
