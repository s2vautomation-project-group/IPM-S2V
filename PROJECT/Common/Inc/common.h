/*
 * common.h
 *
 *  Created on: Aug 5, 2024
 *      Author: KAVYA
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_
#include "application.h"
#include "main.h"
#include "data.h"

void UART1_Init(void);
void UART2_Init(void);
void GsmCommands(uint8_t* cmd);
void Gsm_Init();
void DataToCloud(uint8_t* Time,uint8_t* Ch1,uint8_t* Ch2,uint8_t* Ch3,uint8_t* Ch4,uint8_t* D1,uint8_t* D2,uint8_t* D3,uint8_t* D4);
void DataToUart(struct data *d);
char* url_encode(const char* str);
void uarttx();


#endif /* INC_COMMON_H_ */
