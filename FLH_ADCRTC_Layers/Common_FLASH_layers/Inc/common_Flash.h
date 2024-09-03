/*
 * common_Flash.h
 *
 *  Created on: Sep 1, 2024
 *      Author: User
 */

#ifndef INC_COMMON_FLASH_H_
#define INC_COMMON_FLASH_H_
extern ADC_HandleTypeDef hadc1;
extern I2C_HandleTypeDef hi2c1;

#define FLASH_PAGE_NUMBER 125
#define FLASH_BASE_ADDRESS 0x08000000 // Base address of the flash memory
#define FLASH_PAGE_125_ADDRESS (FLASH_BASE_ADDRESS + (FLASH_PAGE_NUMBER * FLASH_PAGE_SIZE))


void User_SystemClock_Config(void);
void User_ADC1_Init(void);
void User_I2C1_Init(void);
void User_GPIO_Init(void);

void I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t device_address, uint16_t mem_address, uint8_t mem_address_size, uint8_t *data, size_t data_size, uint32_t timeout);
void I2C_read(uint8_t *data);

void Flash_ErasePage(void);
void Flash_WriteData(float d,uint8_t hours, uint8_t minutes, uint8_t seconds);
void Flash_ReadData(uint32_t address, float *d, uint8_t *hours, uint8_t *minutes, uint8_t *seconds);



#endif /* INC_COMMON_FLASH_H_ */
