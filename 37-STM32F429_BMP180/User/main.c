/**
 *	Keil project for BMP180 pressure sensor
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
#include "tm_stm32f4_bmp180.h"
#include "tm_stm32f4_usart.h"

#include <stdio.h>

int main(void) {
	char buffer[50];
	
	/* Working structure */
	TM_BMP180_t BMP180_Data;
	
	/* Initialize system */
	SystemInit();
	
	/* Initialize delay */
	TM_DELAY_Init();
	
	/* Initialize USART1, 11500baud, TX: PB6 */
	TM_USART_Init(USART1, TM_USART_PinsPack_2, 115200);
	
	/* Initialize BMP180 pressure sensor */
	if (TM_BMP180_Init(&BMP180_Data) == TM_BMP180_Result_Ok) {
		/* Init OK */
		TM_USART_Puts(USART1, "BMP180 configured and ready to use\n\n");
	} else {
		/* Device error */
		TM_USART_Puts(USART1, "BMP180 error\n\n");
		while (1);
	}
	
	/* Imagine, we are at 1000 meters above the sea */
	/* And we read pressure of 95000 pascals */
	/* Pressure right on the sea is */
	sprintf(buffer, "Pressure right above the sea: %d pascals\n", TM_BMP180_GetPressureAtSeaLevel(95000, 1000));
	TM_USART_Puts(USART1, buffer);
	sprintf(buffer, "Data were calculated from pressure %d pascals at know altitude %d meters\n\n\n", 95000, 1000);
	TM_USART_Puts(USART1, buffer);

	while (1) {
		/* Start temperature conversion */
		TM_BMP180_StartTemperature(&BMP180_Data);
		
		/* Wait delay in microseconds */
		/* You can do other this here instead of delay */
		Delay(BMP180_Data.Delay);
		
		/* Read temperature first */
		TM_BMP180_ReadTemperature(&BMP180_Data);
		
		/* Start pressure conversion at ultra high resolution */
		TM_BMP180_StartPressure(&BMP180_Data, TM_BMP180_Oversampling_UltraHighResolution);
		
		/* Wait delay in microseconds */
		/* You can do other this here instead of delay */
		Delay(BMP180_Data.Delay);
		
		/* Read pressure value */
		TM_BMP180_ReadPressure(&BMP180_Data);
		
		/* Format data and print to USART */
		sprintf(buffer, "Temp: %2.3f degrees\nPressure: %6d Pascals\nAltitude at current pressure: %3.2f meters\n\n",
			BMP180_Data.Temperature,
			BMP180_Data.Pressure,
			BMP180_Data.Altitude
		);
		/* Send to USART */
		TM_USART_Puts(USART1, buffer);
		
		/* Some delay */
		Delayms(1000);
	}
}
