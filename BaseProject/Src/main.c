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


int main(void){
	uart_init(256000);
	printf("\n");
	//printFix(expand(SIN[270]));
	//printf("\n%", COS(180)>>14);
	//window(0,0,64,32);
	//ball(0,0,170,50);

	//lcdCommunication();
	int Height[36] =
	{
	2, 1, 0, 1, 1, 2,
	3, 3, 3, 2, 1, 2,
	1, 2, 3, 2, 3, 3,
	3, 2, 2, 3, 4, 3,
	4, 3, 3, 2, 1, 2,
	1, 2, 1, 1, 2, 3,
	};
	int mapHeight=35;
	int mapWidth=35;
	//Project start
	int tHeight[73];
	initHeight(tHeight,73);
	clearScreenResCurser();
	drawTerrain(mapWidth,mapHeight,Height);
	//drawBox(7,10,7);
	//drawBox(7,10,7);
	tank(69,mapHeight,60,Height);

	while(1){}

	return 0;
}
