cmake_minimum_required(VERSION 3.22)

# Setup cmake module path and compiler toolchain
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/arm-none-eabi-gcc.cmake)

# Project definition
project(STM32_Project
    VERSION 1.0.0
    LANGUAGES C ASM
)

# MCU Configuration
set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL STM32F446xx)
set(MCU_DEVICE STM32F446RETx)
set(CPU_PARAMETERS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

# Linker script
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F446RETX_FLASH.ld)

# Startup file
set(STARTUP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/System/Startup/startup_stm32f446retx.s)

# Include directories
set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/gpio/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/rcc/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/pwr/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/uart/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/Timers/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/dma/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/irq/Inc
)

# Source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/gpio/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/rcc/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/pwr/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/uart/Src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/Timers/Src/*.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/dma/Src/*.c  # Excluded: has compilation errors, needs fixing
    ${CMAKE_CURRENT_SOURCE_DIR}/System/Drivers/irq/Src/*.c
)

# Executable
set(EXECUTABLE ${PROJECT_NAME})
add_executable(${EXECUTABLE}
    ${SOURCES}
    ${STARTUP_FILE}
)

# Compile definitions
target_compile_definitions(${EXECUTABLE} PRIVATE
    ${MCU_MODEL}
    USE_FULL_ASSERT
    $<$<CONFIG:Debug>:DEBUG>
)

# Include paths
target_include_directories(${EXECUTABLE} PRIVATE
    ${INCLUDE_DIRS}
)

# Compiler options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -fdata-sections
    -ffunction-sections
    $<$<CONFIG:Debug>:-O0 -g3 -ggdb>
    $<$<CONFIG:Release>:-Os -g0>
)

# Linker options
target_link_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -T${LINKER_SCRIPT}
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,-Map=${PROJECT_NAME}.map
    -Wl,--gc-sections
    -Wl,--start-group
    -lc
    -lm
    -Wl,--end-group
    -Wl,--print-memory-usage
)

# Post-build: Generate HEX, BIN, and ASM files
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJDUMP} -h -S $<TARGET_FILE:${EXECUTABLE}> > ${PROJECT_NAME}.asm
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
    COMMENT "Generating HEX, BIN, and ASM files"
)

# Flash target using OpenOCD
add_custom_target(flash
    COMMAND openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd.cfg
            -c "program $<TARGET_FILE:${EXECUTABLE}> verify reset exit"
    DEPENDS ${EXECUTABLE}
    COMMENT "Flashing ${PROJECT_NAME}.elf to target"
)

# Erase target
add_custom_target(erase
    COMMAND openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd.cfg
            -c "init" -c "reset halt" -c "stm32f4x mass_erase 0" -c "exit"
    COMMENT "Erasing flash memory"
)

# Reset target
add_custom_target(reset
    COMMAND openocd -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd.cfg
            -c "init" -c "reset" -c "exit"
    COMMENT "Resetting target"
)

# Print size information
add_custom_target(size
    COMMAND ${CMAKE_SIZE} --format=berkeley $<TARGET_FILE:${EXECUTABLE}>
    DEPENDS ${EXECUTABLE}
    COMMENT "Firmware size:"
)

# Debug with GDB and OpenOCD
add_custom_target(debug
    COMMAND ${CMAKE_GDB} -ex "target extended-remote :3333"
            -ex "monitor reset halt"
            -ex "load"
            $<TARGET_FILE:${EXECUTABLE}>
    DEPENDS ${EXECUTABLE}
    COMMENT "Starting GDB debug session"
)

#═══════════════════════════════════════════════════════════════════════════════
# BACKUP AND CLEAN BUILD TARGETS
#═══════════════════════════════════════════════════════════════════════════════

# Directory to store build history
set(BACKUP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build_history)
set(SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/scripts)

# Backup target - saves current build artifacts with timestamp
add_custom_target(backup
    COMMAND ${SCRIPTS_DIR}/backup_build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Backing up build artifacts to build_history/"
)

# Clean build target - backup, clean, and rebuild
add_custom_target(rebuild
    COMMAND ${SCRIPTS_DIR}/rebuild.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Backup, clean, and rebuild"
)

# List all backups
add_custom_target(list-backups
    COMMAND ls -la ${BACKUP_DIR}/ 2>/dev/null || echo "No backups found"
    COMMENT "List all backed up builds"
)

# Clean old backups (keep last 5)
add_custom_target(clean-backups
    COMMAND bash -c "cd ${BACKUP_DIR} 2>/dev/null && ls -t | tail -n +6 | xargs rm -rf 2>/dev/null; echo 'Old backups cleaned'"
    COMMENT "Remove old backups, keep last 5"
)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "MCU: ${MCU_DEVICE}")
message(STATUS "Linker script: ${LINKER_SCRIPT}")