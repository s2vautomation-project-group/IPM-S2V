/*
 * Uart.c
 *
 *  Created on: Jul 17, 2024
 *      Author: KAVYA
 */


#include "main.h"
#include "Uart.h"
#include "Gsm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define max_buf_len 100

char Reply[max_buf_len]={0};

int CtrlZ=26;
char ch[1];


UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

void UART1_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}


void UART2_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}


void GsmCommands(uint8_t* cmd)
{
	 HAL_UART_Transmit_IT(&huart2, cmd, strlen(cmd));
	 HAL_UART_Receive_IT(&huart2, Reply, max_buf_len);
	 HAL_Delay(1000);
	 HAL_UART_Transmit_IT(&huart1, Reply, strlen(Reply));


}



void Gsm_Init()
{

	HAL_Delay(2000);

//	          GsmCommands((uint8_t*)"AT\r\n");
//	          HAL_Delay(1000);
//	          GsmCommands((uint8_t*)"AT+IPR?\r\n");
//	          HAL_Delay(1000);
//	          GsmCommands((uint8_t*)"AT+CMGF=1\r\n");
//	          HAL_Delay(1000);
//	          GsmCommands((uint8_t*)"AT+CMGS=\"+918880708837\"\r\n");
//	          HAL_Delay(1000);


	          //send data to thingspeak

	                    GsmCommands((uint8_t*)"AT\r\n");
//	                    HAL_Delay(2000);
	                    GsmCommands((uint8_t*)"AT+CPIN?\r\n");
//	                    HAL_Delay(2000);
	                    GsmCommands((uint8_t*)"AT+CSQ\r\n");
//	                    HAL_Delay(2000);
	                    GsmCommands((uint8_t*)"AT+CGATT=1\r\n");
//	                    HAL_Delay(2000);
	                    GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"jionet\"\r\n");
//	                    HAL_Delay(2000);
	                    GsmCommands((uint8_t*)"AT+CGACT=1,1\r\n");
//	                    HAL_Delay(2000);
//	                    GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");
//	                    HAL_Delay(2000);
//	                    GsmCommands((uint8_t*)"AT+HTTPPARA=\"URL\",\"https://api.thingspeak.com/update?api_key=KC4W64MHYV5D5F6U&field1=35\"\r\n");
//	                    HAL_Delay(2000);
//	                    GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");
//	                    HAL_Delay(2000);


}

void DataToGsm(uint8_t* rec_data)
{
	ch[0]=CtrlZ;
	GsmCommands((uint8_t*)rec_data);
	HAL_Delay(1000);
	GsmCommands((uint8_t*)ch);
}

void DataToCloud(int field,uint8_t* cloud_data)
{

			char AT_RTCcloud_data[256];

				//	RTCdata_to_cloud

//				 GsmCommands((uint8_t*)"AT+HTTPTERM\r\n");
				 GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");

					snprintf(AT_RTCcloud_data, sizeof(AT_RTCcloud_data), "AT+HTTPPARA=\"URL\",\https://api.thingspeak.com/update?api_key=Y1KDSHTWPIVWKUFJ&field%d=%s\"\r\n",field,cloud_data);
					GsmCommands((uint8_t*)AT_RTCcloud_data);
					 GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");

}


