################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/Src/IPM.c \
../application/Src/app_ADC.c \
../application/Src/app_GSM.c \
../application/Src/app_RTC.c \
../application/Src/app_config.c \
../application/Src/app_terminal.c 

OBJS += \
./application/Src/IPM.o \
./application/Src/app_ADC.o \
./application/Src/app_GSM.o \
./application/Src/app_RTC.o \
./application/Src/app_config.o \
./application/Src/app_terminal.o 

C_DEPS += \
./application/Src/IPM.d \
./application/Src/app_ADC.d \
./application/Src/app_GSM.d \
./application/Src/app_RTC.d \
./application/Src/app_config.d \
./application/Src/app_terminal.d 


# Each subdirectory must supply rules for building sources it contributes
application/Src/%.o application/Src/%.su application/Src/%.cyclo: ../application/Src/%.c application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/GitHub_F446RE/IPM-S2V/Integration_Config_ADC_RTC_GSM_using_F446RE/Integration_Config_ADC_GSM_RTC_F446RE/application/Inc" -I"E:/GitHub_F446RE/IPM-S2V/Integration_Config_ADC_RTC_GSM_using_F446RE/Integration_Config_ADC_GSM_RTC_F446RE/common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application-2f-Src

clean-application-2f-Src:
	-$(RM) ./application/Src/IPM.cyclo ./application/Src/IPM.d ./application/Src/IPM.o ./application/Src/IPM.su ./application/Src/app_ADC.cyclo ./application/Src/app_ADC.d ./application/Src/app_ADC.o ./application/Src/app_ADC.su ./application/Src/app_GSM.cyclo ./application/Src/app_GSM.d ./application/Src/app_GSM.o ./application/Src/app_GSM.su ./application/Src/app_RTC.cyclo ./application/Src/app_RTC.d ./application/Src/app_RTC.o ./application/Src/app_RTC.su ./application/Src/app_config.cyclo ./application/Src/app_config.d ./application/Src/app_config.o ./application/Src/app_config.su ./application/Src/app_terminal.cyclo ./application/Src/app_terminal.d ./application/Src/app_terminal.o ./application/Src/app_terminal.su

.PHONY: clean-application-2f-Src

