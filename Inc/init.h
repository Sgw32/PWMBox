#include "stm32f1xx_hal.h"
#include "main.h"
#include "lcd_hd44780_i2c.h"

void init_board();
void toggle_led();

void sendUARTStatus();
void initLCD();