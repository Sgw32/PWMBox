#include "adc.h"

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

volatile __IO struct ADC_Rdata adc_Rdata;

// ----------------------PUBLIC----------------------
void ADC_init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_DMA1_CLK_ENABLE();
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 1, 2);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adc_Rdata.data, 2);
}

uint16_t GET_VOLT1(void)
{
	uint16_t data=0;
  HAL_NVIC_DisableIRQ(DMA1_Channel1_IRQn);  
  data = adc_Rdata.data[0];
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);  
  return data;  
}

uint16_t GET_VOLT2(void)
{
	uint16_t data=0;
  HAL_NVIC_DisableIRQ(DMA1_Channel1_IRQn);  
  data = adc_Rdata.data[1];
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);  
  return data;  
}

