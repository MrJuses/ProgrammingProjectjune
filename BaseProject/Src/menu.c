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

void drawLetter(int yPos,int xPos,int color){
	int i,j;
	fgcolor(color);
	for( i = xPos; i <= xPos; i++){
		for( j = yPos; j <= yPos + 1; j++){
			moveToXY(i,j);
			printf("%c",219);
		}
	}
}
void title();
