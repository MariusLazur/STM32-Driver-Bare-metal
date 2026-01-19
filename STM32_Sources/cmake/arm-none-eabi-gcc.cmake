# CMake toolchain file for ARM Cortex-M bare-metal development
# This file configures the cross-compiler for STM32F4 targets

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Skip compiler tests (cross-compiling)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Toolchain prefix
set(TOOLCHAIN_PREFIX arm-none-eabi-)

# Try to find the ARM toolchain
# Check common installation paths
if(APPLE)
    # macOS: Homebrew or manual installation
    set(TOOLCHAIN_SEARCH_PATHS
        /Applications/ARM/bin
        /opt/homebrew/bin
        /usr/local/bin
        $ENV{ARM_TOOLCHAIN_PATH}
    )
elseif(UNIX)
    # Linux
    set(TOOLCHAIN_SEARCH_PATHS
        /usr/bin
        /usr/local/bin
        $ENV{ARM_TOOLCHAIN_PATH}
    )
else()
    # Windows
    set(TOOLCHAIN_SEARCH_PATHS
        "C:/Program Files/GNU Arm Embedded Toolchain/bin"
        "C:/Program Files (x86)/GNU Arm Embedded Toolchain/bin"
        $ENV{ARM_TOOLCHAIN_PATH}
    )
endif()

# Find the compiler
find_program(CMAKE_C_COMPILER
    NAMES ${TOOLCHAIN_PREFIX}gcc
    PATHS ${TOOLCHAIN_SEARCH_PATHS}
    DOC "ARM GCC C Compiler"
)

find_program(CMAKE_CXX_COMPILER
    NAMES ${TOOLCHAIN_PREFIX}g++
    PATHS ${TOOLCHAIN_SEARCH_PATHS}
    DOC "ARM GCC C++ Compiler"
)

find_program(CMAKE_ASM_COMPILER
    NAMES ${TOOLCHAIN_PREFIX}gcc
    PATHS ${TOOLCHAIN_SEARCH_PATHS}
    DOC "ARM GCC ASM Compiler"
)

# Get toolchain path from found compiler
if(CMAKE_C_COMPILER)
    get_filename_component(TOOLCHAIN_PATH ${CMAKE_C_COMPILER} DIRECTORY)
endif()

# Set other tools
find_program(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy PATHS ${TOOLCHAIN_PATH})
find_program(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}objdump PATHS ${TOOLCHAIN_PATH})
find_program(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size PATHS ${TOOLCHAIN_PATH})
find_program(CMAKE_GDB ${TOOLCHAIN_PREFIX}gdb PATHS ${TOOLCHAIN_PATH})

# Set linker
set(CMAKE_LINKER ${CMAKE_C_COMPILER})

# Output suffixes
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")

# Compiler identification
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_C_COMPILER_ID GNU)
set(CMAKE_CXX_COMPILER_ID GNU)

# Root path settings for cross-compilation
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Print toolchain info
message(STATUS "ARM Toolchain Configuration:")
message(STATUS "  C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "  C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "  ASM Compiler: ${CMAKE_ASM_COMPILER}")
message(STATUS "  OBJCOPY: ${CMAKE_OBJCOPY}")
message(STATUS "  SIZE: ${CMAKE_SIZE}")