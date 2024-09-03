/*
 * common_Flash.c
 *
 *  Created on: Sep 1, 2024
 *      Author: User
 */
#include "main.h"
#include "common_Flash.h"
#include "application_Flash.h"


ADC_HandleTypeDef hadc1;
I2C_HandleTypeDef hi2c1;

//extern I2C_HandleTypeDef hi2c1;

uint32_t current_address = FLASH_PAGE_125_ADDRESS;  // Start at the beginning of page 125


void User_SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
 void User_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
 void User_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00707CBB;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void User_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void Flash_ErasePage(void)
{
    // Unlock the Flash memory for write access
    HAL_FLASH_Unlock();

    // Specify the erase operation
    FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PageError = 0;

    // Configure the erase parameters
    EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;          // Erase by pages
    EraseInitStruct.Page        = FLASH_PAGE_NUMBER;                            // Page 125
    EraseInitStruct.NbPages     = 1;                              // Number of pages to erase
    EraseInitStruct.Banks       = FLASH_BANK_1;                   // Bank 1

    // Perform the erase operation
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK)
    {
        // Error handling: Page erase failed
        // You can add error handling code here
    }

    // Lock the Flash memory after erasing
    HAL_FLASH_Lock();
}

// Function to rite ADC data and RTC time to Flash
void Flash_WriteData(float d, uint8_t hours, uint8_t minutes, uint8_t seconds)
{
    HAL_FLASH_Unlock();

    // Convert float to uint64_t
    uint64_t voltage_data = (uint64_t)(*(uint32_t*)&d);
    // Pack time data into a uint64_t
    uint32_t time_data = ((uint32_t)hours << 16) | ((uint32_t)minutes << 8) | (uint32_t)seconds;

    // Write the voltage data to flash
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, current_address, voltage_data);
    current_address += 8;  // Move to the next address

    // Write the time data to flash
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, current_address, time_data);
    current_address += 8;

    HAL_FLASH_Lock();
}

void Flash_ReadData(uint32_t address, float *d, uint8_t *hours, uint8_t *minutes, uint8_t *seconds)
{
    // Cast address to pointer to read 64-bit data
    uint64_t voltage_data = *(uint64_t*)address;

    *d = *(float*)&voltage_data;

    address += 8;  // Move to the next 64-bit block

    // Read and unpack time data from the flash memory

    uint32_t time_data = *(uint32_t*)address;

    *hours = (time_data >> 16) & 0xFF;
    *minutes = (time_data >> 8) & 0xFF;
    *seconds = time_data & 0xFF;
}

//void Flash_WriteData(float d, uint8_t hours, uint8_t minutes, uint8_t seconds)
//{
//    HAL_FLASH_Unlock();
//
//    // Convert float to uint64_t
//    uint64_t voltage_data = (uint64_t)(*(uint32_t*)&d);
//
//    // Pack time data into a uint32_t instead of uint64_t
//    uint32_t time_data = ((uint32_t)hours << 16) | ((uint32_t)minutes << 8) | (uint32_t)seconds;
//
//    // Combine the float data and the time data into one uint64_t
//    uint64_t combined_data = (voltage_data & 0xFFFFFFFF00000000) | (uint32_t)time_data;
//
//    // Write the combined data to flash
//    HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, current_address, combined_data);
//    current_address += 8;  // Move to the next address
//
//    HAL_FLASH_Lock();
//}
//
//void Flash_ReadData(uint32_t address, float *d, uint8_t *hours, uint8_t *minutes, uint8_t *seconds)
//{
//    // Read the combined data from flash
//    uint64_t combined_data = *(uint64_t*)address;
//
//    // Extract the float value from the combined data
//    uint32_t voltage_data = (uint32_t)(combined_data >> 32);
//    *d = *(float*)&voltage_data;
//
//    // Extract the time data from the combined data
//    uint32_t time_data = (uint32_t)(combined_data & 0xFFFFFFFF);
//
//    *hours = (time_data >> 16) & 0xFF;
//    *minutes = (time_data >> 8) & 0xFF;
//    *seconds = time_data & 0xFF;
//}


// Generic I2C write function
void I2C_Write(I2C_HandleTypeDef *hi2c, uint16_t device_address, uint16_t mem_address, uint8_t mem_address_size, uint8_t *data, size_t data_size, uint32_t timeout)
{
    HAL_I2C_Mem_Write(hi2c, device_address, mem_address, mem_address_size, data, data_size, timeout);
}

//read function for RTC
void I2C_read(uint8_t *data)
   {
	HAL_I2C_Mem_Read(&hi2c1, DS3107_ADDRESS, 0x00, 1, data, 7, 1000);
   }
