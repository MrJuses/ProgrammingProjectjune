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


void bossKey(){
	clearScreenResCurser();
	fgcolor(10);
	while(1){
		printf(">insert code here<");
		for(int i = 0; i < 100000; i++);
	}
}
