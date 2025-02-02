# STM32F4
## Libraries and projects

Here are listed all libraries for STM32F4 devices.
Libraries are designed to work with STM32F4xx series of MCU.
Every project here is created with Keil uVision, but tested with GCC compiler too (Coocox).
Each project includes 3 targets:

1. STM32F429-Discovery board (STM32F429, 180MHz)
2. STM32F4-Discovery board (STM32F407, 168MHz)
3. Nucleo F401-RE (STM32F401, 84MHz)

When you download repository and open project, you have to set correct your target, for device you use.
If you use other device in your project, then set your project and copy settings there from target options.

More information below
http://stm32f4-discovery.com


First time with Discovery board?
http://stm32f4-discovery.com

Current librarires:

- All libraries listed at one place for easy editing them from one place and use them for all projects

1. Two default projects are included
	1. Default Keil project, with CMSIS files v.1.4.0 included
	2. Default Keil project, with CMSIS files v.1.4.0 included and clock for STM32F429-Discovery slowed down to 168MHz for USB configuration
	3. Default Keil project, without CMSIS files included, because they are in Keil packs
	4. Default Keil project, without CMSIS files included, because they are in Keil packs and clock for STM32F429-Discovery slowed down to 168MHz for USB configuration
	5. How to make own Keil project? http://stm32f4-discovery.com/2014/04/stm32f429-discovery-with-cmsis-library-in-keil/
2. LED_BUTTON - Project example for STM32F4/29 Discovery
http://bit.ly/1nbAHbs
3. DELAY - Delay library for STM32F4/29
http://bit.ly/1gFrBjl
4. USART - USART library for STM32F4/29
http://bit.ly/1npVXHQ
5. SPI - SPI library for STM32F4/29
http://bit.ly/1lgtcjy
6. ADC - ADC library for STM32F4/29
http://bit.ly/1fINniy
7. DAC - DAC library for STM32F4/29
http://bit.ly/1rwGdTR
8. ILI9341 LCD - STM32F429 Discovery ILI9341 LCD library
http://bit.ly/PQQnCm
9. I2C - I2C library for STM32F4/29
http://bit.ly/1o4TS4q
10. STMPE811 touch driver for STM32F4/29 Discovery board
http://bit.ly/1ob7hYK
11. ILI9341 Button - Button library for ILI9341 LCD and STMPE811 Touch driver on STM32F429
http://bit.ly/RdiIDS
12. ONEWIRE - OneWire library for STM32F4/29
http://bit.ly/1nvT6jG
13. DS18B20 - DS18B20 OneWire temperature sensor library for STM32F4/29
http://bit.ly/1viCnSX
14. SDRAM - ISSI 8MByte SDRAM on STM32F429 Discovery board
http://bit.ly/1jVGY96
15. DS1307 - DS1307 RTC modeule for STM32F429 Discovery
http://bit.ly/1oxFaDK
16. HD44780 - HD44780 Alpha numeric LCD driver for STM32F429 discovery
http://bit.ly/1gR6Lzz
17. NRF24L01+ - NRF24L01+ 2.4 GHz transceiver library
http://bit.ly/1pTkrgY
18. ILI8341 LTDC - ILI9341 LCD with LTDC hardware only for STM32F429
http://bit.ly/1jeZaqH
19. Internal RTC - Library for internal RTC on STM32F4xx devices
http://bit.ly/U4wmKW
20. Independent watchdog - Library for watchdog on STM32F4xx devices
http://bit.ly/1w2ru5n
21. FATFS - Read SDcard with STM32F4xx using SDIO or SPI communication
http://bit.ly/1k9rJGo
22. RNG - Use of True random number generator peripheral on STM32F4xx devices
http://bit.ly/1sCyx4w
23. MFRC522 - Read RFID Cards with STM32F4xx devices
http://bit.ly/1ycHq7P
24. USB VCP - Use STM32F4xx as USB VCP device (Virtual COM Port)
http://bit.ly/1sgSy0M
25. AM2301 - AM2301 (DHT21) temperature and humidity sensor
http://bit.ly/1p2mqy1 
26. ROTARY ENCODER - Connect Rotary Encoder to STM32F4xx device
http://bit.ly/1sWSUeh
27. GPS - Read GPS data on STM32F4xx devices
http://bit.ly/1n93Dgb
28. L3GD20 - Measure rotation of all 3 axis with L3GD20 gyro sensor
http://bit.ly/1pNdpt4
29. USB MSC HOST - Read USB flash drive with STM32F4xx
http://bit.ly/1lAs4Im
30. HC-SR04 - Measure distance with ultrasonic sensor on STM32F4xx
http://bit.ly/1tMP7AX
31. USB HID HOST - Read USB mouse and keyboard on STM32F4xx
http://bit.ly/1tKFMIn
32. 4x4 KEYPAD - Read matrix keypad up to 4x4 with STM32F4xx
http://bit.ly/1qvYtyD
33. PWM - Use PWM on all possible timers for STM32F4xx device
http://bit.ly/1CFInc5
34. USB HID Device - Turn STM32F4 into USB HID Device
http://bit.ly/1qRtTkL
35. LIS302DL/LIS3DSH - Accelerometers on STM32F4-Discovery board. Also can be used with any STM32F4 device
http://bit.ly/X8z9UQ
36. DAC SIGNAL - Output predefined signals with STM32F4 using DAC, DMA and TIM
http://bit.ly/1phUdPD
37. BMP180 - Read atmosferic pressure on STM32F4 device
http://bit.ly/1qfGTve
38. EXTI - Use external interrupts with STM32F4
http://bit.ly/10ltRHI

- PCD8544 LCD (Nokia 5110/3310) - Library for LCD
http://bit.ly/1i7l4tB
