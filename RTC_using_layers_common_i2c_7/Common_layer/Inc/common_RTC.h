/*
 * common.h
 *
 *  Created on: Jul 12, 2024
 *      Author: DELL
 */

#ifndef INC_RTC_COMMON_H_
#define INC_RTC_COMMON_H_

#include  "main.h"

void User_SystemClock_Config();
void USER_I2C1_Init(void);
//void I2C_write(uint8_t *arr);
void I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t device_address, uint16_t mem_address, uint8_t mem_address_size, uint8_t *data, size_t data_size, uint32_t timeout);


void I2C_read(uint8_t *data);

#endif /* INC_RTC_COMMON_H_ */
