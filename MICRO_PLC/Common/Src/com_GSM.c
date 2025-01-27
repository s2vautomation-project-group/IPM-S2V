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
#include "circular_queue.h"
#include "com_config.h"
#include "app_EEPROM.h"
#include "com_EEPROM.h"

#define MAX_HTTP_ACTION_LENGTH 50  // Maximum length for HTTP action response

static char httpActionResponse[MAX_HTTP_ACTION_LENGTH];  // New buffer to store the HTTP action response



extern char eeprom_data[200];

static char GsmData[500];
uint8_t rxgsmBuffer;
CircularQueue rxgsmQueue;




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

void datafromgsm()
{
	gsm_data_receive();
	gsm_Process_Commands();
//	strcpy(httpActionResponse,"+HTTPACTION: 0,716,787");
	process_gsm_command();
	//	uart3_tx((char*)GsmData);
	//	EEPROM_transmit(&d);

}

void gsm_data_receive()
{
	if (HAL_UART_Receive_IT(&huart4, &rxgsmBuffer,1) == HAL_ERROR)
	{
		Error_Handler();
	}
}


void gsm_Process_Commands(void)
{
	static uint8_t cmdIndex = 0;  // Persistent index to track the current command
	uint8_t byte;

	while (!CircularQueue_IsEmpty(&rxgsmQueue)) {
		CircularQueue_Dequeue(&rxgsmQueue, &byte);

		// Add byte to the command
		if (byte != '\r' && byte != '\n')  {
			if (cmdIndex < sizeof(GsmData) - 1) {
				GsmData[cmdIndex++] = byte;
			} else {
				// Handle command overflow (optional)
				cmdIndex = 0;  // Reset on overflow
			}
		} else if (byte == '\n') {
			// Null-terminate the command when '\n' is received
			GsmData[cmdIndex] = '\0';
			cmdIndex = 0;

			if (strstr((char*)GsmData, "+HTTPACTION") != NULL) {
				// Extract the HTTP action response and store it in the separate string
				extract_http_action_response((char*)GsmData);
			}

		}
	}

}

void extract_http_action_response(char* response)
{
    // Look for the "+HTTPACTION" keyword in the response
    char* start = strstr(response, "+HTTPACTION");
    if (start != NULL) {
        // Extract the part starting from "+HTTPACTION" and store it in httpActionResponse
        snprintf(httpActionResponse, sizeof(httpActionResponse), "%s", start);
    }

}

void process_gsm_command() {

//	uart3_tx((char*)httpActionResponse);
//	uart3_tx("\r\n");

	if (strstr(httpActionResponse, "302") != NULL || strstr(httpActionResponse, "706") != NULL) {
		// If "302" is found, send "data is uploaded"
		const char* message1 = "data is uploaded\r\n";
		uart3_tx((char*)message1);
	} else {
		// If "302" is not found, send "data is not uploaded"
		const char* message2 = "data is not uploaded\r\n";
		uart3_tx((char*)message2);
//		EEPROM_transmit(&d);
	}

	memset(httpActionResponse, 0, sizeof(httpActionResponse));  // Clear the response buffer

}






void GsmCommands(uint8_t* cmd)
{
	HAL_UART_Transmit_IT(&huart4, cmd, strlen((char*)cmd));
	//	datafromgsm();
	HAL_Delay(50);

}



void Gsm_Init()
{

	//	HAL_Delay(2000);


	GsmCommands((uint8_t*)"AT\r\n");

	GsmCommands((uint8_t*)"AT+CPIN?\r\n");
	GsmCommands((uint8_t*)"AT+CSQ\r\n");
	GsmCommands((uint8_t*)"AT+CGATT=1\r\n");
	GsmCommands((uint8_t*)"AT+CGACT=0,1\r\n");
	GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"airtelgprs.com\"\r\n");
	//	GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"jionet\"\r\n");
	GsmCommands((uint8_t*)"AT+CGACT=1,1\r\n");

}


void DataToCloud(char* Time,char* Date,char* Ch1,char* Ch2,char* Ch3,char* Ch4,char* MDS,char* D1,char* D2,char* D3,char* D4)
{


	uint8_t AT_RTCcloud_data[500];

	char* encoded_Time = url_encode(Time);
	char* encoded_Date = url_encode(Date);
	char* encoded_Ch1 = url_encode(Ch1);
	char* encoded_Ch2 = url_encode(Ch2);
	char* encoded_Ch3 = url_encode(Ch3);
	char* encoded_Ch4 = url_encode(Ch4);
	char* encoded_MDS = url_encode(MDS);
	char* encoded_D1 = url_encode(D1);
	char* encoded_D2 = url_encode(D2);
	char* encoded_D3 = url_encode(D3);
	char* encoded_D4 = url_encode(D4);


	//	RTCdata_to_cloud


	GsmCommands((uint8_t*)"AT+HTTPTERM\r\n");
	GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");




	snprintf((char*)AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbw_ORyIu9LA6EYqGdO6sIGteNSEyFkUav9giZnn4aCgGJwgcZ1BKgUNTeL18uquJQiK/exec?field1=%s&field2=%s&field3=%s&field4=%s&field5=%s&field6=%s&field7=%s&field8=%s&field9=%s&field10=%s&field11=%s\"\r\n",encoded_Date, encoded_Time, encoded_Ch1,encoded_Ch2,encoded_Ch3,encoded_Ch4,encoded_MDS,encoded_D1,encoded_D2,encoded_D3,encoded_D4);

	//	snprintf((char*)AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbw_ORyIu9LA6EYqGdO6sIGteNSEyFkUav9giZnn4aCgGJwgcZ1BKgUNTeL18uquJQiK/nonexistent?field1=%s&field2=%s&field3=%s&field4=%s&field5=%s&field6=%s&field7=%s&field8=%s&field9=%s&field10=%s&field11=%s\"\r\n",encoded_Date, encoded_Time, encoded_Ch1,encoded_Ch2,encoded_Ch3,encoded_Ch4,encoded_MDS,encoded_D1,encoded_D2,encoded_D3,encoded_D4);

	GsmCommands((uint8_t*)AT_RTCcloud_data);
	//	memset(GsmData, 0, sizeof(GsmData));  // Clear the buffer
//	memset(GsmData, 0, sizeof(GsmData));
	GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");

	free(encoded_Time);
	free(encoded_Date);
	free(encoded_Ch1);
	free(encoded_Ch2);
	free(encoded_Ch3);
	free(encoded_Ch4);
	free(encoded_MDS);
	free(encoded_D1);
	free(encoded_D2);
	free(encoded_D3);
	free(encoded_D4);
	datafromgsm();

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
