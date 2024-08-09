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

void DataTosend(struct data *d)
{

	DataToCloud(d->time,d->CH1,d->CH2,d->CH3,d->CH4,d->D1,d->D2,d->D3,d->D4);


}
