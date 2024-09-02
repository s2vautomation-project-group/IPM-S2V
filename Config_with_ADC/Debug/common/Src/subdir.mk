################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/Src/com_adc.c \
../common/Src/com_config.c 

OBJS += \
./common/Src/com_adc.o \
./common/Src/com_config.o 

C_DEPS += \
./common/Src/com_adc.d \
./common/Src/com_config.d 


# Each subdirectory must supply rules for building sources it contributes
common/Src/%.o common/Src/%.su common/Src/%.cyclo: ../common/Src/%.c common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM/Config_with_ADC/application/Inc" -I"E:/STM/Config_with_ADC/common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-Src

clean-common-2f-Src:
	-$(RM) ./common/Src/com_adc.cyclo ./common/Src/com_adc.d ./common/Src/com_adc.o ./common/Src/com_adc.su ./common/Src/com_config.cyclo ./common/Src/com_config.d ./common/Src/com_config.o ./common/Src/com_config.su

.PHONY: clean-common-2f-Src

