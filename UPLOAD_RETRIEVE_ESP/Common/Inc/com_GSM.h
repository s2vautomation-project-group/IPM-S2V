/*
 * com_GSM.h
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */

#ifndef INC_COM_GSM_H_
#define INC_COM_GSM_H_

#include "app_GSM.h"
#include "main.h"
#include "data.h"
void UART2_Init(void);
void datafromgs();
void DataToWiFi(struct data *d);
//void ProcessData();
void USERRCV_GPIO_Init();
void extract_wifi_data(char* command);
void wifi_data_receive();
void wifi_Process_Commands(void);
void Process_GPIO_Status();

//void wifiHAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
#endif /* INC_COM_GSM_H_ */

