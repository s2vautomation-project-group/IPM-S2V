/*
 * app_adc.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Somanath
 */
#include "main.h"

#ifndef INC_APP_ADC_H_
#define INC_APP_ADC_H_

//typedef enum
//{
//	my_ADC_CHANNEL_5=1,
//	my_ADC_CHANNEL_6=2,
//	BOTH = 3
//}ADC_Channel;

float voltage_cal(void);

void ADC_handler();


#endif /* INC_APP_ADC_H_ */
