/*
 * caller.h
 *
 *  Created on: 7. jun. 2022
 *      Author: emilm
 */
#include "stdio.h"
#include "stdint.h"

#ifndef CALLER_H_
#define CALLER_H_

void window(int y1, int x1, int y2, int x2);
void ball(int y1, int x1, int y2, int x2);
int32_t expand(int32_t i);
void printFix(int32_t i);
void lcdCommunication();


#endif /* CALLER_H_ */
