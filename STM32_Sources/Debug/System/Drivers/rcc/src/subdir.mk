################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Drivers/rcc/src/rcc.c 

OBJS += \
./System/Drivers/rcc/src/rcc.o 

C_DEPS += \
./System/Drivers/rcc/src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
System/Drivers/rcc/src/%.o System/Drivers/rcc/src/%.su System/Drivers/rcc/src/%.cyclo: ../System/Drivers/rcc/src/%.c System/Drivers/rcc/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Inc" -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Drivers/gpio/Inc" -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Drivers/rcc/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Drivers-2f-rcc-2f-src

clean-System-2f-Drivers-2f-rcc-2f-src:
	-$(RM) ./System/Drivers/rcc/src/rcc.cyclo ./System/Drivers/rcc/src/rcc.d ./System/Drivers/rcc/src/rcc.o ./System/Drivers/rcc/src/rcc.su

.PHONY: clean-System-2f-Drivers-2f-rcc-2f-src

