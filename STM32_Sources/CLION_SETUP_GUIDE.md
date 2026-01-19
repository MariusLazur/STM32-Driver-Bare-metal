# CLion STM32 Development Setup Guide

This guide explains how to configure CLion for building, flashing, and debugging STM32 microcontrollers on macOS.

---

## Prerequisites

### 1. Install Required Tools

```bash
# ARM GCC Toolchain (cross-compiler)
# Download from: https://developer.arm.com/downloads/-/gnu-rm
# Install to: /Applications/ARM/

# OpenOCD (On-Chip Debugger)
brew install openocd

# ST-Link Tools (optional, alternative to OpenOCD)
brew install stlink
```

**What each tool does:**

| Tool | Purpose |
|------|---------|
| **ARM GCC Toolchain** | Cross-compiler that compiles C/C++ code for ARM processors (your PC can't run ARM code directly) |
| **OpenOCD** | Open On-Chip Debugger - communicates with the debug probe (ST-Link) to flash and debug the MCU |
| **ST-Link Tools** | Alternative utilities for flashing STM32 via ST-Link (simpler but less features than OpenOCD) |

### 2. Verify Installation

```bash
# Check ARM GCC
/Applications/ARM/bin/arm-none-eabi-gcc --version

# Check OpenOCD
openocd --version

# Check ST-Link tools
st-info --version
```

---

## Project Structure

Your STM32 project should have this structure:

```
YourProject/
├── CMakeLists.txt              # Main CMake build configuration
├── CMakePresets.json           # Build presets for CLion (Debug/Release configs)
├── cmake/
│   └── arm-none-eabi-gcc.cmake # ARM toolchain file (tells CMake how to cross-compile)
├── openocd.cfg                 # OpenOCD debugger configuration
├── STM32xxxx_FLASH.ld          # Linker script (defines memory layout)
├── YourDevice.svd              # SVD file for peripheral register view (optional)
└── Src/
    ├── main.c
    └── startup_stm32xxxx.s     # Startup assembly (initializes MCU before main)
```

**What each file does:**

| File | Purpose |
|------|---------|
| **CMakeLists.txt** | Tells CMake what files to compile, what flags to use, and how to link |
| **CMakePresets.json** | Pre-configured build settings so you don't type long commands |
| **arm-none-eabi-gcc.cmake** | Toolchain file that tells CMake to use ARM compiler instead of your Mac's compiler |
| **openocd.cfg** | Configuration for the debugger - which probe to use, which MCU target |
| **STM32xxxx_FLASH.ld** | Memory map - tells linker where to place code (FLASH) and data (RAM) |
| **.svd file** | XML description of all MCU registers for debugging peripheral view |
| **startup_stm32xxxx.s** | Assembly code that runs before main() - sets up stack, copies data to RAM, calls main |

---

## Step 1: CMake Configuration

### CMakeLists.txt (Explained Line by Line)

```cmake
#═══════════════════════════════════════════════════════════════════════════════
# MINIMUM CMAKE VERSION
#═══════════════════════════════════════════════════════════════════════════════
cmake_minimum_required(VERSION 3.22)
# Specifies the minimum CMake version required
# Version 3.22+ has good support for presets and cross-compilation

#═══════════════════════════════════════════════════════════════════════════════
# TOOLCHAIN FILE (MUST BE BEFORE project())
#═══════════════════════════════════════════════════════════════════════════════
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/arm-none-eabi-gcc.cmake)
# Points to the toolchain file that configures the ARM cross-compiler
# IMPORTANT: Must be set BEFORE project() or it won't work
# ${CMAKE_CURRENT_SOURCE_DIR} = the folder containing this CMakeLists.txt

#═══════════════════════════════════════════════════════════════════════════════
# PROJECT DEFINITION
#═══════════════════════════════════════════════════════════════════════════════
project(YourProject LANGUAGES C ASM)
# project(name)     - Sets the project name (used for output file names)
# LANGUAGES C ASM   - We're using C and Assembly (for startup file)
# Note: No CXX (C++) since most bare-metal STM32 projects are pure C

#═══════════════════════════════════════════════════════════════════════════════
# MCU CONFIGURATION - CHANGE THESE FOR YOUR SPECIFIC MCU
#═══════════════════════════════════════════════════════════════════════════════
set(MCU_MODEL STM32F446xx)
# Preprocessor define for your MCU
# This is used in header files to enable MCU-specific code
# Examples: STM32F103xB, STM32F407xx, STM32L476xx, STM32H743xx

set(CPU_PARAMETERS
    -mcpu=cortex-m4      # CPU core type
                         # Options: cortex-m0, cortex-m0plus, cortex-m3, cortex-m4, cortex-m7

    -mthumb              # Use Thumb instruction set (required for Cortex-M)
                         # Thumb = 16-bit instructions, more compact code

    -mfpu=fpv4-sp-d16    # Floating Point Unit type
                         # fpv4-sp-d16 = single-precision FPU (Cortex-M4F)
                         # fpv5-sp-d16 = single-precision FPU (Cortex-M7)
                         # fpv5-d16    = double-precision FPU (Cortex-M7)
                         # REMOVE this line for Cortex-M0/M3 (no FPU)

    -mfloat-abi=hard     # How to pass float arguments to functions
                         # hard = use FPU registers (faster, requires FPU)
                         # soft = use integer registers (works without FPU)
                         # softfp = software but compatible with hard
)

#═══════════════════════════════════════════════════════════════════════════════
# LINKER SCRIPT - DEFINES MEMORY LAYOUT
#═══════════════════════════════════════════════════════════════════════════════
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32F446RETX_FLASH.ld)
# Path to the linker script
# The linker script tells the linker:
#   - Where FLASH memory starts and its size
#   - Where RAM starts and its size
#   - Where to place code (.text), constants (.rodata), variables (.data, .bss)
#   - Stack and heap sizes

#═══════════════════════════════════════════════════════════════════════════════
# SOURCE FILES
#═══════════════════════════════════════════════════════════════════════════════
file(GLOB_RECURSE SOURCES "Src/*.c")
# GLOB_RECURSE finds all .c files in Src/ and subdirectories
# Stores the list in SOURCES variable
# Note: GLOB is convenient but won't detect new files until you re-run CMake

set(STARTUP_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f446retx.s)
# The startup assembly file - runs before main()
# It does:
#   1. Sets up the stack pointer
#   2. Copies initialized data from FLASH to RAM
#   3. Zeros the .bss section
#   4. Calls SystemInit() (if defined)
#   5. Calls main()

#═══════════════════════════════════════════════════════════════════════════════
# EXECUTABLE TARGET
#═══════════════════════════════════════════════════════════════════════════════
add_executable(${PROJECT_NAME} ${SOURCES} ${STARTUP_FILE})
# Creates an executable target from source files
# ${PROJECT_NAME} = the name set in project() above
# Output will be: YourProject.elf

#═══════════════════════════════════════════════════════════════════════════════
# INCLUDE DIRECTORIES
#═══════════════════════════════════════════════════════════════════════════════
target_include_directories(${PROJECT_NAME} PRIVATE Inc)
# Adds include paths for #include directives
# PRIVATE = only this target uses these paths (not exported to other targets)
# The compiler will search these folders for header files

#═══════════════════════════════════════════════════════════════════════════════
# COMPILE DEFINITIONS (PREPROCESSOR MACROS)
#═══════════════════════════════════════════════════════════════════════════════
target_compile_definitions(${PROJECT_NAME} PRIVATE
    ${MCU_MODEL}                    # e.g., STM32F446xx - enables MCU-specific code
    $<$<CONFIG:Debug>:DEBUG>        # Define DEBUG only in Debug builds
                                    # $<$<CONFIG:Debug>:...> is a generator expression
)

#═══════════════════════════════════════════════════════════════════════════════
# COMPILER OPTIONS
#═══════════════════════════════════════════════════════════════════════════════
target_compile_options(${PROJECT_NAME} PRIVATE
    ${CPU_PARAMETERS}               # MCU-specific flags from above

    -Wall                           # Enable all common warnings
    -Wextra                         # Enable extra warnings

    -fdata-sections                 # Put each variable in its own section
    -ffunction-sections             # Put each function in its own section
                                    # These enable --gc-sections to remove unused code

    $<$<CONFIG:Debug>:-O0 -g3 -ggdb>  # Debug build options:
                                       # -O0 = no optimization (easier to debug)
                                       # -g3 = maximum debug info
                                       # -ggdb = debug info for GDB

    $<$<CONFIG:Release>:-Os -g0>      # Release build options:
                                       # -Os = optimize for size
                                       # -g0 = no debug info
)

#═══════════════════════════════════════════════════════════════════════════════
# LINKER OPTIONS
#═══════════════════════════════════════════════════════════════════════════════
target_link_options(${PROJECT_NAME} PRIVATE
    ${CPU_PARAMETERS}               # Must repeat CPU flags for linker

    -T${LINKER_SCRIPT}              # Use this linker script

    --specs=nano.specs              # Use newlib-nano (smaller C library)
                                    # Reduces code size significantly

    --specs=nosys.specs             # Don't link system calls (no OS)
                                    # Provides stub implementations for _exit, _sbrk, etc.

    -Wl,-Map=${PROJECT_NAME}.map    # Generate a map file
                                    # Shows where everything is placed in memory
                                    # -Wl, passes the option to the linker

    -Wl,--gc-sections               # Garbage collect unused sections
                                    # Removes functions/variables that aren't used
                                    # Works with -fdata-sections and -ffunction-sections

    -Wl,--print-memory-usage        # Print FLASH and RAM usage after linking
)

#═══════════════════════════════════════════════════════════════════════════════
# POST-BUILD COMMANDS - GENERATE ADDITIONAL OUTPUT FILES
#═══════════════════════════════════════════════════════════════════════════════
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    # After building the .elf file, run these commands:

    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
    # Generate Intel HEX file
    # Some programmers prefer .hex format

    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
    # Generate raw binary file
    # Can be used for DFU or direct flash writing

    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
    # Print code size (text, data, bss sections)
)

#═══════════════════════════════════════════════════════════════════════════════
# FLASH TARGET - PROGRAM THE MCU
#═══════════════════════════════════════════════════════════════════════════════
add_custom_target(flash
    COMMAND openocd
        -f ${CMAKE_CURRENT_SOURCE_DIR}/openocd.cfg    # Use our OpenOCD config
        -c "program $<TARGET_FILE:${PROJECT_NAME}> verify reset exit"
        # program = flash the .elf file
        # verify  = read back and verify
        # reset   = reset the MCU after flashing
        # exit    = close OpenOCD when done
    DEPENDS ${PROJECT_NAME}         # Build first if needed
)
```

---

### cmake/arm-none-eabi-gcc.cmake (Explained Line by Line)

```cmake
#═══════════════════════════════════════════════════════════════════════════════
# SYSTEM IDENTIFICATION
#═══════════════════════════════════════════════════════════════════════════════
set(CMAKE_SYSTEM_NAME Generic)
# "Generic" means bare-metal (no operating system)
# Other options: Linux, Windows, Darwin (macOS)
# This tells CMake we're cross-compiling

set(CMAKE_SYSTEM_PROCESSOR arm)
# Target processor architecture
# Tells CMake we're compiling for ARM

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# When CMake tests the compiler, build a static library instead of executable
# Executables need a linker script which we haven't provided yet
# This prevents "cannot find entry symbol _start" errors

#═══════════════════════════════════════════════════════════════════════════════
# TOOLCHAIN PREFIX
#═══════════════════════════════════════════════════════════════════════════════
set(TOOLCHAIN_PREFIX arm-none-eabi-)
# All ARM GCC tools start with this prefix:
#   arm-none-eabi-gcc     (C compiler)
#   arm-none-eabi-g++     (C++ compiler)
#   arm-none-eabi-objcopy (binary conversion)
#   arm-none-eabi-size    (size reporting)
#   arm-none-eabi-gdb     (debugger)
#
# "arm"       = ARM architecture
# "none"      = no vendor
# "eabi"      = Embedded ABI (Application Binary Interface)

#═══════════════════════════════════════════════════════════════════════════════
# FIND COMPILER LOCATION
#═══════════════════════════════════════════════════════════════════════════════
set(TOOLCHAIN_SEARCH_PATHS
    /Applications/ARM/bin           # macOS: Manual installation
    /opt/homebrew/bin               # macOS: Homebrew on Apple Silicon
    /usr/local/bin                  # macOS: Homebrew on Intel
    /usr/bin                        # Linux: System installation
)
# List of directories where the compiler might be installed

find_program(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc PATHS ${TOOLCHAIN_SEARCH_PATHS})
# Find arm-none-eabi-gcc and store path in CMAKE_C_COMPILER
# CMAKE_C_COMPILER is a special CMake variable for the C compiler

find_program(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++ PATHS ${TOOLCHAIN_SEARCH_PATHS})
# Find C++ compiler (even if not used, CMake may need it)

find_program(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc PATHS ${TOOLCHAIN_SEARCH_PATHS})
# For assembly files (.s), we use gcc (it calls the assembler internally)

#═══════════════════════════════════════════════════════════════════════════════
# FIND OTHER TOOLS
#═══════════════════════════════════════════════════════════════════════════════
get_filename_component(TOOLCHAIN_PATH ${CMAKE_C_COMPILER} DIRECTORY)
# Extract the directory path from the full compiler path
# e.g., /Applications/ARM/bin/arm-none-eabi-gcc -> /Applications/ARM/bin

find_program(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy PATHS ${TOOLCHAIN_PATH})
# objcopy: Converts between file formats (ELF -> HEX, ELF -> BIN)

find_program(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}objdump PATHS ${TOOLCHAIN_PATH})
# objdump: Disassembler, shows assembly code from compiled binary

find_program(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size PATHS ${TOOLCHAIN_PATH})
# size: Reports code size (text, data, bss sections)

find_program(CMAKE_GDB ${TOOLCHAIN_PREFIX}gdb PATHS ${TOOLCHAIN_PATH})
# gdb: GNU Debugger for debugging

#═══════════════════════════════════════════════════════════════════════════════
# OUTPUT FILE EXTENSION
#═══════════════════════════════════════════════════════════════════════════════
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")
# Output files will have .elf extension instead of no extension
# ELF = Executable and Linkable Format (standard for embedded)

#═══════════════════════════════════════════════════════════════════════════════
# FORCE COMPILER IDENTIFICATION
#═══════════════════════════════════════════════════════════════════════════════
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
# Skip CMake's compiler identification tests
# Cross-compilers may fail these tests since we can't run ARM code on the host

#═══════════════════════════════════════════════════════════════════════════════
# SEARCH PATH CONFIGURATION
#═══════════════════════════════════════════════════════════════════════════════
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# When looking for programs (like make), search host system paths
# We want to use the Mac's make, not an ARM one

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# When looking for libraries and headers, ONLY search in cross-compiler paths
# Don't accidentally use Mac libraries for ARM target
```

---

### CMakePresets.json (Explained)

```json
{
    "version": 6,
    // JSON schema version for CMake presets

    "configurePresets": [
        // Configure presets define how to run "cmake" (configuration step)
        {
            "name": "arm-debug",
            // Preset identifier - use with: cmake --preset arm-debug

            "displayName": "ARM Debug",
            // Human-readable name shown in CLion

            "generator": "Ninja",
            // Build system generator
            // Ninja is faster than Make, especially for incremental builds
            // Alternatives: "Unix Makefiles", "Xcode"

            "binaryDir": "${sourceDir}/build/Debug",
            // Where to put build files
            // ${sourceDir} = folder containing CMakeLists.txt
            // Keeps build files separate from source

            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Debug",
                // Build type: Debug, Release, RelWithDebInfo, MinSizeRel
                // Debug = no optimization, full debug symbols

                "CMAKE_EXPORT_COMPILE_COMMANDS": "ON"
                // Generate compile_commands.json
                // Used by IDEs and tools for code analysis
            },

            "toolchainFile": "${sourceDir}/cmake/arm-none-eabi-gcc.cmake"
            // Path to toolchain file
            // Same as setting CMAKE_TOOLCHAIN_FILE
        },
        {
            "name": "arm-release",
            "displayName": "ARM Release",
            "generator": "Ninja",
            "binaryDir": "${sourceDir}/build/Release",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Release",
                // Release = optimized for size/speed, no debug info
                "CMAKE_EXPORT_COMPILE_COMMANDS": "ON"
            },
            "toolchainFile": "${sourceDir}/cmake/arm-none-eabi-gcc.cmake"
        }
    ]
}
```

---

## Step 2: OpenOCD Configuration

### openocd.cfg (Explained Line by Line)

```tcl
#═══════════════════════════════════════════════════════════════════════════════
# DEBUG PROBE INTERFACE
#═══════════════════════════════════════════════════════════════════════════════
source [find interface/stlink.cfg]
# Load the ST-Link interface configuration
# "source" = include another config file
# "[find ...]" = search OpenOCD's script directories
#
# Common interfaces:
#   interface/stlink.cfg      - ST-Link V2, V2-1, V3 (Nucleo, Discovery boards)
#   interface/stlink-v2.cfg   - ST-Link V2 only
#   interface/jlink.cfg       - Segger J-Link
#   interface/cmsis-dap.cfg   - CMSIS-DAP compatible probes
#   interface/ftdi/...        - FTDI-based probes

#═══════════════════════════════════════════════════════════════════════════════
# TARGET MCU
#═══════════════════════════════════════════════════════════════════════════════
source [find target/stm32f4x.cfg]
# Load the STM32F4 target configuration
# This file knows:
#   - How to communicate with STM32F4 chips
#   - Flash memory layout and programming algorithm
#   - CPU core type (Cortex-M4)
#
# Common targets:
#   target/stm32f0x.cfg  - STM32F0 series (Cortex-M0)
#   target/stm32f1x.cfg  - STM32F1 series (Cortex-M3)
#   target/stm32f2x.cfg  - STM32F2 series (Cortex-M3)
#   target/stm32f3x.cfg  - STM32F3 series (Cortex-M4)
#   target/stm32f4x.cfg  - STM32F4 series (Cortex-M4)
#   target/stm32f7x.cfg  - STM32F7 series (Cortex-M7)
#   target/stm32h7x.cfg  - STM32H7 series (Cortex-M7)
#   target/stm32l0.cfg   - STM32L0 series (Cortex-M0+)
#   target/stm32l1.cfg   - STM32L1 series (Cortex-M3)
#   target/stm32l4x.cfg  - STM32L4 series (Cortex-M4)
#   target/stm32g0x.cfg  - STM32G0 series (Cortex-M0+)
#   target/stm32g4x.cfg  - STM32G4 series (Cortex-M4)

#═══════════════════════════════════════════════════════════════════════════════
# ADAPTER SPEED
#═══════════════════════════════════════════════════════════════════════════════
adapter speed 2000
# Communication speed in kHz between debug probe and target
# 2000 kHz = 2 MHz
#
# Guidelines:
#   - Higher = faster programming/debugging
#   - Too high = communication errors
#   - Start with 1000-2000, increase if stable
#   - ST-Link V2 max: ~1800 kHz
#   - ST-Link V3/J-Link: can go much higher (4000+)

#═══════════════════════════════════════════════════════════════════════════════
# RESET CONFIGURATION
#═══════════════════════════════════════════════════════════════════════════════
reset_config srst_only srst_nogate
# Configure how to reset the target
#
# srst_only:
#   - Use only SRST (System Reset) pin
#   - Don't use TRST (Test Reset) - some probes don't have it
#
# srst_nogate:
#   - Don't gate (block) SRST signal
#   - Allow reset to happen immediately
#
# Other options:
#   srst_gates_jtag  - SRST also resets debug logic
#   trst_and_srst    - Use both TRST and SRST
#   none             - No hardware reset available

#═══════════════════════════════════════════════════════════════════════════════
# SERVER PORTS
#═══════════════════════════════════════════════════════════════════════════════
gdb_port 3333
# Port for GDB connections
# CLion/GDB connects here for debugging
# Default: 3333

telnet_port 4444
# Port for telnet connections
# You can connect with: telnet localhost 4444
# Useful for manual OpenOCD commands

tcl_port 6666
# Port for TCL scripting connections
# Used by some tools for automation
# Default: 6666
```

---

## Step 3: CLion Configuration

### 3.1 Open Project

1. Open CLion
2. **File → Open** → Select your project folder containing `CMakeLists.txt`
3. CLion will detect the CMake project and show a dialog
4. Click **OK** to load with default settings

### 3.2 Select CMake Preset

1. Go to **Settings → Build, Execution, Deployment → CMake**
   - macOS: **CLion → Settings** or **⌘,**
2. You should see presets listed: `arm-debug`, `arm-release`
3. **Enable** the preset you want (check the checkbox)
4. **Disable** any "Debug" or "Release" profiles that don't use your toolchain
5. Click **Apply** → **OK**

### 3.3 Configure Debug Configuration (Detailed)

1. Go to **Run → Edit Configurations...**

2. Click **+** (Add New Configuration) → **Embedded GDB Server**

3. Fill in each field:

| Field | Value | Explanation |
|-------|-------|-------------|
| **Name** | `Debug STM32` | Name shown in the Run dropdown |
| **Target** | `YourProject` | The CMake target to build |
| **Executable binary** | `YourProject.elf` | The file to flash and debug |
| **Debugger** | `/Applications/ARM/bin/arm-none-eabi-gdb` | Full path to ARM GDB |
| **Download executable** | `Always` | Flash before each debug session |
| **'target remote' args** | `localhost:3333` | GDB connects to OpenOCD on this port |
| **GDB Server** | `/opt/homebrew/bin/openocd` | Full path to OpenOCD |
| **GDB Server args** | `-f /full/path/to/openocd.cfg` | OpenOCD config file (use absolute path!) |
| **Working directory** | `/full/path/to/project` | Where OpenOCD runs from |

4. Click **Advanced GDB Server Options** (expand if hidden):

| Field | Value | Explanation |
|-------|-------|-------------|
| **Reset command** | `monitor reset halt` | Command to reset MCU and halt at start |

5. Click **Apply** → **OK**

### 3.4 Configure Flash-Only Target (Optional)

If you want to flash without debugging:

1. Go to **Run → Edit Configurations...**
2. Click **+** → **CMake Application**
3. Fill in:
   - **Name**: `Flash Only`
   - **Target**: `flash`
   - **Executable**: (leave empty or select any)
4. Click **Apply**

Now you can select "Flash Only" and click Run to just flash without debugging.

### 3.5 Add SVD File for Peripheral View (Optional but Recommended)

The SVD file enables viewing MCU peripheral registers during debugging.

1. Go to **Settings → Build, Execution, Deployment → Embedded Development**
2. Find **Peripheral Registers** section
3. Click **+** to add a new SVD file
4. Browse to your `.svd` file (e.g., `STM32F446.svd`)
5. Click **Apply** → **OK**

**Where to get SVD files:**
- STM32: https://github.com/cmsis-svd/cmsis-svd-data/tree/main/data/STMicro
- Or from STM32CubeMX installation folder

---

## Step 4: Build, Flash, and Debug

### Build

| Method | How |
|--------|-----|
| **CLion GUI** | Click **Build** (hammer icon) or press **⌘F9** |
| **Terminal** | `cmake --preset arm-debug && cmake --build build/Debug` |

### Flash Only (without debugging)

| Method | How |
|--------|-----|
| **CLion GUI** | Select "Flash Only" config, click **Run** (play icon) |
| **Terminal** | `cmake --build build/Debug --target flash` |

### Debug

1. **Set breakpoints** by clicking in the gutter (gray margin left of line numbers)
   - A red dot appears where execution will pause

2. **Select** the "Debug STM32" configuration from the dropdown

3. **Click Debug** (bug icon) or press **⌃D**

4. CLion will:
   - Build the project (if needed)
   - Start OpenOCD in the background
   - Flash the firmware to the MCU
   - Start GDB and connect to OpenOCD
   - Run until the first breakpoint (or `main()` if Reset command is set)

### Debug Controls

| Action | Shortcut | Icon | Description |
|--------|----------|------|-------------|
| **Resume** | ⌘⌥R | ▶ | Continue execution until next breakpoint |
| **Pause** | ⌘⌥P | ⏸ | Pause execution |
| **Stop** | ⌘F2 | ⏹ | Stop debugging |
| **Step Over** | F8 | ↷ | Execute current line, don't enter functions |
| **Step Into** | F7 | ↓ | Execute current line, enter functions |
| **Step Out** | ⇧F8 | ↑ | Run until current function returns |
| **Run to Cursor** | ⌥F9 | | Run until the line where cursor is |

### Debug Panels

| Panel | What it shows |
|-------|---------------|
| **Variables** | Local variables, function arguments, global variables |
| **Watches** | Custom expressions you want to monitor |
| **Call Stack** | Function call hierarchy (who called whom) |
| **Threads** | On RTOS: shows all threads/tasks |
| **Memory** | Raw memory view at any address |
| **Peripherals** | MCU registers (requires SVD file) |
| **Registers** | CPU core registers (R0-R15, PSR, etc.) |
| **Disassembly** | Assembly code view |

---

## Troubleshooting

### "Can't find openocd.cfg"

**Cause:** OpenOCD is looking for the config file in the wrong directory.

**Fix:** Use the full absolute path in GDB Server args:
```
-f /Users/yourname/Projects/YourProject/openocd.cfg
```

### "Address already in use" (port 3333, 4444, or 6666)

**Cause:** Another OpenOCD instance is still running.

**Fix:** Kill it:
```bash
pkill openocd
```

Or find and kill specifically:
```bash
lsof -i :3333
kill -9 <PID>
```

### "No ST-Link detected" or "LIBUSB_ERROR"

**Causes & Fixes:**

1. **Bad USB cable** - Some cables are power-only (no data lines). Try a different cable.

2. **Board not powered** - Check if board LEDs are on.

3. **Permission issue on macOS:**
   ```bash
   # Try with sudo once to test
   sudo openocd -f openocd.cfg
   ```

4. **Another app using ST-Link** - Close STM32CubeIDE, STM32CubeProgrammer, etc.

5. **Unplug and replug** the board.

### "another process has device opened for exclusive access"

**Cause:** Another application has the USB device open.

**Fix:**
```bash
# Kill all potential users
pkill openocd
pkill st-util
pkill STM32CubeProgrammer

# Unplug and replug the board
```

### "Error: jtag status contains invalid mode value"

**Cause:** Communication issue between probe and MCU.

**Fixes:**
1. Lower the adapter speed in openocd.cfg:
   ```tcl
   adapter speed 1000
   ```
2. Check that the correct target file is used
3. Try pressing the reset button on the board

### Linker script "(READONLY)" error with GCC 10

**Cause:** The `(READONLY)` attribute requires GCC 11+.

**Fix:** Remove `(READONLY)` from linker script sections:
```
# Before:
.ARM.extab (READONLY) :

# After:
.ARM.extab :
```

### "__DSB" or "__ISB" undefined

**Cause:** ARM intrinsics not defined.

**Fix:** Add to your code (e.g., in a header file):
```c
#ifndef __DSB
  #define __DSB() __asm volatile ("dsb 0xF":::"memory")
#endif
#ifndef __ISB
  #define __ISB() __asm volatile ("isb 0xF":::"memory")
#endif
#ifndef __DMB
  #define __DMB() __asm volatile ("dmb 0xF":::"memory")
#endif
```

### Breakpoints not working / "Cannot insert breakpoint"

**Causes & Fixes:**

1. **Code in FLASH** - Hardware breakpoints are limited (usually 6). Use fewer breakpoints or enable software breakpoints.

2. **Optimization** - In Release builds, code may be optimized away. Use Debug build.

3. **Wrong ELF file** - Make sure you're debugging the same .elf that was flashed.

---

## Quick Reference

### Terminal Commands

```bash
# Configure project
cmake --preset arm-debug

# Build
cmake --build build/Debug

# Flash
cmake --build build/Debug --target flash

# Clean build
rm -rf build
cmake --preset arm-debug
cmake --build build/Debug

# Kill stuck OpenOCD
pkill openocd

# Check if board is connected (macOS)
ioreg -p IOUSB | grep -i stlink

# Manual OpenOCD flash
openocd -f openocd.cfg -c "program build/Debug/YourProject.elf verify reset exit"

# Manual OpenOCD debug server
openocd -f openocd.cfg
# Then in another terminal:
arm-none-eabi-gdb build/Debug/YourProject.elf
(gdb) target remote localhost:3333
(gdb) monitor reset halt
(gdb) load
(gdb) break main
(gdb) continue
```

### MCU-Specific Settings Reference

| MCU Family | CPU Core | FPU Flag | Float ABI | OpenOCD Target |
|------------|----------|----------|-----------|----------------|
| STM32F0 | cortex-m0 | (none) | soft | stm32f0x.cfg |
| STM32F1 | cortex-m3 | (none) | soft | stm32f1x.cfg |
| STM32F2 | cortex-m3 | (none) | soft | stm32f2x.cfg |
| STM32F3 | cortex-m4 | fpv4-sp-d16 | hard | stm32f3x.cfg |
| STM32F4 | cortex-m4 | fpv4-sp-d16 | hard | stm32f4x.cfg |
| STM32F7 | cortex-m7 | fpv5-sp-d16 | hard | stm32f7x.cfg |
| STM32H7 | cortex-m7 | fpv5-d16 | hard | stm32h7x.cfg |
| STM32L0 | cortex-m0plus | (none) | soft | stm32l0.cfg |
| STM32L1 | cortex-m3 | (none) | soft | stm32l1.cfg |
| STM32L4 | cortex-m4 | fpv4-sp-d16 | hard | stm32l4x.cfg |
| STM32G0 | cortex-m0plus | (none) | soft | stm32g0x.cfg |
| STM32G4 | cortex-m4 | fpv4-sp-d16 | hard | stm32g4x.cfg |

### Memory Sections Explained

| Section | Contents | Location |
|---------|----------|----------|
| `.text` | Code (functions) | FLASH |
| `.rodata` | Constants, strings | FLASH |
| `.data` | Initialized global/static variables | RAM (copied from FLASH at startup) |
| `.bss` | Uninitialized global/static variables | RAM (zeroed at startup) |
| `.stack` | Stack (local variables, return addresses) | RAM |
| `.heap` | Dynamic memory (malloc) | RAM |

---

## Resources

- [ARM GCC Toolchain Download](https://developer.arm.com/downloads/-/gnu-rm)
- [OpenOCD Documentation](https://openocd.org/doc/html/index.html)
- [CLion Embedded Development Guide](https://www.jetbrains.com/help/clion/embedded-development.html)
- [CMSIS SVD Files Repository](https://github.com/cmsis-svd/cmsis-svd-data)
- [STM32 Reference Manuals](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)