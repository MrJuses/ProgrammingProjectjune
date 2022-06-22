#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include <time.h>
#include <stdlib.h>
#include <sin.h>
#include "charset.h"
#include "lcd.h"
#include "math.h"
#include "structs.h"

void lcdDisplay(tank_t * tiger){
	uint8_t buffer[512];
	memset(buffer,0x00,512);
	char string[50];
	sprintf(string,"Health:               %d",tiger->health);
	lcdWrite(buffer,string,1,0);
	sprintf(string,"Fuel:                 %d",tiger->fuel);
	lcdWrite(buffer,string,1,1);
	sprintf(string,"Ammo:                 %d",tiger->ammo1);
	lcdWrite(buffer,string,1,2);
	sprintf(string,"Special Ammo:         %d",tiger->ammo2);
	lcdWrite(buffer,string,1,3);
	lcd_push_buffer(buffer);
}

void lcdWrite(uint8_t buffer[],char string[50], int y, int x){
	int stringLength = strlen(string);
	if(x==0){
		y = 0;
	} else if(x==1){
		y += 128;
	} else if(x==2){
		y += 256;
	} else{
		y += 384;
	}
	for(int i = 0; i < stringLength; i++){
		for(int j = 0; j < 5; j++){
			buffer[y] = character_data[string[i]-0x20][j];
			y++;
		}
	}
}
