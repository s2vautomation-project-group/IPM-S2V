################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common/Src/com_ADC.c \
../Common/Src/com_GSM.c \
../Common/Src/com_RTC.c \
../Common/Src/com_config.c \
../Common/Src/com_terminal.c 

OBJS += \
./Common/Src/com_ADC.o \
./Common/Src/com_GSM.o \
./Common/Src/com_RTC.o \
./Common/Src/com_config.o \
./Common/Src/com_terminal.o 

C_DEPS += \
./Common/Src/com_ADC.d \
./Common/Src/com_GSM.d \
./Common/Src/com_RTC.d \
./Common/Src/com_config.d \
./Common/Src/com_terminal.d 


# Each subdirectory must supply rules for building sources it contributes
Common/Src/%.o Common/Src/%.su Common/Src/%.cyclo: ../Common/Src/%.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/GitHub_F446RE/IPM-S2V/UPDATED_INTEGRATION_F446RE/UPDATED_INTEGRATION/Application/Inc" -I"E:/GitHub_F446RE/IPM-S2V/UPDATED_INTEGRATION_F446RE/UPDATED_INTEGRATION/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-Src

clean-Common-2f-Src:
	-$(RM) ./Common/Src/com_ADC.cyclo ./Common/Src/com_ADC.d ./Common/Src/com_ADC.o ./Common/Src/com_ADC.su ./Common/Src/com_GSM.cyclo ./Common/Src/com_GSM.d ./Common/Src/com_GSM.o ./Common/Src/com_GSM.su ./Common/Src/com_RTC.cyclo ./Common/Src/com_RTC.d ./Common/Src/com_RTC.o ./Common/Src/com_RTC.su ./Common/Src/com_config.cyclo ./Common/Src/com_config.d ./Common/Src/com_config.o ./Common/Src/com_config.su ./Common/Src/com_terminal.cyclo ./Common/Src/com_terminal.d ./Common/Src/com_terminal.o ./Common/Src/com_terminal.su

.PHONY: clean-Common-2f-Src

