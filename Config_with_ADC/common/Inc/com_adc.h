/*
 * com_adc.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Somanath
 */
#include "main.h"
#ifndef INC_COM_ADC_H_
#define INC_COM_ADC_H_

//#define CH5 ADC_CHANNEL_5
//#define CH6 ADC_CHANNEL_6

void USER_SystemClock_Config(void);
void USER_ADC1_Init(void);
void USER_GPIO_Init(void);
void ADC_select_CH1(void);
void ADC_select_CH2(void);
void ADC_select_CH3(void);
void ADC_select_CH4(void);
void adc_start(void);
void adc_conversion(void);
uint16_t adc_value(void);
void adc_stop(void);

//typedef enum
//{
//    CHANNEL_5 = CH5,
//	CHANNEL_6 = CH6,
//	not_selected= 0
//} ADC_Channel;
//
//void USER_SystemClock_Config(void);
//void USER_ADC1_Init(void);
//void USER_GPIO_Init(void);
//void adc_start(void);
//void adc_conversion(void);
//uint16_t adc_value(void);
//void adc_stop(void);
//void ADC_channel_set(ADC_Channel CH_no);
//void ADC_select_CH5(void);
//void ADC_select_CH6(void);
#endif /* INC_COM_ADC_H_ */
