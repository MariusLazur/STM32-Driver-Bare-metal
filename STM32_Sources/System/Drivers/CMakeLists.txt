set(CURRENT_DIR ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(${TARGET_NAME} PUBLIC
        ${CURRENT_DIR}/gpio/inc
        ${CURRENT_DIR}/rcc/inc
        ${CURRENT_DIR}/pwr/inc
        )


target_sources(${TARGET_NAME} PRIVATE  gpio/src/gpio.c)
target_sources(${TARGET_NAME} PRIVATE  pwr/src/pwr.c)
target_sources(${TARGET_NAME} PRIVATE  rcc/src/rcc.c)



