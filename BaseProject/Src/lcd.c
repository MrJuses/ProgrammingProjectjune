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

void lcdDisplay(int health,int ammo){
	uint8_t buffer[512];
	lcd_init();
	lcdWrite(buffer,"Health",36,1,health);
	lcd_push_buffer(buffer);
}

void lcdWrite(uint8_t buffer[],char string[50], int y, int x,int variable){
	int stringLength = strlen(string);
	if(x==1){
		y += 128;
	} else if(x==2){
		y += 256;
	} else{
		y += 384;
	}
	for(int i = 0; i < stringLength; i++){
		for(int j = 0; j < 5; j++){
			//buffer[y] = character_data[string[i]-0x20][j];
			y++;
		}
	}
	//buffer[stringLength]=(char)variable;
	lcd_push_buffer(buffer);
}

/*void lcdWrapString(char string[50], int y, int x){
	int stop = 0,layer = 0;
	int stringLength = strlen(string);
	if(x==1){
		layer = 128;
	} else if(x==2){
		layer = 256;
	} else if(x==3){
		layer = 384;
	} else{
		layer = 0;
	} y += layer;
	while(stop != 10){
		int f = y;
		for(int i = 0; i < stringLength; i++){
			stop++;
			for(int j = 0; j < 5; j++){
				if(f<0){
					buffer[512-f] = character_data[string[i]-0x20][j];
				} else{
					buffer[f] = character_data[string[i]-0x20][j];
				}
				f++;
			}
		}
		lcd_push_buffer(buffer);
		y--;
		for(int i = 0; i < 100000; i++);
		memset(buffer,0x00,512);
	}
}*/
