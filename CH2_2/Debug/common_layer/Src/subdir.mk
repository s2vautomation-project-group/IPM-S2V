################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common_layer/Src/com_adc.c 

OBJS += \
./common_layer/Src/com_adc.o 

C_DEPS += \
./common_layer/Src/com_adc.d 


# Each subdirectory must supply rules for building sources it contributes
common_layer/Src/%.o common_layer/Src/%.su common_layer/Src/%.cyclo: ../common_layer/Src/%.c common_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/CH2_2/common_layer/Inc" -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/CH2_2/application_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common_layer-2f-Src

clean-common_layer-2f-Src:
	-$(RM) ./common_layer/Src/com_adc.cyclo ./common_layer/Src/com_adc.d ./common_layer/Src/com_adc.o ./common_layer/Src/com_adc.su

.PHONY: clean-common_layer-2f-Src

