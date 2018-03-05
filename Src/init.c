#include "init.h"

extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim2;

void init_board()
{
	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
}


void initLCD()
{
	lcdInit(&hi2c1, (uint8_t)0x38, (uint8_t)4, (uint8_t)16);
	
	// Print text and home position 0,0
	lcdPrintStr((uint8_t*)"PWM Meter v1.0", 14);
	
	// Set cursor at zero position of line 3
	//lcdSetCursorPosition(0, 1);

	// Print text at cursor position
	//lcdPrintStr((uint8_t*)"World!", 6);
	vTaskDelay(1000);
}