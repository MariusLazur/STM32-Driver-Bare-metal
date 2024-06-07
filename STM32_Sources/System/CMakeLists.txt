add_subdirectory(drivers)

target_include_directories(${TARGET_NAME} PUBLIC Inc)

target_sources(${TARGET_NAME} PRIVATE   Startup/startup_stm32f446retx.S)
target_sources(${TARGET_NAME} PRIVATE   src/main.c)