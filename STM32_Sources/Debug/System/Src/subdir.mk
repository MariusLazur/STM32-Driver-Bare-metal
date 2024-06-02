################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/Src/main.c \
../System/Src/syscalls.c \
../System/Src/sysmem.c 

OBJS += \
./System/Src/main.o \
./System/Src/syscalls.o \
./System/Src/sysmem.o 

C_DEPS += \
./System/Src/main.d \
./System/Src/syscalls.d \
./System/Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
System/Src/%.o System/Src/%.su System/Src/%.cyclo: ../System/Src/%.c System/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Inc" -I"/Users/mariuslazur/Dev_Projects/STM32-Driver-Bare-metal/STM32_Sources/System/Drivers/gpio/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System-2f-Src

clean-System-2f-Src:
	-$(RM) ./System/Src/main.cyclo ./System/Src/main.d ./System/Src/main.o ./System/Src/main.su ./System/Src/syscalls.cyclo ./System/Src/syscalls.d ./System/Src/syscalls.o ./System/Src/syscalls.su ./System/Src/sysmem.cyclo ./System/Src/sysmem.d ./System/Src/sysmem.o ./System/Src/sysmem.su

.PHONY: clean-System-2f-Src

