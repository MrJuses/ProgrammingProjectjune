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
#include "shoot.h"
#include "lcd.h"
#include "gameplay.h"

typedef struct{
	int angle;
	int speed;
	int xLoc;
	int yLoc;
	int ammo1;
	int ammo2;
	int health;
	int fuel;
}tank_t;

int main(void){
	uart_init(256000);
	clearScreenResCurser();
	init();
	randConfig();
	setLed(1,1,0);
	uint8_t variabel;
	variabel = readJoystick();
	tank_t tank1;
	tank_t tank2;

	//Project start
	lcdDisplay(10,100,10,0);
	int gWidth = 210, gHeight = 100;
	clearScreenResCurser();
	menu(gWidth,10,10);


	//Project start
	int tHeight[73];

	while(1){
		if (variabel != readJoystick()){
			variabel = readJoystick();
			MoveWithJoystick(variabel);
		}
	}

	return 0;
}
