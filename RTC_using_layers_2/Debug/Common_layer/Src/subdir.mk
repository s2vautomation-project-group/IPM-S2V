################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common_layer/Src/common.c \
../Common_layer/Src/ssd1306.c \
../Common_layer/Src/ssd1306_fonts.c 

OBJS += \
./Common_layer/Src/common.o \
./Common_layer/Src/ssd1306.o \
./Common_layer/Src/ssd1306_fonts.o 

C_DEPS += \
./Common_layer/Src/common.d \
./Common_layer/Src/ssd1306.d \
./Common_layer/Src/ssd1306_fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Common_layer/Src/%.o Common_layer/Src/%.su Common_layer/Src/%.cyclo: ../Common_layer/Src/%.c Common_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM IPM project/RTC_using_layers_2/Application_layer/Inc" -I"E:/STM IPM project/RTC_using_layers_2/Common_layer/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common_layer-2f-Src

clean-Common_layer-2f-Src:
	-$(RM) ./Common_layer/Src/common.cyclo ./Common_layer/Src/common.d ./Common_layer/Src/common.o ./Common_layer/Src/common.su ./Common_layer/Src/ssd1306.cyclo ./Common_layer/Src/ssd1306.d ./Common_layer/Src/ssd1306.o ./Common_layer/Src/ssd1306.su ./Common_layer/Src/ssd1306_fonts.cyclo ./Common_layer/Src/ssd1306_fonts.d ./Common_layer/Src/ssd1306_fonts.o ./Common_layer/Src/ssd1306_fonts.su

.PHONY: clean-Common_layer-2f-Src

