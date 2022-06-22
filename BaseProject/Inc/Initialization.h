/*
 * Initialization.h
 *
 *  Created on: Jun 14, 2022
 *      Author: Mars
 */

#ifndef INITIALIZATION_H_
#define INITIALIZATION_H_

void init();
void init2();
void joystickLed();
void setLed(int blue, int green, int red);
uint8_t readJoystick();
void randConfig();
uint16_t readAntenna8();
uint16_t readAntenna9();
uint16_t readAntenna1();
uint16_t readAntenna2();

#endif /* INITIALIZATION_H_ */
