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



uint16_t raw_value;

float adc1_value,adc2_value;

float voltage_cal(void)
{
	 raw_value = adc_value();
	return (raw_value * (3.3 / 4095));
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
	if (channel == my_ADC_CHANNEL_5)
	{
		adc1_value = voltage_cal();
	} else if (channel == my_ADC_CHANNEL_6)
	{
		adc2_value = voltage_cal();
	}
	adc_stop();
}

//void adc_handler(ADC_Channel channel[], size_t num_channel)
void adc_handler(ADC_Channel channel)
{
//	for (size_t i = 0; i < num_channel; i++) {
//    adc_channel(channel[i]);


	adc_channel(channel);
}


//int A1,A2;
//float d1,d2;
//int switch_case=0;
//uint8_t w[4];
//extern uint32_t ss[4];
//
//void adc1(void)
//{
//
//	adc_start();
//	adc_conversion();
//	switch_channel();
//
//	adc_stop();
//	if(w[0]==0)
//	{
//	  ADC_channel_set(CHANNEL_5);
//	  {
//		  switch_channel();
//	  }
//	}
//	if(w[1]==0)
//	{
//	  ADC_channel_set(CHANNEL_6);
//	  {
//		  switch_channel();
//	  }
//	}
//
//
//}
//
//void switch_channel(void)
//{
//	if(ss[0] == CHANNEL_5 )
//	{
//		switch_case=1;
//    }
//	 if(ss[1] == CHANNEL_6 )
//	{
//	    switch_case=2;
//    }
//
//	switch(switch_case)
//	{
//	case 1: A1 = adc_value();
//		    d1 = (A1 * (3.3/4095));
//            w[0]=0;
//            break;
//
//	case 2: A2 = adc_value();
//		    d2 = (A2 * (3.3/4095));
//            w[1]=0;
//	        break;
//	}
//}
////void adc2(void)
////{
////	ADC_select_CH6();
////	adc_start();
////	adc_conversion();
////    f=voltage_cal();
////     adc_stop();
////}
//
//void adc_handler(void)
//{
//	adc1();
//}
