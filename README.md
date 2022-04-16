# YAOS

A New Operating System

## Getting Started

1. `apt install nasm g++ xorisso qemu-system-i386`
2. `make`

## Always TODO

- Comments

## TODO

- Implement string fill constructor
- Implement std::to_string
- Ability to print numbers to the screen
- Ability to convert between between decimal and hex
- Implement std::string::compare and std::string::operator==
- Driver manager
- Debugging function that accepts a memory address and number of bytes, and dumps
  the contents of memory at that address, for the specified number of bytes
- Implement `cout`
- Logging function
- (Implement vectors)

- Reimplement dynamic memory management
- Memory manager driver

- Get info from GRUB (screen size, available memory etc)
- GDT
- Keyboard driver
- Shell
- IDT
- Exceptions
- System calls
- Timer
- Filesystem
- Networking
- Processes
- Tests

## Issues

- Can't create more than 1 string at a time (can't view the second string, prints nothing)
