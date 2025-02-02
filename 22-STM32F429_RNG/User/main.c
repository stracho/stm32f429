/**
 *	Keil project for Random Number Generator
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
#include "tm_stm32f4_usart.h"
#include "tm_stm32f4_rng.h"
#include <stdio.h>

int main(void) {
	char buffer[20];
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay */
	TM_DELAY_Init();
	
	/* Initialize USART1, TX: PB6 */
	TM_USART_Init(USART1, TM_USART_PinsPack_2, 115200);	
	
	/* Initialize random number generator */
	TM_RNG_Init();
	
	while (1) {
		/* Get number */
		sprintf(buffer, "Number: %u\n", TM_RNG_Get());
		/* Put to USART */
		TM_USART_Puts(USART1, buffer);
		Delayms(1000);
	}
}
