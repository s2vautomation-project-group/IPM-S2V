################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Coomon_layer/Src/comm_EEPROM.c 

OBJS += \
./Coomon_layer/Src/comm_EEPROM.o 

C_DEPS += \
./Coomon_layer/Src/comm_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
Coomon_layer/Src/%.o Coomon_layer/Src/%.su Coomon_layer/Src/%.cyclo: ../Coomon_layer/Src/%.c Coomon_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/User/STM32CubeIDE/workspace_1.12.0/EE_PROM/Application_layer/Inc" -I"C:/Users/User/STM32CubeIDE/workspace_1.12.0/EE_PROM/Coomon_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Coomon_layer-2f-Src

clean-Coomon_layer-2f-Src:
	-$(RM) ./Coomon_layer/Src/comm_EEPROM.cyclo ./Coomon_layer/Src/comm_EEPROM.d ./Coomon_layer/Src/comm_EEPROM.o ./Coomon_layer/Src/comm_EEPROM.su

.PHONY: clean-Coomon_layer-2f-Src

