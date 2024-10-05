################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common_layer/Src/Cqueue.c \
../common_layer/Src/com_ADC.c \
../common_layer/Src/com_GSM.c \
../common_layer/Src/com_RTC.c \
../common_layer/Src/com_config.c \
../common_layer/Src/com_terminal.c \
../common_layer/Src/comm_EEPROM.c 

OBJS += \
./common_layer/Src/Cqueue.o \
./common_layer/Src/com_ADC.o \
./common_layer/Src/com_GSM.o \
./common_layer/Src/com_RTC.o \
./common_layer/Src/com_config.o \
./common_layer/Src/com_terminal.o \
./common_layer/Src/comm_EEPROM.o 

C_DEPS += \
./common_layer/Src/Cqueue.d \
./common_layer/Src/com_ADC.d \
./common_layer/Src/com_GSM.d \
./common_layer/Src/com_RTC.d \
./common_layer/Src/com_config.d \
./common_layer/Src/com_terminal.d \
./common_layer/Src/comm_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
common_layer/Src/%.o common_layer/Src/%.su common_layer/Src/%.cyclo: ../common_layer/Src/%.c common_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM/INTEGRATION_EEPROM/application_layer/Inc" -I"E:/STM/INTEGRATION_EEPROM/common_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common_layer-2f-Src

clean-common_layer-2f-Src:
	-$(RM) ./common_layer/Src/Cqueue.cyclo ./common_layer/Src/Cqueue.d ./common_layer/Src/Cqueue.o ./common_layer/Src/Cqueue.su ./common_layer/Src/com_ADC.cyclo ./common_layer/Src/com_ADC.d ./common_layer/Src/com_ADC.o ./common_layer/Src/com_ADC.su ./common_layer/Src/com_GSM.cyclo ./common_layer/Src/com_GSM.d ./common_layer/Src/com_GSM.o ./common_layer/Src/com_GSM.su ./common_layer/Src/com_RTC.cyclo ./common_layer/Src/com_RTC.d ./common_layer/Src/com_RTC.o ./common_layer/Src/com_RTC.su ./common_layer/Src/com_config.cyclo ./common_layer/Src/com_config.d ./common_layer/Src/com_config.o ./common_layer/Src/com_config.su ./common_layer/Src/com_terminal.cyclo ./common_layer/Src/com_terminal.d ./common_layer/Src/com_terminal.o ./common_layer/Src/com_terminal.su ./common_layer/Src/comm_EEPROM.cyclo ./common_layer/Src/comm_EEPROM.d ./common_layer/Src/comm_EEPROM.o ./common_layer/Src/comm_EEPROM.su

.PHONY: clean-common_layer-2f-Src

