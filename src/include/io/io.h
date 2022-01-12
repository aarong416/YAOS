#ifndef _IO_H
#define _IO_H

#include <cstdint.h>

extern "C" std::uint8_t inb(std::uint16_t port);
extern "C" void outb(std::uint16_t port, std::uint8_t val);

#endif
