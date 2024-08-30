/*
 * app_adc.h
 *
 *  Created on: Aug 9, 2024
 *      Author: Somanath
 */

#ifndef INC_APP_ADC_H_
#define INC_APP_ADC_H_
typedef enum
{
	my_ADC_CHANNEL_5=5,
	my_ADC_CHANNEL_6=6
}ADC_Channel;

float voltage_cal(void);
void adc2(ADC_Channel channel);
void adc_handler(ADC_Channel channel);
#endif /* INC_APP_ADC_H_ */
