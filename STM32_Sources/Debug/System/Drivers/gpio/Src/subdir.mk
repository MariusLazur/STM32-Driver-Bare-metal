################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Drivers/gpio/Src/gpio.c 

OBJS += \
./System/Drivers/gpio/Src/gpio.o 

C_DEPS += \
./System/Drivers/gpio/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
System/Drivers/gpio/Src/%.o System/Drivers/gpio/Src/%.su System/Drivers/gpio/Src/%.cyclo: ../System/Drivers/gpio/Src/%.c System/Drivers/gpio/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Inc" -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Drivers/gpio/Inc" -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Drivers/rcc/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Drivers-2f-gpio-2f-Src

clean-System-2f-Drivers-2f-gpio-2f-Src:
	-$(RM) ./System/Drivers/gpio/Src/gpio.cyclo ./System/Drivers/gpio/Src/gpio.d ./System/Drivers/gpio/Src/gpio.o ./System/Drivers/gpio/Src/gpio.su

.PHONY: clean-System-2f-Drivers-2f-gpio-2f-Src

