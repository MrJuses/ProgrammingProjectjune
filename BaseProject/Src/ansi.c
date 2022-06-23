#define ESC 0x1B
#include "ansi.h"
#include "stdio.h"
#include "stdint.h"

//set color to draw
void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

//set color of background
void bgcolor(uint8_t background) {
/*
    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

//Cursor Controls
//move to location on screen
void moveToXY(int x, int y){
	printf("%c[%d;%dH",ESC,x,y);
}
//move up an amount
void moveUp(int i){
	printf("%c[%dA",ESC,i);
}
//move down an amount
void moveDown(int i){
	printf("%c[%dB",ESC,i);
}
//move forward an amount
void moveForward(int i){
	printf("%c[%dC",ESC,i);
}
//move back an amount
void moveBack(int i){
	printf("%c[%dD",ESC,i);
}
//remember position
void savePos(){
	printf("%c[s",ESC);
}
//go to stored location
void recallPos(){
	printf("%c[u",ESC);
}
//reset position
void resPos(){
	printf("%c[H",ESC);
}

//Erase functions
void clearCursorToEnd(){
	printf("%c[J",ESC);
}
void clearScreenResCurser(){
	printf("%c[2J",ESC);
}
void clearCursorToEndLine(){
	printf("%c[K",ESC);
}
void clearLineResCurser(){
	printf("%c[2K",ESC);
}
