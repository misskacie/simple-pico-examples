# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
   set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(PICO_SDK_PATH ${USERHOME}/.pico-sdk/sdk/2.0.0)
set(PICO_TOOLCHAIN_PATH ${USERHOME}/.pico-sdk/toolchain/13_2_Rel1)
if(WIN32)
    set(pico-sdk-tools_DIR ${USERHOME}/.pico-sdk/tools/2.0.0)
    include(${pico-sdk-tools_DIR}/pico-sdk-tools-config.cmake)
    include(${pico-sdk-tools_DIR}/pico-sdk-tools-config-version.cmake)
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")
set(PICO_SDK_FETCH_FROM_GIT 1)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico-example-project C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
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



