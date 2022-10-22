#ifndef DEBUGGING_H
#define DEBUGGING_H

// 2 bytes for the hex digits, 1 for the space, and 1 for the ASCII character
#define CHARACTERS_PER_BYTE 4

#include <cstdint.h>

void dump(void* ptr, uint32_t count);

#endif