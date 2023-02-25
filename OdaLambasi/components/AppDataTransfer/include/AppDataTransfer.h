/***************************** INVS Engineering *******************************
 *
 * FILE				: AppDataTransmission.h
 *
 * AUTHOR			: Özcan BIYIK
 *
 * PROJECT 			: Data Transmission with Mpbil App
 *
 * COMPILER 		: ESP-IDF
 *
 * VERSION 			:
 *
 * LIB VERSION 		:
 *
 * DESCRIPTION		:
 *
 * HISTORY 			: 21.02.23
 *
 *****************************************************************************/

/* Define to prevent recursive inclusion ------------------------------------*/
#ifndef APPDATATRANSMISSION_H_
#define APPDATATRANSMISSION_H_

/* Includes -----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gatt_common_api.h"

#include "sdkconfig.h"

/* Exported defines ----------------------------------------------------------*/
#define APP_DATA_TRANSFER_LOGI_TAG		"App Data Transfer"
/* Exported types ------------------------------------------------------------*/
typedef struct{
    uint8_t length;
    uint8_t Data[185];
}BleTxData_t;

typedef struct{
    uint8_t length;
    uint8_t Data[185];
}BleRxData_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported variables ------------------------------------------------------- */
QueueHandle_t     		BleRxQueue;
/* Exported functions ------------------------------------------------------- */
void AppDataTransfer_NvsInit(void);
void AppDataTransfer_BleInit(void);
void AppDataTransfer_BleSendData(BleTxData_t *BleTxData);
#endif /* APPDATATRANSMISSION_H_ */
