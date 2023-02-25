/******************************* INVS Engineering *******************************
 *
 * PROJECT :
 *
 * COMPILER :
 *
 * VERSION :
 *
 * LIB VERSION :
 *
 * DESCRIPTION :
 *
 * HISTORY :29.06.22
 *
 ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
/*Libraries*/
#include "LedDriver.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*FreeRTOS Libraries*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_freertos_hooks.h"

/*ESP Libraries*/
#include "esp_err.h"
#include "esp_log.h"
#include "nvs_flash.h"

/*ESP32 BLE Libraries*/
#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gatt_common_api.h"

#include "AppDataTransfer.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
nvs_handle_t Nvs_handle;

TaskHandle_t				AppDataTransferRxTaskHandler	= NULL;
/* Private function prototypes -----------------------------------------------*/
void AppDataTransferRxTask(void * param);
void CheckAutoResume(void);

/* Private functions ---------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 ROUTINE NAME : Menu_BleTransmitTask
 INPUT/OUTPUT : void
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void AppDataTransferRxTask(void * param)
{
	BaseType_t 		status;
	BleRxData_t		BleRxData;

	while(1)
	{
		status = xQueueReceive(BleRxQueue, &BleRxData, pdMS_TO_TICKS(100));
		if(status == pdPASS)
		{
			if(BleRxData.length == 11)
			{
				if((BleRxData.Data[0] == 'S') && (BleRxData.Data[1] == 'T') && (BleRxData.Data[2] == 'R') &&
				   (BleRxData.Data[8] == 'E') && (BleRxData.Data[9] == 'N') && (BleRxData.Data[10] == 'D'))
				{
					LedDriver_UpdateLedWhite(BleRxData.Data[4]);
					LedDriver_UpdateLedRGB(BleRxData.Data[5],BleRxData.Data[6],BleRxData.Data[7]);

					uint8_t AutoResume;
					nvs_get_u8(Nvs_handle,"AutoResume",&AutoResume);
					if((BleRxData.Data[3] & 0x01) || AutoResume)
					{
						nvs_set_u8(Nvs_handle,"AutoResumeWhite",BleRxData.Data[4]);
						nvs_set_u8(Nvs_handle,"AutoResumeRed",BleRxData.Data[5]);
						nvs_set_u8(Nvs_handle,"AutoResumeGreen",BleRxData.Data[6]);
						nvs_set_u8(Nvs_handle,"AutoResumeBlue",BleRxData.Data[7]);
						nvs_set_u8(Nvs_handle,"AutoResume",BleRxData.Data[3]);
						nvs_commit(Nvs_handle);
					}
				}
			}
		}
	}

	vTaskDelete(AppDataTransferRxTaskHandler);
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/

/**
  * @brief
  * @param  void
  * @retval void
  */

void CheckAutoResume(void)
{
	uint8_t AutoResume,AutoResumeWhite,AutoResumeRed,AutoResumeGreen,AutoResumeBlue;
	nvs_get_u8(Nvs_handle,"AutoResume",&AutoResume);
	ESP_LOGI(" ", "%d",AutoResume);
	if(AutoResume == 0x01)
	{
		nvs_get_u8(Nvs_handle,"AutoResumeWhite",&AutoResumeWhite);
		nvs_get_u8(Nvs_handle,"AutoResumeRed",&AutoResumeRed);
		nvs_get_u8(Nvs_handle,"AutoResumeGreen",&AutoResumeGreen);
		nvs_get_u8(Nvs_handle,"AutoResumeBlue",&AutoResumeBlue);
		LedDriver_UpdateLedWhite(AutoResumeWhite);
		LedDriver_UpdateLedRGB(AutoResumeRed,AutoResumeGreen,AutoResumeBlue);
	}
}

/* Public functions ----------------------------------------------------------*/
void app_main(void)
{
	AppDataTransfer_NvsInit();

	nvs_open("ODALAMBASI", NVS_READWRITE, &Nvs_handle);

	LedDriver_Init();

	AppDataTransfer_BleInit();

	CheckAutoResume();

	  xTaskCreate(	AppDataTransferRxTask,				/*Task Subroutine*/
					"BLE_rx",			 				/*Task String*/
					4096, 								/*Stack Size*/
					NULL, 								/*Input Parameter*/
					4, 									/*Priority*/
					AppDataTransferRxTaskHandler);		/*HandlerName*/

}
