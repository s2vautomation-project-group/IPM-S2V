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
void GsmCommands(uint8_t* cmd);
void Gsm_Init();
void DataToCloud(char* Time,char* Date,char* Ch1,char* Ch2,char* Ch3,char* Ch4,char* D1,char* D2,char* D3,char* D4);

//void DataToUart();
char* url_encode(const char* str);


#endif /* INC_COM_GSM_H_ */
