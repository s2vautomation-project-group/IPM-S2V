################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/IPM.c \
../Application/Src/app_ADC.c \
../Application/Src/app_GSM.c \
../Application/Src/app_RTC.c \
../Application/Src/app_config.c \
../Application/Src/app_terminal.c 

OBJS += \
./Application/Src/IPM.o \
./Application/Src/app_ADC.o \
./Application/Src/app_GSM.o \
./Application/Src/app_RTC.o \
./Application/Src/app_config.o \
./Application/Src/app_terminal.o 

C_DEPS += \
./Application/Src/IPM.d \
./Application/Src/app_ADC.d \
./Application/Src/app_GSM.d \
./Application/Src/app_RTC.d \
./Application/Src/app_config.d \
./Application/Src/app_terminal.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/GitHub_F446RE/IPM-S2V/UPDATED_INTEGRATION_F446RE/UPDATED_INTEGRATION/Application/Inc" -I"E:/GitHub_F446RE/IPM-S2V/UPDATED_INTEGRATION_F446RE/UPDATED_INTEGRATION/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/IPM.cyclo ./Application/Src/IPM.d ./Application/Src/IPM.o ./Application/Src/IPM.su ./Application/Src/app_ADC.cyclo ./Application/Src/app_ADC.d ./Application/Src/app_ADC.o ./Application/Src/app_ADC.su ./Application/Src/app_GSM.cyclo ./Application/Src/app_GSM.d ./Application/Src/app_GSM.o ./Application/Src/app_GSM.su ./Application/Src/app_RTC.cyclo ./Application/Src/app_RTC.d ./Application/Src/app_RTC.o ./Application/Src/app_RTC.su ./Application/Src/app_config.cyclo ./Application/Src/app_config.d ./Application/Src/app_config.o ./Application/Src/app_config.su ./Application/Src/app_terminal.cyclo ./Application/Src/app_terminal.d ./Application/Src/app_terminal.o ./Application/Src/app_terminal.su

.PHONY: clean-Application-2f-Src

