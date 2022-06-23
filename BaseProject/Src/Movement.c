/*
 * Movement.c
 *
 *  Created on: Jun 14, 2022
 *      Author: Mars
 */

#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include "Initialization.h"
#include "menu.h"
#include "gameplay.h"
#include "bossKey.h"

void moveMenu(uint8_t variabel,int width){
	switch(variabel){
		 case 1: { // UP
			runGame();
			break;
		}case 2: { // DOWN
			break;
		}case 4:{ // LEFT
			menu(width);
			break;
		}case 8:{ // RIGHT
			helpMenu(width);
			break;
		}case 16: { // CENTER
			bossKey();
			break;

		}

	}
}
