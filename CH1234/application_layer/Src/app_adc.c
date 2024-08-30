/*
 * app_adc.c
 *
 *  Created on: Aug 8, 2024
 *      Author: Somanath
 */
#include "main.h"
#include<stdio.h>
#include<stdlib.h>
#include"app_adc.h"
#include"com_adc.h"

int A;
float d,f;

float voltage_cal(void)
{
	A=adc_value();
	return (A*(3.3/4095));
}

void adc1(void)
{
	ADC_select_CH5();
	adc_start();
	adc_conversion();
	d=voltage_cal();
	adc_stop();
}

void adc2(void)
{
	ADC_select_CH6();
	adc_start();
	adc_conversion();
    f=voltage_cal();
	adc_stop();
}

void adc_handler(void)
{
	adc1();
	adc2();
}
