/*
 * com_GSM.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */


#include "main.h"
#include "data.h"
#include "app_GSM.h"
#include "Com_GSM.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"

//uint8_t buf1[4];
//uint8_t buf[60];
//extern char buffer_Time[15];


//extern struct data d;

#define max_buf_len 100

uint8_t Reply[max_buf_len]={0};


extern UART_HandleTypeDef huart4;


void UART4_Init(void)
{


	  /* USER CODE BEGIN UART4_Init 0 */

	  /* USER CODE END UART4_Init 0 */

	  /* USER CODE BEGIN UART4_Init 1 */

	  /* USER CODE END UART4_Init 1 */
	  huart4.Instance = UART4;
	  huart4.Init.BaudRate = 115200;
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





void GsmCommands(uint8_t* cmd)
{
	HAL_UART_Transmit_IT(&huart4, cmd, strlen((char*)cmd));
	HAL_UART_Receive_IT(&huart4, Reply, max_buf_len);
	HAL_Delay(100);

}



void Gsm_Init()
{

//	HAL_Delay(2000);


	GsmCommands((uint8_t*)"AT\r\n");
	GsmCommands((uint8_t*)"AT+CPIN?\r\n");
	GsmCommands((uint8_t*)"AT+CSQ\r\n");
	GsmCommands((uint8_t*)"AT+CGATT=1\r\n");
	GsmCommands((uint8_t*)"AT+CGACT=0,1\r\n");
	GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"jionet\"\r\n");
	GsmCommands((uint8_t*)"AT+CGACT=1,1\r\n");

}


void DataToCloud(char* Time,char* Date,char* Ch1,char* Ch2,char* Ch3,char* Ch4,char* D1,char* D2,char* D3,char* D4)
{

	uint8_t AT_RTCcloud_data[500];

	char* encoded_Time = url_encode(Time);
	char* encoded_Date = url_encode(Date);
	char* encoded_Ch1 = url_encode(Ch1);
	char* encoded_Ch2 = url_encode(Ch2);
	char* encoded_Ch3 = url_encode(Ch3);
	char* encoded_Ch4 = url_encode(Ch4);
	char* encoded_D1 = url_encode(D1);
	char* encoded_D2 = url_encode(D2);
	char* encoded_D3 = url_encode(D3);
	char* encoded_D4 = url_encode(D4);


	//	RTCdata_to_cloud

	GsmCommands((uint8_t*)"AT+HTTPTERM\r\n");
	GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");


	snprintf((char*)AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbz-U5OxlgcTFUr2G3_0L8nzjVQorKuKofxDdJdbM2PCGmTUH6f1J4gkkEfKxTKe0T7a/exec?field1=%s&field2=%s&field3=%s&field4=%s&field5=%s&field6=%s&field7=%s&field8=%s&field9=%s&field10=%s\"\r\n",encoded_Time, encoded_Date, encoded_Ch1,encoded_Ch2,encoded_Ch3,encoded_Ch4,encoded_D1,encoded_D2,encoded_D3,encoded_D4);


	GsmCommands((uint8_t*)AT_RTCcloud_data);
	GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");

	free(encoded_Time);
	free(encoded_Date);
	free(encoded_Ch1);
	free(encoded_Ch2);
	free(encoded_Ch3);
	free(encoded_Ch4);
	free(encoded_D1);
	free(encoded_D2);
	free(encoded_D3);
	free(encoded_D4);

}



char* url_encode(const char* str)
{
	const char* hex = "0123456789ABCDEF";
	char* encoded = malloc(strlen(str) * 3 + 1); // Allocate enough space
	char* ptr = encoded;

	while (*str) {
		if (isalnum((unsigned char)*str) || *str == '-' || *str == '_' || *str == '.' || *str == '~') {
			*ptr++ = *str;
		} else {
			*ptr++ = '%';
			*ptr++ = hex[(*str >> 4) & 0xF];
			*ptr++ = hex[*str & 0xF];
		}
		str++;
	}
	*ptr = '\0';
	return encoded;
}
