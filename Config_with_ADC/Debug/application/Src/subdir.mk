################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/Src/app_adc.c \
../application/Src/app_config.c 

OBJS += \
./application/Src/app_adc.o \
./application/Src/app_config.o 

C_DEPS += \
./application/Src/app_adc.d \
./application/Src/app_config.d 


# Each subdirectory must supply rules for building sources it contributes
application/Src/%.o application/Src/%.su application/Src/%.cyclo: ../application/Src/%.c application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM/Config_with_ADC/application/Inc" -I"E:/STM/Config_with_ADC/common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application-2f-Src

clean-application-2f-Src:
	-$(RM) ./application/Src/app_adc.cyclo ./application/Src/app_adc.d ./application/Src/app_adc.o ./application/Src/app_adc.su ./application/Src/app_config.cyclo ./application/Src/app_config.d ./application/Src/app_config.o ./application/Src/app_config.su

.PHONY: clean-application-2f-Src

