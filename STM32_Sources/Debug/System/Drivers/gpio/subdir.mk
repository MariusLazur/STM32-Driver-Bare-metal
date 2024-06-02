################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Drivers/gpio/gpio.c 

OBJS += \
./System/Drivers/gpio/gpio.o 

C_DEPS += \
./System/Drivers/gpio/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
System/Drivers/gpio/%.o System/Drivers/gpio/%.su System/Drivers/gpio/%.cyclo: ../System/Drivers/gpio/%.c System/Drivers/gpio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I"/Users/mariuslazur/Dev_Projects/ded/STM32_Project/System/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Drivers-2f-gpio

clean-System-2f-Drivers-2f-gpio:
	-$(RM) ./System/Drivers/gpio/gpio.cyclo ./System/Drivers/gpio/gpio.d ./System/Drivers/gpio/gpio.o ./System/Drivers/gpio/gpio.su

.PHONY: clean-System-2f-Drivers-2f-gpio

