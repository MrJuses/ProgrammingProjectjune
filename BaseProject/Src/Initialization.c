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
#include "ansi.h"
#include "shoot.h";

void init(){

	// TIMER INITIALIZE

	RCC->APB1ENR |= RCC_APB1Periph_TIM2;
	TIM2->CR1 = 0x0000;
	TIM2->ARR = 0xF9FF;
	TIM2->PSC = 0x0009;
	TIM2->CR1 = 0x0001;
	TIM2->DIER |= 0x0001;

	NVIC_SetPriority(TIM2_IRQn, 0);
	NVIC_EnableIRQ(TIM2_IRQn);

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A

	// Set pin PA1 to input
		GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
		GPIOA->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOA->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
		GPIOA->PUPDR |= (0x00000002 << (1 * 2)); // Set push/pull register (0x00 -
	//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

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

	// Set pin PC11 to input
		GPIOC->MODER &= ~(0x00000003 << (11 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000000 << (11 * 2)); // Set mode register (0x00 –
	// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->PUPDR &= ~(0x00000003 << (11 * 2)); // Clear push/pull register
		GPIOC->PUPDR |= (0x00000002 << (11 * 2)); // Set push/pull register (0x00 -
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

		RCC->AHBENR |= RCC_AHBPeriph_GPIOD; // Enable clock for GPIO Port C

		// Set pin PC11 to input
				GPIOD->MODER &= ~(0x00000003 << (2 * 2)); // Clear mode register
				GPIOD->MODER |= (0x00000000 << (2 * 2)); // Set mode register (0x00 –
			// Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
				GPIOD->PUPDR &= ~(0x00000003 << (2 * 2)); // Clear push/pull register
				GPIOD->PUPDR |= (0x00000002 << (2 * 2)); // Set push/pull register (0x00 -
			//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

}

void init2(){
		RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C
				// Set pin PC2 to input
		GPIOC->MODER &= ~(0x00000003 << (2 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000000 << (2 * 2)); // Set mode register (0x00 –
				//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->PUPDR &= ~(0x00000003 << (2 * 2)); // Clear push/pull register
		GPIOC->PUPDR |= (0x00000002 << (2 * 2)); // Set push/pull register (0x00 -
				//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

		uint16_t valone = GPIOC->IDR & (0x0001 << 2); //Read from pin PA0

			// Set pin PA1 to input
		GPIOC->MODER &= ~(0x00000003 << (3 * 2)); // Clear mode register
		GPIOC->MODER |= (0x00000000 << (3 * 2)); // Set mode register (0x00 –
				//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
		GPIOC->PUPDR &= ~(0x00000003 << (3 * 2)); // Clear push/pull register
		GPIOC->PUPDR |= (0x00000002 << (3 * 2)); // Set push/pull register (0x00 -
				//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

		uint16_t valtwo = GPIOC->IDR & (0x0001 << 3); //Read from pin PA1

		RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
		RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
		RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12

		ADC1->CR = 0x00000000; // Clear CR register
		ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
		ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

		ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
		for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

		ADC1->CR |= 0x80000000; // Start ADC1 calibration
		while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
		for (int i = 0 ; i < 100 ; i++) {} // Wait for a little while

		ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
		while (!(ADC1->ISR & 0x00000001)); // Wait until ready

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
void window(int y1, int x1, int y2, int x2){
	clearScreenResCurser();
	int x, y;
	for(x = x1; x < x2; x++){
		for(y = y1; y < y2; y++){
			if (x == x1){
				if (y == y1){
					printf("%c",201);
				} else if (y == y2-1){
					printf("%c\n",187);
				} else{
					printf("%c",205);
				}
			} else if(x == x2 - 1){
				if (y == y1){
					printf("%c",200);
				} else if (y == y2 - 1){
					printf("%c\n",188);
				} else{
					printf("%c",205);
				}
			} else{
				if (y == y1){
					printf("%c",186);
				} else if (y == y2 - 1){
					printf("%c\n",186);
				} else{
					printf(" ");
				}
			}
		}
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

uint16_t readAntenna8(){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
		uint16_t x = ADC_GetConversionValue(ADC1);
		return x;
}

uint16_t readAntenna9(){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
		uint16_t y = ADC_GetConversionValue(ADC1);
		return y;
}

uint16_t readAntenna1(){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);
	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
	uint16_t x = ADC_GetConversionValue(ADC1); // Read the ADC value
	return x;
}
uint16_t readAntenna2(){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);
	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read
	uint16_t y = ADC_GetConversionValue(ADC1); // Read the ADC value
	return y;
}

uint8_t readJoystick(){
	uint16_t up = GPIOA->IDR & (0x0001 << 4); //Read from pin PA4
	uint16_t center = GPIOB->IDR & (0x0001 << 5); //Read from pin PB5
	uint16_t down = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0
	uint16_t left = GPIOC->IDR & (0x0001 << 1); //Read from pin PC1
	uint16_t right = GPIOC->IDR & (0x0001 << 0); //Read from pin PC0

	uint8_t bit = 0;

	if (up){
		bit |= 0x01;
	}
	if (down){
		bit |= 0x02;
	}
	if (left){
		bit |= 0x04;
	}
	if (right){
		bit |= 0x08;
	}
	if (center){
		bit |= 0x10;
	}
	return bit;
}

void randConfig(){
	RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
	RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
	RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12

	ADC1->CR = 0x00000000; // Clear CR register
	ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
	ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

	ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
	for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

	ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
	while (!(ADC1->ISR & 0x00000001)); // Wait until ready
}

