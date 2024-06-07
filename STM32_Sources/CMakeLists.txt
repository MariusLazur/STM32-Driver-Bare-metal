cmake_minimum_required(VERSION 3.10)
include(CMakePrintHelpers)

# Set the compiler toolchain
include(arm-none-eabi-toolchain.cmake)

# Project name
project(STM32DriverBareMetal)

# Set compiler flags
set(CMAKE_C_FLAGS " -mthumb -lc -Wimplicit-function-declaration")
set(CMAKE_CXX_FLAGS " -mthumb -lc -Wimplicit-function-declaration")

# Linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F103C8Tx_FLASH.ld)

message(STATUS "Target Name: ${PROJECT_NAME}")

# Add include directories
include_directories(
        System/Drivers/gpio/Inc
        System/Drivers/pwr/inc
        System/Drivers/rcc/inc
        System/Inc
)

# Add source files
add_executable(${PROJECT_NAME}
        System/Drivers/gpio/Inc/gpio.h
        System/Drivers/gpio/Inc/gpio_reg.h
        System/Drivers/gpio/Src/gpio.c
        System/Drivers/pwr/inc/pwr.h
        System/Drivers/pwr/inc/pwr_reg.h
        System/Drivers/pwr/src/pwr.c
        System/Drivers/rcc/inc/rcc.h
        System/Drivers/rcc/inc/rcc_reg.h
        System/Drivers/rcc/src/rcc.c
        System/Inc/std_types.h
        System/Inc/STM32F446RE_Base.h
        System/Inc/types.h
        System/Src/main.c
)

# Set the output file extension to .elf
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")

# Generate the .hex file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY_COMPILER} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        DEPENDS ${PROJECT_NAME}.elf
        COMMENT "Generating IHEX file ${PROJECT_NAME}.hex"
)

# Generate the disassembly file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJDUMP_COMPILER} -Dsx ${PROJECT_NAME}.elf > ${PROJECT_NAME}.dasm
        DEPENDS ${PROJECT_NAME}.elf
        COMMENT "Generating Disassembly file ${PROJECT_NAME}.dasm"
)

# Generate the assembly file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJDUMP_COMPILER} -xd ${PROJECT_NAME}.elf > ${PROJECT_NAME}.asm
        DEPENDS ${PROJECT_NAME}.elf
        COMMENT "Generating Disassembly file ${PROJECT_NAME}.asm"
)
