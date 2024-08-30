################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application_layer/Src/app_adc.c 

OBJS += \
./application_layer/Src/app_adc.o 

C_DEPS += \
./application_layer/Src/app_adc.d 


# Each subdirectory must supply rules for building sources it contributes
application_layer/Src/%.o application_layer/Src/%.su application_layer/Src/%.cyclo: ../application_layer/Src/%.c application_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/CH2_2/common_layer/Inc" -I"C:/Users/Somanath/STM32CubeIDE/workspace_1.12.0/CH2_2/application_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application_layer-2f-Src

clean-application_layer-2f-Src:
	-$(RM) ./application_layer/Src/app_adc.cyclo ./application_layer/Src/app_adc.d ./application_layer/Src/app_adc.o ./application_layer/Src/app_adc.su

.PHONY: clean-application_layer-2f-Src

