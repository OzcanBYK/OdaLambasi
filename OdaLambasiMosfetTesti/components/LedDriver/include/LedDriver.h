/***************************** INVS Engineering *******************************
 *
 * FILE				: LedDriver.h
 *
 * AUTHOR			: Özcan BIYIK
 *
 * PROJECT 			: Led Driver
 *
 * COMPILER 		: ESP-IDF
 *
 * VERSION 			:
 *
 * LIB VERSION 		:
 *
 * DESCRIPTION		: RGB ve/veya Standart Led Sürme
 *
 * HISTORY 			: 27.01.23
 *
 *****************************************************************************/

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef LEDDRIVER_H_
#define LEDDRIVER_H_

/* Includes -----------------------------------------------------------------*/
#include "LedDriverConfig.h"
#include "driver/ledc.h"
#include "esp_log.h"
/* Exported defines ----------------------------------------------------------*/
#define	LEDC_CHANNEL_WHITE 		LEDC_CHANNEL_0

#define	LEDC_CHANNEL_RED 		LEDC_CHANNEL_1
#define	LEDC_CHANNEL_GREEN 		LEDC_CHANNEL_2
#define	LEDC_CHANNEL_BLUE 		LEDC_CHANNEL_3

#define SPEED_MODE				LEDC_LOW_SPEED_MODE
#define TIMER_NUMBER          	LEDC_TIMER_0
#define PWM_FREQUENCY			200
#define CLOCK_CONFIG			LEDC_AUTO_CLK
#define INTERRUPT_TYPE			LEDC_INTR_DISABLE

#define LED_DRIVER_LOGI_TAG		"Led Driver"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported variables ------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
void LedDriver_Init(void);
void LedDriver_UpdateLedWhite(uint16_t Value);
void LedDriver_UpdateLedRed(uint16_t Value);
void LedDriver_UpdateLedGreen(uint16_t Value);
void LedDriver_UpdateLedBlue(uint16_t Value);
void LedDriver_UpdateLedRGB(uint16_t Red,uint16_t Green,uint16_t Blue);

#endif /* LEDDRIVER_H_ */
