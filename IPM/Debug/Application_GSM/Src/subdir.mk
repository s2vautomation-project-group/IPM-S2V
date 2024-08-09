################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application_GSM/Src/Application_GSM.c 

OBJS += \
./Application_GSM/Src/Application_GSM.o 

C_DEPS += \
./Application_GSM/Src/Application_GSM.d 


# Each subdirectory must supply rules for building sources it contributes
Application_GSM/Src/%.o Application_GSM/Src/%.su Application_GSM/Src/%.cyclo: ../Application_GSM/Src/%.c Application_GSM/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/IPM/Application_GSM/Inc" -I"C:/Users/KAVYA/STM32CubeIDE/workspace_1.12.0/IPM/Common_GSM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application_GSM-2f-Src

clean-Application_GSM-2f-Src:
	-$(RM) ./Application_GSM/Src/Application_GSM.cyclo ./Application_GSM/Src/Application_GSM.d ./Application_GSM/Src/Application_GSM.o ./Application_GSM/Src/Application_GSM.su

.PHONY: clean-Application_GSM-2f-Src

