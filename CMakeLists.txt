cmake_minimum_required(VERSION 3.16)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_SYSROOT /home/elmot/sysroot-rpi)
set(CMAKE_SYSROOT_LINK  ${CMAKE_SYSROOT})
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

project(rpi-clion-example)

set(CMAKE_CXX_STANDARD 14)

add_executable(rpi.elf main.c)
target_link_libraries(rpi.elf gpiod)

add_custom_target(rpi-stripped.elf ALL
        aarch64-linux-gnu-objcopy -g rpi.elf rpi-stripped.elf
        DEPENDS rpi.elf
        BYPRODUCTS rpi-stripped.elf
        )

add_custom_command(TARGET rpi.elf
        COMMAND file rpi.elf
        COMMAND aarch64-linux-gnu-objdump -T rpi.elf
        POST_BUILD)