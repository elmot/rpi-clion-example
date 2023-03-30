Clion example project for embedded Linux debug
===



This project demonstrates how to cross-compile and debug an application for Raspberry Pi(RPi).
A workaround for a feature request
[CPP-23898](https://youtrack.jetbrains.com/issue/CPP-23898) is also implemented here.

The project is made for Raspberry Pi OS 64-bit, release date 21-Feb-2023,
Kernel version 5.15, Debian version 11 (bullseye)

Raspberry Pi is configured to have IP address 192.168.0.101, *sshd* to be started on boot.

Cross-Compilation
---
RPi-compatible toolchain & sysroot are installed to 
its standard location *C:\SysGCC\raspberry64*

To optimize binary size a special build step is added (see `add_custom_target` clause in `CMakeLists.txt`).
 

Debugging
---
A run configuration of type `Remote GDB Server` copies the stripped binary to the target board 
and starts it there under gdbserver. 

Generated '.gdbinit' script forces gdb to use symbols from full (i.e. non-stripped) binary.

WSL/Docker requirements
---
* Ubuntu 22.04LTS
* [CMake 3.23+](https://cmake.org/download/)
* Packages installed: 
  * binutils-aarch64-linux-gnu
  * g++-aarch64-linux-gnu
  * gcc-aarch64-linux-gnu
  * make

References
* [CLion homepage](https://www.jetbrains.com/clion/) 
* [CLion Remote debug via GDB/gdbserver](https://www.jetbrains.com/help/clion/remote-debug-via-gdb-gdbserver.html)
* [CMake](https://cmake.org/)
* [Raspberry Pi toolchain](https://gnutoolchains.com/raspberry64/)