/*
 * Initialization.c
 *
 *  Created on: Jun 14, 2022
 *      Author: Mars
 */

// Function that declares LEDS and JOYSTICK
#include "stdio.h"
#include "stdint.h"
#include "30010_io.h"

void init(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A

	// Set pin PA4 to input
		GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000000 << (4 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
		GPIOA->PUPDR |= (0x00000002 << (4 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)


	// Set pin A9 to output LED BLUE
		GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
		GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10
	//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
		GPIOA->OTYPER |= (0x0000 << (9)); // Set output type register (0x00 -
	//Push pull, 0x01 - Open drain)
		GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 –
	//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)


	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B

	// Set pin PB5 to input
		GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000000 << (5 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
		GPIOB->PUPDR |= (0x00000002 << (5 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)


	// Set pin PB0 to input
		GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
		GPIOB->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	// Set pin B4 to output LED RED
		GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
		GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10
	//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
		GPIOB->OTYPER |= (0x0000 << (4)); // Set output type register (0x00 -
	//Push pull, 0x01 - Open drain)
		GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
		GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 –
	//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)


	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

	// Set pin PC1 to input
		GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
		GPIOC->PUPDR |= (0x00000002 << (1 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	// Set pin PC0 to input
		GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
		GPIOC->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	// Set pin C7 to output LED GREEN
		GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
		GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10
	//MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
		GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
		GPIOC->OTYPER |= (0x0000 << (7)); // Set output type register (0x00 -
	//Push pull, 0x01 - Open drain)
		GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 –
	//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

}
void joystickLed(){
		uint16_t up = GPIOA->IDR & (0x0001 << 4); //Read from pin PA4
		uint16_t center = GPIOB->IDR & (0x0001 << 5); //Read from pin PB5
		uint16_t down = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0
		uint16_t left = GPIOC->IDR & (0x0001 << 1); //Read from pin PC1
		uint16_t right = GPIOC->IDR & (0x0001 << 0); //Read from pin PC0

		if (up){
			GPIOA->ODR |= (0x0001 << 9); // Blue PRINT YELLOW
		}
		if (down){
			GPIOB->ODR |= (0x0001 << 4); // Red PRINT CYAN
		}
		if (left){
			GPIOA->ODR |= (0x0001 << 9); // Blue PRINT GREEN
			GPIOB->ODR |= (0x0001 << 4); // Red
		}
		if (right){
			GPIOC->ODR |= (0x0001 << 7); // Green PRINT BLUE
			GPIOB->ODR |= (0x0001 << 4); // Red
		}
		if (center){
			GPIOC->ODR |= (0x0001 << 7); // Green PRINT MAGENTA
		}
}

void setLed(int blue, int green, int red){
	if (blue == 1){
		if (green == 1){
			if (red == 1){ // NO LED
				GPIOC->ODR |= (0x0001 << 7); // Green
				GPIOA->ODR |= (0x0001 << 9); // Blue
				GPIOB->ODR |= (0x0001 << 4); // Red
			}else { // RED
				GPIOC->ODR |= (0x0001 << 7); // Green
				GPIOA->ODR |= (0x0001 << 9); // Blue
			}
		}else if (red == 1) { // GREEN
			GPIOA->ODR |= (0x0001 << 9); // Blue
			GPIOB->ODR |= (0x0001 << 4); // Red
		}else { // YELLOW
			GPIOA->ODR |= (0x0001 << 9); // Blue
		}
	}else if (green == 1){
		if (red == 1){ // BLUE
			GPIOC->ODR |= (0x0001 << 7); // Green
			GPIOB->ODR |= (0x0001 << 4); // Red
		}else { // CYAN
			GPIOC->ODR |= (0x0001 << 7); // Green
		}
	}else if (red == 1){ // CYAN
		GPIOB->ODR |= (0x0001 << 4); // Red
	}else {
		// White
	}
}

