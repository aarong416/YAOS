#ifndef _IO_H
#define _IO_H

#include <cstdint.h>

extern "C" uint8_t inb(uint16_t port);
extern "C" void outb(uint16_t port, uint8_t val);

#endif
