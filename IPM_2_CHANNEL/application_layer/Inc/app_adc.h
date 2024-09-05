/*
 * app_adc.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Somanath
 */

#ifndef INC_APP_ADC_H_
#define INC_APP_ADC_H_
typedef enum
{
	my_ADC_CHANNEL_5=1,
	my_ADC_CHANNEL_6=2
}ADC_Channel;

float voltage_cal(void);
void adc2(ADC_Channel channel);
//void adc_handler(ADC_Channel channel);
void adc_handler(ADC_Channel channel[], size_t num_channel);


#endif /* INC_APP_ADC_H_ */
