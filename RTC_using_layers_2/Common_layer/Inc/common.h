/*
 * common.h
 *
 *  Created on: Jul 12, 2024
 *      Author: DELL
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

void USER_I2C1_Init(void);
void I2C_write(uint8_t *arr);
void I2C_read(uint8_t *data);

#endif /* INC_COMMON_H_ */
