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
#include "Movement.h"
<<<<<<< Updated upstream
#include "shoot.h"
=======
#include "lcd.h"

>>>>>>> Stashed changes

int main(void){
	uart_init(256000);
	clearScreenResCurser();
	init();
	setLed(1,1,0);
	uint8_t variabel;
	variabel = readJoystick();

	//printf("\n");
	//Project start
<<<<<<< Updated upstream
	//int gWidth = 189, gHeight = 100;
	//clearScreenResCurser();
	//menu(gWidth,10,10,1,0,0);
=======
	lcdDisplay(4,4);
	int gWidth = 189, gHeight = 100;
	clearScreenResCurser();
	menu(gWidth,10,10);
>>>>>>> Stashed changes


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
	tank(69,mapHeight,60,Height);
	shoot(12,12,4,45,1);
	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			MoveWithJoystick(variabel);
		}
	}

	return 0;
}
