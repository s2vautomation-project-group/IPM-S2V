/*
 * com.h
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#include "main.h"

#ifndef COMMON_INC_COM_H_
#define COMMON_INC_COM_H_


typedef enum
{
	OUTPUT,
	INPUT
}mode;

typedef enum
{
  PIN_RESET = 0U,
  PIN_SET
} myPinState;

void SystemClock_Config(void);
void user_output_GPIO_Init(void);
void user_GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,mode PIN_mode);
void gpio_output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,mode PIN_mode);
void gpio_input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, mode PIN_mode);
void user_USART1_UART_Init(void);
void data_receive();
myPinState read_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void write_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, myPinState PinState);



#endif /* COMMON_INC_COM_H_ */
