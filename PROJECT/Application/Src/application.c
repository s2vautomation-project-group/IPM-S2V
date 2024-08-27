/*
 * application.c
 *
 *  Created on: Aug 5, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "application.h"
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "ctype.h"

char buffer_Time[15];


int count=0;

void DataToGsm(struct data *d1)
{
	uint8_t sec=d1->sec;
	uint8_t ST=d1->scan_time;
	//	DataToCloud(d1->time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->D1,d1->D2,d1->D3,d1->D4);
	sprintf(buffer_Time,"%02d:%02d:%02d",d1->hr,d1->min,d1->sec);

	if(d1->GPIO[0]=='1')
	{
		strcpy(d1->Status1, "High");
	}
	else
	{
		strcpy(d1->Status1, "Low");
	}

	if(d1->GPIO[1]=='1')
	{
		strcpy(d1->Status2, "High");
	}
	else
	{
		strcpy(d1->Status2, "Low");
	}

	if(d1->GPIO[2]=='1')
	{
		strcpy(d1->Status3, "High");
	}
	else
	{
		strcpy(d1->Status3, "Low");
	}

	if(d1->GPIO[3]=='1')
	{
		strcpy(d1->Status4, "High");
	}
	else
	{
		strcpy(d1->Status4, "Low");
	}




	if(sec==59)
	{
		count=count+1;

	}


	if(count==ST)
	{
		DataToCloud(buffer_Time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->Status1,d1->Status2,d1->Status3,d1->Status4);
		count=0;
	}


}




