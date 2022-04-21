# YAOS

A New Operating System

## Getting Started

1. `apt install nasm g++ xorisso qemu-system-i386`
2. `make`

## Always TODO

- Comments

## TODO

- Driver manager
- Implement `cout`

- Memory manager driver
- Logging function

- Implement string fill constructor
- Implement std::to_string
- Implement std::string::compare and std::string::operator==

- Get info from GRUB (screen size, available memory etc)
- GDT
- Timer
- Keyboard driver
- Shell
- IDT
- Exceptions
- System calls
- Filesystem
- Networking
- Processes
- Tests

## Issues

- Can't create more than 1 string at a time (can't view the second string, prints nothing)
- `itoa` not working properly. Refer to `dump` in `dump.cpp`
