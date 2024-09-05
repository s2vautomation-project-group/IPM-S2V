/*
 * com_adc.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Somanath
 */
#include "main.h"
#ifndef INC_COM_ADC_H_
#define INC_COM_ADC_H_
void USER_SystemClock_Config(void);
void USER_ADC1_Init(void);
void USER_GPIO_Init(void);
void ADC_select_CH5(void);
void ADC_select_CH6(void);
void adc_start(void);
void adc_conversion(void);
uint16_t adc_value(void);
void adc_stop(void);
#endif /* INC_COM_ADC_H_ */
