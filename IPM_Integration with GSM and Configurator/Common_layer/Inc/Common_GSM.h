/*
 * Common_GSM.h
 *
 *  Created on: Aug 1, 2024
 *      Author: DELL
 */

#ifndef INC_COMMON_GSM_H_
#define INC_COMMON_GSM_H_

#include "Application_Gsm.h"
#include "main.h"

//void UART1_Init(void);
void UART2_Init(void);
void GsmCommands(uint8_t* cmd);
void Gsm_Init();
void DataToGsm(uint8_t* rec_data);
//void DataToCloud(uint8_t* RTC_date_data,uint8_t* RTC_time_data,uint8_t* adc_data);
void DataToCloud(uint8_t* RTC_data,uint8_t* adc_data);
//void DataToCloud(int field,uint8_t* cloud_data);
//void RTCDataToCloud(uint8_t* cloud_data);
char* url_encode(const char* str);

#endif /* INC_COMMON_GSM_H_ */
