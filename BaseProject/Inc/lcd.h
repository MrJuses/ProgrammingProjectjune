/*
 * Lcd.h
 *
 *  Created on: 16. jun. 2022
 *      Author: emilm
 */

#ifndef LCD_H_
#define LCD_H_
#include "structs.h"
void lcdDisplay(tank_t * tiger);
void lcdWrite(uint8_t buffer[],char string[50], int y, int x);


#endif /* LCD_H_ */
