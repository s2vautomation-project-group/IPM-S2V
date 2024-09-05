/*
 * Common_GSM.c
 *
 *  Created on: Aug 1, 2024
 *      Author: DELL
 */

#include "main.h"
#include "Application_GSM.h"
#include "Common_Gsm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define max_buf_len 100

uint8_t Reply[max_buf_len]={0};

int CtrlZ=26;
char ch[1];


//UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

//void UART1_Init(void)
//{
//
//  /* USER CODE BEGIN USART1_Init 0 */
//
//  /* USER CODE END USART1_Init 0 */
//
//  /* USER CODE BEGIN USART1_Init 1 */
//
//  /* USER CODE END USART1_Init 1 */
//  huart1.Instance = USART1;
//  huart1.Init.BaudRate = 115200;
//  huart1.Init.WordLength = UART_WORDLENGTH_8B;
//  huart1.Init.StopBits = UART_STOPBITS_1;
//  huart1.Init.Parity = UART_PARITY_NONE;
//  huart1.Init.Mode = UART_MODE_TX_RX;
//  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//  if (HAL_UART_Init(&huart1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART1_Init 2 */
//
//  /* USER CODE END USART1_Init 2 */
//
//}


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
	 HAL_UART_Transmit_IT(&huart2, cmd, strlen((char*)cmd));
	 HAL_UART_Receive_IT(&huart2, Reply, max_buf_len);
	 HAL_Delay(100);
	// HAL_UART_Transmit_IT(&huart1, Reply, strlen((char*)Reply));


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
	                    HAL_Delay(10);
                        GsmCommands((uint8_t*)"AT+CPIN?\r\n");
                        HAL_Delay(10);
	                    GsmCommands((uint8_t*)"AT+CSQ\r\n");
	                    HAL_Delay(10);
	                    GsmCommands((uint8_t*)"AT+CGATT=1\r\n");
	                    HAL_Delay(10);
	                    GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"airtelgprs.com\"\r\n");
	                    HAL_Delay(10);
	                    GsmCommands((uint8_t*)"AT+CGACT=1,1\r\n");
	                    HAL_Delay(10);
//


}

//void DataToGsm(uint8_t* rec_data)
//{
//	ch[0]=CtrlZ;
//	GsmCommands((uint8_t*)rec_data);
//	HAL_Delay(1000);
//	GsmCommands((uint8_t*)ch);
//}


//void DataToCloud(uint8_t* RTC_date_data,uint8_t* RTC_time_data,uint8_t* adc_data)
//{
//
//			uint8_t AT_RTCcloud_data[256];
//
//				//	RTCdata_to_cloud
//
////				 GsmCommands((uint8_t*)"AT+HTTPTERM\r\n");
//				 GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");
//
////					snprintf(AT_RTCcloud_data, sizeof(AT_RTCcloud_data), "AT+HTTPPARA=\"URL\",\https://api.thingspeak.com/update?api_key=Y1KDSHTWPIVWKUFJ&field%d=%s\"\r\n",field,cloud_data);
//
//					snprintf(AT_RTCcloud_data,sizeof(AT_RTCcloud_data), "AT+HTTPPARA=\"URL\",\https://script.google.com/macros/s/AKfycbyqqjCHXcKWwFu4uCEfpEd_f2WFQiKbyG084cx9PSkYiwnDwenu58b_lH7QTOjnUJMlww/exec?field1=%s&field2=%s&field3=%s\"\r\n",(char*)RTC_date_data,(char*)RTC_time_data,(char*)adc_data);
//					GsmCommands((uint8_t*)AT_RTCcloud_data);
//					 GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");
//
//}


void DataToCloud(uint8_t* RTC_data, uint8_t* adc_data)
{

			uint8_t AT_RTCcloud_data[256];

			char* encoded_RTC_data = url_encode((char*)RTC_data);
			    char* encoded_adc_data = url_encode((char*)adc_data);


				//	RTCdata_to_cloud

				 //GsmCommands((uint8_t*)"AT+HTTPTERM\r\n");
				 GsmCommands((uint8_t*)"AT+HTTPINIT\r\n");


				 snprintf((char*)AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycby4sSHIr9TCKa0kzVpgYUEjU7b-bNvSJCnG2Gudf8cmSKShpM3dUZPcyeBAZVYJfWKV/exec?field1=%s&field2=%s\"\r\n",encoded_RTC_data, encoded_adc_data);

//					snprintf(AT_RTCcloud_data, sizeof(AT_RTCcloud_data), "AT+HTTPPARA=\"URL\",\https://api.thingspeak.com/update?api_key=Y1KDSHTWPIVWKUFJ&field%d=%s\"\r\n",field,cloud_data);


//				 snprintf(AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbyLSuScQBF1GOx4mF4KqTnwraq44K9x2roV38OmpNi6GQOP_srVrmM2XlQHFSWzKbMI/exec?field1=%s&field2=%s\"\r\n",RTC_data,adc_data);
//					snprintf(AT_RTCcloud_data,sizeof(AT_RTCcloud_data), "AT+HTTPPARA=\"URL\",\https://script.google.com/macros/s/AKfycbyRFUZ6mtG47oo06jN6elCj2Zq41r2QrjdROOz-AtCCj6mnL4hzXSkpr7Zdz16FgCHTXw/exec?field1=%s&field2=%s\"\r\n",(char*)RTC_data,(char*)adc_data);
					GsmCommands((uint8_t*)AT_RTCcloud_data);
					 GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");

					 free(encoded_RTC_data);
					free(encoded_adc_data);

}

char* url_encode(const char* str) {
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



