/*
 * Lcd.h
 *
 *  Created on: 16. jun. 2022
 *      Author: emilm
 */

#ifndef LCD_H_
#define LCD_H_

void lcdDisplay(int health, int ammo);
void lcdWrite(uint8_t buffer[],char string[50], int y, int x,int variable);

#endif /* LCD_H_ */
