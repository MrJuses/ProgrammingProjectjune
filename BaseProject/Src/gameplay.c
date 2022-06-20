/*
 * gameplay.c
 *
 *  Created on: 17. jun. 2022
 *      Author: Thomas
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "caller.h"
#include "ansi.h"
#include <time.h>
#include <stdlib.h>
#include <sin.h>
#include "charset.h"
#include "visuals.h"
#include "random.h"
#include "fixed.h"
#include "shoot.h"
#include "gameplay.h"
void runGame(){
	int Height[36] =
		{
		2, 1, 0, 1, 1, 2,
		3, 3, 3, 2, 1, 2,
		1, 2, 3, 2, 3, 3,
		3, 2, 2, 3, 4, 3,
		4, 3, 3, 2, 1, 2,
		1, 2, 1, 1, 2, 3,
		};

		int mapHeight=49;
		int mapWidth=35;
	clearScreenResCurser();
	drawTerrain(mapWidth,mapHeight,Height);
	tank(69,mapHeight,2,Height,2);
	tank(138,mapHeight,31,Height,4);
	shoot(31,35,4,40,1,Height,mapHeight);
	shoot(31,35,4,45,1,Height,mapHeight);
	shoot(31,35,4,20,1,Height,mapHeight);
	shoot(31,35,4,20,1,Height,mapHeight);
	shoot(31,35,4,20,1,Height,mapHeight);

	//tank(69,mapHeight,2,Height,2);
	//tank(138,mapHeight,31,Height,4);


}


