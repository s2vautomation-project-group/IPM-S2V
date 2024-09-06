################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common/Src/Common_GSM.c \
../Common/Src/com_adc.c \
../Common/Src/com_config.c 

OBJS += \
./Common/Src/Common_GSM.o \
./Common/Src/com_adc.o \
./Common/Src/com_config.o 

C_DEPS += \
./Common/Src/Common_GSM.d \
./Common/Src/com_adc.d \
./Common/Src/com_config.d 


# Each subdirectory must supply rules for building sources it contributes
Common/Src/%.o Common/Src/%.su Common/Src/%.cyclo: ../Common/Src/%.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/CONFIG_ADC_GSM/Application/Inc" -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/CONFIG_ADC_GSM/Common/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-Src

clean-Common-2f-Src:
	-$(RM) ./Common/Src/Common_GSM.cyclo ./Common/Src/Common_GSM.d ./Common/Src/Common_GSM.o ./Common/Src/Common_GSM.su ./Common/Src/com_adc.cyclo ./Common/Src/com_adc.d ./Common/Src/com_adc.o ./Common/Src/com_adc.su ./Common/Src/com_config.cyclo ./Common/Src/com_config.d ./Common/Src/com_config.o ./Common/Src/com_config.su

.PHONY: clean-Common-2f-Src

