/*
 * Application_GSM.c
 *
 *  Created on: Aug 1, 2024
 *      Author: DELL
 */


#include "main.h"
#include "Application_GSM.h"
#include "Common_Gsm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char data[500]="Welcome_GSM";
//int rtcdata=12;
//float adcdata=40.6;



//void DataTosend(int rtcdatedata,int rtctimedata,float adcdata)
//{
//	uint8_t RTC_date_data[20];
//	uint8_t RTC_time_data[20];
//	uint8_t ADC_data[20];
//	//DataToGsm(data);
//	snprintf(RTC_date_data, sizeof(RTC_date_data), "%d", rtcdatedata);
//	snprintf(RTC_time_data, sizeof(RTC_time_data), "%d", rtctimedata);
//	snprintf(ADC_data, sizeof(ADC_data), "%.2f", adcdata);
//
////	DataToCloud(1,RTC_date_data);
////	HAL_Delay(5000);
////	DataToCloud(1,RTC_time_data);
////	HAL_Delay(5000);
////	DataToCloud(2,ADC_cloud_data);
////	HAL_Delay(5000);
//	DataToCloud(RTC_date_data,RTC_time_data,ADC_data);
//
//
//}
//


void DataTosend(char* time,char* val)
{
//	uint8_t RTC_data[20];
//	uint8_t ADC_data[20];
//	//DataToGsm(data);
//	snprintf(RTC_data, sizeof(RTC_data), "%2d:%2d:%2d", hour,minutes,seconds);
//	snprintf(ADC_data, sizeof(ADC_data), "%f", adcdata);

//	DataToCloud(1,RTC_date_data);
//	HAL_Delay(5000);
//	DataToCloud(1,RTC_time_data);
//	HAL_Delay(5000);
//	DataToCloud(2,ADC_cloud_data);
//	HAL_Delay(5000);
	DataToCloud(time,val);


}
