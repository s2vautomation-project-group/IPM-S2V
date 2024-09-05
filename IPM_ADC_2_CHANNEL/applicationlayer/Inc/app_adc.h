/*
 * app_adc.h
 *
 *  Created on: Sep 4, 2024
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
void adc_channel(ADC_Channel channel);
void adc_handler(ADC_Channel channel);
#endif /* INC_APP_ADC_H_ */
