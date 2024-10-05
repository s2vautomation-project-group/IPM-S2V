/*
 * comm_EEPROM.h
 *
 *  Created on: Sep 24, 2024
 *      Author: User
 */

#ifndef INC_COMM_EEPROM_H_
#define INC_COMM_EEPROM_H_

#include "main.h"

void USER_I2C3_Init(void);
#define EEPROM_ADDRESS 0xA0                              // AT24C256C 7-bit I2C address
#define EEPROM_MAX_ADDRESS 0x7FFF

HAL_StatusTypeDef eeprom_write(uint16_t mem_address, uint8_t *data, uint16_t size);
HAL_StatusTypeDef eeprom_read(uint16_t mem_address, uint8_t *data, uint16_t size);
#endif /* INC_COMM_EEPROM_H_ */
