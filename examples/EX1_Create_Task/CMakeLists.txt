cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

project(example C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(ex1_create_task
        main.c
        )

target_include_directories(ex1_create_task PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )

target_link_libraries(ex1_create_task pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)

# Enable usb output, disable uart output
pico_enable_stdio_usb(ex1_create_task 1)
pico_enable_stdio_uart(ex1_create_task 0)

pico_add_extra_outputs(ex1_create_task)