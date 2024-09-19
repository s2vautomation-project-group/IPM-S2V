################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/Src/com_ADC.c \
../common/Src/com_GSM.c \
../common/Src/com_RTC.c \
../common/Src/com_config.c \
../common/Src/com_terminal.c 

OBJS += \
./common/Src/com_ADC.o \
./common/Src/com_GSM.o \
./common/Src/com_RTC.o \
./common/Src/com_config.o \
./common/Src/com_terminal.o 

C_DEPS += \
./common/Src/com_ADC.d \
./common/Src/com_GSM.d \
./common/Src/com_RTC.d \
./common/Src/com_config.d \
./common/Src/com_terminal.d 


# Each subdirectory must supply rules for building sources it contributes
common/Src/%.o common/Src/%.su common/Src/%.cyclo: ../common/Src/%.c common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/GitHub_F446RE/IPM-S2V/Integration_Config_ADC_RTC_GSM_using_F446RE/Integration_Config_ADC_GSM_RTC_F446RE/application/Inc" -I"E:/GitHub_F446RE/IPM-S2V/Integration_Config_ADC_RTC_GSM_using_F446RE/Integration_Config_ADC_GSM_RTC_F446RE/common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-Src

clean-common-2f-Src:
	-$(RM) ./common/Src/com_ADC.cyclo ./common/Src/com_ADC.d ./common/Src/com_ADC.o ./common/Src/com_ADC.su ./common/Src/com_GSM.cyclo ./common/Src/com_GSM.d ./common/Src/com_GSM.o ./common/Src/com_GSM.su ./common/Src/com_RTC.cyclo ./common/Src/com_RTC.d ./common/Src/com_RTC.o ./common/Src/com_RTC.su ./common/Src/com_config.cyclo ./common/Src/com_config.d ./common/Src/com_config.o ./common/Src/com_config.su ./common/Src/com_terminal.cyclo ./common/Src/com_terminal.d ./common/Src/com_terminal.o ./common/Src/com_terminal.su

.PHONY: clean-common-2f-Src

