#ifndef DEBUGGING_H
#define DEBUGGING_H

#define CHARACTERS_PER_BYTE 4 // 2 bytes for the hex digits, 1 for the space,
                              // and 1 for the ascii value

#include <cstdint.h>

void dump(void* ptr, uint32_t count);

#endif