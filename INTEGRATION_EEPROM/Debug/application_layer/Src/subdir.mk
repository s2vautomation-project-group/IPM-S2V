################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application_layer/Src/IPM.c \
../application_layer/Src/app_ADC.c \
../application_layer/Src/app_EEPROM.c \
../application_layer/Src/app_GSM.c \
../application_layer/Src/app_RTC.c \
../application_layer/Src/app_config.c \
../application_layer/Src/app_terminal.c 

OBJS += \
./application_layer/Src/IPM.o \
./application_layer/Src/app_ADC.o \
./application_layer/Src/app_EEPROM.o \
./application_layer/Src/app_GSM.o \
./application_layer/Src/app_RTC.o \
./application_layer/Src/app_config.o \
./application_layer/Src/app_terminal.o 

C_DEPS += \
./application_layer/Src/IPM.d \
./application_layer/Src/app_ADC.d \
./application_layer/Src/app_EEPROM.d \
./application_layer/Src/app_GSM.d \
./application_layer/Src/app_RTC.d \
./application_layer/Src/app_config.d \
./application_layer/Src/app_terminal.d 


# Each subdirectory must supply rules for building sources it contributes
application_layer/Src/%.o application_layer/Src/%.su application_layer/Src/%.cyclo: ../application_layer/Src/%.c application_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM/INTEGRATION_EEPROM/application_layer/Inc" -I"E:/STM/INTEGRATION_EEPROM/common_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application_layer-2f-Src

clean-application_layer-2f-Src:
	-$(RM) ./application_layer/Src/IPM.cyclo ./application_layer/Src/IPM.d ./application_layer/Src/IPM.o ./application_layer/Src/IPM.su ./application_layer/Src/app_ADC.cyclo ./application_layer/Src/app_ADC.d ./application_layer/Src/app_ADC.o ./application_layer/Src/app_ADC.su ./application_layer/Src/app_EEPROM.cyclo ./application_layer/Src/app_EEPROM.d ./application_layer/Src/app_EEPROM.o ./application_layer/Src/app_EEPROM.su ./application_layer/Src/app_GSM.cyclo ./application_layer/Src/app_GSM.d ./application_layer/Src/app_GSM.o ./application_layer/Src/app_GSM.su ./application_layer/Src/app_RTC.cyclo ./application_layer/Src/app_RTC.d ./application_layer/Src/app_RTC.o ./application_layer/Src/app_RTC.su ./application_layer/Src/app_config.cyclo ./application_layer/Src/app_config.d ./application_layer/Src/app_config.o ./application_layer/Src/app_config.su ./application_layer/Src/app_terminal.cyclo ./application_layer/Src/app_terminal.d ./application_layer/Src/app_terminal.o ./application_layer/Src/app_terminal.su

.PHONY: clean-application_layer-2f-Src

