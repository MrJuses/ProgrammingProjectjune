/*
 * menu.h
 *
 *  Created on: 14. jun. 2022
 *      Author: emilm
 */

#ifndef MENU_H_
#define MENU_H_

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

#endif /* MENU_H_ */
