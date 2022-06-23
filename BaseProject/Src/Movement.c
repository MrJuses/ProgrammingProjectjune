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
			clearScreenResCurser();
			fgcolor(2);
			for(int i = 0 ; i < 5 ; i++){
				moveToXY(2,2);
				printf("EXITING GAME");
				for(int q = 0 ; q < 10 ; q++){
					printf(".");
					for(int y = 0 ; y < 200000 ; y++);
				}
				moveToXY(2,2);
				printf("EXITING GAME          ");

			}
			clearScreenResCurser();
			exit(0);
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
