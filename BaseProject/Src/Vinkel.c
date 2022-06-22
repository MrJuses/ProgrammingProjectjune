
/*
 * Vinkel.c
 *
 *  Created on: Jun 21, 2022
 *      Author: Mars
 */

#include "stdio.h"
#include "Endgame.h"

int GetAngleplayer1(int adcangle){
	int angle;
	if (adcangle > 4077){
		angle = 0;
	}else if (adcangle < 1357){
		angle = 180;
	}else if (adcangle < 4077 & adcangle > 3917){
		angle = 10;
	}else if (adcangle < 3917 & adcangle > 3757){
		angle = 20;
	}else if (adcangle < 3757 & adcangle > 3597){
		angle = 30;
	}else if (adcangle < 3597 & adcangle > 3437){
		angle = 40;
	}else if (adcangle < 3437 & adcangle > 3277){
		angle = 50;
	}else if (adcangle < 3277 & adcangle > 3117){
		angle = 60;
	}else if (adcangle < 3117 & adcangle > 2957){
		angle = 70;
	}else if (adcangle < 2957 & adcangle > 2797){
		angle = 80;
	}else if (adcangle < 2796 & adcangle > 2637){
		angle = 90;
	}else if (adcangle < 2637 & adcangle > 2477){
		angle = 100;
	}else if (adcangle < 2477 & adcangle > 2317){
		angle = 110;
	}else if (adcangle < 2317 & adcangle > 2157){
		angle = 120;
	}else if (adcangle < 2157 & adcangle > 1997){
		angle = 130;
	}else if (adcangle < 1997 & adcangle > 1837){
		angle = 140;
	}else if (adcangle < 1837 & adcangle > 1677){
		angle = 150;
	}else if (adcangle < 1677 & adcangle > 1517){
		angle = 160;
	}else if (adcangle < 1517 & adcangle > 1357){
		angle = 170;
	}else {
		angle = 0;
	}
	return angle;
}

int GetAngleplayer2(int adcangle){
	int angle;
	if (adcangle > 4066){
		angle = 180;
	}else if (adcangle < 1128){
		angle = 0;
	}else if (adcangle < 4066 & adcangle > 3893){
		angle = 170;
	}else if (adcangle < 3893 & adcangle > 3720){
		angle = 160;
	}else if (adcangle < 3720 & adcangle > 3547){
		angle = 150;
	}else if (adcangle < 3547 & adcangle > 3374){
		angle = 140;
	}else if (adcangle < 3374 & adcangle > 3204){
		angle = 130;
	}else if (adcangle < 3204 & adcangle > 3031){
		angle = 120;
	}else if (adcangle < 3031 & adcangle > 2858){
		angle = 110;
	}else if (adcangle < 2858 & adcangle > 2685){
		angle = 100;
	}else if (adcangle < 2685 & adcangle > 2512){
		angle = 90;
	}else if (adcangle < 2512 & adcangle > 2339){
		angle = 80;
	}else if (adcangle < 2339 & adcangle > 2166){
		angle = 70;
	}else if (adcangle < 2166 & adcangle > 1993){
		angle = 60;
	}else if (adcangle < 1993 & adcangle > 1820){
		angle = 50;
	}else if (adcangle < 1820 & adcangle > 1647){
		angle = 40;
	}else if (adcangle < 1647 & adcangle > 1474){
		angle = 30;
	}else if (adcangle < 1474 & adcangle > 1301){
		angle = 20;
	}else if (adcangle < 1301 & adcangle > 1128){
		angle = 10;
	}
	return angle;
}
