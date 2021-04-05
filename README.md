Clion example project for embedded Linux debug
===

This project demonstrates how to cross-compile and debug an application for Raspberry Pi(RPi).
A workaround for a feature request
[CPP-23898](https://youtrack.jetbrains.com/issue/CPP-23898) is also implemented here. 

Raspberry Pi is configured to have IP address 192.168.0.110, *sshd* to be started on boot.

Cross-Compilation
---
RPi-compatible toolchain & sysroot are installed to 
its standard location *C:\SysGCC\raspberry*

The toolchain for the project is configures in `File | Settings | Build, Execution, Deployment | Toolchains` dialog
To 

To optimize binary size a special build step is added (see `add_custom_target` clause in `CMakeLists.txt`).
 
It makes a `rpi-stripped.elf` binary without debug info.

Debugging
---
A run configuration of type `Remote GDB Server` copies the stripped binary to the target board 
and starts it there under gdbserver. 

A custom '.gdbinit' script load full(non-stripped) version is loaded to gdb.


References
* [CLion homepage](https://www.jetbrains.com/clion/) 
* [CLion Remote debug via GDB/gdbserver](https://www.jetbrains.com/help/clion/remote-debug-via-gdb-gdbserver.html)
* [CMake](https://cmake.org/)
* [Raspberry Pi toolchain](https://gnutoolchains.com/raspberry/)