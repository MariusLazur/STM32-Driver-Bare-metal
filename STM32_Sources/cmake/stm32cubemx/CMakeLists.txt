cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE

    ../../System/Drivers/gpio/Inc
    ../../System/Drivers/dma/Inc
    ../../System/Drivers/irq/Inc
    ../../System/Drivers/pwr/Inc
    ../../System/Drivers/rcc/Inc
    ../../System/Drivers/Timers/Inc
    ../../System/Drivers/uart/Inc
    ../../System/Inc
)

target_sources(stm32cubemx INTERFACE
   ../../System/Drivers/gpio/Src/gpio.c
   ../../System/Drivers/pwr/Src/pwr.c
   ../../System/Drivers/rcc/Src/rcc.c
   ../../System/Drivers/uart/Src/uart.c
   ../../System/Src/main.c
   ../../System/Startup/startup_stm32f446retx.s  
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


