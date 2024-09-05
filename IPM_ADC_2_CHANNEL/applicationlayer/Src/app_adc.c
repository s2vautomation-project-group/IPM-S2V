/*
 * app_adc.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Somanath
 */
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include"app_adc.h"
#include"com_adc.h"

#define MIN_VALUE 3.3
#define MAX_VALUE 4095

int raw_value;
float adc1_value,adc2_value;

float voltage_cal(void)
{
	raw_value=adc_value();
	return (raw_value*(MIN_VALUE/MAX_VALUE));
}

void adc_channel(ADC_Channel channel)
{
	switch(channel)
	{
	case my_ADC_CHANNEL_5:
		ADC_select_CH5();
		break;
	case my_ADC_CHANNEL_6:
		ADC_select_CH6();
		break;
	}

	adc_start();
	adc_conversion();
	if(channel==my_ADC_CHANNEL_5)
	{
		adc1_value=voltage_cal();
	}
	else if(channel==my_ADC_CHANNEL_6)
	{
		adc2_value=voltage_cal();
	}
	adc_stop();
}

void adc_handler(ADC_Channel channel)
{
	adc_channel(channel);
}
