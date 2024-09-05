################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../applicationlayer/Src/app_adc.c 

OBJS += \
./applicationlayer/Src/app_adc.o 

C_DEPS += \
./applicationlayer/Src/app_adc.d 


# Each subdirectory must supply rules for building sources it contributes
applicationlayer/Src/%.o applicationlayer/Src/%.su applicationlayer/Src/%.cyclo: ../applicationlayer/Src/%.c applicationlayer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/IPM_ADC_2_CHANNEL/commonlayer/Inc" -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/IPM_ADC_2_CHANNEL/applicationlayer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-applicationlayer-2f-Src

clean-applicationlayer-2f-Src:
	-$(RM) ./applicationlayer/Src/app_adc.cyclo ./applicationlayer/Src/app_adc.d ./applicationlayer/Src/app_adc.o ./applicationlayer/Src/app_adc.su

.PHONY: clean-applicationlayer-2f-Src

