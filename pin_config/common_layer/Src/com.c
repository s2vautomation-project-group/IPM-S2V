/*
 * com.c
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#include "main.h"
#include "com.h"
#include <string.h>

//GPIO1,A3,OUTPUT
//GPIO1,A3,INPUT
//GPIO1,A4,INPUT
//GPIO2,A4,OUTPUT
//GPIO3,A5,OUTPUT
//GPIO3,A5,INPUT

//GPIO4,A6,OUTPUT
//GPIO4,A6,INPUT


char arr3[20];
extern char  buffer[20];
UART_HandleTypeDef huart1;
GPIO_InitTypeDef GPIO_InitStruct = {0};


 void user_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}


 void user_GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,mode PIN_mode)
 {
   GPIO_InitTypeDef GPIO_InitStruct = {0};
 /* USER CODE BEGIN MX_GPIO_Init_1 */
 /* USER CODE END MX_GPIO_Init_1 */

   /* GPIO Ports Clock Enable */
   __HAL_RCC_GPIOC_CLK_ENABLE();
   __HAL_RCC_GPIOA_CLK_ENABLE();

   /*Configure GPIO pin Output Level */
     HAL_GPIO_WritePin(GPIOx, GPIO_Pin,PIN_mode);

     if(PIN_mode == OUTPUT)
     {
    	gpio_output(GPIOx,GPIO_Pin,PIN_mode);
     }
     else if(PIN_mode == INPUT)
     {
         gpio_input(GPIOx,GPIO_Pin,PIN_mode);
     }

     /*Configure GPIO pin : VCP_RX_Pin */
   GPIO_InitStruct.Pin = VCP_RX_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   GPIO_InitStruct.Alternate = GPIO_AF3_USART2;
   HAL_GPIO_Init(VCP_RX_GPIO_Port, &GPIO_InitStruct);

 /* USER CODE BEGIN MX_GPIO_Init_2 */
 /* USER CODE END MX_GPIO_Init_2 */
 }

 void gpio_output(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,mode PIN_mode)
 {
     GPIO_InitTypeDef GPIO_InitStruct = {0};

     /* Configure GPIO pins : PA3 PA4 PA5 PA6 PA7 */
     GPIO_InitStruct.Pin = GPIO_Pin;
     GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
 }

 void gpio_input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, mode PIN_mode)
 {
     GPIO_InitTypeDef GPIO_InitStruct = {0};

     /* Configure GPIO pins : PA3 PA4 PA5 PA6 */
     GPIO_InitStruct.Pin = GPIO_Pin;
     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
 }

 void user_output_GPIO_Init(void)
  {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
         HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                                 |GPIO_PIN_7, GPIO_PIN_RESET);


         /*Configure GPIO pins : PA3 PA4 PA5 PA6
                                  PA7 */
         GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                                 |GPIO_PIN_7;
         GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
         GPIO_InitStruct.Pull = GPIO_NOPULL;
         GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
         HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);



    /*Configure GPIO pin : VCP_RX_Pin */
    GPIO_InitStruct.Pin = VCP_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF3_USART2;
    HAL_GPIO_Init(VCP_RX_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
  }


 void data_receive()
 {
 	HAL_UART_Receive(&huart1,(uint8_t *)buffer,strlen,500);
 }


 myPinState read_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
 {
	return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

 }

 void write_gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, myPinState PinState)
 {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin,PinState);
 }



