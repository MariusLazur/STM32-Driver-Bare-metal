################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../System/Startup/startup_stm32f446retx.s 

OBJS += \
./System/Startup/startup_stm32f446retx.o 

S_DEPS += \
./System/Startup/startup_stm32f446retx.d 


# Each subdirectory must supply rules for building sources it contributes
System/Startup/%.o: ../System/Startup/%.s System/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-System-2f-Startup

clean-System-2f-Startup:
	-$(RM) ./System/Startup/startup_stm32f446retx.d ./System/Startup/startup_stm32f446retx.o

.PHONY: clean-System-2f-Startup

