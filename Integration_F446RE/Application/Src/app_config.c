/*
 * app_config.c
 *
 *  Created on: Sep 13, 2024
 *      Author: KAVYA
 */

#include <stdio.h>
#include "com_config.h"
#include "app_config.h"
#include "app_ADC.h"
#include "app_RTC.h"
#include "com_ADC.h"
#include <string.h>
#include "data.h"
#include "main.h"
#include <stdlib.h>
int switch_val=0;
char tx_data[15];
UART_HandleTypeDef huart1;
char arr1[10];
char arr2[10];
char *token;
int flag;
uint8_t* pin_status;
char config[4];
uint8_t s[4];
extern struct data d;
uint8_t adcChnlChecker[4];

void Configurator()
{
	data_receive();

	if (tx_data[0] != '\0')
	{
		flag = 1; // Set flag to indicate data has been received
	}
	else
	{
		flag=0;
	}

	if (flag)
	{
		extract_data();
		pin_config();
		clear_buffer();
	}
	reset_output(&d);
	set_output(&d);
	//           		HAL_UART_Transmit(&huart2, (uint8_t*)d.GPIO, 4, HAL_MAX_DELAY);

	read_pinstatus(&d);
	//status_transmit();
	//DataTOgsm(d);


}

void clear_buffer()
{
	memset(tx_data,0,sizeof (tx_data));
}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
//
//   HAL_UART_Receive_IT(&huart1, (uint8_t *)buffer, 20);
// }

void set_output(struct data *d)
{
	if(config[0] == 0)
	{
		d->GPIO[0] = write_gpio(GPIOA,GPIO_PIN_13, PIN_SET);
	}

	if(config[1] == 0)
	{
		d->GPIO[1] = write_gpio(GPIOA,GPIO_PIN_14, PIN_SET);
	}

	if(config[2] == 0)
	{
		d->GPIO[2] = write_gpio(GPIOC,GPIO_PIN_13, PIN_SET);
	}

	if(config[3] == 0)
	{
		d->GPIO[3] = write_gpio(GPIOC,GPIO_PIN_14, PIN_SET);
	}
	//	HAL_UART_Transmit(&huart2, (uint8_t *)d.GPIO, 4,1000);
}

void reset_output(struct data *d1)
{
	if(config[0] == 0)
	{
		d1->GPIO[0] = write_gpio(GPIOA,GPIO_PIN_13, PIN_RESET);
	}

	if(config[1] == 0)
	{
		d1->GPIO[1]=write_gpio(GPIOA,GPIO_PIN_14, PIN_RESET);
	}

	if(config[2] == 0)
	{
		d1->GPIO[2] = write_gpio(GPIOC,GPIO_PIN_13, PIN_RESET);
	}

	if(config[3] == 0)
	{
		d1->GPIO[3] = write_gpio(GPIOC,GPIO_PIN_14, PIN_RESET);
	}
}

void read_pinstatus(struct data *d2)
{
	if(config[0]==1)
	{
		d2->GPIO[0]=read_gpio( GPIOA,GPIO_PIN_13);
	}
	if(config[1]==1)
	{
		d2->GPIO[1]=read_gpio( GPIOA,GPIO_PIN_14);
	}
	if(config[2]==1)
	{
		d2->GPIO[2]=read_gpio( GPIOC,GPIO_PIN_13);
	}
	if(config[3]==1)
	{
		d2->GPIO[3]=read_gpio( GPIOC,GPIO_PIN_14);
	}
	//	 return d->GPIO;
}


void extract_data()
{
	token = strtok(tx_data, ",");


	if (token != NULL)
	{
		strncpy(arr1, token, sizeof(arr1) - 1);

		arr1[sizeof(arr1) - 1] = '\0';// Ensure null-termination
		strcpy(d.arr1,arr1);


		token = strtok(NULL, ",");
	}

	// Get the second token and store it in arr2
	if (token != NULL)
	{
		strncpy(arr2, token, sizeof(arr2) - 1);

		arr2[sizeof(arr2) - 1] = '\0'; // Ensure null-termination
		strcpy(d.arr2,arr2);

		//token = strtok(NULL, ",");
	}


}

//void DataTOgsm(struct status d)
//{
//	gpiostatus(d);
//}

//void gpiostatus(struct status d)
//{
//	 s[0]=d.gpio[0];
//	 s[1]=d.gpio[1];
//	 s[2]=d.gpio[2];
//	 s[3]=d.gpio[3];
//	 s[4]=d.SCANTIME;
//}

void pin_config()
{

	if(strcmp(arr1,"A13")==0)
	{
		switch_val=1;
	}

	else if(strcmp(arr1,"A14")==0)
	{
		switch_val=2;
	}

	else if(strcmp(arr1,"C13")==0)
	{
		switch_val=3;
	}

	else if(strcmp(arr1,"C14")==0)
	{
		switch_val=4;
	}

	else if(strcmp(arr1,"ADC1")==0)
	{
		switch_val=5;
	}

	else if(strcmp(arr1,"RTC")==0)
	{
		switch_val=6;
	}

	else if(strcmp(arr1,"DATE")==0)
	{
		switch_val=7;
	}
	else if(strcmp(arr1,"SCANTIME")==0)
	{
		switch_val=8;
	}


	switch(switch_val)
	{

	case 1:
		if(strcmp(arr2,"OUTPUT")==0)
		{
			user_GPIO_Init(GPIOA,GPIO_PIN_13,OUTPUT);
			config[0] = 0;
		}

		else if(strcmp(arr2,"INPUT")==0)
		{
			user_GPIO_Init(GPIOA,GPIO_PIN_13,INPUT);
			config[0] = 1;
		}
		break;

	case 2:
		if(strcmp(arr2,"OUTPUT")==0)
		{
			user_GPIO_Init(GPIOA,GPIO_PIN_14,OUTPUT);
			config[1]=0;
		}

		else if(strcmp(arr2,"INPUT")==0)
		{
			user_GPIO_Init(GPIOA,GPIO_PIN_14,INPUT);
			config[1]=1;
		}
		break;

	case 3:
		if(strcmp(arr2,"OUTPUT")==0)
		{
			user_GPIO_Init(GPIOC,GPIO_PIN_13,OUTPUT);
			config[2]=0;
		}

		else if(strcmp(arr2,"INPUT")==0)
		{
			user_GPIO_Init(GPIOC,GPIO_PIN_13,INPUT);
			config[2]=1;
		}

		break;

	case 4:
		if(strcmp(arr2,"OUTPUT")==0)
		{
			user_GPIO_Init(GPIOC,GPIO_PIN_14,OUTPUT);
			config[3]=0;
		}

		else if(strcmp(arr2,"INPUT")==0)
		{
			user_GPIO_Init(GPIOC,GPIO_PIN_14,INPUT);
			config[3]=1;
		}
		break;

	case 5:
		if(strcmp(arr2,"CH1")==0)
		{
			ADC_select_CH1();
			adcChnlChecker[0] = 1;
		}

		else if(strcmp(arr2,"CH2")==0)
		{
			ADC_select_CH2();
			adcChnlChecker[1] = 1;
		}

		else if(strcmp(arr2,"CH3")==0)
		{
			ADC_select_CH3();
			adcChnlChecker[2] = 1;
		}

		else if(strcmp(arr2,"CH4")==0)
		{
			ADC_select_CH4();
			adcChnlChecker[3] = 1;
		}

		else if(strcmp(arr2,"DB2")==0)
		{
			adcChnlChecker[0] = 0;
			adcChnlChecker[1] = 0;
			adcChnlChecker[2] = 0;
			adcChnlChecker[3] = 0;
		}
		else
		{
			__NOP();
		}
		break;

	case 6:

		token = strtok(arr2, ":");

		// Get the first token and convert to integer
		if (token != NULL)
		{
			d.hour = atoi(token);
			token = strtok(NULL, ":");
		}

		// Get the second token and convert to integer
		if (token != NULL)
		{
			d.minutes = atoi(token);
			token = strtok(NULL, ":");
		}

		// Get the third token and convert to integer
		if (token != NULL)
		{

			d.seconds = atoi(token);
		}
		//				 Set_Time(time);

		set_time(d.seconds,d.minutes,d.hour,3,0,0,0);

		break;
	case 7:

		token = strtok(arr2, ":");

		// Get the first token and convert to integer
		if (token != NULL)
		{
			d.dayofmonth = atoi(token);
			token = strtok(NULL, ":");
		}

		// Get the second token and convert to integer
		if (token != NULL)
		{
			d.month = atoi(token);
			token = strtok(NULL, ":");
		}

		// Get the third token and convert to integer
		if (token != NULL)
		{
			d.year = atoi(token);
		}
		//				 Set_Time(time);

		set_time(d.seconds,d.minutes,d.hour,1,d.dayofmonth,d.month,d.year);
		break;

	case 8:
		d.scan_time = (uint8_t)atoi(arr2);
		break;

	}
}
