/***************************** INVS Engineering *******************************
 *
 * FILE				: LedDriverConfig.h
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
#ifndef COMPONENTS_LEDDRIVER_INCLUDE_LEDDRIVERCONFIG_H_
#define COMPONENTS_LEDDRIVER_INCLUDE_LEDDRIVERCONFIG_H_

/* Includes -----------------------------------------------------------------*/
#include "driver/ledc.h"

/* Config defines ----------------------------------------------------------*/

#define IS_STANDART_ACTIVE		1
#define	GPIO_NUM_WHITE 			GPIO_NUM_26

#define IS_RGB_ACTIVE			1
#define	GPIO_NUM_RED			GPIO_NUM_32
#define	GPIO_NUM_GREEN 			GPIO_NUM_33
#define	GPIO_NUM_BLUE 			GPIO_NUM_25

#define DUTY_RESOLUTION_BIT		LEDC_TIMER_8_BIT

#define IS_LOGI_ENABLE			1

#endif /* COMPONENTS_LEDDRIVER_INCLUDE_LEDDRIVERCONFIG_H_ */
