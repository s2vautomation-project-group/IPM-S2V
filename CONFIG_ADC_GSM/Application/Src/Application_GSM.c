/*
 * Application_GSM.c
 *
 *  Created on: Sep 6, 2024
 *      Author: KAVYA
 */


#include "main.h"
#include "Application_GSM.h"
#include "Common_GSM.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "data.h"
char buffer_Time[15];
	char CH1[10];
	char CH2[10];
	char CH3[10];
	char CH4[10];
//extern struct data d;

int count=0;

extern UART_HandleTypeDef huart2;

void DataToGsm(struct data *d)
{
	uint8_t sec=d->sec;
	uint8_t ST=d->scan_time;
	//	DataToCloud(d1->time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->D1,d1->D2,d1->D3,d1->D4);
	sprintf(buffer_Time,"%02d:%02d:%02d",d->hr,d->min,d->sec);
//	HAL_UART_Transmit(&huart2, (uint8_t*)d->GPIO, 4, HAL_MAX_DELAY);
	sprintf(CH1,"%f",d->adc1_value);
	sprintf(CH2,"%f",d->adc2_value);
	sprintf(CH3,"%f",d->adc3_value);
	sprintf(CH4,"%f",d->adc4_value);

	if(d->GPIO[0]==1)
	{
		strcpy(d->Status1, "High");
	}
	else
	{
		strcpy(d->Status1, "Low");
	}

	if(d->GPIO[1]==1)
	{
		strcpy(d->Status2, "High");
	}
	else
	{
		strcpy(d->Status2, "Low");
	}

	if(d->GPIO[2]==1)
	{
		strcpy(d->Status3, "High");
	}
	else
	{
		strcpy(d->Status3, "Low");
	}

	if(d->GPIO[3]==1)
	{
		strcpy(d->Status4, "High");
	}
	else
	{
		strcpy(d->Status4, "Low");
	}





	if(sec==59)
	{
		count=count+1;

	}


	if(count==1)
	{
		DataToCloud(buffer_Time,CH1,CH2,CH3,CH4,d->Status1,d->Status2,d->Status3,d->Status4);
		count=0;
	}


}


//void DataToGsm()
//{
//	uint8_t sec=d.sec;
//	//	uint8_t ST=d.scan_time;
//	//	DataToCloud(d1->time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->D1,d1->D2,d1->D3,d1->D4);
//	sprintf(buffer_Time,"%02d:%02d:%02d",d.hr,d.min,d.sec);
////	HAL_UART_Transmit(&huart2, (uint8_t*)d.GPIO, 4, HAL_MAX_DELAY);
////	HAL_UART_Transmit(&huart2, (uint8_t*)0x1, 1, HAL_MAX_DELAY);
//
//
//	if(d.GPIO[0]==1)
//	{
//		strcpy(d.Status1, "High");
//	}
//	else
//	{
//		strcpy(d.Status1, "Low");
//	}
//
//	if(d.GPIO[1]==1)
//	{
//		strcpy(d.Status2, "High");
//	}
//	else
//	{
//		strcpy(d.Status2, "Low");
//	}
//
//	if(d.GPIO[2]==1)
//	{
//		strcpy(d.Status3, "High");
//	}
//	else
//	{
//		strcpy(d.Status3, "Low");
//	}
//
//	if(d.GPIO[3]==1)
//	{
//		strcpy(d.Status4, "High");
//	}
//	else
//	{
//		strcpy(d.Status4, "Low");
//	}
//
//
//
//
//
//	if(sec==59)
//	{
//		count=count+1;
//
//	}
//
//
//	if(count==1)
//	{
//	    DataToCloud(buffer_Time,d.CH1,d.CH2,d.CH3,d.CH4,d.Status1,d.Status2,d.Status3,d.Status4);
//		count=0;
//	}
//
//
//}

