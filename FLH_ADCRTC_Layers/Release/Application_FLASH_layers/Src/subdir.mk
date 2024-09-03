################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application_FLASH_layers/Src/application_Flash.c 

OBJS += \
./Application_FLASH_layers/Src/application_Flash.o 

C_DEPS += \
./Application_FLASH_layers/Src/application_Flash.d 


# Each subdirectory must supply rules for building sources it contributes
Application_FLASH_layers/Src/%.o Application_FLASH_layers/Src/%.su Application_FLASH_layers/Src/%.cyclo: ../Application_FLASH_layers/Src/%.c Application_FLASH_layers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/User/STM32CubeIDE/workspace_1.12.0/FLH_ADCRTC_Layers/Application_FLASH_layers/Inc" -I"C:/Users/User/STM32CubeIDE/workspace_1.12.0/FLH_ADCRTC_Layers/Common_FLASH_layers/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application_FLASH_layers-2f-Src

clean-Application_FLASH_layers-2f-Src:
	-$(RM) ./Application_FLASH_layers/Src/application_Flash.cyclo ./Application_FLASH_layers/Src/application_Flash.d ./Application_FLASH_layers/Src/application_Flash.o ./Application_FLASH_layers/Src/application_Flash.su

.PHONY: clean-Application_FLASH_layers-2f-Src

