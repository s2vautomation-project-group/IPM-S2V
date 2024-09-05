/*
 * app_adc.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Somanath
 */
#include "main.h"

#ifndef INC_APP_ADC_H_
#define INC_APP_ADC_H_

typedef enum
{
	my_ADC_CHANNEL_5=1,
	my_ADC_CHANNEL_6=2
}ADC_Channel;

float voltage_cal(void);
//void adc2(ADC_Channel channel);
//void adc_handler(ADC_Channel channel);
//void adc_handler(ADC_Channel channel[], size_t num_channel);
void adc_handler(ADC_Channel channel);
//float voltage_cal(void);
//void adc1(void);
void adc_channel(ADC_Channel channel);
//void adc_handler(void);
#endif /* INC_APP_ADC_H_ */
