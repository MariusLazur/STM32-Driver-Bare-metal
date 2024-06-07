# arm-none-eabi-toolchain.cmake
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX "arm-none-eabi-")
set(TOOLCHAIN_PATH "/Applications/ARM/bin")

# Specify the cross compiler
set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PATH}/${TOOLCHAIN_PREFIX}gcc)

# Specify compiler flags
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m4 -mthumb")

# Specify linker flags to include required libraries
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -mthumb -specs=nano.specs -specs=nosys.specs")

# Include directories for the toolchain
include_directories(${TOOLCHAIN_PATH}/../arm-none-eabi/include)
