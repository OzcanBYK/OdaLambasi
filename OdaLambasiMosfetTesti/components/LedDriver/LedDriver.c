/***************************** INVS Engineering *******************************
 *
 * FILE				: LedDriver.c
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

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "LedDriver.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_Init
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_Init(void)
{
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = SPEED_MODE,
        .timer_num        = TIMER_NUMBER,
        .duty_resolution  = DUTY_RESOLUTION_BIT,
        .freq_hz          = PWM_FREQUENCY,
        .clk_cfg          = CLOCK_CONFIG
    };
    ledc_timer_config(&ledc_timer);

#if (IS_STANDART_ACTIVE)
    ledc_channel_config_t ledcChannelWhite = {
		.speed_mode     = SPEED_MODE,
		.channel        = LEDC_CHANNEL_WHITE,
		.timer_sel      = TIMER_NUMBER,
		.intr_type      = INTERRUPT_TYPE,
		.gpio_num       = GPIO_NUM_WHITE,
		.duty           = 0, // Set duty to 0%
		.hpoint         = 0
	};
    ledc_channel_config(&ledcChannelWhite);
#endif

#if (IS_RGB_ACTIVE)
    ledc_channel_config_t ledcChannelRed = {
		.speed_mode     = SPEED_MODE,
		.channel        = LEDC_CHANNEL_RED,
		.timer_sel      = TIMER_NUMBER,
		.intr_type      = INTERRUPT_TYPE,
		.gpio_num       = GPIO_NUM_RED,
		.duty           = 0, // Set duty to 0%
		.hpoint         = 0
	};
	ledc_channel_config(&ledcChannelRed);

    ledc_channel_config_t ledcChannelGreen = {
		.speed_mode     = SPEED_MODE,
		.channel        = LEDC_CHANNEL_GREEN,
		.timer_sel      = TIMER_NUMBER,
		.intr_type      = INTERRUPT_TYPE,
		.gpio_num       = GPIO_NUM_GREEN,
		.duty           = 0, // Set duty to 0%
		.hpoint         = 0
	};
	ledc_channel_config(&ledcChannelGreen);

    ledc_channel_config_t ledcChannelBlue = {
		.speed_mode     = SPEED_MODE,
		.channel        = LEDC_CHANNEL_BLUE,
		.timer_sel      = TIMER_NUMBER,
		.intr_type      = INTERRUPT_TYPE,
		.gpio_num       = GPIO_NUM_BLUE,
		.duty           = 0, // Set duty to 0%
		.hpoint         = 0
	};
	ledc_channel_config(&ledcChannelBlue);
#endif

#if (IS_LOGI_ENABLE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "Driver installed");
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/


/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_UpdateLedWhite
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_UpdateLedWhite(uint16_t Value)
{
#if (IS_STANDART_ACTIVE)
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_WHITE, Value);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_WHITE);
#else
	ESP_LOGI(LED_DRIVER_LOGI_TAG, "White is not active");
#endif

#if (IS_LOGI_ENABLE && IS_STANDART_ACTIVE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "White: %d",Value);
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/


/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_UpdateLedWhite
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_UpdateLedRed(uint16_t Value)
{
#if (IS_RGB_ACTIVE)
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_RED, Value);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_RED);
#else
	ESP_LOGI(LED_DRIVER_LOGI_TAG, "RGB is not active");
#endif

#if (IS_LOGI_ENABLE && IS_RGB_ACTIVE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "Red: %d",Value);
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/


/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_UpdateLedWhite
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_UpdateLedGreen(uint16_t Value)
{
#if (IS_RGB_ACTIVE)
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_GREEN, Value);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_GREEN);
#else
	ESP_LOGI(LED_DRIVER_LOGI_TAG, "RGB is not active");
#endif

#if (IS_LOGI_ENABLE && IS_RGB_ACTIVE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "Green: %d",Value);
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/


/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_UpdateLedWhite
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_UpdateLedBlue(uint16_t Value)
{
#if (IS_RGB_ACTIVE)
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_BLUE, Value);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_BLUE);
#else
	ESP_LOGI(LED_DRIVER_LOGI_TAG, "RGB is not active");
#endif

#if (IS_LOGI_ENABLE && IS_RGB_ACTIVE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "Blue: %d",Value);
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/


/*-----------------------------------------------------------------------------
 ROUTINE NAME : Ledc_UpdateLedWhite
 INPUT/OUTPUT :
 DESCRIPTION  :
 ----------------------------------------------------------------------------*/
void LedDriver_UpdateLedRGB(uint16_t Red,uint16_t Green,uint16_t Blue)
{
#if (IS_RGB_ACTIVE)
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_RED, Red);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_RED);
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_GREEN, Green);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_GREEN);
	ledc_set_duty(SPEED_MODE, LEDC_CHANNEL_BLUE, Blue);
	ledc_update_duty(SPEED_MODE, LEDC_CHANNEL_BLUE);
#else
	ESP_LOGI(LED_DRIVER_LOGI_TAG, "RGB is not active");
#endif

#if (IS_LOGI_ENABLE && IS_RGB_ACTIVE)
    ESP_LOGI(LED_DRIVER_LOGI_TAG, "Red: %d, Green: %d, Blue: %d",Red,Green,Blue);
#endif
}
/*------------------------END OF CURRENT FUNCTION----------------------------*/

/*******************************END OF FILE***********************************/
