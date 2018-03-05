#ifndef __ADC_R__H
#define __ADC_R__H

#ifdef __cplusplus
 extern "C" {
#endif 

#include "stm32f1xx_hal.h"

#define ADC_BATTERY_VOLT     0.02647435897435897435897435897436

struct ADC_Rdata{
    volatile __IO uint16_t data[3];
    volatile __IO uint8_t convflag;
   };

void ADC_init(void);	 
	
uint16_t GET_VOLT1(void);	 
uint16_t GET_VOLT2(void);	
	 
#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_IT_H */

