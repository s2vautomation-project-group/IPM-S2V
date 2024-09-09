/*
 * app_adc.h
 *
 *  Created on: Sep 9, 2024
 *      Author: KAVYA
 */

#ifndef INC_APP_ADC_H_
#define INC_APP_ADC_H_
//typedef enum
//{
//	my_ADC_CHANNEL_5=1,
//	my_ADC_CHANNEL_6=2,
//	BOTH = 3
//}ADC_Channel;
#include "data.h"

float voltage_cal(void);

void ADC_handler(struct data *d);



#endif /* INC_APP_ADC_H_ */
