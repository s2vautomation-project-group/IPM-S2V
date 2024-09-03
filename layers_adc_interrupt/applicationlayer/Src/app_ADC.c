/*
 * ADC.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Somanath
 */
#include <app_ADC.h>
#include <com_adc.h>
#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include"math.h"

extern ADC_HandleTypeDef hadc1;
#define MIN_VALUE 3.3
#define MAX_VALUE 4095
float d;
float vol;
int temp;


float Voltage_Calculation(void)
{
	vol=(float)(temp*(MIN_VALUE/MAX_VALUE));
    return vol;
}

void adc_handler(void)
{

	d =(float)Voltage_Calculation();
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	temp=(int)adc_value();
	//HAL_ADC_Start_IT(&hadc1);

}
