#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include "Initialization.h"
#include "menu.h"
#include "gameplay.h"
#include "bossKey.h"

//menu navigation
void moveMenu(uint8_t variabel,int width){
	switch(variabel){
		 case 1: { // UP start game
			runGame();
			break;
		}case 2: { // DOWN  exit game
			clearScreenResCurser();
			fgcolor(2);
			//exit animation
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
		}case 4:{ // LEFT back to main menu
			menu(width);
			break;
		}case 8:{ // RIGHT help menu
			helpMenu(width);
			break;
		}case 16: { // CENTER bosskey
			bossKey();
			break;

		}

	}
}
