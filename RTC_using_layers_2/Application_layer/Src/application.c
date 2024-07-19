/*
 * application.c
 *
 *  Created on: Jul 12, 2024
 *      Author: DELL
 */



#include <stdint.h>
#include "stdio.h"
#include "application.h"
#include <string.h>
#include "common.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
//Convert normal decimal numbers to binary coded decimal
uint8_t decToBcd(int val)
{
	return (uint8_t)( (val/10*16) + (val%10) );
}
//Convert binary coded decimal to normal decimal numbers
int bcdToDec(uint8_t val)
{
	return (int)( (val/16*10) + (val%16) );
}
typedef struct {
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t dayofweek;
	uint8_t dayofmonth;
	uint8_t month;
	uint8_t year;
} TIME;

TIME time;

//function to set time
void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
{
	uint8_t set_time[7];
	set_time[0] = decToBcd(sec);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(hour);
	set_time[3] = decToBcd(dow);
	set_time[4] = decToBcd(dom);
	set_time[5] = decToBcd(month);
	set_time[6] = decToBcd(year);

I2C_write(set_time);
//  {
//	HAL_I2C_Mem_Write(&hi2c1, DS3107_ADDRESS, 0x00, 1, set_time, 7, 1000);
//  }

}
void Get_Time (void)
{
	uint8_t get_time[7];
	I2C_read(get_time);
//   {
//	HAL_I2C_Mem_Read(&hi2c1, DS3107_ADDRESS, 0x00, 1, get_time, 7, 1000);
//   }
	time.seconds 	= bcdToDec(get_time[0]);
	time.minutes 	= bcdToDec(get_time[1]);
	time.hour 		= bcdToDec(get_time[2]);
	time.dayofweek  = bcdToDec(get_time[3]);
	time.dayofmonth = bcdToDec(get_time[4]);
	time.month 		= bcdToDec(get_time[5]);
	time.year 		= bcdToDec(get_time[6]);
}

char buffer[15];


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void app(void)
{
  /* USER CODE BEGIN 1 */
//	char array[] = "HELLO WORLD";
//	char retval;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */




  /* USER CODE BEGIN 2 */

//  ssd1306_Fill(White);
//  ssd1306_UpdateScreen();

  //Set_Time(40, 14, 04, 3, 16, 7, 24);

//  ssd1306_SetCursor(5, 5);
//  retval = ssd1306_WriteString(array, Font_11x18, White);
//  ssd1306_UpdateScreen();



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  while (1)
//  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  Get_Time();
	  	  sprintf(buffer, "%02d:%02d:%02d", time.hour, time.minutes, time.seconds);

//	  	  lcd_put_cur(0,0);
//	  	  lcd_send_string(buffer);

	  	  ssd1306_SetCursor(5, 5);
	  	  ssd1306_WriteString(buffer, Font_7x10, White);
	  	  ssd1306_UpdateScreen();


	  	  sprintf(buffer, "%02d-%02d-20%02d", time.dayofmonth, time.month, time.year);
//	  	  lcd_put_cur(1,0);
//	  	  lcd_send_string(buffer);
	  	 ssd1306_SetCursor(7, 20);
	  		  	  ssd1306_WriteString(buffer, Font_7x10, White);
	  		  	  ssd1306_UpdateScreen();

	  	  HAL_Delay(500);
  }
  /* USER CODE END 3 */
//}
