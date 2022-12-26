#ifndef SETUP_H
#define SETUP_H

#include <kernel.h>

void setupDrivers(KernelInfo kinfo);
void setupHardwareCursor(uint8_t cursor_start, uint8_t cursor_end);

#endif
