/*
 * common.c
 *
 *  Created on: Aug 5, 2024
 *      Author: KAVYA
 */

#include "main.h"
#include "application.h"
#include "common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



uint8_t buf[50];
#define max_buf_len 100

uint8_t Reply[max_buf_len]={0};


UART_HandleTypeDef huart2;

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

void DataToUart(struct data *d)
{

		  		sprintf(buf,"%s,%s,%s,%s,%s,%s,%s,%s,%s\r\n",d->time,d->CH1,d->CH2,d->CH3,d->CH4,d->D1,d->D2,d->D3,d->D4);
		  		     HAL_UART_Transmit(&huart2, (uint8_t*)buf, strlen(buf), HAL_MAX_DELAY);
HAL_Delay(500);

}



void GsmCommands(uint8_t* cmd)
{
	 HAL_UART_Transmit_IT(&huart2, cmd, strlen((char*)cmd));
	 HAL_UART_Receive_IT(&huart2, Reply, max_buf_len);
	 HAL_Delay(1000);

}



void Gsm_Init()
{

	HAL_Delay(2000);


	                    GsmCommands((uint8_t*)"AT\r\n");
                        GsmCommands((uint8_t*)"AT+CPIN?\r\n");
	                    GsmCommands((uint8_t*)"AT+CSQ\r\n");
	                    GsmCommands((uint8_t*)"AT+CGATT=1\r\n");
	                    GsmCommands((uint8_t*)"AT+CGDCONT=1,\"IPV6\",\"jionet\"\r\n");
	                    GsmCommands((uint8_t*)"AT+CGACT=1,1\r\n");

}


void DataToCloud(uint8_t* Time,uint8_t* Ch1,uint8_t* Ch2,uint8_t* Ch3,uint8_t* Ch4,uint8_t* D1,uint8_t* D2,uint8_t* D3,uint8_t* D4)
{

			uint8_t AT_RTCcloud_data[500];

			char* encoded_Time = url_encode(Time);
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


				 snprintf(AT_RTCcloud_data, sizeof(AT_RTCcloud_data),"AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbwaEr2bwPZ4lsp0eJuNW61im6PEJ0zI5yxW0n7_kDA9N-wocsdiVT38l-30--cFvb_H/exec?field1=%s&field2=%s&field3=%s&field4=%s&field5=%s&field6=%s&field7=%s&field8=%s&field9=%s\"\r\n",encoded_Time, encoded_Ch1,encoded_Ch2,encoded_Ch3,encoded_Ch4,encoded_D1,encoded_D2,encoded_D3,encoded_D4);


					GsmCommands((uint8_t*)AT_RTCcloud_data);
					 GsmCommands((uint8_t*)"AT+HTTPACTION=0\r\n");

					 free(encoded_Time);
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



