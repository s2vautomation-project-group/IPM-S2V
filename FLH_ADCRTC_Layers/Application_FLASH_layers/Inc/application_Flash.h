/*
 * application_Flash.h
 *
 *  Created on: Sep 1, 2024
 *      Author: User
 */

#ifndef INC_APPLICATION_FLASH_H_
#define INC_APPLICATION_FLASH_H_

#include <main.h>

#define DS3107_ADDRESS 0xD0

#define MIN_VALUE 3.3
#define MAX_VALUE 4095

uint8_t decToBcd(int val);
uint8_t bcdToDec(uint8_t val);
void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year);
void Get_Time (void);

void adc_handler(void);
float Voltage_Calculation(void);

void Flash_ErasePage(void);

void Application_Init(void);
void Application_Run(void);


#endif /* INC_APPLICATION_FLASH_H_ */
