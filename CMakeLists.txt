cmake_minimum_required(VERSION 3.19)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_DIR C:/SysGCC/raspberry)
set(CMAKE_SYSROOT ${TOOLCHAIN_DIR}/arm-linux-gnueabihf/sysroot)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-g++.exe)
set(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-gcc.exe)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

project(rpi-clion-example)

set(CMAKE_CXX_STANDARD 14)

add_executable(rpi.elf problem_007.cpp)

add_custom_target(rpi-stripped.elf ALL
        ${TOOLCHAIN_DIR}/bin/arm-linux-gnueabihf-objcopy.exe -g rpi.elf rpi-stripped.elf
        DEPENDS rpi.elf
        BYPRODUCTS rpi-stripped.elf
        )
