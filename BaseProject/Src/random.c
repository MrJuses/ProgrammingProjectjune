#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include <time.h>
#include <stdlib.h>
#include <sin.h>
#include "charset.h"
#include "random.h"
#include "Initialization.h"

//takes output from potentiometers and adds them together then spits out a random number between 0 and 9
int getRand(){
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	int x = ADC_GetConversionValue(ADC1); // Read the ADC value

	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_1Cycles5);

	ADC_StartConversion(ADC1); // Start ADC read
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

	x += ADC_GetConversionValue(ADC1); // Read the ADC value;
	x = x % 10;
	return x;
}

