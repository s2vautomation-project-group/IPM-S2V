/*
 * Terminal.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "data.h"
#include "ctype.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "app_terminal.h"
#include "com_terminal.h"
uint8_t buf[200];
//uint8_t buf2[20];
extern char CH1[10];
extern char CH2[10];
extern char CH3[10];
extern char CH4[10];



void terminal(struct data *d)
{
sprintf((char*)buf,"TIME:%02d:%02d:%02d 	 DATE:%02d/%02d/%02d  	CH1:%s  	CH2:%s  	CH3:%s  	CH4:%s  	GPIO1:%s  		GPIO2:%s  		GPIO3:%s  	 GPIO4:%s\r\n",d->hour,d->minutes,d->seconds,d->dayofmonth,d->month,d->year,CH1,CH2,CH3,CH4,d->Status1,d->Status2,d->Status3,d->Status4);
//	sprintf((char*)buf2,"%02d:%02d:%02d\r\n",d->dayofmonth,d->month,d->year);
	uart3_tx(buf);
//	HAL_Delay(100);

}
