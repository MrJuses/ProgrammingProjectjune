#ifndef STRUCTS_H_
#define STRUCTS_H_
typedef struct{
	int angle;
	int speed;
	int xLoc;
	int yLoc;
	int ammo1;
	int ammo2;
	int health;
	int fuel;
	int color;
}tank_t;
typedef struct{
	int x;
	int y;
}powerUp_t;
typedef struct{
	int roundNum;
}game_t;
//This header constructs 3 structs used for the game
#endif /* STRUCTS_H_ */
