/*
 * application_Flash.c
 *
 *  Created on: Sep 1, 2024
 *      Author: User
 */
#include "main.h"
#include "application_Flash.h"
#include "common_Flash.h"

float d,vol;
int temp;


typedef struct
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hour;
    uint8_t dayofweek;
    uint8_t dayofmonth;
    uint8_t month;
    uint8_t year;
} TIME;

TIME time;

//ADC_HandleTypeDef hadc1;
//I2C_HandleTypeDef hi2c1;

void Application_Init(void)
{
    Flash_ErasePage();
    Set_Time(1, 9, 2, 0, 0, 0, 0);
}

void Application_Run(void)
{
   // float d;
    uint32_t current_address = FLASH_PAGE_125_ADDRESS;  // Start at the beginning of page 125

    HAL_ADC_Start_IT(&hadc1);
    d = Voltage_Calculation();

    Get_Time();
    Flash_WriteData(d, time.hour, time.minutes, time.seconds);

    float read_d;
    uint8_t read_hours, read_minutes, read_seconds;

   Flash_ReadData(current_address - 16, &read_d, &read_hours, &read_minutes, &read_seconds);

    HAL_Delay(1000);  // 5 seconds delay for example
}

float Voltage_Calculation(void)
{
	vol=(float)(temp*(MIN_VALUE/MAX_VALUE));
    return vol;
}

void adc_handler(void)
{

	d = (float)Voltage_Calculation();
}

uint32_t adc_value(void)
{
return	HAL_ADC_GetValue(&hadc1);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	temp = adc_value();
	//HAL_ADC_Start_IT(&hadc1);

}

//Convert normal decimal numbers to binary coded decimal
uint8_t decToBcd(int val)
{
	return (uint8_t)( (val/10*16) + (val%10) );
}

//Convert binary coded decimal to normal decimal numbers
uint8_t bcdToDec(uint8_t val)
{
	return (uint8_t)( (val/16*10) + (val%16) );
}

uint8_t set_time[7];
void Set_Time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
{
	//I2C_Write(&hi2c1, DS3107_ADDRESS, 0x00, 1, set_time, 7, 1000);

	set_time[0] = decToBcd(sec);
    set_time[1] = decToBcd(min);
    set_time[2] = decToBcd(hour);
    set_time[3] = decToBcd(dow);
    set_time[4] = decToBcd(dom);
    set_time[5] = decToBcd(month);
    set_time[6] = decToBcd(year);

    I2C_Write(&hi2c1, DS3107_ADDRESS, 0x00, 1, set_time, 7, 1000);


}

uint8_t get_time[7];
void Get_Time(void)
{
	      I2C_read(get_time);

	        time.seconds    = bcdToDec(get_time[0]);
    	    time.minutes    = bcdToDec(get_time[1]);
    	    time.hour       = bcdToDec(get_time[2]);
    	    time.dayofweek  = bcdToDec(get_time[3]);
    	    time.dayofmonth = bcdToDec(get_time[4]);
    	    time.month      = bcdToDec(get_time[5]);
    	    time.year       = bcdToDec(get_time[6]);
}

