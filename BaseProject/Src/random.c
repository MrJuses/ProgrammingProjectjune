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
#include "random.h"

int getRand(int lowerLimit,int upperLimit){
	srand(time(NULL));
	lowerLimit++;
	int r =  lowerLimit + rand() % (upperLimit - lowerLimit);
	return r;
}

int randVal(){
	static int randArr[100];
	for(int i = 0; i < 20; i++){
		randArr[i] = getRand(1,2);
	}
	for(int i = 21; i < 50; i++){
		randArr[i] = getRand(1,10);
	}
	for(int i = 51; i < 100; i++){
		randArr[i] = getRand(1,100);
	}
	return randArr;
}

