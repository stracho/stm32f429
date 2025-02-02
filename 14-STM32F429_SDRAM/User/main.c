/**
 *	Keil project for SDRAM connected on STM32F429 Discovery board
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
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_sdram.h"
#include "tm_stm32f4_delay.h"

int main(void) {
	uint16_t write, read;
	uint8_t i;
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay */
	TM_DELAY_Init();
	
	/* Initialize leds */
	TM_DISCO_LedInit();
	
	/* Initialize SDRAM */
	if (TM_SDRAM_Init()) {
		TM_DISCO_LedOn(LED_GREEN);
	} else {
		TM_DISCO_LedOn(LED_RED);
	}
	/* Some delay */
	Delayms(2000);
	
	write = 1234;
	/* Write 16bit value to SDRAM at location 0x3214 */
	TM_SDRAM_Write16(0x3214, write);
	/* Read from location 0x3214 */
	read = TM_SDRAM_Read16(0x3214);
	
	if (write == read) {
		TM_DISCO_LedOff(LED_GREEN | LED_RED);
		/* Blink leds to indicate that reading and writing was correct */
		for (i = 0; i < 10; i++) {
			TM_DISCO_LedToggle(LED_GREEN | LED_RED);
			Delayms(100);
		}
	}
	
	while (1) {
	
	}
}
