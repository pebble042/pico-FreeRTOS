cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

project(example_ex1 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(example1
        main.c
        ex1_create_task.c
        )

target_include_directories(example1 
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        )

target_compile_definitions(example1 PRIVATE
        mainEX1_CREATE_TASK_ONLY=1
        )

target_link_libraries(
        example1 
        pico_stdlib 
        FreeRTOS-Kernel 
        FreeRTOS-Kernel-Heap4
        )

# Enable usb output, disable uart output
pico_enable_stdio_usb(example1 1)
pico_enable_stdio_uart(example1 0)

pico_add_extra_outputs(example1)