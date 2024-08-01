################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application_layer/Src/Application_GSM.c \
../Application_layer/Src/application_ADC.c \
../Application_layer/Src/application_RTC.c 

OBJS += \
./Application_layer/Src/Application_GSM.o \
./Application_layer/Src/application_ADC.o \
./Application_layer/Src/application_RTC.o 

C_DEPS += \
./Application_layer/Src/Application_GSM.d \
./Application_layer/Src/application_ADC.d \
./Application_layer/Src/application_RTC.d 


# Each subdirectory must supply rules for building sources it contributes
Application_layer/Src/%.o Application_layer/Src/%.su Application_layer/Src/%.cyclo: ../Application_layer/Src/%.c Application_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM IPM project/IPM_Integration with GSM/Application_layer/Inc" -I"E:/STM IPM project/IPM_Integration with GSM/Common_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application_layer-2f-Src

clean-Application_layer-2f-Src:
	-$(RM) ./Application_layer/Src/Application_GSM.cyclo ./Application_layer/Src/Application_GSM.d ./Application_layer/Src/Application_GSM.o ./Application_layer/Src/Application_GSM.su ./Application_layer/Src/application_ADC.cyclo ./Application_layer/Src/application_ADC.d ./Application_layer/Src/application_ADC.o ./Application_layer/Src/application_ADC.su ./Application_layer/Src/application_RTC.cyclo ./Application_layer/Src/application_RTC.d ./Application_layer/Src/application_RTC.o ./Application_layer/Src/application_RTC.su

.PHONY: clean-Application_layer-2f-Src

