/*
 * Gsm.c
 *
 *  Created on: Jul 17, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "Uart.h"
#include "Gsm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char data[500]="Welcome_GSM";
//int rtcdata=12;
//float adcdata=40.6;



void DataTosend(int rtcdatedata,int rtctimedata,float adcdata)
{
	char RTC_date_data[20];
	char RTC_time_data[20];
	char ADC_cloud_data[20];
	//DataToGsm(data);
	snprintf(RTC_date_data, sizeof(RTC_date_data), "%d", rtcdatedata);
	snprintf(RTC_time_data, sizeof(RTC_time_data), "%d", rtctimedata);
	snprintf(ADC_cloud_data, sizeof(ADC_cloud_data), "%.2f", adcdata);

	DataToCloud(1,RTC_date_data);
	HAL_Delay(5000);
	DataToCloud(1,RTC_time_data);
	HAL_Delay(5000);
	DataToCloud(2,ADC_cloud_data);
	HAL_Delay(5000);


}
