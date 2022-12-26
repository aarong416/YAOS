#ifndef _IO_H
#define _IO_H

#define PORT_VGA_COMMAND 0x3D4
#define PORT_VGA_DATA    0x3D5

#include <cstdint.h>

extern "C" uint8_t inb(uint16_t port);
extern "C" void outb(uint16_t port, uint8_t val);

#endif
