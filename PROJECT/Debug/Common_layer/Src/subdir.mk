################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common_layer/Src/Uart.c 

OBJS += \
./Common_layer/Src/Uart.o 

C_DEPS += \
./Common_layer/Src/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
Common_layer/Src/%.o Common_layer/Src/%.su Common_layer/Src/%.cyclo: ../Common_layer/Src/%.c Common_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/PROJECT/Application_layer/Inc" -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/PROJECT/Common_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common_layer-2f-Src

clean-Common_layer-2f-Src:
	-$(RM) ./Common_layer/Src/Uart.cyclo ./Common_layer/Src/Uart.d ./Common_layer/Src/Uart.o ./Common_layer/Src/Uart.su

.PHONY: clean-Common_layer-2f-Src

