/**
 *	Keil project for HC-SR04 Ultrasonic distance sensor
 *	
 * 	Tested on STM32F4-, STM32F429- Discovery and Nucleo F401RE boards
 *
 *	Before you start, select your target, on the right of the "Load" button
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision 5
 */
/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_hcsr04.h"
#include <stdio.h>

int main(void) {
	float distance;
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay functions */
	TM_DELAY_Init();
	
	/* Initialize LEDs on board */
	TM_DISCO_LedInit();
	
	/* Turn on LED red */
	TM_DISCO_LedOn(LED_RED);
	
	/* Initialize distance sensor */
	if (!TM_HCSR04_Init()) {
		/* Sensor is not ready to use */
		/* Maybe wiring is incorrect */
		while (1) {
			TM_DISCO_LedToggle(LED_RED | LED_GREEN);
			Delayms(100);
		}
	}

	while (1) {
		/* Read distance */
		/* Distance is returned in cm */
		distance = TM_HCSR04_Read();
		
		/* Something is going wrong, maybe incorrect pinout */
		if (distance < 0) {
			TM_DISCO_LedOn(LED_RED);
			TM_DISCO_LedOff(LED_GREEN);
		} else if (distance > 50) {
			/* Distance more than 50cm */
			TM_DISCO_LedOn(LED_GREEN);
			TM_DISCO_LedOff(LED_RED);
		} else {
			/* Distance between 0 and 50cm */
			TM_DISCO_LedOff(LED_GREEN | LED_RED);
		}
		
		/* Give some time to sensor */
		Delayms(100);
	}
}
