/*
 * app_adc.h
 *
 *  Created on: Sep 6, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "data.h"

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
