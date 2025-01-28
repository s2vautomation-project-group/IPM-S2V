/*
 * app_RTC.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "data.h"
#include <stdint.h>
#include "stdio.h"
#include <string.h>
#include "com_RTC.h"
#include "app_RTC.h"


extern I2C_HandleTypeDef hi2c1;




#define RTC_add 0xD0

//decimal to bcd convertion

uint8_t dec_bcd(int val)
{
	return (uint8_t)((val/10*16)+(val%10));
}

//bcd to decimal convertion

int bcd_dec(uint8_t val)
{
	return (int)((val/16*10)+(val%16));
}




uint8_t Set_time[7];
void set_time(uint8_t sec,uint8_t min,uint8_t hr,uint8_t day,uint8_t dat,uint8_t mon,uint8_t yr)
{
	uint8_t Set_time[7];
	Set_time[0]=dec_bcd(sec);
	Set_time[1]=dec_bcd(min);
	Set_time[2]=dec_bcd(hr);
	Set_time[3]=dec_bcd(day);
	Set_time[4]=dec_bcd(dat);
	Set_time[5]=dec_bcd(mon);
	Set_time[6]=dec_bcd(yr);

	HAL_I2C_Mem_Write(&hi2c1, RTC_add, 0x00, 1, Set_time, 7, HAL_MAX_DELAY);  //1 bytes
}


uint8_t Get_time[7];
void get_time(struct data *d)
{
	uint8_t Get_time[7];
	HAL_I2C_Mem_Read(&hi2c1, RTC_add, 0x00, 1, Get_time, 7, HAL_MAX_DELAY);
	d->seconds=bcd_dec(Get_time[0]);
	d->minutes=bcd_dec(Get_time[1]);
	d->hour=bcd_dec(Get_time[2]);
	d->dayofweek=bcd_dec(Get_time[3]);
	d->dayofmonth=bcd_dec(Get_time[4]);
	d->month=bcd_dec(Get_time[5]);
	d->year=bcd_dec(Get_time[6]);
}










