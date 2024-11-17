cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(PICO_BOARD pico CACHE STRING "Board type")
set(PICO_PLATFORM rp2040)
set(PICO_SDK_FETCH_FROM_GIT 1)
set(FREERTOS_FETCH_FROM_GIT 1)
# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()
# Initialise the Raspberry Pi Pico SDK

pico_sdk_init()

project(pico-example-project C CXX ASM)



# ====================================================================================
# ====================================================================================
# ====================================================================================
add_executable(hello-world-example hello-world-example.c )

pico_set_program_name(hello-world-example "hello-world-example")
pico_set_program_version(hello-world-example "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(hello-world-example 0)
pico_enable_stdio_usb(hello-world-example 0)

# Add the standard library to the build
target_link_libraries(hello-world-example
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(hello-world-example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

pico_add_extra_outputs(hello-world-example)

# ====================================================================================
# ====================================================================================
# ====================================================================================
add_executable(gpio-example gpio-example.c )

pico_set_program_name(gpio-example "gpio-example")
pico_set_program_version(gpio-example "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(gpio-example 0)
pico_enable_stdio_usb(gpio-example 0)

# Add the standard library to the build
target_link_libraries(gpio-example
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(gpio-example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(gpio-example
        hardware_gpio
        )

pico_add_extra_outputs(gpio-example)

# ====================================================================================
# ====================================================================================
# ====================================================================================
add_executable(interupt-example interupt-example.c )

pico_set_program_name(interupt-example "interupt-example")
pico_set_program_version(interupt-example "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(interupt-example 0)
pico_enable_stdio_usb(interupt-example 0)

# Add the standard library to the build
target_link_libraries(interupt-example
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(interupt-example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(interupt-example
        hardware_gpio
        )

pico_add_extra_outputs(interupt-example)

# ====================================================================================
# ====================================================================================
# ====================================================================================
add_executable(multicore-example multicore-example.c )

pico_set_program_name(multicore-example "multicore-example")
pico_set_program_version(multicore-example "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(multicore-example 0)
pico_enable_stdio_usb(multicore-example 0)

# Add the standard library to the build
target_link_libraries(multicore-example
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(multicore-example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(multicore-example
        pico_multicore
        )

pico_add_extra_outputs(multicore-example)

# ====================================================================================
# ====================================================================================
# ====================================================================================

add_library(freertos_config INTERFACE)
target_include_directories(freertos_config INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/FreeRTOS"
) 


include(FreeRTOS/FreeRTOS_import.cmake)
include(FreeRTOS/FreeRTOS_Kernel_import.cmake)

add_executable(freertos-example freertos-example.c FreeRTOS/FreeRTOSPortAux.c)

pico_set_program_name(freertos-example "freertos-example")
pico_set_program_version(freertos-example "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(freertos-example 0)
pico_enable_stdio_usb(freertos-example 0)

# Add the standard library to the build
target_link_libraries(freertos-example
        pico_stdlib)
 
# Add the standard include files to the build
target_include_directories(freertos-example PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(freertos-example
        FreeRTOS-Kernel 
        FreeRTOS-Kernel-Heap4 
        freertos_config
        )

pico_add_extra_outputs(freertos-example)


