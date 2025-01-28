/*
 * app_GSM.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "app_GSM.h"
#include "com_GSM.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "data.h"
char buffer_Time[15];
char buffer_Date[15];
char CH1[10];
char CH2[10];
char CH3[10];
char CH4[10];
char MDS[10];
static uint8_t Old_value = 0; // Retain value between function calls
static uint8_t count = 0; // Flag to indicate if data has been transmitted this minute

//extern struct data d;


UART_HandleTypeDef huart2;

void DataToCloud(struct data *d)
{

	uint8_t New_value=d->minutes;

//	//	DataToCloud(d1->time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->D1,d1->D2,d1->D3,d1->D4);
	sprintf((char*)buffer_Time,"%02d:%02d:%02d",d->hour,d->minutes,d->seconds);
	sprintf((char*)buffer_Date,"%02d/%02d/%02d",d->dayofmonth,d->month,d->year);

	//	HAL_UART_Transmit(&huart2, (uint8_t*)d->GPIO, 4, HAL_MAX_DELAY);
	sprintf((char*)CH1,"%f",d->adc1_value);
	sprintf((char*)CH2,"%f",d->adc2_value);
	sprintf((char*)CH3,"%f",d->adc3_value);
	sprintf((char*)CH4,"%f",d->adc4_value);
	sprintf((char*)MDS,"%f",d->MDS_value);

	if(d->GPIO[0]==1)
	{
		strcpy(d->Status1, "HIGH");
	}
	else
	{
		strcpy(d->Status1, "LOW");
	}

	if(d->GPIO[1]==1)
	{
		strcpy(d->Status2, "HIGH");
	}
	else
	{
		strcpy(d->Status2, "LOW");
	}

	if(d->GPIO[2]==1)
	{
		strcpy(d->Status3, "HIGH");
	}
	else
	{
		strcpy(d->Status3, "LOW");
	}

	if(d->GPIO[3]==1)
	{
		strcpy(d->Status4, "HIGH");
	}
	else
	{
		strcpy(d->Status4, "LOW");
	}

//	DataToPass();

	if (New_value != Old_value) {
		count++;
	}

	if (count >= d->scan_time) {
		// Transmit data
		if(d->scan_time>0)
		{
			DataToPass();
			count = 0; // Reset the counter after transmission
		}
	}
	Old_value = New_value;

}

void DataToPass()
{
	DataToWiFi(&d);
}

