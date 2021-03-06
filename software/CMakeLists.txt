# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/caden/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_cube C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pico_cube
                base/mux.cpp
                base/basic_functions.cpp
                base/HelpfulFunctions.cpp
                RelativeCoordinates/Relativistic.cpp
                App/App.cpp
                pico_cube.cpp 
                )

pico_set_program_name(pico_cube "pico_cube")
pico_set_program_version(pico_cube "0.1")

pico_enable_stdio_uart(pico_cube 1)
pico_enable_stdio_usb(pico_cube 0)

# Add the standard library to the build
target_link_libraries(pico_cube pico_stdlib hardware_adc)

# Add any user requested libraries
target_link_libraries(pico_cube
        hardware_spi
        pico_multicore
        )

pico_add_extra_outputs(pico_cube)

