#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
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
#include "Endgame.h"
#include "Vinkel.h"
#include "Timer.h"

int main(void){
	//initializing
	uart_init(256000);
	clearScreenResCurser();
	init();
	init2();
	randConfig();

	//reset LEDs
	GPIOC->ODR |= (0x0001 << 7); // Green
	GPIOA->ODR |= (0x0001 << 9); // Blue
	GPIOB->ODR |= (0x0001 << 4); // Red

	//set LED to white
	setLed(1,1,1);
	uint8_t variabel;
	variabel = readJoystick();

	//Project start
	//screen width
	int gWidth = 210;
	clearScreenResCurser();

	//open menu
	menu(gWidth);

	while(1){

	}
	return 0;
}
