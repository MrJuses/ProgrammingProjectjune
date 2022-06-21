/*
 * turn.c
 *
 *  Created on: 21. jun. 2022
 *      Author: Tnopn
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
#include "random.h"
#include "structs.h"
#include "initialization.h"
#include "menu.h"
#include "meteor.h"
#include "lcd.h"

void roundCount(int Height[] ,int baseHeight,game_t game,tank_t tiger, tank_t sherman, powerUp_t powerUp, uint16_t variabel){
	for(int i = 0; i < game.roundNum; i++){
		randMeteor(Height,baseHeight,tiger,sherman);
	}
	lcdDisplay(tiger.health,tiger.ammo1,tiger.fuel,tiger.ammo2);
	turn(Height,baseHeight,tiger,sherman,powerUp,variabel);

	lcdDisplay(sherman.health,sherman.ammo1,sherman.fuel,sherman.ammo2);
	turn(Height,baseHeight,sherman,tiger,powerUp,variabel);

	game.roundNum++;

}

void turn(int Height[] ,int baseHeight, tank_t tiger, tank_t sherman, powerUp_t powerUp, uint16_t variabel){
	int fire=0;

	while(fire==0){
			if (variabel != readButton()){
				variabel = readButton();
				if(shootButton(variabel)==4){
					fire=shoot(Height,baseHeight, tiger,sherman,powerUp);
				} else if(shootButton(variabel)==2048){
					shoot(Height,baseHeight, tiger,sherman,powerUp);
					shoot(Height,baseHeight, tiger,sherman,powerUp);
					fire=shoot(Height,baseHeight, tiger,sherman,powerUp);
				}
			} else if (variabel != readJoystick()){
				variabel = readJoystick();
				moveMenu(variabel,210);
		}
	}
}

