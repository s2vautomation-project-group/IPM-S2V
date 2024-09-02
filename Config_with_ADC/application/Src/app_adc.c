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

int A1,A2;
float d1,d2;
int switch_case=0;
extern uint32_t ss;

void adc1(void)
{

	adc_start();
	adc_conversion();
	switch_channel();

	adc_stop();

}

void switch_channel(void)
{
	if(ss == CHANNEL_5 )
	{
		switch_case=1;
	}
	else if(ss == CHANNEL_6 )
	{
	switch_case=2;
	}

	switch(switch_case)
	{
	case 1: A1 = adc_value();
		    d1 = (A1 * (3.3/4095));

	        break;

	case 2: A2 = adc_value();
		    d2 = (A2 * (3.3/4095));

	        break;
	}
}
//void adc2(void)
//{
//	ADC_select_CH6();
//	adc_start();
//	adc_conversion();
//    f=voltage_cal();
//     adc_stop();
//}

void adc_handler(void)
{
	adc1();
}
