/*
 * fixed.c
 *
 *  Created on: 16. jun. 2022
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

//general purpose code
int32_t expand(int32_t i) {
// Converts an 18.14 fixed point number to 16.16
return i << 2;
}
int32_t fixRound(int32_t i){
	return i>>8;
}
int32_t convert(int i){
	return i<<8;
}
void printFix(int32_t i) {
// Prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // Handle negative numbers
		printf("-"); i = ~i + 1;
	}
	printf("%ld.%04ld", i >> 8, 10000 * (uint32_t)(i & 0xFFFF) >> 8); // Print a maximum of 4 decimal digits to avoid overflow
}

