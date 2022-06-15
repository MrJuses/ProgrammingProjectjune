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

void MoveWithJoystick(uint8_t variabel){


	switch(variabel){
		 case 1: { // UP
			 clearScreenResCurser();
			moveUp(1);
			moveBack(1);
			printf(" XX ");
			moveBack(4);
			moveUp(1);
			printf("XXXX");
			moveBack(4);
			moveUp(1);
			printf("O  O");
			break;
		}case 2: { // DOWN
			clearScreenResCurser();
			 moveDown(1);
			 moveBack(1);
				printf(" XX ");
				moveBack(4);
				moveDown(1);
				printf("XXXX");
				moveBack(4);
				moveDown(1);
				printf("O  O");
			break;
		}case 4:{ // LEFT
			clearScreenResCurser();
			moveBack(8);
			printf(" XX ");
			moveBack(4);
			moveDown(1);
			printf("XXXX");
			moveBack(4);
			moveDown(1);
			printf("O  O");
			break;
		}case 8:{ // RIGHT
			clearScreenResCurser();
			moveForward(1);
			printf(" XX ");
			moveBack(3);
			printf("XXXX");
			moveBack(3);
			printf("O  O");
			break;
		}case 16: { // CENTER
			clearScreenResCurser();

			break;

		}

	}
}
