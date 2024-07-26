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
int rtcdata=12;
float adcdata=40.6;



void DataTosend()
{
	char RTC_cloud_data[20];
	char ADC_cloud_data[20];
	//DataToGsm(data);
	snprintf(RTC_cloud_data, sizeof(RTC_cloud_data), "%d", rtcdata);
	snprintf(ADC_cloud_data, sizeof(ADC_cloud_data), "%.2f", adcdata);
	DataToCloud(1,RTC_cloud_data);

	DataToCloud(2,ADC_cloud_data);

//	HAL_Delay(3000);





}
