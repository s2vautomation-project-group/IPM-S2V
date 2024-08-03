/*
 * application.c
 *
 *  Created on: Jul 12, 2024
 *      Author: DELL
 */


#include "Common_GSM.h"
#include "Application_GSM.h"
#include "application_RTC.h"
#include <stdint.h>
#include "stdio.h"
#include <string.h>
#include "common_RTC.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "main.h"
#include "application_ADC.h"
#include "app_config.h"
#include "com_config.h"
extern ADC_HandleTypeDef hadc1;
extern float d;
extern  char A[4];

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


      I2C_Write(&hi2c1, DS3107_ADDRESS, 0x00, 1, set_time, 7, 1000);


}
void Get_Time (void)
{
	uint8_t get_time[7];

	I2C_read(get_time);

	time.seconds 	= bcdToDec(get_time[0]);
    time.minutes 	= bcdToDec(get_time[1]);
	time.hour 		= bcdToDec(get_time[2]);
	time.dayofweek  = bcdToDec(get_time[3]);
	time.dayofmonth = bcdToDec(get_time[4]);
	time.month 		= bcdToDec(get_time[5]);
	time.year 		= bcdToDec(get_time[6]);
}

char buffer_OLED[15];
char buffer_ADC[15];
char buffer_Configurator[4];

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void app(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */




  /* USER CODE BEGIN 2 */


//  Set_Time(40, 14, 04, 3, 16, 7, 24);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  while (1)
//  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


     data_receive();


	  Get_Time();
	  	  sprintf(buffer_OLED, "%02d:%02d:%02d", time.hour, time.minutes, time.seconds);





	  	  ssd1306_SetCursor(5, 5);
	  	  OLED_data(buffer_OLED);


	  	  //HAL_Delay(500);

	  	  /*ADC function started*/

	  	  HAL_ADC_Start_IT(&hadc1);
	  	  adc_handler();

	  	sprintf(buffer_ADC, "%f", d);
  		  ssd1306_SetCursor(7, 20);
  		  OLED_data(buffer_ADC);

  		  /*GSM functionalities started*/

//  		DataTosend(time.hour,time.minutes,time.seconds,d);


  		  DataTosend(buffer_OLED,buffer_ADC);		// 3 sec;
  		    /*Configurator functionalities*/
			  Configurator();
  		  sprintf(buffer_Configurator, "%s", A);
  		  ssd1306_SetCursor(7, 20);
 		  OLED_data(buffer_Configurator);
  		  //OLED_data(A);







  }


          void OLED_data(char* buffer)
         {

	  	    ssd1306_WriteString(buffer, Font_6x8, White);
	  	    ssd1306_UpdateScreen();

	  	  }
  /* USER CODE END 3 */
//}
