/*
 * app_adc.c
 *
 *  Created on: Aug 9, 2024
 *      Author: Somanath
 */
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include"app_adc.h"
#include"com_adc.h"

uint16_t A;
float d,f;

float voltage_cal(void)
{
	 A = adc_value();
	return (A * (3.3 / 4095));
}

void adc_channel(ADC_Channel channel)
{
	switch(channel)
	{
	case my_ADC_CHANNEL_5:
		ADC_select_CH5();
		break;
	case my_ADC_CHANNEL_6:
		ADC_select_CH5();
		break;
	default:printf("invalid channel");

	}
	adc_start();
	adc_conversion();
	if (channel == ADC_CHANNEL_5)
	{
		d = voltage_cal();
	} else if (channel == ADC_CHANNEL_6)
	{
		f = voltage_cal();
	}
	adc_stop();
}

void adc_handler(ADC_Channel channel)
{
	adc_channel(channel);
}
