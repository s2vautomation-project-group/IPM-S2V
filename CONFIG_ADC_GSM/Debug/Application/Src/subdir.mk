################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/Application_GSM.c \
../Application/Src/app_adc.c \
../Application/Src/app_config.c 

OBJS += \
./Application/Src/Application_GSM.o \
./Application/Src/app_adc.o \
./Application/Src/app_config.o 

C_DEPS += \
./Application/Src/Application_GSM.d \
./Application/Src/app_adc.d \
./Application/Src/app_config.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/CONFIG_ADC_GSM/Application/Inc" -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/CONFIG_ADC_GSM/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/Application_GSM.cyclo ./Application/Src/Application_GSM.d ./Application/Src/Application_GSM.o ./Application/Src/Application_GSM.su ./Application/Src/app_adc.cyclo ./Application/Src/app_adc.d ./Application/Src/app_adc.o ./Application/Src/app_adc.su ./Application/Src/app_config.cyclo ./Application/Src/app_config.d ./Application/Src/app_config.o ./Application/Src/app_config.su

.PHONY: clean-Application-2f-Src

