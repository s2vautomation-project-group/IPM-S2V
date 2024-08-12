/*
 * Application_GSM.c
 *
 *  Created on: Aug 5, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "Application_GSM.h"
#include "Common_Gsm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count=0;

void DataToGsm(struct data *d1)
{
	uint8_t seconds=d1->sec;
	if(seconds==59)
	{
		count=count+1;
	}


	if(count==3)
	{
		DataToCloud(d1->time,d1->CH1,d1->CH2,d1->CH3,d1->CH4,d1->D1,d1->D2,d1->D3,d1->D4);
		count=0;
	}


}

