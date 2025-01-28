/*
 * com_GSM.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */


#include "main.h"
#include "data.h"
#include "app_GSM.h"
#include "com_GSM.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "com_config.h"
#include "circular_queue.h"



//extern struct data d;
//
extern char CH1[10];
extern char CH2[10];
extern char CH3[10];
extern char CH4[10];
extern char MDS[10];
uint8_t WiFi_cloud_data[256];

//CircularQueue wifirxQueue;
char *wifitoken;

static char WifiData[100];
uint8_t rxwifiBuffer;
CircularQueue rxwifiQueue;
char RCV_GPIO1[5];
char RCV_GPIO2[5];
char RCV_GPIO3[5];
char RCV_GPIO4[5];



UART_HandleTypeDef huart4;


void UART4_Init(void)
{


	/* USER CODE BEGIN UART4_Init 0 */

	/* USER CODE END UART4_Init 0 */

	/* USER CODE BEGIN UART4_Init 1 */

	/* USER CODE END UART4_Init 1 */
	huart4.Instance = UART4;
	huart4.Init.BaudRate = 9600;
	huart4.Init.WordLength = UART_WORDLENGTH_8B;
	huart4.Init.StopBits = UART_STOPBITS_1;
	huart4.Init.Parity = UART_PARITY_NONE;
	huart4.Init.Mode = UART_MODE_TX_RX;
	huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart4.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart4) != HAL_OK)
	{
		Error_Handler();
	}
	/* USER CODE BEGIN UART4_Init 2 */

	/* USER CODE END UART4_Init 2 */

}


void USERRCV_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_RESET);

	/*Configure GPIO pin : PB15 */
	GPIO_InitStruct.Pin = GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PC6 PC7 PC8 */
	GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}







void DataToWiFi(struct data *d)
{

	sprintf((char*)WiFi_cloud_data,"U:%s,P:%s,TIME:%02d:%02d:%02d,DATE:%02d/%02d/%02d,CH1:%s,CH2:%s,CH3:%s,CH4:%s,MDS:%s,GPIO1:%s,GPIO2:%s,GPIO3:%s,GPIO4:%s\r\n",d->username,d->password,d->hour,d->minutes,d->seconds,d->dayofmonth,d->month,d->year,CH1,CH2,CH3,CH4,MDS,d->Status1,d->Status2,d->Status3,d->Status4);
	HAL_UART_Transmit(&huart4, WiFi_cloud_data, strlen((char*)WiFi_cloud_data), HAL_MAX_DELAY);
	HAL_Delay(100);

}

void datafromgs()
{
	wifi_data_receive();
	wifi_Process_Commands();
	Process_GPIO_Status();

}

void wifi_data_receive()
{
	if (HAL_UART_Receive_IT(&huart4, &rxwifiBuffer,1) == HAL_ERROR)
	{
		Error_Handler();
	}
}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	if (huart->Instance == UART4)
//	{
//		// Enqueue received bytes into the circular queue
//
//		if (!CircularQueue_Enqueue(&rxwifiQueue, rxwifiBuffer))
//		{
//			// Handle queue overflow if necessary (optional)
//		}
//
//		// Restart UART reception for the next chunk of data
//		HAL_UART_Receive_IT(&huart4, &rxwifiBuffer, 1);
//	}
//}



void wifi_Process_Commands(void)
{
	static uint8_t cmdIndex = 0;  // Persistent index to track the current command
	uint8_t byte;
	memset(WifiData, 0, sizeof(WifiData));  // Clear the response buffer

	while (!CircularQueue_IsEmpty(&rxwifiQueue)) {
		CircularQueue_Dequeue(&rxwifiQueue, &byte);

		// Add byte to the command
		if (byte != ';') {
			if (cmdIndex < sizeof(WifiData) - 1) {
				WifiData[cmdIndex++] = byte;
			} else {
				// Handle command overflow (optional)
				cmdIndex = 0;  // Reset on overflow
			}
		} else {
			// Command completed when '\n' is received
			WifiData[cmdIndex] = '\0';  // Null-terminate the command
			cmdIndex = 0;


		}
		uart3_tx((char*)WifiData);
//		// Process the command
//					if(strcmp(WifiData,"GPIO Status")==0)
//					{
//					extract_wifi_data(WifiData);
//					}
//					else if(strcmp(WifiData,"Data to EEPROM")==0)
//					{
//		//				Data_To_EEPROM(eeprom_data);
//					}
	}
}


void extract_wifi_data(char* WifiData)
{
	wifitoken = strtok(WifiData, ",");


	if (wifitoken != NULL)
	{
		strncpy(RCV_GPIO1, wifitoken, sizeof(RCV_GPIO1) - 1);

		RCV_GPIO1[sizeof(RCV_GPIO1) - 1] = '\0';// Ensure null-termination


		wifitoken = strtok(NULL, ",");
	}

	// Get the second token and store it in arr2
	if (wifitoken != NULL)
	{
		strncpy(RCV_GPIO2, wifitoken, sizeof(RCV_GPIO2) - 1);

		RCV_GPIO2[sizeof(RCV_GPIO2) - 1] = '\0'; // Ensure null-termination

		wifitoken = strtok(NULL, ",");
	}
	if (wifitoken != NULL)
	{
		strncpy(RCV_GPIO3, wifitoken, sizeof(RCV_GPIO3) - 1);

		RCV_GPIO3[sizeof(RCV_GPIO3) - 1] = '\0'; // Ensure null-termination

		wifitoken = strtok(NULL, ",");
	}
	if (wifitoken != NULL)
	{
		strncpy(RCV_GPIO4, wifitoken, sizeof(RCV_GPIO4) - 1);

		RCV_GPIO4[sizeof(RCV_GPIO4) - 1] = '\0'; // Ensure null-termination

		//			wifitoken = strtok(NULL, ",");
	}


}


void Process_GPIO_Status()
{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, SET);
//	HAL_Delay(1000);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, RESET);
//	HAL_Delay(1000);



	if(strcmp(RCV_GPIO1,"HIGH")==0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, RESET);
	}

	if(strcmp(RCV_GPIO2,"HIGH")==0)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, RESET);
		}

	if(strcmp(RCV_GPIO3,"HIGH")==0)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, RESET);
		}

	if(strcmp(RCV_GPIO4,"HIGH")==0)
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
		}

}
