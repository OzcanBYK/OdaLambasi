/***************************** INVS Engineering *******************************
 *
 * FILE				: main.c
 *
 * AUTHOR			: Özcan BIYIK
 *
 * PROJECT 			: Oda Lambasý Mosfet Denemesi
 *
 * COMPILER 		: ESP-IDF
 *
 * VERSION 			:
 *
 * LIB VERSION 		:
 *
 * DESCRIPTION		:
 *
 * HISTORY 			: 27.01.23
 *
 *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "LedDriver.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t Counter;
/* Private function prototypes -----------------------------------------------*/
void app_main(void);

/* Private functions ---------------------------------------------------------*/
void app_main(void)
{
	ESP_LOGI("TEST", "MOSFET TESTI");

	LedDriver_Init();

	while(1)
	{
		Counter += 10;

		//LedDriver_UpdateLedWhite(Counter);
		LedDriver_UpdateLedRGB(Counter, Counter, Counter);

		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}
