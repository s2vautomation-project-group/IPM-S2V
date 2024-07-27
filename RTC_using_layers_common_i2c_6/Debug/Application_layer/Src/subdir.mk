################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application_layer/Src/application.c 

OBJS += \
./Application_layer/Src/application.o 

C_DEPS += \
./Application_layer/Src/application.d 


# Each subdirectory must supply rules for building sources it contributes
Application_layer/Src/%.o Application_layer/Src/%.su Application_layer/Src/%.cyclo: ../Application_layer/Src/%.c Application_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM IPM project/RTC_using_layers_common_i2c_6/Application_layer/Inc" -I"E:/STM IPM project/RTC_using_layers_common_i2c_6/Common_layer/Inc" -I"E:/STM IPM project/RTC_using_layers_common_i2c_6/Core/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application_layer-2f-Src

clean-Application_layer-2f-Src:
	-$(RM) ./Application_layer/Src/application.cyclo ./Application_layer/Src/application.d ./Application_layer/Src/application.o ./Application_layer/Src/application.su

.PHONY: clean-Application_layer-2f-Src

